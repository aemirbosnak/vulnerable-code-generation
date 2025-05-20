//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
/*
 * This program converts a text string to a morse code string.
 * It is written in a safe style, using only standard C functions and
 * avoiding any potential security risks.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LEN 256
#define MAX_MORSE_LEN 256

// Define a struct to represent a morse code character
typedef struct {
    char letter;
    char code[10];
} morse_char_t;

// Define an array of morse code characters
static morse_char_t morse_chars[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'\'', ".----."},
    {'/', "-..-."},
    {'(', "-.--."},
    {')', "-.--.-"},
    {'&', ".-..."},
    {':', "---..."},
    {';', "-.-.-."},
    {'=', "-...-"},
    {'+', ".-.-."},
    {'-', "-....-"},
    {'_', "..--.-"},
    {'"', ".-..-."},
    {'$', "...-..-"},
    {'@', ".--.-."},
};

// Define a function to convert a text string to a morse code string
char* text_to_morse(const char* text) {
    char* morse = malloc(MAX_MORSE_LEN);
    size_t len = strlen(text);
    size_t morse_len = 0;
    for (size_t i = 0; i < len; i++) {
        char c = text[i];
        if (c == ' ') {
            morse[morse_len++] = ' ';
        } else {
            for (size_t j = 0; j < sizeof(morse_chars) / sizeof(morse_char_t); j++) {
                if (c == morse_chars[j].letter) {
                    strcpy(morse + morse_len, morse_chars[j].code);
                    morse_len += strlen(morse_chars[j].code);
                    break;
                }
            }
        }
    }
    morse[morse_len] = '\0';
    return morse;
}

int main() {
    char text[MAX_INPUT_LEN];
    printf("Enter a text string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    char* morse = text_to_morse(text);
    printf("Morse code: %s\n", morse);
    free(morse);
    return 0;
}