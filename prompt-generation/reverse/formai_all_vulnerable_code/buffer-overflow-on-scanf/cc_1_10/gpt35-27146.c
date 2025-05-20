//FormAI DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of passwords
#define MAX_PASSWORDS 100

// Define password structure
typedef struct {
    char service[50];
    char username[50];
    char password[50];
} Password;

// Define password database
Password password_db[MAX_PASSWORDS];

// Define function prototypes
void add_password();
void view_passwords();
void search_passwords();

// Define main function
int main() {
    int choice;

    printf("Welcome to Password Manager\n");

    // Loop until user chooses to exit
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Passwords\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password();
                break;

            case 2:
                view_passwords();
                break;

            case 3:
                search_passwords();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to add password
void add_password() {
    static int num_passwords = 0;

    // Check if maximum number of passwords has been reached
    if(num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached. Cannot add more.\n");
        return;
    }

    printf("\nEnter the service name: ");
    scanf("%s", password_db[num_passwords].service);

    printf("Enter the username: ");
    scanf("%s", password_db[num_passwords].username);

    printf("Enter the password: ");
    scanf("%s", password_db[num_passwords].password);

    printf("Password added successfully\n");

    num_passwords++;
}

// Function to view passwords
void view_passwords() {
    // Check if there are any passwords
    if(password_db[0].service[0] == '\0') {
        printf("There are no passwords in the database.\n");
        return;
    }

    printf("\nList of Passwords:\n");
    printf("Sr. No.\tService Name\tUsername\tPassword\n");

    for(int i = 0; i < MAX_PASSWORDS; i++) {
        if(password_db[i].service[0] == '\0') break;

        printf("%d\t%s\t%s\t%s\n", i + 1, password_db[i].service, password_db[i].username, password_db[i].password);
    }
}

// Function to search passwords
void search_passwords() {
    char service[50];

    printf("\nEnter the service name: ");
    scanf("%s", service);

    for(int i = 0; i < MAX_PASSWORDS; i++) {
        if(password_db[i].service[0] == '\0') break;

        if(strcmp(password_db[i].service, service) == 0) {
            printf("\nService Name: %s\n", password_db[i].service);
            printf("Username: %s\n", password_db[i].username);
            printf("Password: %s\n", password_db[i].password);
            return;
        }
    }

    printf("No password found for the service.\n");
}