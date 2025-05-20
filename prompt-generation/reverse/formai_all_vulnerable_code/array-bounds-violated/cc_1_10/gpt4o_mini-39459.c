//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// The Surreal Symphony of Strings
void transformIntoEldritchLife(char *input, char *output);
int isPalindrome(char *str);
void echoTheCosmicTales(char *str, char *result);

int main() {
    char input[MAX_LENGTH];
    char result[MAX_LENGTH];

    printf("Welcome to the Surreal Palindrome Checker!\n");
    printf("Speak your words into the void: ");
    fgets(input, sizeof(input), stdin);

    // Eliminate the tangible white space and newline
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // A transformation: the metamorphosis of the ordinary
    transformIntoEldritchLife(input, result);

    // Echo back the cosmic tales
    echoTheCosmicTales(result, input);

    return 0;
}

// Wormholes of transformation weave the mundane to the profound
void transformIntoEldritchLife(char *input, char *output) {
    // Pretend to change every letter into its counterpart in the universe
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[j++] = input[i] + 32; // Lowercase
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[j++] = input[i]; // Lowercase
        } else if (input[i] == ' ') {
            continue; // The space of consciousness
        } else {
            output[j++] = input[i]; // Non-alphabetic remains
        }
    }
    output[j] = '\0';
}

// The labyrinthine existence of palindrome checking
int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a mirror of truth
        }
        left++;
        right--;
    }
    return 1; // A true reflection of one's inner self
}

// The echo chamber of the cosmic tales
void echoTheCosmicTales(char *str, char *original) {
    printf("In spectral reverberation, the words commune:\n");
    if (isPalindrome(str)) {
        printf("The truth unveils: '%s' is a surreal palindrome!\n", original);
    } else {
        printf("Ah! The distortion of reality: '%s' is not a palindrome.\n", original);
    }
}

// Useless lines left behind, fragments of forgotten code:
// #define DIALOGUE "Life is but a dream"
// #include <time.h>