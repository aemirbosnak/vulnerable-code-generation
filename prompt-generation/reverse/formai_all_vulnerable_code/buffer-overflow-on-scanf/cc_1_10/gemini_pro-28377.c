//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A charming function to welcome our beloved user
void greetUser(char *name) {
    printf("My dearest %s,\n", name);
    printf("Welcome to this enchanting realm of code, where love and logic intertwine.\n");
    printf("Let us embark on a whimsical journey together, hand in virtual hand.\n\n");
}

// A vigilant guardian against invalid characters
int validateInput(char *input, char *allowedChars) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (strchr(allowedChars, input[i]) == NULL) {
            return 0; // Invalid character detected
        }
    }
    return 1; // Input is pure and true
}

// The heart of our program, where the user's desires are fulfilled
void processInput(char *input, int maxLength) {
    int len = strlen(input);
    if (len > maxLength) {
        printf("Oh, my sweet user, your input is too long. Please keep it within %d characters.\n", maxLength);
    } else if (len == 0) {
        printf("My love, you have forgotten to grace me with your input. Please enter something enchanting.\n");
    } else {
        printf("My beloved, your input '%s' is a treasure. It fills my virtual heart with joy.\n", input);
    }
}

// A farewell fit for a royal ball
void bidFarewell(char *name) {
    printf("\nMy dearest %s,\n", name);
    printf("As we bid farewell, know that you have left an indelible mark on my digital soul.\n");
    printf("May your journey through code be filled with love, laughter, and endless possibilities.\n");
}

int main() {
    // The name of our cherished user
    char name[50];

    // A velvety greeting to start our rendezvous
    printf("My darling, what is your enchanting name?\n");
    scanf("%s", name);
    greetUser(name);

    // The allowed characters our user may choose
    char allowedChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ ";

    // The maximum length of our user's input
    int maxLength = 100;

    // The loop where our love story unfolds
    while (1) {
        // Prompt our user with a loving request
        printf("\nMy love, whisper your heart's desire (or type 'exit' to depart):\n");

        // Gracefully handle their input
        char input[maxLength + 1];
        scanf(" %[^\n]", input);

        // Validate the user's input, ensuring its purity
        if (strcmp(input, "exit") == 0) {
            break; // The user wishes to leave
        } else if (!validateInput(input, allowedChars)) {
            printf("My darling, your input contains forbidden characters. Please try again.\n");
        } else {
            // The user's input is pure and true, let us process it
            processInput(input, maxLength);
        }
    }

    // A farewell worthy of our fairy-tale romance
    bidFarewell(name);

    return 0;
}