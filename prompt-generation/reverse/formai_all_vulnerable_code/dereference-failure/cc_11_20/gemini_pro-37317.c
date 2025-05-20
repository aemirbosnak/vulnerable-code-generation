//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
/*
 * Alien Translator, version 1.0
 *
 * This program translates a message from English to Alien according to
 * the following rules:
 *
 *   1. All vowels are replaced with their corresponding digit:
 *      a -> 1
 *      e -> 2
 *      i -> 3
 *      o -> 4
 *      u -> 5
 *
 *   2. All consonants are replaced with their ASCII code:
 *      b -> 98
 *      c -> 99
 *      d -> 100
 *      ...
 *      z -> 122
 *
 *   3. Spaces are replaced with underscores.
 *
 * For example, the message "Hello, world!" would be translated to
 * "H3ll4, w96rld!".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* message = argv[1];
    char* alien_message = malloc(strlen(message) + 1);
    if (alien_message == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        if (c == 'a' || c == 'A') {
            alien_message[i] = '1';
        } else if (c == 'e' || c == 'E') {
            alien_message[i] = '2';
        } else if (c == 'i' || c == 'I') {
            alien_message[i] = '3';
        } else if (c == 'o' || c == 'O') {
            alien_message[i] = '4';
        } else if (c == 'u' || c == 'U') {
            alien_message[i] = '5';
        } else if (c >= 'a' && c <= 'z') {
            alien_message[i] = c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            alien_message[i] = c;
        } else if (c == ' ') {
            alien_message[i] = '_';
        } else {
            alien_message[i] = c;
        }
    }

    alien_message[strlen(message)] = '\0';

    printf("%s\n", alien_message);

    free(alien_message);

    return EXIT_SUCCESS;
}