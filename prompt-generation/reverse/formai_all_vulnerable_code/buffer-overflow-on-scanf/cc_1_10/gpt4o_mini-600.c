//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max Constants
#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Structure to hold User Data
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} User;

// Function Declarations
void add_user(User users[], int *user_count);
void display_users(const User users[], int user_count);
void search_user(const User users[], int user_count);
void delete_user(User users[], int *user_count);
void update_user(User users[], int user_count);
void save_data(const User users[], int user_count);
void load_data(User users[], int *user_count);

// Main Function
int main() {
    User users[MAX_RECORDS];
    int user_count = 0;
    int choice;

    load_data(users, &user_count); // Load existing user data if available

    do {
        printf("\n=== Simple User Database ===\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Search User\n");
        printf("4. Update User\n");
        printf("5. Delete User\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: add_user(users, &user_count); break;
            case 2: display_users(users, user_count); break;
            case 3: search_user(users, user_count); break;
            case 4: update_user(users, user_count); break;
            case 5: delete_user(users, &user_count); break;
            case 6: save_data(users, user_count); printf("Data saved. Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new user
void add_user(User users[], int *user_count) {
    if (*user_count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }
    
    User new_user;
    new_user.id = *user_count + 1; // Assign ID based on current count

    printf("Enter name: ");
    fgets(new_user.name, sizeof(new_user.name), stdin);
    new_user.name[strcspn(new_user.name, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(new_user.email, sizeof(new_user.email), stdin);
    new_user.email[strcspn(new_user.email, "\n")] = 0; // Remove newline

    users[*user_count] = new_user;
    (*user_count)++;
    printf("User added successfully!\n");
}

// Function to display all users
void display_users(const User users[], int user_count) {
    if (user_count == 0) {
        printf("No users found in the database.\n");
        return;
    }

    printf("\n=== User List ===\n");
    for (int i = 0; i < user_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

// Function to search for a user by name
void search_user(const User users[], int user_count) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcasecmp(users[i].name, search_name) == 0) {
            printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("User not found.\n");
    }
}

// Function to delete a user by ID
void delete_user(User users[], int *user_count) {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *user_count) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = id - 1; i < *user_count - 1; i++) {
        users[i] = users[i + 1]; // Shift left
    }
    (*user_count)--;
    printf("User deleted successfully!\n");
}

// Function to update user details
void update_user(User users[], int user_count) {
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    if (id < 1 || id > user_count) {
        printf("Invalid ID!\n");
        return;
    }

    User *user = &users[id - 1];

    printf("Updating user ID: %d\n", id);
    printf("Current name: %s\n", user->name);
    printf("Enter new name (or press Enter to keep it): ");
    char buffer[MAX_NAME_LENGTH];
    fgets(buffer, sizeof(buffer), stdin);
    
    if (strcmp(buffer, "\n") != 0) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(user->name, buffer);
    }

    printf("Current email: %s\n", user->email);
    printf("Enter new email (or press Enter to keep it): ");
    fgets(buffer, sizeof(buffer), stdin);
    
    if (strcmp(buffer, "\n") != 0) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        strcpy(user->email, buffer);
    }

    printf("User updated successfully!\n");
}

// Function to save data to a file
void save_data(const User users[], int user_count) {
    FILE *file = fopen("userdata.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%d,%s,%s\n", users[i].id, users[i].name, users[i].email);
    }
    fclose(file);
}

// Function to load data from a file
void load_data(User users[], int *user_count) {
    FILE *file = fopen("userdata.txt", "r");
    if (!file) return; // No data file exists, just return

    while (fscanf(file, "%d,%49[^,],%99[^\n]\n", &users[*user_count].id, users[*user_count].name, users[*user_count].email) == 3) {
        (*user_count)++;
    }
    fclose(file);
}