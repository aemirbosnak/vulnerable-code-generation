//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

int main() {
    char passwords[MAX_PASSWORDS][MAX_LENGTH];
    char masterPassword[MAX_LENGTH];
    int numPasswords = 0;

    srand(time(0)); // seed random number generator

    printf("Welcome to Password Manager!\n");
    printf("Enter your master password: ");
    fgets(masterPassword, sizeof(masterPassword), stdin);
    masterPassword[strcspn(masterPassword, "\n")] = 0; // remove newline character

    printf("What would you like to do?\n");
    printf("1. Add a new password\n");
    printf("2. Display all passwords\n");
    printf("3. Generate a random password\n");
    printf("4. Quit\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                if (numPasswords == MAX_PASSWORDS) {
                    printf("Error: password limit reached\n");
                } else {
                    printf("Enter a new password: ");
                    fgets(passwords[numPasswords++], MAX_LENGTH, stdin);
                    passwords[numPasswords-1][strcspn(passwords[numPasswords-1], "\n")] = 0;
                    printf("Password added!\n");
                }
                break;
            case 2:
                if (numPasswords == 0) {
                    printf("No passwords saved\n");
                } else {
                    for (int i = 0; i < numPasswords; i++) {
                        printf("%d. %s\n", i+1, passwords[i]);
                    }
                }
                break;
            case 3:
                printf("Enter the desired password length: ");
                int length;
                scanf("%d", &length);
                getchar(); // consume newline character

                char password[MAX_LENGTH];
                for (int i = 0; i < length; i++) {
                    password[i] = rand() % 94 + 33; // generate random printable ASCII character
                }
                password[length] = 0;
                printf("Your new password is: %s\n", password);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}