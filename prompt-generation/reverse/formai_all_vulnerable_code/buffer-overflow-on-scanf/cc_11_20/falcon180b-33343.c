//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char *text_to_morse(char *text) {
    char *morse = malloc(MAX_LENGTH * sizeof(char));
    char *ptr = morse;

    strcpy(ptr, "");

    while (*text) {
        if (isalpha(*text)) {
            switch (*text) {
                case 'A':
                    strcat(ptr, ".-");
                    break;
                case 'B':
                    strcat(ptr, "-...");
                    break;
                case 'C':
                    strcat(ptr, "-.-.");
                    break;
                case 'D':
                    strcat(ptr, "-..");
                    break;
                case 'E':
                    strcat(ptr, ".");
                    break;
                case 'F':
                    strcat(ptr, "..-.");
                    break;
                case 'G':
                    strcat(ptr, "--.");
                    break;
                case 'H':
                    strcat(ptr, "....");
                    break;
                case 'I':
                    strcat(ptr, "..");
                    break;
                case 'J':
                    strcat(ptr, ".---");
                    break;
                case 'K':
                    strcat(ptr, "-.-");
                    break;
                case 'L':
                    strcat(ptr, ".-..");
                    break;
                case 'M':
                    strcat(ptr, "--");
                    break;
                case 'N':
                    strcat(ptr, "-.");
                    break;
                case 'O':
                    strcat(ptr, "---");
                    break;
                case 'P':
                    strcat(ptr, ".--.");
                    break;
                case 'Q':
                    strcat(ptr, "--.-");
                    break;
                case 'R':
                    strcat(ptr, ".-.");
                    break;
                case 'S':
                    strcat(ptr, "...");
                    break;
                case 'T':
                    strcat(ptr, "-");
                    break;
                case 'U':
                    strcat(ptr, "..-");
                    break;
                case 'V':
                    strcat(ptr, "...-");
                    break;
                case 'W':
                    strcat(ptr, ".--");
                    break;
                case 'X':
                    strcat(ptr, "-..-");
                    break;
                case 'Y':
                    strcat(ptr, "-.--");
                    break;
                case 'Z':
                    strcat(ptr, "--..");
                    break;
                default:
                    strcat(ptr, "");
                    break;
            }
        } else {
            strcat(ptr, " ");
        }
        text++;
    }

    return morse;
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter text to convert to Morse code: ");
    scanf("%s", text);

    char *morse = text_to_morse(text);

    printf("Morse code: %s\n", morse);

    free(morse);

    return 0;
}