//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code characters
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", ".", ".-.-.-", "--..--", "...---...", "....---", ".....---", "-....---", "--...---", "---..---", "----..---", "-----..---",
    ".----..---", "..---..---", "...--..---", "....-..---", ".....-..---", "-....-..---", "--...--..---", "---..--..---", "----..-..---", "-----.-..---", ".----.-..---", "..---.-..---", "...--.-..---", "....--..---",
    "....---..---", "...--..-..---", "..---..-..---", ".----..-..---", "-....-..-..---", "-.-..-..---", "---.-..-..---", "---.--..-..---", "----.-..-..---", "-----.-..-..---", ".----.-..-..---", "..---.-..-..---",
    "...--.-..-..---", "-...-.-..-..---", "-.-.-.-..-..---", "-...-.-..-..---", "---.-.-..-..---", "-....-..-..---", "---.--..-..---", "-----..-..---", ".----..-..---", "---.--..-..---", "-....-..-..---", "-.-..-..---",
    "--...-..---", "-.-.-..-..---", "-...-.-..---", "---.-..-..---", "-....-..-..---", "---.--..-..---", "-----..-..---", ".----..-..---", "---.--..-..---"
};

// Morse code lookup table
char *morse_lookup[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8",
    "9", " ", ".-", "--.-.-", "---...", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", ".", ".-.-.-", "--..--", "...---...", "....---", ".....---", "-....---", "--...---",
    "---..---", "----..---", "-----..---", ".----..---", "..---..---", "...--..---", "....-..---", ".....-..---", "-....-..---", "--...--..---", "---..--..---", "----..-..---", "-----.-..---", ".----.-..---",
    "..---.-..---", "...--.-..---", "-...-.-..---", "-.-..-..---", "---.-..-..---", "---.--..-..---", "----.-..-..---", "-----.-..-..---", ".----.-..-..---", "..---.-..-..---", "...--.-..-..---", "-...-.-..-..---",
    "-.-.-.-..-..---", "-...-.-..-..---", "---.-.-..-..---", "-....-..-..---", "---.--..-..---", "-----..-..---", ".----..-..---", "---.--..-..---", "-....-..-..---", "-.-..-..---", "--...-..---",
    "-.-.-..-..---", "-...-.-..---", "---.-..-..---", "-....-..-..---", "---.--..-..---", "-----..-..---", ".----..-..---", "---.--..-..---"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return morse_code[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5 + 1);
    int i, j, k;
    for (i = 0, j = 0; i < len; i++) {
        char *c = char_to_morse(str[i]);
        if (c != NULL) {
            for (k = 0; k < strlen(c); k++) {
                morse[j++] = c[k];
                morse[j++] = ' ';
            }
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';
    return morse;
}

// Convert a Morse code string to a character
char morse_to_char(char *morse) {
    int i;
    for (i = 0; i < 37; i++) {
        if (strcmp(morse, morse_code[i]) == 0) {
            return morse_lookup[i];
        }
    }
    return '\0';
}

// Convert a Morse code string to a string
char *morse_to_string(char *morse) {
    int len = strlen(morse);
    char *str = malloc(len / 5 + 1);
    int i, j, k;
    for (i = 0, j = 0; i < len; i++) {
        if (morse[i] == ' ') {
            if (morse[i + 1] == ' ') {
                str[j++] = morse_to_char(morse + i - 3);
                i++;
            }
        }
    }
    str[j] = '\0';
    return str;
}

// Print the Morse code for a string
void print_morse(char *str) {
    char *morse = string_to_morse(str);
    printf("%s\n", morse);
    free(morse);
}

// Print the string for a Morse code string
void print_string(char *morse) {
    char *str = morse_to_string(morse);
    printf("%s\n", str);
    free(str);
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Convert the string to Morse code
    char *morse = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse);

    // Convert the Morse code back to a string
    char *str2 = morse_to_string(morse);

    // Print the string
    printf("String: %s\n", str2);

    free(morse);
    free(str2);

    return 0;
}