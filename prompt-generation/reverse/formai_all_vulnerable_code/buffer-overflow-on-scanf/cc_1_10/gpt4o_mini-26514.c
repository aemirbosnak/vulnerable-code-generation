//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 256
#define USERNAME_LENGTH 256

typedef struct Node {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    struct Node* next;
} Node;

Node* head = NULL;

void add_entry();
void view_entries();
void delete_entry();
void free_memory();
void menu();

int main() {
    int choice;
    
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the integer input

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    free_memory();
    return 0;
}

void menu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    printf("Enter username: ");
    fgets(new_node->username, USERNAME_LENGTH, stdin);
    new_node->username[strcspn(new_node->username, "\n")] = 0; // Remove newline character

    printf("Enter password: ");
    fgets(new_node->password, PASSWORD_LENGTH, stdin);
    new_node->password[strcspn(new_node->password, "\n")] = 0; // Remove newline character

    new_node->next = head;
    head = new_node;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (head == NULL) {
        printf("No entries found.\n");
        return;
    }

    Node* current = head;
    printf("\n--- Entries ---\n");
    while (current != NULL) {
        printf("Username: %s, Password: %s\n", current->username, current->password);
        current = current->next;
    }
}

void delete_entry() {
    char username[USERNAME_LENGTH];
    printf("Enter username to delete: ");
    fgets(username, USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->username, username) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
        return;
    }

    if (previous == NULL) { // Deleting the head
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Entry deleted successfully!\n");
}

void free_memory() {
    Node* current = head;
    Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}