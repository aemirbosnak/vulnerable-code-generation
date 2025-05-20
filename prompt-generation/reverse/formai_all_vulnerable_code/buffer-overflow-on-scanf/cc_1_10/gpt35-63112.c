//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20   // Maximum length of password 
#define MAX_USERNAME_LENGTH 20   // Maximum length of username 
#define MAX_ENTRIES 100          // Maximum number of password entries 

struct password_entry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct password_entry database[MAX_ENTRIES];
int num_entries = 0;

// Function to add a new password entry
void add_password() {
    if (num_entries == MAX_ENTRIES) {
        printf("Error: password database is full!\n");
        return;
    }
    struct password_entry e;
    printf("Enter username: ");
    fgets(e.username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter password: ");
    fgets(e.password, MAX_PASSWORD_LENGTH, stdin);
    database[num_entries++] = e;
    printf("Password added.\n");
}

// Function to display all password entries in the database
void display_passwords() {
    printf("Password database:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n", database[i].username, database[i].password);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add password\n");
        printf("2. Display passwords\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();   // discard newline character
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}