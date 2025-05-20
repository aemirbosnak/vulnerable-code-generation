//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} User;

User database[MAX_RECORDS];
int current_index = 0;

void add_user() {
    if (current_index >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    User new_user;
    new_user.id = current_index + 1; // Simple ID generation
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter email: ");
    scanf("%s", new_user.email);
    database[current_index] = new_user;
    current_index++;
    printf("User added successfully! ID: %d\n", new_user.id);
}

void display_users() {
    if (current_index == 0) {
        printf("No users found in the database.\n");
        return;
    }
    
    printf("\n--- User List ---\n");
    for (int i = 0; i < current_index; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

void search_user() {
    int id;
    printf("Enter User ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < current_index; i++) {
        if (database[i].id == id) {
            printf("User found: ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

void update_user() {
    int id;
    printf("Enter User ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < current_index; i++) {
        if (database[i].id == id) {
            printf("Updating User: ID: %d, Current Name: %s, Current Email: %s\n", 
                    database[i].id, database[i].name, database[i].email);
            printf("Enter new name: ");
            scanf("%s", database[i].name);
            printf("Enter new email: ");
            scanf("%s", database[i].email);
            printf("User updated successfully!\n");
            return;
        }
    }
    printf("User with ID %d not found for update.\n", id);
}

void delete_user() {
    int id;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < current_index; i++) {
        if (database[i].id == id) {
            for (int j = i; j < current_index - 1; j++) {
                database[j] = database[j + 1]; // Shift records left
            }
            current_index--;
            printf("User with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("User with ID %d not found for deletion.\n", id);
}

void display_menu() {
    printf("\n--- Database Management System ---\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Search User\n");
    printf("4. Update User\n");
    printf("5. Delete User\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                display_users();
                break;
            case 3:
                search_user();
                break;
            case 4:
                update_user();
                break;
            case 5:
                delete_user();
                break;
            case 6:
                printf("Exiting the program. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}