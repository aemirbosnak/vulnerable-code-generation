//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/* convert character to Morse code string */
char* morse(char c) {
    static char morse_code[5];

    switch (toupper(c)) {
        case 'A':
            strcpy(morse_code, ".-");
            break;
        case 'B':
            strcpy(morse_code, "-...");
            break;
        case 'C':
            strcpy(morse_code, "-.-.");
            break;
        case 'D':
            strcpy(morse_code, "-..");
            break;
        case 'E':
            strcpy(morse_code, ".");
            break;
        case 'F':
            strcpy(morse_code, "..-.");
            break;
        case 'G':
            strcpy(morse_code, "--.");
            break;
        case 'H':
            strcpy(morse_code, "....");
            break;
        case 'I':
            strcpy(morse_code, "..");
            break;
        case 'J':
            strcpy(morse_code, ".---");
            break;
        case 'K':
            strcpy(morse_code, "-.-");
            break;
        case 'L':
            strcpy(morse_code, ".-..");
            break;
        case 'M':
            strcpy(morse_code, "--");
            break;
        case 'N':
            strcpy(morse_code, "-.");
            break;
        case 'O':
            strcpy(morse_code, "---");
            break;
        case 'P':
            strcpy(morse_code, ".--.");
            break;
        case 'Q':
            strcpy(morse_code, "--.-");
            break;
        case 'R':
            strcpy(morse_code, ".-.");
            break;
        case 'S':
            strcpy(morse_code, "...");
            break;
        case 'T':
            strcpy(morse_code, "-");
            break;
        case 'U':
            strcpy(morse_code, "..-");
            break;
        case 'V':
            strcpy(morse_code, "...-");
            break;
        case 'W':
            strcpy(morse_code, ".--");
            break;
        case 'X':
            strcpy(morse_code, "-..-");
            break;
        case 'Y':
            strcpy(morse_code, "-.--");
            break;
        case 'Z':
            strcpy(morse_code, "--..");
            break;
        case '0':
            strcpy(morse_code, "-----");
            break;
        case '1':
            strcpy(morse_code, ".----");
            break;
        case '2':
            strcpy(morse_code, "..---");
            break;
        case '3':
            strcpy(morse_code, "...--");
            break;
        case '4':
            strcpy(morse_code, "....-");
            break;
        case '5':
            strcpy(morse_code, ".....");
            break;
        case '6':
            strcpy(morse_code, "-....");
            break;
        case '7':
            strcpy(morse_code, "--...");
            break;
        case '8':
            strcpy(morse_code, "---..");
            break;
        case '9':
            strcpy(morse_code, "----.");
            break;
        default:
            strcpy(morse_code, "");
            break;
    }

    return morse_code;
}

/* convert string to Morse code */
char* string_to_morse(char* str) {
    static char morse_str[MAX_LENGTH * 5] = "";

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == ' ')
            strcat(morse_str, "   "); // add three spaces for word space
        else
            sprintf(morse_str, "%s%s ", morse_str, morse(c)); // add space after each letter
    }

    return morse_str;
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter text to be converted to Morse code: ");
    fgets(input_str, MAX_LENGTH, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; // remove newline character

    printf("Morse code: %s\n", string_to_morse(input_str));

    return 0;
}