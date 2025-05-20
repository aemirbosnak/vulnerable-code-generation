//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: careful
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

void add_user();
void display_users();
void find_user();
void delete_user();
void edit_user();
void save_to_file();
void load_from_file();

int main() {
    int choice;
    load_from_file();

    while (1) {
        printf("\n--- User Database Management ---\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Find User\n");
        printf("4. Edit User\n");
        printf("5. Delete User\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                display_users();
                break;
            case 3:
                find_user();
                break;
            case 4:
                edit_user();
                break;
            case 5:
                delete_user();
                break;
            case 6:
                save_to_file();
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}

void add_user() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more users.\n");
        return;
    }

    User new_user;
    new_user.id = record_count + 1; // auto-increment id
    printf("Enter Name: ");
    getchar(); // to consume newline character
    fgets(new_user.name, NAME_LENGTH, stdin);
    new_user.name[strcspn(new_user.name, "\n")] = '\0'; // remove newline
    printf("Enter Email: ");
    fgets(new_user.email, EMAIL_LENGTH, stdin);
    new_user.email[strcspn(new_user.email, "\n")] = '\0'; // remove newline

    database[record_count++] = new_user;
    printf("User added successfully!\n");
}

void display_users() {
    if (record_count == 0) {
        printf("No users in the database.\n");
        return;
    }
    printf("\n--- User List ---\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

void find_user() {
    int id;
    printf("Enter User ID to find: ");
    scanf("%d", &id);

    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printf("User found! ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

void edit_user() {
    int id;
    printf("Enter User ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printf("Editing User ID: %d\n", database[i].id);
            printf("Enter new Name: ");
            getchar(); // to consume newline character
            fgets(database[i].name, NAME_LENGTH, stdin);
            database[i].name[strcspn(database[i].name, "\n")] = '\0'; // remove newline
            printf("Enter new Email: ");
            fgets(database[i].email, EMAIL_LENGTH, stdin);
            database[i].email[strcspn(database[i].email, "\n")] = '\0'; // remove newline
            printf("User updated successfully!\n");
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

void delete_user() {
    int id;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            for (int j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1]; // shift records left
            }
            record_count--;
            printf("User with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

void save_to_file() {
    FILE *file = fopen("users.dat", "wb");
    if (file == NULL) {
        printf("Error: Unable to save data to file.\n");
        return;
    }
    fwrite(database, sizeof(User), record_count, file);
    fclose(file);
    printf("Data saved to users.dat successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    record_count = fread(database, sizeof(User), MAX_RECORDS, file);
    fclose(file);
    printf("Data loaded from users.dat successfully!\n");
}