//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

void print_menu() {
    printf("1. Add Password\n2. Delete Password\n3. List Passwords\n4. Exit\n");
}

int main() {
    Password* passwords = NULL;
    int num_passwords = 0;
    int menu_choice;

    passwords = malloc(num_passwords * sizeof(Password));
    if (passwords == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (1) {
        print_menu();
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                if (num_passwords == MAX_PASSWORD_LENGTH) {
                    printf("No more passwords can be added\n");
                    break;
                }

                printf("Enter username: ");
                fgets(passwords[num_passwords].username, MAX_PASSWORD_LENGTH, stdin);
                printf("Enter password: ");
                fgets(passwords[num_passwords].password, MAX_PASSWORD_LENGTH, stdin);

                num_passwords++;
                break;
            case 2:
                if (num_passwords == 0) {
                    printf("No passwords to delete\n");
                    break;
                }

                printf("Enter username: ");
                fgets(passwords[--num_passwords].username, MAX_PASSWORD_LENGTH, stdin);
                printf("Password deleted\n");
                break;
            case 3:
                printf("Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s %s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid menu choice\n");
        }
    }

    free(passwords);
    return 0;
}