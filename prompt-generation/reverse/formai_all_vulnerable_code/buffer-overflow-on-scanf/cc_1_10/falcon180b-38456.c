//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    int line_number;
    char *content;
    struct node *next;
} Node;

Node *create_node(char *filename, int line_number, char *content) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->filename = filename;
    node->line_number = line_number;
    node->content = content;
    node->next = NULL;
    return node;
}

void add_node(Node *head, Node *new_node) {
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *curr_node = head;
    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

void print_list(Node *head) {
    Node *curr_node = head;
    while (curr_node!= NULL) {
        printf("%s:%d - %s\n", curr_node->filename, curr_node->line_number, curr_node->content);
        curr_node = curr_node->next;
    }
}

void free_list(Node *head) {
    Node *curr_node = head;
    while (curr_node!= NULL) {
        Node *temp_node = curr_node;
        curr_node = curr_node->next;
        free(temp_node->filename);
        free(temp_node->content);
        free(temp_node);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *content = NULL;
    int line_number = 0;
    size_t len = 0;
    Node *head = NULL;

    printf("Enter the name of the file to recover:\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    while (getline(&line, &len, fp)!= -1) {
        line_number++;
        content = realloc(content, strlen(line) + 1);
        strcpy(content, line);
        add_node(head, create_node(filename, line_number, content));
    }

    fclose(fp);
    print_list(head);
    free_list(head);

    return 0;
}