//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;

    printf("Encryptor v0.1\n");
    printf("Type a line to encrypt, type 'quit' to exit\n");

    while (1) {
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line)] = '\0';

        if (strcmp(line, "quit") == 0) {
            break;
        }

        token = strtok(line, " ");

        if (token == NULL) {
            printf("Invalid input. Please type a line to encrypt, or type 'quit' to exit\n");
            continue;
        }

        int length = strlen(token);
        char encrypted_line[length];

        for (int i = 0; i < length; i++) {
            char current_char = token[i];
            if (isalpha(current_char)) {
                if (isupper(current_char)) {
                    encrypted_line[i] = (char)(((int)current_char + 3) % 26 + 'A');
                } else {
                    encrypted_line[i] = (char)(((int)current_char + 3) % 26 + 'a');
                }
            } else {
                encrypted_line[i] = current_char;
            }
        }

        encrypted_line[length] = '\0';
        printf("%s -> %s\n", token, encrypted_line);
    }

    return 0;
}