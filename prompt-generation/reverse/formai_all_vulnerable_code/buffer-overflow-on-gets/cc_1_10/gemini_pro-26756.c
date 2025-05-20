//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void decode(char *message) {
    int i, j, k, l;
    char *words[100];
    char *decodedMessage[100];
    int wordCount = 0;
    int decodedMessageCount = 0;
    char *token;

    token = strtok(message, " ");
    while (token != NULL) {
        words[wordCount] = token;
        wordCount++;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < wordCount; i++) {
        l = strlen(words[i]);
        k = 0;
        decodedMessage[decodedMessageCount] = (char *)malloc(l + 1);
        for (j = l - 1; j >= 0; j--) {
            if (j % 2 == 0) {
                decodedMessage[decodedMessageCount][k] = words[i][j];
            } else {
                decodedMessage[decodedMessageCount][k] = toupper(words[i][j]);
            }
            k++;
        }
        decodedMessage[decodedMessageCount][k] = '\0';
        decodedMessageCount++;
    }

    for (i = 0; i < decodedMessageCount; i++) {
        printf("%s ", decodedMessage[i]);
    }
    printf("\n");
}

int main() {
    char message[1000];
    printf("Enter the message: ");
    gets(message);
    decode(message);
    return 0;
}