//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node* head) {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory error\n");
            exit(0);
        }
        printf("Enter element %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(i == 0) {
            head = newNode;
        }
        else {
            struct Node* temp = head;
            while(temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* searchList(struct Node* head, int key) {
    struct Node* temp = head;
    while(temp!= NULL) {
        if(temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;
    createList(head);
    displayList(head);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    struct Node* result = searchList(head, key);

    if(result == NULL) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at position %d\n", result->data);
    }

    return 0;
}