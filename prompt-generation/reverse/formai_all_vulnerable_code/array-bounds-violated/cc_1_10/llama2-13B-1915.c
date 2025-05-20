//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 50

struct password {
    char *name;
    char *password;
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i;

    // Initialize passwords array
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
    }

    // Ask user for password and store it in the array
    while (1) {
        printf("Enter password: ");
        scanf("%49s", passwords[i].password);
        passwords[i].name = malloc(strlen(passwords[i].password) + 1);
        strcpy(passwords[i].name, "Password ");
        strcat(passwords[i].name, passwords[i].password);
        i++;
        if (i >= MAX_PASSWORDS) {
            break;
        }
    }

    // Print all stored passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("%d: %s\n", i, passwords[i].name);
    }

    // Ask user to select a password to print
    int selection;
    printf("Select a password to print (1-%d): ", MAX_PASSWORDS);
    scanf("%d", &selection);

    // Print selected password
    if (selection > 0 && selection <= MAX_PASSWORDS) {
        printf("%d: %s\n", selection - 1, passwords[selection - 1].password);
    }

    // Free memory
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].name);
    }

    return 0;
}