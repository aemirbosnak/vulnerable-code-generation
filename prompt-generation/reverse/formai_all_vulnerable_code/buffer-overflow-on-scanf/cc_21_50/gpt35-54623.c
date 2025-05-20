//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToMorse(char letter);

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input);
    for(int i = 0; i < strlen(input); i++) {
        char *morse = convertToMorse(input[i]);
        printf("%s ", morse);
        free(morse);
    }
    return 0;
}

char* convertToMorse(char letter) {
    switch(letter) {
        case 'a':
        case 'A': return strdup(".-");
        case 'b':
        case 'B': return strdup("-...");
        case 'c':
        case 'C': return strdup("-.-.");
        case 'd':
        case 'D': return strdup("-..");
        case 'e':
        case 'E': return strdup(".");
        case 'f':
        case 'F': return strdup("..-.");
        case 'g':
        case 'G': return strdup("--.");
        case 'h':
        case 'H': return strdup("....");
        case 'i':
        case 'I': return strdup("..");
        case 'j':
        case 'J': return strdup(".---");
        case 'k':
        case 'K': return strdup("-.-");
        case 'l':
        case 'L': return strdup(".-..");
        case 'm':
        case 'M': return strdup("--");
        case 'n':
        case 'N': return strdup("-.");
        case 'o':
        case 'O': return strdup("---");
        case 'p':
        case 'P': return strdup(".--.");
        case 'q':
        case 'Q': return strdup("--.-");
        case 'r':
        case 'R': return strdup(".-.");
        case 's':
        case 'S': return strdup("...");
        case 't':
        case 'T': return strdup("-");
        case 'u':
        case 'U': return strdup("..-");
        case 'v':
        case 'V': return strdup("...-");
        case 'w':
        case 'W': return strdup(".--");
        case 'x':
        case 'X': return strdup("-..-");
        case 'y':
        case 'Y': return strdup("-.--");
        case 'z':
        case 'Z': return strdup("--..");
        case '0': return strdup("-----");
        case '1': return strdup(".----");
        case '2': return strdup("..---");
        case '3': return strdup("...--");
        case '4': return strdup("....-");
        case '5': return strdup(".....");
        case '6': return strdup("-....");
        case '7': return strdup("--...");
        case '8': return strdup("---..");
        case '9': return strdup("----.");
        default: return strdup("");
    }
}