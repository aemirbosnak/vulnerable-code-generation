#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    char *special_chars = "!@#$%^&*()-+={}[]|;:'\",.<>?/\\";

    for (int i = 0; i < 3; ++i) {
        printf("Enter input %d: ", i + 1);
        fgets(input, sizeof(input), stdin);

        for (int j = 0; input[j] != '\0'; ++j) {
            if (strchr(special_chars, input[j]) != NULL) {
                input[j] = '_';
            } else if (!isalnum(input[j]) && input[j] != '_' && input[j] != ' ') {
                input[j] = ' ';
            }
        }

        printf("Sanitized input: %s\n", input);
    }

    return 0;
}
