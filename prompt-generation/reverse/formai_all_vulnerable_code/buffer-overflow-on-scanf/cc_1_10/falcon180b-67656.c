//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char data[MAX_SIZE];
    int size;
    struct Node* next;
};

struct Node* createNode(char data[], int size) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

struct Node* addNode(struct Node* head, char data[], int size) {
    struct Node* newNode = createNode(data, size);
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int search(struct Node* head, char data[], int size) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (strstr(temp->data, data)!= NULL) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    char data[MAX_SIZE];
    int size;

    printf("Enter data to be searched: ");
    scanf("%s", data);

    printf("Enter the size of data: ");
    scanf("%d", &size);

    head = addNode(head, data, size);

    int result = search(head, data, size);

    if (result == 1) {
        printf("Data found in the list\n");
    } else {
        printf("Data not found in the list\n");
    }

    return 0;
}