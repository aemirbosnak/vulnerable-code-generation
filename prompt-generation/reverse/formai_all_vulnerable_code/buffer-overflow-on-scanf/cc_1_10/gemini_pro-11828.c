//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: random
// Palindrome Checker: A Poetic Exploration of Linguistic Symmetry

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An Array of Palindromic Delights
char *palindromes[] = {
    "A man, a plan, a canal, Panama!",
    "Racecar",
    "Step on no pets",
    "Was it a car or a cat I saw?",
    "A Toyota taco cat",
    "Sit on a potato pan, Otis",
    "Satan oscillate my metallic sonatas",
    "Palindrome",
    "ABBA",
    "Palindrome", // Yes, we repeated it for emphasis!
};

int palindrome(char *str) {
    int len = strlen(str);

    // If the string is empty or has only one character, it's a palindrome
    if (len < 1) return 1;

    // Check if the first and last characters match (recursive!)
    if (str[0] != str[len - 1]) return 0;

    // Recursively check the rest of the string
    return palindrome(str + 1) && palindrome(str + len - 2);
}

int main() {
    printf("Welcome to the Palindrome Emporium!\n");
    printf("Where words and phrases dance in perfect symmetry.\n\n");

    // A Canvas for Our Palindromic Explorations
    char input[100];

    // Prompt the user to offer their linguistic masterpiece
    printf("Enter a word or phrase for us to scrutinize:\n");
    scanf("%s", input);

    // The Moment of Truth: Is it a Palindromic Wonder?
    int isPalindrome = palindrome(input);

    // Time to Unve the Linguistic Landscape
    if (isPalindrome) {
        printf("\nBehold! '%s' is a triumphant palindrome!\n", input);
        printf("It reads the same backward and forward, a linguistic mirror.\n");
    } else {
        printf("\nAlas, '%s' is not a palindrome.\n", input);
        printf("It defies symmetry, a jumble of letters in disguise.\n");
    }

    // Showcase the Palindromic Treasures
    printf("\nNow, let us bask in the glory of some preeminent palindromes:\n");
    for (int i = 0; i < 10; i++) {
        printf("- %s\n", palindromes[i]);
    }

    printf("\nThank you for visiting the Palindrome Emporium!");
    printf("May your linguistic journeys forever seek symmetry and grace.\n");

    return 0;
}