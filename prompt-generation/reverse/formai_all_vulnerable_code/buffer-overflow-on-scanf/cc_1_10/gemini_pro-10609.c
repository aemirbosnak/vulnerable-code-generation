//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
};

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *to_morse_string(char *s) {
    int len = strlen(s);
    char *morse_code = malloc(len * 5 + 1); // Each character can be represented by up to 5 Morse code units plus a space
    int i;
    int pos = 0;
    for (i = 0; i < len; i++) {
        char *morse = to_morse(s[i]);
        strcpy(morse_code + pos, morse);
        pos += strlen(morse);
        morse_code[pos++] = ' ';
    }
    morse_code[pos] = '\0';
    return morse_code;
}

// Print a string in Morse code
void print_morse(char *s) {
    int len = strlen(s);
    int i;
    for (i = 0; i < len; i++) {
        if (s[i] == '.') {
            printf("·");
        } else if (s[i] == '-') {
            printf("-·");
        } else if (s[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Get the input string
    char *s = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", s);

    // Convert the string to Morse code
    char *morse_code = to_morse_string(s);

    // Print the Morse code
    printf("Morse code: ");
    print_morse(morse_code);

    return 0;
}