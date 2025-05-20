//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the data structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// function to insert a value into a linked list
void insert(node_t **head, int val) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

// main function to read values from a file and insert them into a linked list
int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the file to read from: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    node_t *head = NULL;
    char buffer[100];
    while (fgets(buffer, 100, fp)) {
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            int val = atoi(token);
            insert(&head, val);
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    // perform some data mining on the linked list here
    int total = 0;
    node_t *curr = head;
    while (curr != NULL) {
        total += curr->data;
        curr = curr->next;
    }
    printf("Total: %d\n", total);
    // free memory used by the linked list
    curr = head;
    while (curr != NULL) {
        node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    return 0;
}