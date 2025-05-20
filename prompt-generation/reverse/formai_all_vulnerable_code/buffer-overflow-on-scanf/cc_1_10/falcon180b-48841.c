//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    struct node* next;
};

void createLinkedList(struct node** head, char* str) {
    int i = 0;
    struct node* newNode = NULL;
    struct node* temp = NULL;

    *head = NULL;

    while (str[i]!= '\0') {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory error\n");
            exit(0);
        }

        strncpy(newNode->data, &str[i], MAX_SIZE);
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        }
        else {
            temp = *head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        i++;
    }
}

void searchLinkedList(struct node* head, char* str) {
    struct node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found\n");
}

int main() {
    char str[MAX_SIZE];
    struct node* head = NULL;

    printf("Enter a string: ");
    scanf("%s", str);

    createLinkedList(&head, str);

    printf("Enter a string to search: ");
    scanf("%s", str);

    searchLinkedList(head, str);

    return 0;
}