//Falcon-180B DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int is_valid;
} Password;

int main() {
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter a password: ");
        scanf("%s", passwords[num_passwords].password);

        int length = strlen(passwords[num_passwords].password);
        if (length < 8) {
            printf("Password must be at least 8 characters.\n");
            passwords[num_passwords].is_valid = 0;
        } else {
            passwords[num_passwords].is_valid = 1;
        }

        num_passwords++;
    }

    int choice;
    do {
        printf("1. View passwords\n");
        printf("2. Delete a password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_passwords; i++) {
                if (passwords[i].is_valid) {
                    printf("%d. %s\n", i+1, passwords[i].password);
                }
            }
            break;
        case 2:
            printf("Enter the password number to delete: ");
            scanf("%d", &choice);
            if (choice >= 1 && choice <= num_passwords) {
                memset(passwords[choice-1].password, 0, MAX_PASSWORD_LENGTH);
                passwords[choice-1].is_valid = 0;
            } else {
                printf("Invalid password number.\n");
            }
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}