//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct to hold password data
typedef struct {
    char username[30];
    char password[30];
} passwords;

// function to display menu options
void displayOptions() {
    printf("\n*************** PASSWORD MANAGER ******************\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Generate new password\n");
    printf("4. Exit\n");
    printf("***************************************************\n");
}

// function to add password
void addPassword(passwords *passwordArr, int *passwordCount) {
    printf("Enter username: ");
    scanf("%s", passwordArr[*passwordCount].username);
    printf("Enter password: ");
    scanf("%s", passwordArr[*passwordCount].password);
    printf("\nPassword added successfully!\n");
    *passwordCount += 1;
}

// function to view passwords
void viewPasswords(passwords passwordArr[], int passwordCount) {
    if (passwordCount == 0) {
        printf("No passwords found!\n");
        return;
    }

    printf("\nUsername\tPassword\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("%s\t\t%s\n", passwordArr[i].username, passwordArr[i].password);
    }
    printf("\n");
}

// function to generate password
void generatePassword() {
    srand(time(NULL)); // seed for random number generator

    int length;
    printf("Enter length of password (between 8 and 16): ");
    scanf("%d", &length);

    if (length < 8 || length > 16) {
        printf("Invalid length entered!\n");
        return;
    }

    printf("Your new password is: ");
    for (int i = 0; i < length; i++) {
        int randomChar = rand() % 94 + 33; // ASCII characters from 33 to 126
        printf("%c", (char) randomChar);
    }
    printf("\n");
}

int main() {
    passwords passwordArr[100]; // array of password data
    int passwordCount = 0; // count of passwords in array

    int option = 0;
    while (option != 4) {
        displayOptions();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addPassword(passwordArr, &passwordCount);
                break;
            case 2:
                viewPasswords(passwordArr, passwordCount);
                break;
            case 3:
                generatePassword();
                break;
            case 4:
                printf("Thank you for using the password manager!\n");
                break;
            default:
                printf("Invalid option entered, try again!\n");
                break;
        }
    }

    return 0;
}