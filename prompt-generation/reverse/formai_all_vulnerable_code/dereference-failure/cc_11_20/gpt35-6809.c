//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

#define MAXLEN 100

char* text_to_morse(char* text);
const char* letter_to_morse(char letter);
const char* digit_to_morse(char digit);

int main(void) {
    char text[MAXLEN];
    printf("Enter text: ");
    fgets(text, MAXLEN, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character from input

    char* morse_code = text_to_morse(text);
    printf("Morse Code: %s\n", morse_code);

    return 0;
}

char* text_to_morse(char* text) {
    char* morse_code = malloc(sizeof(char) * MAXLEN);
    morse_code[0] = '\0';

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c == ' ') strcat(morse_code, "/ ");
        else if (c >= 'A' && c <= 'Z') strcat(morse_code, letter_to_morse(c)); // uppercase letter
        else if (c >= 'a' && c <= 'z') strcat(morse_code, letter_to_morse(c - 32)); // lowercase letter converted to uppercase
        else if (c >= '0' && c <= '9') strcat(morse_code, digit_to_morse(c)); // digit
        else strcat(morse_code, "?"); // unrecognized character
    }

    return morse_code;
}

const char* letter_to_morse(char letter) {
    switch (letter) {
        case 'A': return ".- ";
        case 'B': return "-... ";
        case 'C': return "-.-. ";
        case 'D': return "-.. ";
        case 'E': return ". ";
        case 'F': return "..-. ";
        case 'G': return "--. ";
        case 'H': return ".... ";
        case 'I': return ".. ";
        case 'J': return ".--- ";
        case 'K': return "-.- ";
        case 'L': return ".-.. ";
        case 'M': return "-- ";
        case 'N': return "-. ";
        case 'O': return "--- ";
        case 'P': return ".--. ";
        case 'Q': return "--.- ";
        case 'R': return ".-. ";
        case 'S': return "... ";
        case 'T': return "- ";
        case 'U': return "..- ";
        case 'V': return "...- ";
        case 'W': return ".-- ";
        case 'X': return "-..- ";
        case 'Y': return "-.-- ";
        case 'Z': return "--.. ";
        default: return "?"; // unrecognized letter
    }
}

const char* digit_to_morse(char digit) {
    switch (digit) {
        case '0': return "----- ";
        case '1': return ".---- ";
        case '2': return "..--- ";
        case '3': return "...-- ";
        case '4': return "....- ";
        case '5': return "..... ";
        case '6': return "-.... ";
        case '7': return "--... ";
        case '8': return "---.. ";
        case '9': return "----. ";
        default: return "?"; // unrecognized digit
    }
}