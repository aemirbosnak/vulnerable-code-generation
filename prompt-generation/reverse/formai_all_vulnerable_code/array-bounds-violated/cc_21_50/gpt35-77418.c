//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define DOT "."
#define DASH "-"
#define SPACE " "

char* text_to_morse(char c) {
    switch (c) {
        case 'a': case 'A': return DOT SPACE DASH;
        case 'b': case 'B': return DASH SPACE DOT SPACE DOT SPACE DOT;
        case 'c': case 'C': return DASH SPACE DOT SPACE DASH SPACE DOT;
        case 'd': case 'D': return DASH SPACE DOT SPACE DOT;
        case 'e': case 'E': return DOT;
        case 'f': case 'F': return DOT SPACE DOT SPACE DASH SPACE DOT;
        case 'g': case 'G': return DASH SPACE DASH SPACE DOT;
        case 'h': case 'H': return DOT SPACE DOT SPACE DOT SPACE DOT;
        case 'i': case 'I': return DOT SPACE DOT;
        case 'j': case 'J': return DOT SPACE DASH SPACE DASH SPACE DASH;
        case 'k': case 'K': return DASH SPACE DOT SPACE DASH;
        case 'l': case 'L': return DOT SPACE DASH SPACE DOT SPACE DOT;
        case 'm': case 'M': return DASH SPACE DASH;
        case 'n': case 'N': return DASH SPACE DOT;
        case 'o': case 'O': return DASH SPACE DASH SPACE DASH;
        case 'p': case 'P': return DOT SPACE DASH SPACE DASH SPACE DOT;
        case 'q': case 'Q': return DASH SPACE DASH SPACE DOT SPACE DASH;
        case 'r': case 'R': return DOT SPACE DASH SPACE DOT;
        case 's': case 'S': return DOT SPACE DOT SPACE DOT;
        case 't': case 'T': return DASH;
        case 'u': case 'U': return DOT SPACE DOT SPACE DASH;
        case 'v': case 'V': return DOT SPACE DOT SPACE DOT SPACE DASH;
        case 'w': case 'W': return DOT SPACE DASH SPACE DASH;
        case 'x': case 'X': return DASH SPACE DOT SPACE DOT SPACE DASH;
        case 'y': case 'Y': return DASH SPACE DOT SPACE DASH SPACE DASH;
        case 'z': case 'Z': return DASH SPACE DASH SPACE DOT SPACE DOT;
        case '0': return DASH SPACE DASH SPACE DASH SPACE DASH SPACE DASH;
        case '1': return DOT SPACE DASH SPACE DASH SPACE DASH SPACE DASH;
        case '2': return DOT SPACE DOT SPACE DASH SPACE DASH SPACE DASH;
        case '3': return DOT SPACE DOT SPACE DOT SPACE DASH SPACE DASH;
        case '4': return DOT SPACE DOT SPACE DOT SPACE DOT SPACE DASH;
        case '5': return DOT SPACE DOT SPACE DOT SPACE DOT SPACE DOT;
        case '6': return DASH SPACE DOT SPACE DOT SPACE DOT SPACE DOT;
        case '7': return DASH SPACE DASH SPACE DOT SPACE DOT SPACE DOT;
        case '8': return DASH SPACE DASH SPACE DASH SPACE DOT SPACE DOT;
        case '9': return DASH SPACE DASH SPACE DASH SPACE DASH SPACE DOT;
        case ' ': return "/";
        default: return "";
    }
}

int main(int argc, char *argv[]) {
    char text[256];
    printf("Enter your message: ");
    fgets(text, sizeof(text), stdin);
    int len = strlen(text);
    // remove new line character from text
    if (text[len-1] == '\n') {
        text[len-1] = '\0';
    }
    for (int i = 0; i < strlen(text); i++) {
        char *morse = text_to_morse(text[i]);
        if (strcmp(morse, "") != 0) {
            printf("%s ", morse);
        }
    }
    printf("\n");
    return 0;
}