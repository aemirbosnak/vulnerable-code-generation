//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct Node {
    char *data;
    struct Node *next;
};

void print_list(struct Node *head) {
    struct Node *tmp = head;
    while (tmp!= NULL) {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

void delete_list(struct Node *head) {
    struct Node *tmp = head;
    while (tmp!= NULL) {
        free(tmp->data);
        struct Node *ptr = tmp;
        tmp = tmp->next;
        free(ptr);
    }
}

void recursive_file_read(FILE *fp, struct Node *head) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline character
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->data = strdup(line);
        new_node->next = head->next;
        head->next = new_node;
    }
}

int main() {
    FILE *fp;
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct Node *head = malloc(sizeof(struct Node));
    head->data = "";
    head->next = NULL;

    recursive_file_read(fp, head);

    print_list(head);

    delete_list(head);
    free(head);

    fclose(fp);
    return 0;
}