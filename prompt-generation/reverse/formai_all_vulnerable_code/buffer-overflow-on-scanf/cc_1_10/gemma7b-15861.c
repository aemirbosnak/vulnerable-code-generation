//Gemma-7B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];

    // Create a bunch of terrible passwords
    passwords[0].name = "Mr. Fluff";
    passwords[0].password = "FluffMcFluff";

    passwords[1].name = "Ms. Grudge";
    passwords[1].password = "AngryCat";

    passwords[2].name = "Mr. Squiggly";
    passwords[2].password = "PurpleRainbows";

    // Attempt to crack each password
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        char *guess = "";
        int attempts = 0;

        printf("%s, prepare for a brain-bending adventure!\n", passwords[i].name);

        // Loop until the password is cracked or the user gives up
        while (!strcmp(guess, passwords[i].password) && attempts < 10) {
            printf("Enter your guess: ");
            scanf("%s", guess);

            attempts++;

            // Check if the guess is correct
            if (strcmp(guess, passwords[i].password) == 0) {
                printf("Congratulations, you have cracked the password!\n");
            } else {
                printf("Incorrect guess. Try again.\n");
            }
        }

        // If the user ran out of attempts, let them know
        if (attempts == 10) {
            printf("Sorry, but you have exhausted all your attempts. You will never crack this password.\n");
        }
    }

    return 0;
}