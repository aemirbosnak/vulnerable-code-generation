//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50

struct password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *passwords_file;
    char filename[50] = "passwords.txt";
    char input_buffer[100];
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    // Open the passwords file
    passwords_file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (passwords_file == NULL) {
        printf("Error: could not open passwords file.\n");
        return 1;
    }

    // Read the passwords from the file
    while (fscanf(passwords_file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    // Close the passwords file
    fclose(passwords_file);

    // Prompt the user for a username
    printf("Enter your username: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove the newline character from the input

    // Search for the user's password in the passwords file
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, input_buffer) == 0) {
            // Password found
            printf("Your password is: %s\n", passwords[i].password);
            return 0;
        }
    }

    // Password not found
    printf("Error: username not found.\n");
    return 1;
}