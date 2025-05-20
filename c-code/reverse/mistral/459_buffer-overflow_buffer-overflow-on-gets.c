#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *futuristicWords[10] = {"ZORP", "QUX", "BLARG", "GLEK", "ZOT", "KLONK", "ZOINK", "BLEEP", "ZAP", "ZOID"};

int main() {
    char input[100];
    char output[100];
    char c;
    time_t t;

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    time(&t);
    srand(t);

    int i = 0;
    for (int j = 0; input[j] != '\0'; ++j) {
        if (input[j] == ' ') {
            output[i++] = 'SPACE';
            continue;
        }
        output[i++] = futuristicWords[rand() % 10][rand() % strlen(futuristicWords[rand() % 10])];
    }
    output[i] = '\0';

    printf("Output: %s\n", output);

    return 0;
}
