#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE], output[BUFFER_SIZE];
    gets(input);

    int len = strlen(input);
    for (int i = 0; i < len; ++i) {
        output[i] = 'A' + rand() % (123 - 'A');
        if (input[i] == ' ') {
            output[i] = 'SPACE';
        }
    }

    srand(time(NULL));
    for (int i = 0, j = 0; i < len; ++i) {
        if (input[i] != ' ') {
            int random_index = rand() % len;
            char temp = output[random_index];
            output[random_index] = input[i];
            output[i] = temp;
        }
    }

    printf("%s\n", output);

    return 0;
}
