#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE] = {0};
    int i, j;
    srand(time(0));

    printf("Enter a string: ");
    gets(input);

    for (i = 0; input[i]; i++) {
        if (input[i] == ' ') {
            strcpy(output + strlen(output), "SPACE");
        } else {
            for (j = 0; j < 5; j++) {
                int randomChar = rand() % 62;
                if (randomChar < 26) {
                    output[strlen(output)] = 'A' + randomChar;
                } else if (randomChar < 52) {
                    output[strlen(output)] = 'a' + (randomChar - 26);
                } else {
                    output[strlen(output)] = '0' + (randomChar - 52);
                }
            }
        }
    }

    printf("Futuristic String: %s\n", output);

    return 0;
}
