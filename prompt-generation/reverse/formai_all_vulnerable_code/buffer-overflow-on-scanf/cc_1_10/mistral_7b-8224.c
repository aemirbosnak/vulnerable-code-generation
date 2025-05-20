//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 100
#define PASSWORD_LENGTH 50
#define SALT_LENGTH 10

typedef struct user {
    char name[20];
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
} User;

void generate_salt(User *user) {
    int i;
    for (i = 0; i < SALT_LENGTH; i++) {
        user->salt[i] = rand() % 26 + 'a';
    }
    user->salt[SALT_LENGTH] = '\0';
}

int check_password(User *user, char *attempt) {
    char hash[PASSWORD_LENGTH];
    int i;

    strcpy(hash, user->password);
    for (i = 0; i < strlen(user->salt); i++) {
        hash[strlen(user->password) + i] = hash[i] ^ user->salt[i];
    }

    return strcmp(hash, attempt) == 0;
}

int main() {
    srand(time(NULL));
    User users[MAX_USERS];
    int i, choice;
    char name[20], password[PASSWORD_LENGTH], attempt[PASSWORD_LENGTH];

    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] != '\0') continue;

        printf("Enter name for user %d: ", i + 1);
        scanf("%s", name);

        if (strlen(name) > 19) {
            printf("Name too long.\n");
            continue;
        }

        strcpy(users[i].name, name);
        generate_salt(&users[i]);

        printf("Enter password for %s: ", name);
        scanf("%s", password);

        strcpy(users[i].password, password);

        printf("Password saved for %s.\n", name);
    }

    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] == '\0') break;

        printf("User %s:\n", users[i].name);
        printf("Enter password to check: ");
        scanf("%s", attempt);

        if (check_password(&users[i], attempt)) {
            printf("Correct password.\n");
        } else {
            printf("Incorrect password.\n");
        }
    }

    return 0;
}