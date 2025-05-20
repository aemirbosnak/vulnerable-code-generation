//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char *password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("No passwords found.\n");
        return 1;
    }

    while (fscanf(file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password) == 2) {
        num_passwords++;

        if (num_passwords == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }
    }

    fclose(file);

    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    int found = 0;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }

    return 0;
}