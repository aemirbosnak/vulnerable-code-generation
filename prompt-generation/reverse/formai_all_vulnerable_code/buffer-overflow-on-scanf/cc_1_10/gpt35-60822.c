//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define GB 1073741824 // 1GB size in bytes

typedef struct file_node {
    char *file_name;
    long long file_size;
    struct file_node *next_file;
} file_node;

file_node *head = NULL;

bool append_file_node(char *file_name, long long file_size) {
    file_node *new_node = malloc(sizeof(file_node));
    if (new_node == NULL) {
        return false;
    }
    new_node->file_name = file_name;
    new_node->file_size = file_size;
    new_node->next_file = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        file_node *current_node = head;
        while (current_node->next_file != NULL) {
            current_node = current_node->next_file;
        }
        current_node->next_file = new_node;
    }
    return true;
}

void delete_list() {
    file_node *current_node = head;
    while (current_node != NULL) {
        file_node *temp = current_node;
        current_node = current_node->next_file;
        free(temp->file_name);
        free(temp);
    }
    head = NULL;
}

void print_file_list() {
    printf("\tFile Name\t|\tFile Size\n");
    printf("---------------------------------------------\n");
    file_node *current_node = head;
    while (current_node != NULL) {
        printf("\t%-15s|\t%lld GB\n", current_node->file_name, current_node->file_size / GB);
        current_node = current_node->next_file;
    }
}

void analyze_disk_space(char *path) {
    FILE *fp;
    char command[100] = "du -h ";
    strcat(command, path);
    strcat(command, "/*");
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp)) {
        char file_size[10];
        char *token = strtok(buffer, "\t");
        strcpy(file_size, token);
        token = strtok(NULL, "\t");
        char *file_name = malloc(strlen(token) * sizeof(char));
        strcpy(file_name, token);
        if (!append_file_node(file_name, atoll(file_size))) {
            printf("Out of memory error!\n");
            pclose(fp);
            delete_list();
            exit(1);
        }
    }
    pclose(fp);
}

int main() {
    char path[100];
    printf("Enter the path you want to analyze: ");
    scanf("%s", path);
    analyze_disk_space(path);
    print_file_list();
    delete_list();
    return 0;
}