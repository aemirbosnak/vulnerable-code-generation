//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *file;
    int num_passwords = 0;
    struct Password passwords[MAX_PASSWORDS];

    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: Passwords file not found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", passwords[num_passwords].name, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    fclose(file);

    int choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
        printf("4. Save passwords\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", passwords[num_passwords].name);
            printf("Enter password: ");
            scanf("%s", passwords[num_passwords].password);
            num_passwords++;
            break;
        case 2:
            printf("Enter name of password to delete: ");
            scanf("%s", passwords[num_passwords - 1].name);
            num_passwords--;
            break;
        case 3:
            printf("Enter name of password to search: ");
            scanf("%s", passwords[num_passwords - 1].name);
            printf("Password: %s\n", passwords[num_passwords - 1].password);
            break;
        case 4:
            file = fopen("passwords.txt", "w");
            if (file == NULL) {
                printf("Error: Could not save passwords.\n");
            } else {
                for (int i = 0; i < num_passwords; i++) {
                    fprintf(file, "%s %s\n", passwords[i].name, passwords[i].password);
                }
                fclose(file);
                printf("Passwords saved successfully.\n");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}