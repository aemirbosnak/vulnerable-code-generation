//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached!\n");
        return;
    }
    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: password is too long!\n");
        return;
    }
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].length = length;
    num_passwords++;
}

void print_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t", passwords[i].username);
        for (int j = 0; j < passwords[i].length; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void delete_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            num_passwords--;
            break;
        }
    }
}

int main() {
    add_password("user1", "password1");
    add_password("user2", "password2");
    print_passwords();
    delete_password("user2");
    print_passwords();
    return 0;
}