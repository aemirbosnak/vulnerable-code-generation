//MISTRAL-7B DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code dictionary
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
int morseLength[] = {1, 3, 3, 2, 1, 3, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// Private key for encryption
char key[5] = {'J', 'A', 'M', 'E', 'S'};

void encodeMorse(char *message, char *encodedMessage) {
    int messageLength = strlen(message);
    int i = 0, j = 0;

    while (i < messageLength) {
        char currentChar = toupper(message[i]);

        if (currentChar == ' ') {
            encodedMessage[j++] = ' ';
            i++;
            continue;
        }

        int morseIndex = 0;

        while (morseIndex < 62 && morse[morseIndex][0] != currentChar) {
            morseIndex++;
        }

        if (morseIndex >= 62) {
            encodedMessage[j++] = '?';
            i++;
            continue;
        }

        strcat(encodedMessage, morse[morseIndex]);

        int keyIndex = 0;

        while (keyIndex < 5 && morseLength[keyIndex] != morseLength[morseIndex % 62]) {
            keyIndex++;
        }

        encodedMessage[j++] = key[keyIndex];

        i++;
    }

    encodedMessage[j] = '\0';
}

void decodeMorse(char *encodedMessage, char *message) {
    int i = 0, j = 0;

    while (encodedMessage[i] != '\0') {
        int morseIndex = 0;

        while (morseIndex < 62 && strlen(morse[morseIndex]) != 1 + encodedMessage[i] - 48) {
            morseIndex++;
        }

        if (morseIndex >= 62) {
            message[j++] = '?';
            i++;
            continue;
        }

        if (isalpha(encodedMessage[i + 1])) {
            message[j++] = morse[morseIndex][morseLength[morseIndex] + (encodedMessage[i + 1] - 'A')];
            i++;
            continue;
        }

        message[j++] = morse[morseIndex][0];
        i += 2;
    }

    message[j] = '\0';
}

int main() {
    char message[100], encodedMessage[150], decodedMessage[100];

    printf("Lovers, write your secret messages below:\n");
    scanf("%s", message);

    encodeMorse(message, encodedMessage);

    printf("Encoded message: %s\n", encodedMessage);

    // Lovers exchange the encoded messages

    decodeMorse(encodedMessage, decodedMessage);

    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}