//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

struct Password {
    char site[20];
    char username[20];
    char password[PASSWORD_LENGTH];
};

int main() {
    FILE *file;
    char filename[50] = "passwords.txt";
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;
    char site[20];
    char username[20];
    char password[PASSWORD_LENGTH];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %s\n", passwords[num_passwords].site, passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    fclose(file);

    while (1) {
        printf("\n\nPassword Manager\n");
        printf("1. Add new password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter site name: ");
                scanf("%s", site);
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                file = fopen(filename, "a");
                if (file == NULL) {
                    printf("Error: File not found.\n");
                    exit(1);
                }

                fprintf(file, "%s %s %s\n", site, username, password);
                fclose(file);

                printf("\nPassword added successfully.\n");
                break;

            case '2':
                printf("\n\nPasswords:\n");

                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error: File not found.\n");
                    exit(1);
                }

                while (fscanf(file, "%s %s %s\n", passwords[num_passwords].site, passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
                    printf("%s %s %s\n", passwords[num_passwords].site, passwords[num_passwords].username, "**********");
                    num_passwords++;
                }

                fclose(file);
                break;

            case '3':
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}