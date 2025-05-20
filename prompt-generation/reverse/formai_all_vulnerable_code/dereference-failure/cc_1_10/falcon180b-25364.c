//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char* convert_to_ascii(char* input) {
    int i = 0;
    char* output = malloc(MAX_LENGTH * sizeof(char));

    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = input[i] + 32;
            } else if (islower(input[i])) {
                output[i] = input[i] - 32;
            }
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';

    return output;
}

void print_ascii_art(char* ascii_art) {
    int i = 0;

    for (i = 0; ascii_art[i]!= '\0'; i++) {
        if (ascii_art[i] == '\n') {
            printf("\n");
        } else {
            printf("%c", ascii_art[i]);
        }
    }
}

int main() {
    char* input = NULL;
    char* ascii_art = NULL;

    printf("Enter some text: ");
    fgets(input, MAX_LENGTH, stdin);

    ascii_art = convert_to_ascii(input);
    print_ascii_art(ascii_art);

    free(input);
    free(ascii_art);

    return 0;
}