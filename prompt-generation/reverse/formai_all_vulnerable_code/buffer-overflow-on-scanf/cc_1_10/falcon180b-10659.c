//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Welcome to the Medieval Password Manager!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords >= MAX_PASSWORDS) {
                printf("You have reached the maximum number of passwords.\n");
            } else {
                printf("Enter the name of the password: ");
                scanf("%s", passwords[num_passwords].name);

                printf("Enter the password: ");
                scanf("%s", passwords[num_passwords].password);

                num_passwords++;
            }
            break;

        case 2:
            if (num_passwords == 0) {
                printf("You have no passwords.\n");
            } else {
                printf("\nPasswords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s: %s\n", passwords[i].name, passwords[i].password);
                }
            }
            break;

        case 3:
            printf("Thank thee for using the Medieval Password Manager.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}