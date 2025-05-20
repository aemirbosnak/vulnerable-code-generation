//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16
#define SALT_LENGTH 8

typedef struct {
    char password[PASSWORD_LENGTH + 1];
    char salt[SALT_LENGTH + 1];
} password_t;

void generate_password(password_t *password) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i, j;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password->password[i] = chars[rand() % strlen(chars)];
    }

    password->password[PASSWORD_LENGTH] = '\0';
}

void generate_salt(password_t *password) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i, j;

    for (i = 0; i < SALT_LENGTH; i++) {
        password->salt[i] = chars[rand() % strlen(chars)];
    }

    password->salt[SALT_LENGTH] = '\0';
}

int main() {
    FILE *passwords_file;
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;

    passwords_file = fopen("passwords.txt", "r");

    if (passwords_file == NULL) {
        fprintf(stderr, "Error: could not open passwords.txt\n");
        return 1;
    }

    while (fscanf(passwords_file, "%c", &choice)!= EOF) {
        switch (choice) {
            case 'a':
                generate_password(&passwords[num_passwords]);
                generate_salt(&passwords[num_passwords]);
                num_passwords++;
                break;
            case 'd':
                if (num_passwords > 0) {
                    num_passwords--;
                }
                break;
            case's':
                printf("Enter the name of the service:\n");
                scanf("%s", passwords[num_passwords - 1].salt);
                break;
            case 'p':
                printf("Enter the password for %s:\n", passwords[num_passwords - 1].salt);
                scanf("%s", passwords[num_passwords - 1].password);
                break;
            case 'q':
                fclose(passwords_file);
                return 0;
            default:
                fprintf(stderr, "Error: invalid choice\n");
        }
    }

    fclose(passwords_file);

    return 0;
}