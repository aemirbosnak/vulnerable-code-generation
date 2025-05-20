#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void log_message(char *message) {
    char logs[10];
    strncat(logs, message, BUFFER_SIZE);
    printf("Logged message: %s\n", logs);
}

void parse_input(char *input) {
    char token[BUFFER_SIZE];
    char delimiter[] = "|";
    char *tokenizer = strtok(input, delimiter);
    int count = 0;

    while (tokenizer != NULL) {
        if (count < 3) {
            strncat(token, tokenizer, BUFFER_SIZE);
            log_message(token);
        } else {
            char level[3];
            char severity[5];
            char message[BUFFER_SIZE];

            strncpy(level, tokenizer, 2);
            strncpy(severity, tokenizer + 2, 4);
            strncpy(message, tokenizer + 6, BUFFER_SIZE - 5);

            // Array bounds violated intentionally
            printf("Level: %s\n", level);
            printf("Severity: %s\n", severity);
            printf("Message: %s\n", message + strlen(message) + 1); // Intentionally dereferencing beyond the end of the string

            tokenizer = strtok(NULL, delimiter);
            count++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    parse_input(argv[1]);

    return 0;
}
