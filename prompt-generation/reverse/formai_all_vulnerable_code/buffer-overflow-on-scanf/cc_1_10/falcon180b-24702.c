//Falcon-180B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_updated;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}|:<>?-=[];',./";
    int i = 0;
    while (i < MAX_PASSWORD_LENGTH) {
        password[i] = chars[rand() % strlen(chars)];
        i++;
    }
    password[i] = '\0';
}

void save_password(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].password, password);
            passwords[i].last_updated = time(NULL);
            return;
        }
    }
    if (num_passwords < MAX_PASSWORDS) {
        strcpy(passwords[num_passwords].username, username);
        strcpy(passwords[num_passwords].password, password);
        passwords[num_passwords].last_updated = time(NULL);
        num_passwords++;
    }
}

int main() {
    srand(time(NULL));

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    if (num_passwords == 0) {
        generate_password(password);
        save_password(username, password);
        printf("Your initial password is: %s\n", password);
    } else {
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                printf("Your password is: %s\n", passwords[i].password);
                return 0;
            }
        }
        printf("Invalid username.\n");
        return 1;
    }

    return 0;
}