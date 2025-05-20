//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct {
    char username[50];
    char password[50];
} Password;

void generatePassword(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    FILE *file = fopen("passwords.txt", "r");
    if (file!= NULL) {
        while (fscanf(file, "%s %s\n", passwords[numPasswords].username, passwords[numPasswords].password) == 2) {
            numPasswords++;
        }
        fclose(file);
    }

    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Generate password\n");
        printf("3. Save passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                generatePassword(passwords[numPasswords].password, 12);
                numPasswords++;
                printf("Password added successfully.\n");
            }
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", passwords[numPasswords-1].username);
            generatePassword(passwords[numPasswords-1].password, 12);
            printf("Password generated successfully.\n");
            break;

        case 3:
            file = fopen("passwords.txt", "w");
            if (file!= NULL) {
                for (int i = 0; i < numPasswords; i++) {
                    fprintf(file, "%s %s\n", passwords[i].username, passwords[i].password);
                }
                fclose(file);
                printf("Passwords saved successfully.\n");
            } else {
                printf("Error saving passwords.\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}