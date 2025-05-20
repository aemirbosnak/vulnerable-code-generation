//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct knight {
    char name[30];
    char password[MAX_PASSWORD_LENGTH + 1];
};

void create_knight(struct knight *knight, char *name, char *password) {
    strcpy(knight->name, name);
    strcpy(knight->password, password);
}

int authenticate_knight(struct knight knights[MAX_USERS], char *name, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            if (strcmp(knights[i].password, password) == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    struct knight knights[MAX_USERS];

    if (argc != 3) {
        printf("Usage: %s <name> <password>\n", argv[0]);
        return 1;
    }

    create_knight(&knights[0], argv[1], argv[2]);

    printf("Welcome, noble %s!\n", knights[0].name);

    int authentication_status;
    while (1) {
        printf("Please enter your name to authenticate: ");
        char name[MAX_PASSWORD_LENGTH + 1];
        scanf("%s", name);

        printf("Please enter your password: ");
        char password[MAX_PASSWORD_LENGTH + 1];
        scanf("%s", password);

        authentication_status = authenticate_knight(knights, name, password);

        if (authentication_status != -1) {
            printf("Authentication successful!\n");
            break;
        } else {
            printf("Authentication failed.\n");
        }
    }

    return 0;
}