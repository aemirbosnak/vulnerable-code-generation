//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Linked List!\n");

    // Define the structure for the Linked List node
    struct Node {
        int data;
        struct Node* next;
    } *head, *tail;

    int choice = 1;
    int val;

    while (choice) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a node\n");
        printf("2. Delete a node\n");
        printf("3. Print the list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            {
                printf("Enter the value to be added: ");
                scanf("%d", &val);
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = val;
                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = newNode;
                }
                printf("Node has been added to the end!\n");
                break;
            }

            case 2:
            {
                if (head == NULL) {
                    printf("Linked List is empty!\n");
                }
                else {
                    int pos = 0;
                    printf("Enter the position of the node to be deleted: ");
                    scanf("%d", &pos);
                    struct Node* current = head;

                    // If position is at the first node, delete the head
                    if (pos == 1) {
                        head = head->next;
                    }
                    else {
                        for (int i = 1; i < pos - 1; ++i) {
                            current = current->next;
                        }
                        struct Node* temp = current->next;
                        current->next = temp->next;
                        free(temp);
                    }
                    printf("Node has been deleted!\n");
                }
                break;
            }

            case 3:
            {
                if (head == NULL) {
                    printf("Linked List is empty!\n");
                }
                else {
                    struct Node* current = head;
                    printf("Linked List:\n");
                    while (current != NULL) {
                        printf("%d ", current->data);
                        current = current->next;
                    }
                    printf("\n");
                }
                break;
            }
          
            case 4:
            {
                printf("Thank you for using the C Linked List!\n");
                exit(0); // Exit the program with status of 0
            }
          
            default:
            {
                printf("Invalid choice, please try again!\n");
                break;
            }
        }
    }

    return 0; // Exit the program with status of 0
}