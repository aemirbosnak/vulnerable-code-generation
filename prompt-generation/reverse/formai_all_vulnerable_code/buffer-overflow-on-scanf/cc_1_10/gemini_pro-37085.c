//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

// Morse code table
const char* morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Convert a character to Morse code
char* char_to_morse(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return (char*)morse_code[ch - 'A'];
    } else if (ch >= 'a' && ch <= 'z') {
        return (char*)morse_code[ch - 'a'];
    } else if (ch >= '0' && ch <= '9') {
        return (char*)morse_code[ch - '0' + 26];
    } else if (ch == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a word to Morse code
char* word_to_morse(char* word) {
    char* morse_word = malloc(strlen(word) * 5);
    int i;
    for (i = 0; i < strlen(word); i++) {
        strcat(morse_word, char_to_morse(word[i]));
        strcat(morse_word, " ");
    }
    return morse_word;
}

// Main function
int main() {
    char word[MAX_WORD_LEN + 1];
    char* morse_word;

    printf("Enter a word to convert to Morse code: ");
    scanf("%s", word);

    morse_word = word_to_morse(word);

    printf("Morse code: %s\n", morse_word);

    free(morse_word);

    return 0;
}