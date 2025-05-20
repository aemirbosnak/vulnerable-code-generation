//Gemma-7B DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {

    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    int n = 0;
    printf("Enter the number of queries: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int query = 0;
        printf("Enter the query: ");
        scanf("%d", &query);

        switch (query) {
            case 1:
                printf("The data at the beginning of the list is: %d\n", head->data);
                break;
            case 2:
                printf("The data at the end of the list is: %d\n", (head->next)->data);
                break;
            case 3:
                printf("The data at the middle of the list is: %d\n", (head->next->next)->data);
                break;
            default:
                printf("Invalid query\n");
                break;
        }
    }

    return 0;
}