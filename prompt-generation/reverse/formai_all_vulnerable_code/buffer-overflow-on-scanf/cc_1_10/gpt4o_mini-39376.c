//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define DATABASE_FILE "users.db"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void save_to_file(User users[], int count) {
    FILE *file = fopen(DATABASE_FILE, "wb");
    if (file) {
        fwrite(users, sizeof(User), count, file);
        fclose(file);
    } else {
        perror("Error saving to file");
    }
}

void load_from_file(User users[], int *count) {
    FILE *file = fopen(DATABASE_FILE, "rb");
    if (file) {
        *count = fread(users, sizeof(User), MAX_USERS, file);
        fclose(file);
    } else {
        perror("Error loading from file");
    }
}

void add_user(User users[], int *count) {
    if (*count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    
    User new_user;
    new_user.id = *count + 1;

    printf("Enter name: ");
    scanf(" %[^\n]s", new_user.name);
    printf("Enter age: ");
    scanf("%d", &new_user.age);
    
    users[(*count)++] = new_user;
    save_to_file(users, *count);
    printf("User added successfully!\n");
}

void display_users(User users[], int count) {
    if (count == 0) {
        printf("No users to display.\n");
        return;
    }
    
    printf("User List:\n");
    printf("ID\tName\t\tAge\n");
    printf("------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\n", users[i].id, users[i].name, users[i].age);
    }
}

void search_user(User users[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", name);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(users[i].name, name) != NULL) {
            printf("Found User: ID: %d, Name: %s, Age: %d\n", users[i].id, users[i].name, users[i].age);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No user found with the name '%s'.\n", name);
    }
}

void delete_user(User users[], int *count) {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Invalid user ID.\n");
        return;
    }
    
    for (int i = id - 1; i < *count - 1; i++) {
        users[i] = users[i + 1];
    }
    
    (*count)--;
    save_to_file(users, *count);
    printf("User deleted successfully!\n");
}

int main() {
    User users[MAX_USERS];
    int user_count = 0;
    
    load_from_file(users, &user_count);
    
    int choice;
    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Search User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2:
                display_users(users, user_count);
                break;
            case 3:
                search_user(users, user_count);
                break;
            case 4:
                delete_user(users, &user_count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}