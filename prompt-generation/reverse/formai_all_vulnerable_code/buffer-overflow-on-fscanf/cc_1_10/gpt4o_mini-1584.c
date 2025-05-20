//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

User database[MAX_RECORDS];
int record_count = 0;

void addUser() {
    if (record_count >= MAX_RECORDS) {
        printf("Database full! Cannot add more users.\n");
        return;
    }

    printf("Enter name: ");
    fgets(database[record_count].name, NAME_LENGTH, stdin);
    database[record_count].name[strcspn(database[record_count].name, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(database[record_count].email, EMAIL_LENGTH, stdin);
    database[record_count].email[strcspn(database[record_count].email, "\n")] = 0; // Remove newline

    database[record_count].id = record_count + 1; // Generate ID based on record count
    record_count++;
    printf("User added successfully!\n");
}

void deleteUser() {
    int id;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character left by scanf

    if (id < 1 || id > record_count) {
        printf("Invalid ID!\n");
        return;
    }

    // Shift records to fill the gap
    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;
    printf("User deleted successfully!\n");
}

void displayUsers() {
    if (record_count == 0) {
        printf("No users in the database.\n");
        return;
    }

    printf("\nList of Users:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

void saveDatabase() {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%d,%s,%s\n", database[i].id, database[i].name, database[i].email);
    }
    fclose(file);
    printf("Database saved to file successfully!\n");
}

void loadDatabase() {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("No existing database found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%99[^\n]\n", &database[record_count].id, database[record_count].name, database[record_count].email) == 3) {
        record_count++;
        if (record_count >= MAX_RECORDS) {
            printf("Database reached max capacity while loading!\n");
            break;
        }
    }
    fclose(file);
    printf("Database loaded successfully!\n");
}

int main() {
    int choice;

    loadDatabase();

    do {
        printf("\n--- User Database Management ---\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Display Users\n");
        printf("4. Save Database\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character left in the buffer
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                saveDatabase();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}