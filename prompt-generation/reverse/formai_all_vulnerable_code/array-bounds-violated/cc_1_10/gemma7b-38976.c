//Gemma-7B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *pass;
    int used;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int i = 0;
    char input[255];

    // Create and initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].pass = NULL;
        passwords[i].used = 0;
    }

    // Get user input
    printf("Enter a password name: ");
    scanf("%s", passwords[i].name);

    // Get user password
    printf("Enter your password: ");
    scanf("%s", passwords[i].pass);

    // Mark password as used
    passwords[i].used = 1;

    // Repeat for remaining passwords
    for (i = 1; i < MAX_PASSWORDS; i++) {
        printf("Enter a password name: ");
        scanf("%s", passwords[i].name);

        // Get user password
        printf("Enter your password: ");
        scanf("%s", passwords[i].pass);

        // Mark password as used
        passwords[i].used = 1;
    }

    // Print passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name && passwords[i].pass) {
            printf("Name: %s, Password: %s, Used: %d\n", passwords[i].name, passwords[i].pass, passwords[i].used);
        }
    }

    return 0;
}