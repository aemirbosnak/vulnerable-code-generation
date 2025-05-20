//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open passwords file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s", passwords[numPasswords].name, passwords[numPasswords].password) == 2) {
        numPasswords++;
        if (numPasswords >= MAX_PASSWORDS) {
            printf("Error: too many passwords in file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Error: maximum number of passwords reached.\n");
            } else {
                printf("Enter name of password: ");
                scanf("%s", passwords[numPasswords].name);

                char *password = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
                printf("Enter password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);

                strcpy(passwords[numPasswords].password, password);
                numPasswords++;

                FILE *file = fopen("passwords.txt", "a");
                if (file == NULL) {
                    printf("Error: could not open passwords file.\n");
                    return 1;
                }

                fprintf(file, "%s %s\n", passwords[numPasswords - 1].name, passwords[numPasswords - 1].password);
                fclose(file);
            }
        } else if (choice == 2) {
            printf("Passwords:\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%s: %s\n", passwords[i].name, passwords[i].password);
            }
        } else if (choice == 3) {
            printf("Exiting program...\n");
            return 0;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}