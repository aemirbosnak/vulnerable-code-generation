//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char *data;
    struct node *next;
};

void addNode(struct node **head, char *data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void traverseList(struct node *head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    char input[MAX_SIZE];
    char search[MAX_SIZE];

    printf("Enter the elements of the list (enter 'done' when finished):\n");
    scanf("%s", input);
    while (strcmp(input, "done")!= 0) {
        addNode(&head, input);
        printf("Enter the next element (enter 'done' when finished):\n");
        scanf("%s", input);
    }

    printf("Enter the element to search for:\n");
    scanf("%s", search);

    struct node *current = head;
    int found = 0;

    while (current!= NULL) {
        if (strcmp(current->data, search) == 0) {
            printf("%s found at position %d\n", search, found + 1);
            found = 1;
        }
        current = current->next;
        found++;
    }

    if (found == 0) {
        printf("%s not found\n", search);
    }

    return 0;
}