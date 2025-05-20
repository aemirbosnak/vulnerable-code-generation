#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void generate_random_string(char *str, int length) {
    char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; ++i) {
        str[i] = chars[rand() % strlen(chars)];
    }
    str[length] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    int input_length = strlen(input);
    char output[MAX_LENGTH * 5];

    for (int i = 0; i < input_length; ++i) {
        if (input[i] == ' ') {
            strcat(output, "SPACE");
        } else {
            int random_length = 1 + rand() % 4;
            generate_random_string(output + strlen(output), random_length);
            strncat(output, &input[i], 1);
        }
    }

    printf("Futuristic text: %s\n", output);

    return 0;
}
