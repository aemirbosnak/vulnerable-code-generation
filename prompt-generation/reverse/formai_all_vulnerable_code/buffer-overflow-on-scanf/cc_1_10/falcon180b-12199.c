//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data;
    int count;
    struct Node *next;
};

struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *head, char data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp!= NULL) {
        if (temp->data == data) {
            temp->count++;
            return head;
        }
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node *searchNode(struct Node *head, char data) {
    struct Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%c -> %d\n", temp->data, temp->count);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;
    char str[MAX_SIZE];
    int i, n;

    printf("Enter a string: ");
    scanf("%s", str);
    n = strlen(str);

    for (i = 0; i < n; i++) {
        head = insertNode(head, str[i]);
    }

    printf("Linked list: ");
    printList(head);

    printf("\nEnter a character to search: ");
    scanf("%c", &str[0]);

    struct Node *result = searchNode(head, str[0]);

    if (result == NULL) {
        printf("Character not found\n");
    } else {
        printf("Character found with count %d\n", result->count);
    }

    return 0;
}