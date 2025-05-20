//Falcon-180B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char input[MAX_PASSWORD_LENGTH];
    FILE *file;

    // Open file for reading
    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read passwords from file
    while (fscanf(file, "%s %s %s", passwords[num_passwords].website, passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    fclose(file);

    // Prompt user for website to search for
    printf("Enter website to search for: ");
    scanf("%s", input);

    // Convert input to uppercase for case-insensitive comparison
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Search for password in array
    int index = -1;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, input) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Password not found.\n");
    } else {
        // Display password
        printf("Website: %s\n", passwords[index].website);
        printf("Username: %s\n", passwords[index].username);
        printf("Password: %s\n", passwords[index].password);
    }

    return 0;
}