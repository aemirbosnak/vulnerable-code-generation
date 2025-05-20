//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Behold! The ancient scroll of palindrome manifestation.
// Where echoes of words dance upon the stage of letters.
// Will thou embark on this journey to unravel the secrets 
// of symmetric expressions hidden within the fabric of language?

// This function cleanses the input, casting away non-letter characters.
void cleanse(char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0'; // Close the tale of cleaning
}

// This function unveils the truth – is it a palindrome?
int is_palindrome(const char *string) {
    int left = 0;
    int right = strlen(string) - 1;
    
    // As the pointers move closer, truths reveal their nature
    while (left < right) {
        if (string[left] != string[right]) {
            return 0; // A riddle unsolved, it shall not return
        }
        left++;
        right--;
    }
    return 1; // The mirror reflects a perfect form
}

int main() {
    char input[MAX_SIZE];
    char cleaned[MAX_SIZE];

    // Speak, brave traveler! What words do you bear?
    printf("Enter a phrase to check for palindrome qualities: ");
    fgets(input, MAX_SIZE, stdin);
    
    // Erase the marks of chaos and bring forth a clean essence
    cleanse(input, cleaned);

    // The moment arrives – release the judgment!
    if (is_palindrome(cleaned)) {
        printf("The phrase is a palindrome! A true reflection of symmetry.\n");
    } else {
        printf("Alas! The phrase is not a palindrome. Distorted echoes, indeed.\n");
    }
    
    // The script ends, but the echoes live on...
    
    // Journey repeat command for the adventurous spirit
    char repeat;
    printf("Would you like to check another phrase? (y/n): ");
    scanf(" %c", &repeat);
    while (repeat == 'y' || repeat == 'Y') {
        printf("Enter a phrase to check for palindrome qualities: ");
        getchar(); // Clear newline from buffer
        fgets(input, MAX_SIZE, stdin);
        cleanse(input, cleaned);
        
        if (is_palindrome(cleaned)) {
            printf("The phrase is a palindrome!\n");
        } else {
            printf("Alas, not a palindrome!\n");
        }
        
        printf("Would you like to check another phrase? (y/n): ");
        scanf(" %c", &repeat);
    }

    printf("Farewell, seeker of symmetry!\n");

    // Thus the journey ends, the tales of palindromes etched in memory.
    return 0;
}