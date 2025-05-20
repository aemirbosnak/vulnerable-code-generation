//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Ahoy there, mateys! Prepare yerselves for a journey into the depths of the seven seas, where we'll forge a password as mighty as the kraken!

char *password_generator(int length) {

    // Prepare the deck, matey! We'll be usin' a trusty array to hold our booty.
    char *password = malloc(length + 1);

    // Now, let's cast the lines and set sail towards randomness!
    srand(time(NULL));

    // Weigh anchor and hoist the sails, matey! We're embarkin' on an adventure.
    for (int i = 0; i < length; i++) {
        // Roll the dice, matey! Choose a character from the vast ocean of possibilities.
        int char_index = rand() % 94;

        // Load yer cannons with characters, matey!
        switch (char_index) {
            case 0 ... 25:
                password[i] = 'a' + char_index;
                break;
            case 26 ... 51:
                password[i] = 'A' + (char_index - 26);
                break;
            case 52 ... 77:
                password[i] = '0' + (char_index - 52);
                break;
            case 78 ... 93:
                password[i] = '!' + (char_index - 78);
                break;
        }
    }

    // Cap'n, all hands on deck! Time to hoist the Jolly Roger!
    password[length] = '\0';

    // Return the hard-earned treasure, matey!
    return password;
}

int main() {

    // Avast there, matey! How long shall yer password be?
    int length;
    printf("Enter the length of yer password, matey: ");
    scanf("%d", &length);

    // Prepare to shiver yer timbers, matey! We're gonna generate a password that'll make Blackbeard green with envy.
    char *password = password_generator(length);

    // Raise yer tankards, mateys! We've got the password.
    printf("Avast there, matey! Yer password be: %s\n", password);

    // Free the memory, matey. We don't want any landlubbers plunderin' our treasure!
    free(password);

    // Weigh anchor and set sail towards new adventures, matey!
    return 0;
}