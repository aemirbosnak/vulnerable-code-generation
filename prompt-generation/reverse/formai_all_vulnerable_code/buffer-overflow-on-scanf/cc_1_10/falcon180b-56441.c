//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>

// function to display menu
void displayMenu() {
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
}

// function to validate username and password
int validateLogin(char *username, char *password) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// function to register a new user
void registerUser(char *username, char *password) {
    printf("User registered successfully!\n");
}

// main function
int main() {
    char choice;
    char username[50];
    char password[50];

    do {
        displayMenu();
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                if (validateLogin(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed.\n");
                }

                break;

            case '2':
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                registerUser(username, password);

                break;

            case '3':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '3');

    return 0;
}