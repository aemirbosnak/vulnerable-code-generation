#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 1000

char *futuristic_characters[] = {
    "!", "@", "#", "$", "%", "&", "*", "(", ")", "+", "=", ";", ":", ".", ",", "-", "_",
    "|", "[", "]", "{", "}", "~", "^", "`", ">", "<", "?", "/", "\\", " ", "\t"
};

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int i, len, rand_index;
    time_t t;

    printf("Enter text: ");
    fgets(input, BUFFER_SIZE, stdin);

    len = strlen(input);

    srand((unsigned)time(&t));

    for (i = 0; i < len; ++i) {
        if (isalnum(input[i])) {
            output[i] = futuristic_characters[rand() % (sizeof(futuristic_characters) / sizeof(futuristic_characters[0]))];
        } else if (input[i] == ' ') {
            output[i] = 'SPACE';
        } else {
            output[i] = input[i];
        }
    }

    printf("Output: %s\n", output);

    return 0;
}
