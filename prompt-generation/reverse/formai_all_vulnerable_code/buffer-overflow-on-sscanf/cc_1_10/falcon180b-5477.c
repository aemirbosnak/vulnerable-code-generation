//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *file;
    char filename[MAX_PASSWORD_LENGTH];
    char choice;
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Welcome to the Happy Password Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new password\n");
        printf("2. Save passwords to file\n");
        printf("3. Load passwords from file\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the password: ");
                scanf(" %s", passwords[num_passwords].name);
                printf("Enter the password: ");
                scanf(" %s", passwords[num_passwords].password);
                num_passwords++;
                break;
            case '2':
                printf("Enter the filename to save passwords to: ");
                scanf(" %s", filename);
                file = fopen(filename, "w");
                if (file == NULL) {
                    printf("Error: could not open file.\n");
                } else {
                    for (int i = 0; i < num_passwords; i++) {
                        fprintf(file, "%s:%s\n", passwords[i].name, passwords[i].password);
                    }
                    fclose(file);
                    printf("Passwords saved to file.\n");
                }
                break;
            case '3':
                printf("Enter the filename to load passwords from: ");
                scanf(" %s", filename);
                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error: could not open file.\n");
                } else {
                    while (fgets(filename, MAX_PASSWORD_LENGTH, file)!= NULL) {
                        sscanf(filename, "%s:%s", passwords[num_passwords].name, passwords[num_passwords].password);
                        num_passwords++;
                    }
                    fclose(file);
                    printf("Passwords loaded from file.\n");
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}