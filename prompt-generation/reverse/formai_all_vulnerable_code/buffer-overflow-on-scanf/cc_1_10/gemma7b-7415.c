//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    int i, data, choice;

    printf("Welcome to the Crazy Database!\n");
    printf("------------------------\n");

    // Inserting data into the linked list
    printf("Enter 1 to insert data: ");
    scanf("%d", &choice);

    while (choice == 1) {
        printf("Enter data: ");
        scanf("%d", &data);

        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Data inserted successfully!\n");

        printf("Enter 1 to insert more data or any other number to exit: ");
        scanf("%d", &choice);
    }

    // Printing the linked list
    printf("Your data: ");
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nThank you for using the Crazy Database!\n");

    return 0;
}