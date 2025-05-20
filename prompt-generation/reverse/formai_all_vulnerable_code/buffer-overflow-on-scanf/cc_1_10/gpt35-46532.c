//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring structures
struct Node {
    char website[50];
    char username[50];
    char password[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char website[], char username[], char password[]) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->website, website);
    strcpy(new_node->username, username);
    strcpy(new_node->password, password);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node to the linked list
void insertNode(struct Node** head, char website[], char username[], char password[]) {
    struct Node* new_node = createNode(website, username, password);
    new_node->next = *head;
    *head = new_node;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("Website: %s\n", temp->website);
        printf("Username: %s\n", temp->username);
        printf("Password: %s\n", temp->password);
        printf("\n");
        temp = temp->next;
    }
}

// Function to search for a website and return its password
char* getPassword(struct Node* head, char website[]) {
    struct Node* temp = head;
    while(temp != NULL) {
        if(strcmp(temp->website, website) == 0) {
            return temp->password;
        }
        temp = temp->next;
    }
    return "Website not found";
}

int main() {
    struct Node* head = NULL;
    int choice;
    char website[50], username[50], password[50], search_website[50];

    do {
        printf("1. Add new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter website name: ");
                scanf("%s", website);
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                insertNode(&head, website, username, password);
                printf("Password added successfully!\n\n");
                break;
            case 2:
                printf("\nList of all passwords:\n");
                display(head);
                break;
            case 3:
                printf("\nEnter website name to search password: ");
                scanf("%s", search_website);
                printf("Password: %s\n\n", getPassword(head, search_website));
                break;
            case 4:
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while(choice != 4);

    return 0;
}