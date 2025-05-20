//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
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
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, char data[], int size) {
    struct Node* newNode = createNode(data, size);
    struct Node* temp = head;
    if (head == NULL || strcmp(head->data, data) > 0) {
        newNode->next = head;
        head = newNode;
    } else {
        while (temp!= NULL && strcmp(temp->data, data) < 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(struct Node* head, char data[]) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    char data[MAX_SIZE];
    int choice, size;

    do {
        printf("\n1. Insert\n2. Search\n3. Print\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%s", data);
                printf("Enter size: ");
                scanf("%d", &size);
                head = insertNode(head, data, size);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%s", data);
                if (search(head, data)) {
                    printf("Data found\n");
                } else {
                    printf("Data not found\n");
                }
                break;
            case 3:
                printf("List: ");
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}