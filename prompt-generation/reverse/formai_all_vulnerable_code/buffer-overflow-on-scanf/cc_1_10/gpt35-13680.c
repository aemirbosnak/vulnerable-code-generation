//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    printf("Welcome to Memory Management Program!\n\n");
    Node* head = NULL;
    Node* current = NULL;
    Node* temp = NULL;
    int num_nodes = 0;
    int option;
    int memory = 0;

    while(1) {
        printf("Select an option:\n1. Create a new node\n2. Delete a node\n3. View current memory\n4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter data for new node: ");
                int data;
                scanf("%d", &data);
                
                temp = (Node*)malloc(sizeof(Node));
                if(temp == NULL) {
                    printf("Memory Allocation Error!\nExiting Program...");
                    exit(1);
                }
                temp->data = data;
                temp->next = NULL;

                if(head == NULL) {
                    head = temp;
                    current = temp;
                }
                else {
                    current->next = temp;
                    current = temp;
                }

                num_nodes++;
                memory += sizeof(Node);
                break;

            case 2:
                if(head == NULL) {
                    printf("There are no nodes to delete.\n");
                    break;
                }
                else {
                    temp = head;
                    head = head->next;
                    free(temp);
                    num_nodes--;
                    memory -= sizeof(Node);
                }
                break;

            case 3:
                printf("Current Memory: %d bytes\n", memory);
                break;

            case 4:
                printf("Exiting Program...\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}