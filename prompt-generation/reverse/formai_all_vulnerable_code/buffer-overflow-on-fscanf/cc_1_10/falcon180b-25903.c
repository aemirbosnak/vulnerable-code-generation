//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

struct password_entry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *file;
    int num_passwords = 0;
    struct password_entry passwords[MAX_PASSWORDS];

    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open passwords file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", passwords[num_passwords].username, passwords[num_passwords].password) == 2) {
        num_passwords++;
        if (num_passwords == MAX_PASSWORDS) {
            printf("Error: maximum number of passwords reached.\n");
            break;
        }
    }

    fclose(file);

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        fgets(username, MAX_USERNAME_LENGTH, stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Enter password: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Login successful.\n");
        } else {
            printf("Login failed.\n");
        }
    }

    return 0;
}