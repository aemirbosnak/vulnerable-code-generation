//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_KEY "&%#*@!^$"

void alien_encode(char* message, char* alien_message, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            alien_message[i] = ALIEN_KEY[(int)toupper(message[i]) - 65];
        } else {
            alien_message[i] = message[i];
        }
    }
    alien_message[length] = '\0';
}

void alien_decode(char* alien_message, char* message, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (isalpha(alien_message[i])) {
            message[i] = ALIEN_KEY[(int)toupper(alien_message[i]) - *ALIEN_KEY];
        } else {
            message[i] = alien_message[i];
        }
    }
    message[length] = '\0';
}

int main() {
    char input[100], output[100], alien_input[100], alien_output[100];
    int length;

    printf("English to Alien Translation Program\n");
    printf("------------------------------------\n");

    printf("Enter English message: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    length = strlen(input);

    // Allocate memory for alien_output
    alien_output[length] = '\0';

    alien_encode(input, alien_output, length);

    printf("Alien message: %s\n", alien_output);

    // Allocate memory for output
    output[length] = '\0';

    alien_decode(alien_output, output, length);

    printf("English message: %s\n", output);

    return 0;
}