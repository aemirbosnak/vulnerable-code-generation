//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In a parallel universe, where shadows dance and echoes whisper, lies a realm of encrypted secrets, guarded by the enigmatic "Cipher Keeper."

// The Cipher Keeper, a master of linguistic labyrinths, conjures an array of 10 enigmatic passphrases, each an intricate tapestry of characters.

char *passphrases[] = {
    "Riddles shroud, shadows entwine, secrets whisper in the ethereal abyss.",
    "Beneath the veil of twilight's embrace, forgotten knowledge stirs in slumbering places.",
    "Amidst the dance of stars, a constellation of secrets emerges, guiding the lost through uncharted realms.",
    "Whispers echo through the hallowed halls, ancient wisdom whispered by voices long gone.",
    "In the depths of forgotten lore, a tapestry of cryptic symbols conceals the path to enlightenment.",
    "Like fragile threads, memories weave a tapestry of whispered secrets, echoing through the corridors of time.",
    "Within the twilight's embrace, dreams take flight, revealing secrets hidden in the ethereal expanse.",
    "Beneath the ripple of reality's surface, where ethereal whispers whisper, enigmatic truths await discovery.",
    "In the realm of forgotten dreams, the echoes of ancient voices guide those seeking knowledge.",
    "As shadows dance and whispers intertwine, the whispers of secrets whisper in the ethereal abyss."
};

// The seeker, an intrepid soul yearning for knowledge, must embark on a quest through this linguistic labyrinth, deciphering each passphrase to unlock the secrets it holds.

int main() {
    int choice;
    char input[100];

    while (1) {
        printf("In the realm of shadows and whispers, welcome, seeker.\n");
        printf("Before you embark on your quest, choose a passphrase to decipher: (enter a number between 1 and 10)\n");

        for (int i = 0; i < 10; i++) {
            printf("%d. %s\n", i + 1, passphrases[i]);
        }

        scanf("%d", &choice);

        if (choice < 1 || choice > 10) {
            printf("Invalid choice. Please choose a number between 1 and 10.\n");
        } else {
            printf("You have chosen: %s\n", passphrases[choice - 1]);
            printf("Decipher the passphrase to unlock the secret: ");
            scanf(" %[^\n]", input);

            // The seeker's response, a key forged in the crucible of their intellect, must match the correct decryption to unveil the hidden secret.

            if (strcmp(input, "secrets") == 0) {
                printf("Congratulations, seeker! You have unlocked the secret: Knowledge is the key that unlocks the gates of enlightenment.\n");
            } else {
                printf("Your response does not match the key. The secret remains hidden for now.\n");
            }
        }

        printf("\nWould you like to continue your quest? (y/n)\n");
        scanf(" %c", &input);

        if (input[0] == 'n') {
            printf("Until next time, seeker. May the whispers guide you on your path.\n");
            break;
        }
    }

    return 0;
}