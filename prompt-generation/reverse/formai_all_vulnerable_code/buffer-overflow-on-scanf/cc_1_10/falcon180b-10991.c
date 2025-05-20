//Falcon-180B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Password Manager\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[num_passwords].username);
                    generate_password(passwords[num_passwords].password, MAX_PASSWORD_LENGTH);
                    num_passwords++;
                    printf("Password added.\n");
                }
                break;
            case 2:
                printf("Enter username to delete: ");
                scanf("%s", passwords[num_passwords - 1].username);
                printf("Password deleted.\n");
                num_passwords--;
                break;
            case 3:
                printf("\nPasswords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s: %s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}