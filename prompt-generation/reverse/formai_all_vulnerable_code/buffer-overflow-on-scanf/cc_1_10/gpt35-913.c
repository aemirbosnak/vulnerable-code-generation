//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encodeToMorseCode(char *message, char *morseCode) {
    char *morseCodes[] = {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
        "--..--", ".-.-.-", "..--..", "-.-.--"
    };

    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int position = tolower(message[i]) - 'a';
            strcat(morseCode, morseCodes[position]);
        } else if (isdigit(message[i])) {
            int position = message[i] - '0';
            strcat(morseCode, morseCodes[position]);
        } else if (isspace(message[i])) {
            strcat(morseCode, " ");
        } else {
            switch (message[i]) {
                case ',':
                    strcat(morseCode, morseCodes[36]);
                    break;
                case '.':
                    strcat(morseCode, morseCodes[37]);
                    break;
                case '?':
                    strcat(morseCode, morseCodes[38]);
                    break;
                case '!':
                    strcat(morseCode, morseCodes[39]);
                    break;
                default:
                    break;
            }
        }
        strcat(morseCode, " ");
    }
}

int main() {
    char message[100];
    char morseCode[1000] = "";
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    encodeToMorseCode(message, morseCode);
    printf("Morse code: %s", morseCode);

    return 0;
}