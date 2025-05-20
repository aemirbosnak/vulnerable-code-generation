//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node with given data
Node* create_node(char *data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to read CSV file and return a linked list of rows
Node* read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    Node *head = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        Node *row = create_node(token);
        Node *prev_row = head;
        while ((token = strtok(NULL, ","))!= NULL) {
            Node *cell = create_node(token);
            prev_row->next = cell;
            prev_row = cell;
        }
        head = row;
    }

    fclose(fp);
    return head;
}

// Function to print linked list
void print_list(Node *head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    char filename[100];
    printf("Enter CSV file name: ");
    scanf("%s", filename);

    Node *list = read_csv(filename);
    printf("CSV data:\n");
    print_list(list);

    return 0;
}