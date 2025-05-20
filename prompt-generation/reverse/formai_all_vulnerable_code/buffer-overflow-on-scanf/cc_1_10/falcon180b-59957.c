//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int searchList(Node *head, char *data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node *head = NULL;
    char data[MAX_SIZE];

    printf("Enter the maximum number of nodes: ");
    scanf("%d", &data[0]);
    printf("Enter the data for each node:\n");
    for (int i = 0; i < data[0]; i++) {
        scanf("%s", &data[i + 1]);
    }

    head = createNode(data);

    printf("Original List: ");
    displayList(head);

    printf("\nSearch for 'apple': %d\n", searchList(head, "apple"));
    printf("Search for 'banana': %d\n", searchList(head, "banana"));
    printf("Search for 'cherry': %d\n", searchList(head, "cherry"));
    printf("Search for 'date': %d\n", searchList(head, "date"));
    printf("Search for 'elderberry': %d\n", searchList(head, "elderberry"));

    return 0;
}