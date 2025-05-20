//FormAI DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {

    char *message = malloc(sizeof(char) * 100);

    printf("Enter a message to recover: ");
    scanf("%99[^\n]", message);

    int key;

    do {
        printf("Enter the key to recover the message: ");
        scanf("%d", &key);

        if (key < 1 || key > 26) {
            printf("Invalid key. Please enter a key between 1 and 26.\n");
        }
    } while (key < 1 || key > 26);

    int messageLength = strlen(message);

    for (int i = 0; i < messageLength; i++) {

        char currentChar = message[i];

        if (currentChar == ' ') {
            continue;
        }

        if (currentChar >= 'a' && currentChar <= 'z') {
            currentChar = currentChar - key;

            if (currentChar < 'a') {
                currentChar = currentChar + 26;
            }
        }

        if (currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = currentChar - key;

            if (currentChar < 'A') {
                currentChar = currentChar + 26;
            }
        }

        message[i] = currentChar;
    }

    printf("Recovered Message: %s\n", message);

    free(message);

    return 0;
}