//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USER_LENGTH 20

typedef struct {
    char username[MAX_USER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int main() {
    FILE *file;
    char filename[MAX_USER_LENGTH];
    int num_passwords = 0;
    int i, j;
    password_t passwords[MAX_PASSWORDS];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in passwords from file
    while (fscanf(file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password) == 2) {
        num_passwords++;
        if (num_passwords == MAX_PASSWORDS) {
            printf("Error: too many passwords.\n");
            exit(1);
        }
    }

    // Close file
    fclose(file);

    // Get username from user
    printf("Enter username: ");
    scanf("%s", passwords[0].username);

    // Search for password in list
    for (i = 0; i < num_passwords; i++) {
        if (!strcmp(passwords[i].username, passwords[0].username)) {
            printf("Password: %s\n", passwords[i].password);
            exit(0);
        }
    }

    // Password not found
    printf("Error: password not found.\n");
    exit(1);
}