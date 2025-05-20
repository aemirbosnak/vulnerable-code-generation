//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: funny
#include <stdio.h>
#include <string.h>

// Morse code table
char morse_table[][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", ".-.-", "-.--", "--..--", ".-.-.-", "...---...", "-....-", "--...", "---...", "----", "-----", ".-", "..--..", "...---...", "....-", ".....", "-....-", "-.-.--", "-.--.-", ".-.-.-", ".----.", "-....-", "--...", "-.--.", ".-..-.", ".----.", "-.-.--", "--..--", "-..---", "-....-", "-.-.-.-", "-----", ".-", "..-..", "---...", "-.-.-."
};

// Convert a character to Morse code
char* char_to_morse(char c) {
    int index = c - 'a';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5);
    int index = 0;
    for (int i = 0; i < len; i++) {
        char* morse_char = char_to_morse(str[i]);
        strcpy(morse_code + index, morse_char);
        index += strlen(morse_char);
        morse_code[index++] = ' ';
    }
    morse_code[index - 1] = '\0';
    return morse_code;
}

// Print a string in Morse code
void print_morse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            printf("dit ");
        } else if (str[i] == '-') {
            printf("dah ");
        } else if (str[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Get the input string
    printf("Enter a string to convert to Morse code: ");
    char str[100];
    scanf("%s", str);

    // Convert the string to Morse code
    char* morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Print the Morse code as dits and dahs
    printf("Dits and dahs: ");
    print_morse(morse_code);

    return 0;
}