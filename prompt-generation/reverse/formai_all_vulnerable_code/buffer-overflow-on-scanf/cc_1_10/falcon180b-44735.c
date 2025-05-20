//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int is_valid;
} Password;

void generate_password(char *password) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    const int chars_len = strlen(chars);
    int i = 0;
    while (i < MAX_PASSWORD_LENGTH) {
        int rand_index = rand() % chars_len;
        password[i] = chars[rand_index];
        i++;
    }
    password[i] = '\0';
}

int main() {
    Password *passwords = malloc(sizeof(Password) * MAX_PASSWORDS);
    int num_passwords = 0;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    srand(time(NULL));

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        generate_password(password);

        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                strcpy(passwords[i].password, password);
                printf("Password updated for %s.\n", username);
                break;
            }
        }

        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached. Please delete one to add a new one.\n");
        } else {
            strcpy(passwords[num_passwords].username, username);
            strcpy(passwords[num_passwords].password, password);
            num_passwords++;
            printf("Password added for %s.\n", username);
        }
    }

    return 0;
}