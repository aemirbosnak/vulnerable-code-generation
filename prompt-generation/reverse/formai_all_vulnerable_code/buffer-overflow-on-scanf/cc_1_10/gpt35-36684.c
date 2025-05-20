//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 50

typedef struct password {
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void printWelcomeMessage()
{
    printf("Welcome to Password Manager!\n");
    printf("==============================\n\n");
}

void printMenu()
{
    printf("1. Add a password\n");
    printf("2. Edit a password\n");
    printf("3. Delete a password\n");
    printf("4. View all passwords\n");
    printf("5. Exit\n");
}

void addPassword()
{
    Password newPassword;

    printf("Enter name of website or application: ");
    fgets(newPassword.name, MAX_LENGTH, stdin);

    printf("Enter password: ");
    fgets(newPassword.value, MAX_LENGTH, stdin);

    passwords[numPasswords++] = newPassword;

    printf("Password added successfully!\n\n");
}

void editPassword()
{
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];

    printf("Enter name of website or application to edit: ");
    fgets(name, MAX_LENGTH, stdin);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Enter new password: ");
            fgets(value, MAX_LENGTH, stdin);

            strcpy(passwords[i].value, value);

            printf("Password updated successfully!\n\n");
            return;
        }
    }

    printf("Password not found!\n\n");
}

void deletePassword()
{
    char name[MAX_LENGTH];

    printf("Enter name of website or application to delete: ");
    fgets(name, MAX_LENGTH, stdin);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            for (int j = i+1; j < numPasswords; j++) {
                passwords[j-1] = passwords[j];
            }
            numPasswords--;

            printf("Password deleted successfully!\n\n");
            return;
        }
    }

    printf("Password not found!\n\n");
}

void viewPasswords()
{
    printf("%-50s %s\n", "Website/Application", "Password");
    printf("===============================================================\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%-50s %s\n", passwords[i].name, passwords[i].value);
    }

    printf("\n");
}

void displayCurrentTime()
{
    time_t currentTime;
    time(&currentTime);
    printf("Current Time: %s\n", ctime(&currentTime));
}

int main(int argc, char **argv) {
    printWelcomeMessage();
    while (1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                editPassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                viewPasswords();
                break;
            case 5:
                printf("Thank you for using Password Manager!\n");
                displayCurrentTime();
                return 0;
            default:
                printf("Please enter a valid choice!\n\n");
        }
    }
}