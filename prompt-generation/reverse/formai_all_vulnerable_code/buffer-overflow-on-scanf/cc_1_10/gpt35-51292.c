//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 //Maximum number of stored passwords
#define MAX_ATTEMPTS 3 //Maximum number of password attempts

//Structure to store each password entry
typedef struct PasswordEntry {
    char website[50];
    char username[50];
    char password[50];
} PasswordEntry;

int main() {
    PasswordEntry passwords[MAX_PASSWORDS]; //Array of PasswordEntry structures to store passwords
    int passwordCount = 0; //Count of current number of stored passwords

    //Welcome message
    printf("Welcome to Password Management System!\n\n");

    //Main menu
    while (1) {
        printf("Enter a number to select an option:\n");
        printf("1. Add new password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: { //Add new password
                //Get details of new password from user
                PasswordEntry newPassword;
                printf("Enter website name: ");
                scanf("%s", newPassword.website);
                printf("Enter username/email: ");
                scanf("%s", newPassword.username);
                printf("Enter password: ");
                scanf("%s", newPassword.password);

                //Add new password to array
                passwords[passwordCount] = newPassword;
                passwordCount++;

                printf("Password added successfully!\n\n");
                break;
            }
            case 2: { //View saved passwords
                printf("Enter your Master password: ");
                char masterPassword[50];
                scanf("%s", masterPassword);

                if (strcmp(masterPassword, "12345") != 0) { //Incorrect master password
                    printf("Wrong password! Try again.\n");
                    break;
                }

                printf("Here are your saved passwords:\n\n");
                for (int i = 0; i < passwordCount; i++) {
                    printf("Website: %s\n", passwords[i].website);
                    printf("Username: %s\n", passwords[i].username);
                    printf("Password: %s\n\n", passwords[i].password);
                }
                break;
            }
            case 3: //Exit program
                printf("Goodbye!\n");
                exit(0);
            default: //Invalid input
                printf("Invalid input! Try again.\n");
        }
    }

    return 0;
}