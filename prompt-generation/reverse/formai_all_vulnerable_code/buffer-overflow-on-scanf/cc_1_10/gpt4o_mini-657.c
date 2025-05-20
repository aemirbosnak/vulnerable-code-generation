//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50
#define ERROR_MESSAGE_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    int age;
} User;

typedef struct {
    User users[MAX_USERS];
    int count;
} UserDatabase;

typedef enum {
    SUCCESS,
    DATABASE_FULL,
    INVALID_AGE,
    USER_NOT_FOUND,
    DATABASE_EMPTY,
    UNKNOWN_ERROR
} ErrorCode;

void log_error(const char* message) {
    FILE *log_file = fopen("error_log.txt", "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
}

void print_error(ErrorCode code) {
    switch (code) {
        case DATABASE_FULL:
            printf("Error: The user database is full.\n");
            break;
        case INVALID_AGE:
            printf("Error: User age must be greater than 0.\n");
            break;
        case USER_NOT_FOUND:
            printf("Error: User not found in the database.\n");
            break;
        case DATABASE_EMPTY:
            printf("Error: The user database is empty.\n");
            break;
        case UNKNOWN_ERROR:
            printf("Error: An unknown error occurred.\n");
            break;
        case SUCCESS:
        default:
            break;
    }
}

ErrorCode add_user(UserDatabase* db, const char* name, int age) {
    if (db->count >= MAX_USERS) {
        log_error("Failed to add user. Database is full.");
        return DATABASE_FULL;
    }
    if (age <= 0) {
        log_error("Failed to add user. Invalid age.");
        return INVALID_AGE;
    }
    strcpy(db->users[db->count].name, name);
    db->users[db->count].age = age;
    db->count++;
    return SUCCESS;
}

ErrorCode remove_user(UserDatabase* db, const char* name) {
    if (db->count == 0) {
        log_error("Failed to remove user. Database is empty.");
        return DATABASE_EMPTY;
    }
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->users[i].name, name) == 0) {
            for (int j = i; j < db->count - 1; j++) {
                db->users[j] = db->users[j + 1];
            }
            db->count--;
            return SUCCESS;
        }
    }
    log_error("Failed to remove user. User not found.");
    return USER_NOT_FOUND;
}

void list_users(const UserDatabase* db) {
    if (db->count == 0) {
        print_error(DATABASE_EMPTY);
        return;
    }
    printf("Users in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Name: %s, Age: %d\n", db->users[i].name, db->users[i].age);
    }
}

void free_database(UserDatabase* db) {
    db->count = 0; // Reset database count
}

void interactive_menu() {
    UserDatabase db = { .count = 0 };
    int choice;
    char name[NAME_LENGTH];
    int age;

    while (1) {
        printf("\nUser Database Menu:\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                if (add_user(&db, name, age) != SUCCESS) {
                    print_error(add_user(&db, name, age));
                }
                break;
            case 2:
                printf("Enter name of user to remove: ");
                scanf("%s", name);
                if (remove_user(&db, name) != SUCCESS) {
                    print_error(remove_user(&db, name));
                }
                break;
            case 3:
                list_users(&db);
                break;
            case 4:
                free_database(&db);
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    interactive_menu();
    return 0;
}