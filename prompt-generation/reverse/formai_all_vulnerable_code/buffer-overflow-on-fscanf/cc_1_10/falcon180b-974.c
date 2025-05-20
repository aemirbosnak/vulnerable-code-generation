//Falcon-180B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8
#define NUM_PASSWORDS 10

struct password {
    char name[20];
    char password[LENGTH + 1];
};

int main() {
    FILE *file;
    struct password passwords[NUM_PASSWORDS];
    int num_passwords = 0;

    // Open the password file
    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open password file.\n");
        return 1;
    }

    // Read in the passwords
    while (fscanf(file, "%s %s", passwords[num_passwords].name, passwords[num_passwords].password) == 2) {
        num_passwords++;
        if (num_passwords == NUM_PASSWORDS) {
            break;
        }
    }

    // Close the password file
    fclose(file);

    // Generate a new password
    char password[LENGTH + 1];
    int i;
    for (i = 0; i < LENGTH; i++) {
        password[i] = 'a' + rand() % 26;
    }
    password[LENGTH] = '\0';

    // Check if the new password is in the list
    int found = 0;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            printf("Error: password \"%s\" already exists.\n", password);
            return 1;
        }
    }

    // Add the new password to the list
    strcpy(passwords[num_passwords].name, "New Password");
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;

    // Open the password file for writing
    file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error: could not open password file.\n");
        return 1;
    }

    // Write out the passwords
    for (i = 0; i < num_passwords; i++) {
        fprintf(file, "%s %s\n", passwords[i].name, passwords[i].password);
    }

    // Close the password file
    fclose(file);

    // Print the new password
    printf("New password: %s\n", password);

    return 0;
}