//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN_MORSE 26

char morseCode[] = ".- -.... -.-. ---.-..-.. --.......-. --. -.-- ---.--. -.-- --..";

void encode(char c) {
    int i;
    for (i = 0; i < LEN_MORSE; i++) {
        if (morseCode[i] == c) {
            printf("%c", i + 'A');
            return;
        }
    }
    printf("%c", c);
}

void encodeText(char* text) {
    int i, j;
    char c;
    for (i = 0, j = 0; i < strlen(text); i++) {
        c = text[i];
        if (isalpha(c)) {
            encode(c);
        } else if (isdigit(c)) {
            for (j = 0; j < strlen(text) && text[i + j] == '0'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '1'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '2'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '3'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '4'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '5'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '6'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '7'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '8'; j++) {
                encode(c);
            }
            for (j = 0; j < strlen(text) && text[i + j] == '9'; j++) {
                encode(c);
            }
        }
    }
}

int main() {
    char text[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", text);
    encodeText(text);
    return 0;
}