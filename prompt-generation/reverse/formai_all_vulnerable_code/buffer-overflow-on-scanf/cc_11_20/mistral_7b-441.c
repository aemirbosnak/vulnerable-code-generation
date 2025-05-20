//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DOT "_"
#define DASH "/"
#define SPACE " "

void morseCode(char c) {
    switch (tolower(c)) {
        case 'a': printf("%s.%s", DOT, DOT); break;
        case 'b': printf("%s%s%s", DASH, DOT, DASH); break;
        case 'c': printf("%s-%s--", DOT, DOT); break;
        case 'd': printf("%s..", DOT, DOT); break;
        case 'e': printf(DOT); break;
        case 'f': printf("%s%s.%s", DASH, DOT, DOT); break;
        case 'g': printf("%s--%s", DASH, DASH); break;
        case 'h': printf("%s....", DOT, DOT, DOT, DOT); break;
        case 'i': printf("%s%s", DOT, DOT); break;
        case 'j': printf("%s.--%s..", DOT, DASH, DOT); break;
        case 'k': printf("%s-%s%s", DASH, DOT, DASH); break;
        case 'l': printf("%s.%s..", DOT, DOT, DOT); break;
        case 'm': printf("%s--", DASH, DASH); break;
        case 'n': printf("%s-.", DASH, DOT); break;
        case 'o': printf("%s---", DASH, DASH, DASH); break;
        case 'p': printf("%s.--.", DOT, DASH, DOT); break;
        case 'q': printf("%s--.-", DASH, DOT, DASH, DOT); break;
        case 'r': printf("%s.-.", DOT, DASH); break;
        case 's': printf("%s...", DOT, DOT, DOT); break;
        case 't': printf("-"); break;
        case 'u': printf("%s..%s", DOT, DOT); break;
        case 'v': printf("%s.%s.%s", DOT, DASH, DOT); break;
        case 'w': printf("%s.--", DOT, DASH); break;
        case 'x': printf("%s-..", DASH, DOT); break;
        case 'y': printf("%s.--.-", DOT, DASH, DOT, DASH); break;
        case 'z': printf("%s--..", DASH, DOT, DOT, DOT); break;
        case ' ': printf("%s", SPACE); break;
        default: printf("Invalid character: %c", c);
    }
}

int main() {
    char input[101];
    printf("Enter text to convert to Morse code: ");
    scanf("%s", input);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        morseCode(input[i]);
        if (i < len - 1) printf(" ");
    }

    printf("\n");
    return 0;
}