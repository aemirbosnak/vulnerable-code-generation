//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    FILE* passwords_file = fopen("passwords.txt", "r");
    if (passwords_file == NULL) {
        printf("Error: could not open passwords file.\n");
        return 1;
    }

    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (fscanf(passwords_file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
        if (num_passwords == MAX_PASSWORDS) {
            printf("Error: too many passwords in file.\n");
            fclose(passwords_file);
            return 1;
        }
    }

    fclose(passwords_file);

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password for %s:\n%s\n", username, passwords[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: could not find password for username.\n");
        return 1;
    }

    return 0;
}