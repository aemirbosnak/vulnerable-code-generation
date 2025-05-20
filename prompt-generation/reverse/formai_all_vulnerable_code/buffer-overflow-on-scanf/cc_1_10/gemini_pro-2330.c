//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of the input string
#define MAX_LEN 100

// A sentinel to mark the program's end
#define SENTINEL ""

// A rhythmic function to check if a string is a palindrome
bool is_palindrome(char *str) {
    int len = strlen(str);

    // A lyrical loop, traversing the string's mirrored halves
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    // A resounding affirmation of palindromic purity
    return true;
}

// Begin the program's harmonious execution
int main() {
    char input[MAX_LEN];

    // A graceful invitation to enter a word or phrase
    printf("Enter a word or phrase to test for palindromicity: ");
    scanf("%s", input);

    // Loop until the sentinel is encountered, marking the conclusion of our linguistic expedition
    while (strcmp(input, SENTINEL) != 0) {
        // The verdict, a resonant echo of the string's palindromic nature
        if (is_palindrome(input)) {
            printf("%s is a palindrome.\n", input);
        } else {
            printf("%s is not a palindrome.\n", input);
        }

        // A pause for reflection, awaiting the next linguistic challenge
        printf("\nEnter another word or phrase (or \"%s\" to exit): ", SENTINEL);
        scanf("%s", input);
    }

    // A graceful farewell, bidding adieu to the world of linguistic exploration
    printf("Thank you for playing the Palindrome Checker! Farewell.\n");

    return 0;
}