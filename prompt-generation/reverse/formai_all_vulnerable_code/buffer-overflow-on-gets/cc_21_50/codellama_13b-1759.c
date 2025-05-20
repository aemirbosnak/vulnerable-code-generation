//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
/* Text to Morse code conversion example program in C */

#include <stdio.h>

int main() {
    char text[100], morse[100];
    int i, j, k;

    printf("Enter a text: ");
    gets(text);

    j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'A':
                morse[j++] = '.-';
                break;
            case 'B':
                morse[j++] = '-...';
                break;
            case 'C':
                morse[j++] = '-.-.';
                break;
            case 'D':
                morse[j++] = '-..';
                break;
            case 'E':
                morse[j++] = '.';
                break;
            case 'F':
                morse[j++] = '..-.';
                break;
            case 'G':
                morse[j++] = '--.';
                break;
            case 'H':
                morse[j++] = '....';
                break;
            case 'I':
                morse[j++] = '..';
                break;
            case 'J':
                morse[j++] = '.---';
                break;
            case 'K':
                morse[j++] = '-.-';
                break;
            case 'L':
                morse[j++] = '.-..';
                break;
            case 'M':
                morse[j++] = '--';
                break;
            case 'N':
                morse[j++] = '-.';
                break;
            case 'O':
                morse[j++] = '---';
                break;
            case 'P':
                morse[j++] = '.--.';
                break;
            case 'Q':
                morse[j++] = '--.-';
                break;
            case 'R':
                morse[j++] = '.-.';
                break;
            case 'S':
                morse[j++] = '...';
                break;
            case 'T':
                morse[j++] = '-';
                break;
            case 'U':
                morse[j++] = '..-';
                break;
            case 'V':
                morse[j++] = '...-';
                break;
            case 'W':
                morse[j++] = '.--';
                break;
            case 'X':
                morse[j++] = '-..-';
                break;
            case 'Y':
                morse[j++] = '-.--';
                break;
            case 'Z':
                morse[j++] = '--..';
                break;
            case '1':
                morse[j++] = '.----';
                break;
            case '2':
                morse[j++] = '..---';
                break;
            case '3':
                morse[j++] = '...--';
                break;
            case '4':
                morse[j++] = '....-';
                break;
            case '5':
                morse[j++] = '.....';
                break;
            case '6':
                morse[j++] = '-....';
                break;
            case '7':
                morse[j++] = '--...';
                break;
            case '8':
                morse[j++] = '---..';
                break;
            case '9':
                morse[j++] = '----.';
                break;
            case '0':
                morse[j++] = '-----';
                break;
            default:
                break;
        }
    }

    morse[j] = '\0';

    printf("Morse code: %s\n", morse);

    return 0;
}