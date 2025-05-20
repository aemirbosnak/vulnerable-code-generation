//Falcon-180B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_updated;
} Password;

int main() {
    FILE *passwords_file = fopen("passwords.txt", "r");
    if (passwords_file == NULL) {
        printf("No passwords file found. Creating a new one.\n");
        passwords_file = fopen("passwords.txt", "w");
        if (passwords_file == NULL) {
            printf("Failed to create passwords file.\n");
            return 1;
        }
    }

    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (fscanf(passwords_file, "%s %s %ld\n", passwords[num_passwords].username, passwords[num_passwords].password, &passwords[num_passwords].last_updated)!= EOF) {
        num_passwords++;
    }

    fclose(passwords_file);

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username:\n");
    scanf("%s", username);

    bool found_password = false;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password for %s:\n", username);
            printf("%s\n", passwords[i].password);
            found_password = true;
            break;
        }
    }

    if (!found_password) {
        printf("Password not found.\n");
    }

    return 0;
}