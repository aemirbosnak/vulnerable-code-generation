#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 50

int main() {
    char input[MAX_INPUT];
    char sanitized[MAX_INPUT];

    for(int i = 0; i < 3; ++i) {
        printf("Enter line %d: ", i + 1);
        fgets(input, MAX_INPUT, stdin);

        for(int j = 0; input[j] != '\n' && j < MAX_INPUT; ++j) {
            if(input[j] == '@' || input[j] == '#' || input[j] == '%') {
                sanitized[j] = ' ';
            } else if(input[j] >= 'A' && input[j] <= 'Z') {
                sanitized[j] = input[j] + 32;
            } else {
                sanitized[j] = input[j];
            }
        }
        sanitized[strlen(input)] = '\0';

        printf("Welcome, %s!\n", sanitized);
    }

    return 0;
}
