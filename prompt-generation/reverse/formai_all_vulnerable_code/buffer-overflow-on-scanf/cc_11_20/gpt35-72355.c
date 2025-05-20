//FormAI DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {  // Defining the structure of the node of the linked list
    char email[50];
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    int choice;
    char email[50];

    while(1) {
        printf("\n-----Mailing List Manager-----\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. View mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Adding email to the mailing list
                printf("Enter email: ");
                scanf("%s", email);
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                strcpy(new_node->email, email);
                new_node->next = head;
                head = new_node;
                printf("Email added to mailing list!\n");
                break;

            case 2: // Removing email from the mailing list
                if(head == NULL) {
                    printf("Mailing list is empty!\n");
                    break;
                }
                printf("Enter email to be removed: ");
                scanf("%s", email);
                if(strcmp(head->email, email) == 0) { // Checking if email to be removed is the first node
                    head = head->next;
                    printf("Email removed from mailing list!\n");
                    break;
                }
                struct Node* prev = head;
                struct Node* cur = head->next;
                while(cur != NULL && strcmp(cur->email, email) != 0) { // Finding the node to be removed
                    prev = cur;
                    cur = cur->next;
                }
                if(cur == NULL) {
                    printf("Email not found in mailing list!\n");
                    break;
                }
                prev->next = cur->next;
                printf("Email removed from mailing list!\n");
                break;

            case 3: // Viewing the mailing list
                if(head == NULL) {
                    printf("Mailing list is empty!\n");
                    break;
                }
                printf("---Mailing List---\n");
                struct Node* ptr = head;
                while(ptr != NULL) {
                    printf("%s\n", ptr->email);
                    ptr = ptr->next;
                }
                break;

            case 4: // Exiting the program
                printf("Program exiting...");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}