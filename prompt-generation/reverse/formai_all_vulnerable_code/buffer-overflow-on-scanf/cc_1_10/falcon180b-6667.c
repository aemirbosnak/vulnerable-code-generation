//Falcon-180B DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 3
#define CORRECT_PASS "12345"

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int tries = 0;
    char pass[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the password with random characters
    for (int i = 0; i < 5; i++) {
        pass[i] = rand_num(48, 57) + rand_num(65, 90);
    }

    // Print the password
    printf("Password: %s\n", pass);

    // Start the game loop
    while (1) {
        // Get the user's guess
        char input[10];
        printf("Enter your guess: ");
        scanf("%s", input);

        // Convert the input to uppercase
        for (int i = 0; i < 5; i++) {
            input[i] = toupper(input[i]);
        }

        // Check if the guess is correct
        if (strcmp(input, pass) == 0) {
            printf("Congratulations! You guessed the password in %d tries.\n", tries + 1);
            break;
        } else if (++tries >= MAX_TRIES) {
            printf("Sorry, you ran out of tries. The correct password was %s.\n", CORRECT_PASS);
            break;
        } else {
            printf("Incorrect guess. Try again.\n");
        }
    }

    return 0;
}