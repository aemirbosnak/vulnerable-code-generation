//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a node in mailing list
struct node {
    char name[20];
    char email[30];
    struct node* next;
};

// Function to create new node
struct node* create_node(char* name, char* email) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

// Function to print the entire mailing list
void print_list(struct node* head) {
    while(head != NULL) {
        printf("Name: %s\nEmail: %s\n", head->name, head->email);
        head = head->next;
    }
}

// Main function
int main() {
    int choice;
    char name[20], email[30];
    struct node* head = NULL, *temp = NULL;
    while(1) {
        printf("1. Add contact\n2. View contacts\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                if(head == NULL) {
                    head = create_node(name, email);
                    temp = head;
                }
                else {
                    temp->next = create_node(name, email);
                    temp = temp->next;
                }
                printf("Contact added successfully!\n");
                break;
            case 2:
                if(head == NULL) {
                    printf("Mailing list is empty!\n");
                    break;
                }
                printf("Mailing list:\n");
                print_list(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}