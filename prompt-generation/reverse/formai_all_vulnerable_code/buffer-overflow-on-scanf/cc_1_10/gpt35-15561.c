//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passwords {
    char* password;
    struct Passwords* next;
};

void addPassword(struct Passwords** head_ref, char* password) {
    struct Passwords* new_node = (struct Passwords*)malloc(sizeof(struct Passwords));
    new_node->password = password;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void displayPasswords(struct Passwords* node) {
    if(node == NULL) {
        printf("No passwords in database.\n");
        return;
    }
    printf("Passwords:\n");
    while(node != NULL) {
        printf("%s\n", node->password);
        node = node->next;
    }
}

void deletePassword(struct Passwords** head_ref, char* password) {
    struct Passwords* temp = *head_ref, *prev;
    if(temp != NULL && strcmp(temp->password, password) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && strcmp(temp->password, password) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Password not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void clearPasswords(struct Passwords** head_ref) {
    struct Passwords* current = *head_ref;
    struct Passwords* next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

void menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Clear All Passwords\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    char password[50];
    struct Passwords* head = NULL;
    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter password: ");
                scanf("%s", password);
                addPassword(&head, password);
                printf("Password added successfully.\n");
                break;
            case 2:
                displayPasswords(head);
                break;
            case 3:
                printf("\nEnter password to delete: ");
                scanf("%s", password);
                deletePassword(&head, password);
                break;
            case 4:
                clearPasswords(&head);
                printf("All passwords cleared from database.\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 0);
    return 0;
}