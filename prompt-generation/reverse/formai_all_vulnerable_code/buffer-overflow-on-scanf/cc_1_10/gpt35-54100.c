//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 50
#define MAX_FRIENDS 50

#define DB_FILE "users.db"

// Struct to represent a user
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    char friends[MAX_FRIENDS][MAX_NAME_LEN];
    int num_friends;
} User;

// Function to print a user's information
void print_user(User *user) {
    printf("Name: %s\n", user->name);
    printf("Phone: %s\n", user->phone);
    printf("Email: %s\n", user->email);
    printf("Friends: ");
    for (int i = 0; i < user->num_friends; i++) {
        printf("%s ", user->friends[i]);
    }
    printf("\n");
}

// Function to add a new user to the database
void add_user() {
    User user;
    printf("Name: ");
    scanf("%s", user.name);
    printf("Phone: ");
    scanf("%s", user.phone);
    printf("Email: ");
    scanf("%s", user.email);
    user.num_friends = 0;

    // Open database file in append mode
    FILE *fp = fopen(DB_FILE, "ab");
    if (fp == NULL) {
        printf("Error: could not open database file.\n");
        return;
    }

    // Write user data to file
    fwrite(&user, sizeof(User), 1, fp);

    // Close database file
    fclose(fp);

    printf("User added!\n");
}

// Function to search for a user by name
void search_user() {
    char name[MAX_NAME_LEN];
    printf("Name: ");
    scanf("%s", name);

    // Open database file in read mode
    FILE *fp = fopen(DB_FILE, "rb");
    if (fp == NULL) {
        printf("Error: could not open database file.\n");
        return;
    }

    bool found_user = false;
    User user;
    while (fread(&user, sizeof(User), 1, fp) == 1) {
        if (strcmp(user.name, name) == 0) {
            found_user = true;
            print_user(&user);
        }
    }

    if (!found_user) {
        printf("User not found.\n");
    }

    // Close database file
    fclose(fp);
}

// Function to print all the users in the database
void print_all_users() {
    // Open database file in read mode
    FILE *fp = fopen(DB_FILE, "rb");
    if (fp == NULL) {
        printf("Error: could not open database file.\n");
        return;
    }

    User user;
    while (fread(&user, sizeof(User), 1, fp) == 1) {
        print_user(&user);
    }

    // Close database file
    fclose(fp);
}

// Main function
int main() {
    int choice;
    do {
        printf("1. Add user\n");
        printf("2. Search user\n");
        printf("3. Print all users\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                search_user();
                break;
            case 3:
                print_all_users();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}