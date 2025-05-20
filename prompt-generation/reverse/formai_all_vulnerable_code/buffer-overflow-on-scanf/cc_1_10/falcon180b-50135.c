//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100
#define MAX_USERNAME_LEN 50

struct Password {
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
};

int main() {
    FILE *file;
    char filename[MAX_PASSWORD_LEN+1];
    int num_passwords = 0;
    struct Password passwords[MAX_PASSWORDS];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in passwords from file
    while (fscanf(file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
        if (num_passwords == MAX_PASSWORDS) {
            printf("Error: maximum number of passwords reached.\n");
            exit(1);
        }
    }

    // Close file
    fclose(file);

    // Prompt user for username
    printf("Enter username: ");
    scanf("%s", passwords[0].username);

    // Search for password
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return 0;
        }
    }

    // Password not found
    printf("Password not found.\n");
    return 0;
}