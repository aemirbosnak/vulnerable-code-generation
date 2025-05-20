//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t timestamp;
} Password;

int num_passwords = 0;
Password passwords[MAX_PASSWORDS];

void add_password(char* username, char* password) {
    num_passwords++;
    strcpy(passwords[num_passwords-1].username, username);
    strcpy(passwords[num_passwords-1].password, password);
    passwords[num_passwords-1].timestamp = time(NULL);
}

int login(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\nTimestamp: %s\n", passwords[i].username, passwords[i].password, ctime(&passwords[i].timestamp));
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the Cyberpunk Password Manager!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    add_password(username, password);
    printf("Password added successfully!\n");

    print_passwords();

    return 0;
}