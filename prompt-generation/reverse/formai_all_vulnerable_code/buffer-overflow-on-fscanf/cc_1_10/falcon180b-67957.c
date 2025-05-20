//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define PASSWORD_LENGTH 20

struct password {
    char name[50];
    char password[PASSWORD_LENGTH + 1];
};

void generate_password(char* password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i = 0;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    FILE* file;
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char filename[50];
    char password[PASSWORD_LENGTH + 1];
    int choice;

    printf("Welcome to the Password Manager!\n");

    do {
        printf("\n");
        printf("1. Create a new password\n");
        printf("2. Save passwords to file\n");
        printf("3. Load passwords from file\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name for the new password: ");
            scanf("%s", passwords[num_passwords].name);
            generate_password(passwords[num_passwords].password);
            num_passwords++;
            break;

        case 2:
            printf("Enter the filename to save the passwords to: ");
            scanf("%s", filename);

            file = fopen(filename, "w");

            if (file == NULL) {
                printf("Error: Could not open file.\n");
            } else {
                for (int i = 0; i < num_passwords; i++) {
                    fprintf(file, "%s %s\n", passwords[i].name, passwords[i].password);
                }

                fclose(file);
                printf("Passwords saved to file.\n");
            }

            break;

        case 3:
            printf("Enter the filename to load the passwords from: ");
            scanf("%s", filename);

            file = fopen(filename, "r");

            if (file == NULL) {
                printf("Error: Could not open file.\n");
            } else {
                while (fscanf(file, "%s %s", passwords[num_passwords].name, passwords[num_passwords].password)!= EOF) {
                    num_passwords++;
                }

                fclose(file);
                printf("%d passwords loaded from file.\n", num_passwords);
            }

            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}