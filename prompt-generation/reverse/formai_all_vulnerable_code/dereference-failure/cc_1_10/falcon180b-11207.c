//Falcon-180B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_t;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    FILE* file = fopen("passwords.txt", "r");
    if (file!= NULL) {
        while (fscanf(file, "%s\n", passwords[num_passwords].password) == 1 && num_passwords < MAX_PASSWORDS) {
            passwords[num_passwords++].length = strlen(passwords[num_passwords - 1].password);
        }
        fclose(file);
    }

    char choice;
    do {
        printf("Password Management System\n");
        printf("1. Generate new password\n");
        printf("2. Save current password\n");
        printf("3. View saved passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the desired password length: ");
                int length;
                scanf("%d", &length);
                generate_password(passwords[num_passwords].password, length);
                passwords[num_passwords].length = length;
                num_passwords++;
                break;
            case '2':
                printf("Enter the password to save: ");
                scanf("%s", passwords[num_passwords].password);
                passwords[num_passwords].length = strlen(passwords[num_passwords].password);
                num_passwords++;
                break;
            case '3':
                printf("Saved Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%d. %s (%d characters)\n", i + 1, passwords[i].password, passwords[i].length);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    file = fopen("passwords.txt", "w");
    if (file!= NULL) {
        for (int i = 0; i < num_passwords; i++) {
            fprintf(file, "%s\n", passwords[i].password);
        }
        fclose(file);
    }

    return 0;
}