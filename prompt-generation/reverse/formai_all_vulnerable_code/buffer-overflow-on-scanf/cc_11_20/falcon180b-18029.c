//Falcon-180B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    while(1) {
        printf("Enter the service name: ");
        scanf("%s", passwords[num_passwords].service);

        printf("Enter the username: ");
        scanf("%s", passwords[num_passwords].username);

        printf("Enter the password: ");
        scanf("%s", passwords[num_passwords].password);

        num_passwords++;

        if(num_passwords >= MAX_PASSWORDS) {
            break;
        }
    }

    int choice;
    do {
        printf("\n\nPassword Manager\n");
        printf("1. Add a new password\n");
        printf("2. View passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the service name: ");
                scanf("%s", passwords[num_passwords].service);

                printf("Enter the username: ");
                scanf("%s", passwords[num_passwords].username);

                printf("Enter the password: ");
                scanf("%s", passwords[num_passwords].password);

                num_passwords++;

                if(num_passwords >= MAX_PASSWORDS) {
                    printf("Error: Password list is full\n");
                }

                break;

            case 2:
                printf("\n\nPasswords:\n");
                for(int i = 0; i < num_passwords; i++) {
                    printf("%s %s %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                }

                break;

            case 3:
                printf("Enter the service name to delete: ");
                scanf("%s", passwords[num_passwords-1].service);

                for(int i = 0; i < num_passwords-1; i++) {
                    if(strcmp(passwords[i].service, passwords[num_passwords-1].service) == 0) {
                        memcpy(&passwords[i], &passwords[num_passwords-1], sizeof(struct password));
                    }
                }

                num_passwords--;

                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice!= 4);

    return 0;
}