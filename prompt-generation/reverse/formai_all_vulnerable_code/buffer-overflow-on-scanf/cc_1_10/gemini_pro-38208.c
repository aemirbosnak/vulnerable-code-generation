//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Declare the alphabet table
const char *alphabet_table[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
    "T", "U", "V", "W", "X", "Y", "Z"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index < 0 || index > 25) {
        return NULL;
    }
    return strdup(morse_table[index]);
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    if (morse_code == NULL) {
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse == NULL) {
            free(morse_code);
            return NULL;
        }
        strcpy(morse_code + j, morse);
        j += strlen(morse);
        morse_code[j++] = ' ';
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Function to convert Morse code to a string
char *morse_to_string(char *morse_code) {
    int len = strlen(morse_code);
    char *str = malloc(len / 5 + 1);
    if (str == NULL) {
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (morse_code[i] == ' ') {
            continue;
        }
        int index = -1;
        for (int k = 0; k < 26; k++) {
            if (strcmp(morse_code + i, morse_table[k]) == 0) {
                index = k;
                break;
            }
        }
        if (index == -1) {
            free(str);
            return NULL;
        }
        str[j++] = alphabet_table[index];
        i += strlen(morse_table[index]) - 1;
    }
    str[j] = '\0';
    return str;
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code\n");
        return -1;
    }

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Convert the Morse code to a string
    char *new_str = morse_to_string(morse_code);
    if (new_str == NULL) {
        printf("Error converting Morse code to string\n");
        free(morse_code);
        return -1;
    }

    // Print the new string
    printf("New string: %s\n", new_str);

    // Free the memory
    free(morse_code);
    free(new_str);

    return 0;
}