//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
/*
 * Text to Morse code conversion example program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>

int main() {
    char text[100];
    char morse[100];
    int i, j;

    printf("Enter a text: ");
    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'A': morse[i] = ".-"; break;
            case 'B': morse[i] = "-..."; break;
            case 'C': morse[i] = "-.-."; break;
            case 'D': morse[i] = "-.."; break;
            case 'E': morse[i] = "."; break;
            case 'F': morse[i] = "..-."; break;
            case 'G': morse[i] = "--."; break;
            case 'H': morse[i] = "...."; break;
            case 'I': morse[i] = ".."; break;
            case 'J': morse[i] = ".---"; break;
            case 'K': morse[i] = "-.-"; break;
            case 'L': morse[i] = ".-.."; break;
            case 'M': morse[i] = "--"; break;
            case 'N': morse[i] = "-."; break;
            case 'O': morse[i] = "---"; break;
            case 'P': morse[i] = ".--."; break;
            case 'Q': morse[i] = "--.-"; break;
            case 'R': morse[i] = ".-."; break;
            case 'S': morse[i] = "..."; break;
            case 'T': morse[i] = "-"; break;
            case 'U': morse[i] = "..-"; break;
            case 'V': morse[i] = "...-"; break;
            case 'W': morse[i] = ".--"; break;
            case 'X': morse[i] = "-..-"; break;
            case 'Y': morse[i] = "-.--"; break;
            case 'Z': morse[i] = "--.."; break;
            case '0': morse[i] = "-----"; break;
            case '1': morse[i] = ".----"; break;
            case '2': morse[i] = "..---"; break;
            case '3': morse[i] = "...--"; break;
            case '4': morse[i] = "....-"; break;
            case '5': morse[i] = "....."; break;
            case '6': morse[i] = "-...."; break;
            case '7': morse[i] = "--..."; break;
            case '8': morse[i] = "---.."; break;
            case '9': morse[i] = "----."; break;
            case ' ': morse[i] = "/"; break;
            default: morse[i] = ""; break;
        }
    }

    printf("Morse code: ");
    for (j = 0; morse[j] != '\0'; j++) {
        printf("%s ", morse[j]);
    }
    printf("\n");

    return 0;
}