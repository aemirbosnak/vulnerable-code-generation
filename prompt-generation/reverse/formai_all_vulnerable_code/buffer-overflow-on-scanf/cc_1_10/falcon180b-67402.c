//Falcon-180B DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int size;
    struct node *next;
} node;

void addNode(node **head, char *name, int size) {
    node *newNode = malloc(sizeof(node));
    newNode->name = strdup(name);
    newNode->size = size;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    while (head!= NULL) {
        printf("%s (%d)\n", head->name, head->size);
        head = head->next;
    }
}

void freeList(node *head) {
    while (head!= NULL) {
        free(head->name);
        free(head);
        head = head->next;
    }
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sortList(node **head) {
    qsort(*head, 1, sizeof(node), compare);
}

int main() {
    char input[MAX_SIZE];
    char *token;
    char *filename;
    FILE *file;
    int size;
    node *head = NULL;

    printf("Enter filename: ");
    scanf("%s", input);
    filename = strdup(input);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(input, MAX_SIZE, file)!= NULL) {
        token = strtok(input, " ");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                size = strlen(token);
                addNode(&head, token, size);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Unsorted list:\n");
    printList(head);

    sortList(&head);

    printf("\nSorted list:\n");
    printList(head);

    freeList(head);

    return 0;
}