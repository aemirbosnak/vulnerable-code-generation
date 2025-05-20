//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

int find_password(char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        int index = find_password(username);
        if (index!= -1) {
            printf("Enter password for %s: ", username);
            scanf("%s", password);

            if (strcmp(passwords[index].password, password) == 0) {
                printf("Login successful.\n");
            } else {
                printf("Incorrect password.\n");
            }
        } else {
            printf("User not found.\n");
            add_password(username, password);
        }
    }

    return 0;
}