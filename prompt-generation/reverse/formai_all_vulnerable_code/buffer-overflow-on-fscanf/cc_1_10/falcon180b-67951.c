//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MIN_PASSWORD_LENGTH 8
#define MIN_PASSWORD_COMPLEXITY 3

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_changed;
} Password;

int main() {
    FILE *passwords_file;
    char filename[MAX_USERNAME_LENGTH + 7];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    srand(time(NULL));
    printf("Welcome to the Password Manager!\n\n");

    // Read in passwords file
    sprintf(filename, "passwords.txt");
    passwords_file = fopen(filename, "r");

    if (passwords_file == NULL) {
        printf("No passwords file found.\n");
        exit(1);
    }

    while (fscanf(passwords_file, "%s %s %ld\n", username, password, &passwords[num_passwords].last_changed) == 3) {
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            exit(1);
        }
        num_passwords++;
    }

    fclose(passwords_file);

    while (1) {
        printf("\nEnter username: ");
        fgets(username, MAX_USERNAME_LENGTH, stdin);
        username[strcspn(username, "\n")] = '\0';

        if (strlen(username) > MAX_USERNAME_LENGTH) {
            printf("Username too long.\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(username, passwords[i].username) == 0) {
                printf("\nEnter current password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0';

                if (strcmp(password, passwords[i].password) == 0) {
                    printf("\nPassword correct.\n");
                    found = 1;
                    break;
                } else {
                    printf("\nPassword incorrect.\n");
                }
            }
        }

        if (!found) {
            printf("\nUser not found.\n");
        }
    }

    return 0;
}