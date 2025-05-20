//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// structure to hold password information
typedef struct {
    char username[32];
    char password[64];
} password_t;

int main() {
    int num_passwords = 0;
    password_t passwords[MAX_PASSWORDS];

    // read in passwords from a file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open passwords.txt\n");
        return 1;
    }

    while (num_passwords < MAX_PASSWORDS && fscanf(fp, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password) == 2) {
        num_passwords++;
    }

    fclose(fp);

    // prompt user for username and password
    char username[32];
    printf("Enter your username: ");
    scanf("%s", username);

    char password[64];
    printf("Enter your password: ");
    scanf("%s", password);

    // check if username and password match any stored passwords
    int found_password = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
            found_password = 1;
            break;
        }
    }

    if (found_password) {
        printf("Password accepted\n");
    } else {
        printf("Password not found\n");
    }

    return 0;
}