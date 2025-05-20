//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swan_song(int position);
void penning_verses(char str[], int length);
int is_palindrome(char str[], int length);

int main() {
    char opus[100]; // The lines of our love
    int length;

    // The first act begins
    printf("Enter the words, dear heart, to see if they doth mirror:\n");
    fgets(opus, sizeof(opus), stdin); // A whisper through the air
    length = strlen(opus); // The measure of sweet sentiments

    // Remove the newline character if present
    if (opus[length - 1] == '\n') {
        opus[length - 1] = '\0'; // The last breath of our line
        length--; // Reset the length
    }

    // A call to action, oh fair Juliet!
    penning_verses(opus, length); 

    return 0;
}

// A masquerade of verses, my love
void penning_verses(char str[], int length) {
    int result;

    // The heart's pulse - check if the lines reflect
    result = is_palindrome(str, length);
    
    // The response echoes through the ages
    if (result) {
        printf("Behold! 'Tis a palindrome: our words remain as one.\n");
    } else {
        printf("Alas! 'Tis not a palindrome; the heart doth stray.\n");
    }
}

// Shakespearean core - the essence of a palindrome
int is_palindrome(char str[], int length) {
    int left = 0;
    int right = length - 1;

    // The tale unfolds as we compare characters
    while (left < right) {
        // Skip spaces and consider only alphabets
        while (left < right && !isalpha(str[left])) left++;
        while (left < right && !isalpha(str[right])) right--;

        // Convert to lower case for the fairness of the judgment
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome, alas!
        }
        left++;
        right--;
    }
    return 1; // A cherished palindrome, truly!
}

// A sonnet to capture the end of our tale
void swan_song(int position) {
    if (position == 1) {
        printf("In fair Verona, where we lay our scene.\n");
    } else {
        printf("The drama of love and life shall ever gleam.\n");
    }
}