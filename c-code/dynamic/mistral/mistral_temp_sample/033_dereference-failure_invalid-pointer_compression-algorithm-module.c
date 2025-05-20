#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    char temp[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; i++) {
        if (i > BUFFER_SIZE - 1) {
            printf("Buffer overflow!\n");
            return;
        }
        temp[j++] = input[i];

        if ((i + 1) % 10 == 0) {
            temp[j] = '\0';
            strcat(output, temp);
            strcpy(temp, "");
            j = 0;
        }
    }

    temp[j] = '\0';
    strcat(output, temp);
}

int main() {
    char input[BUFFER_SIZE];
    char output[10];

    printf("Enter a string to compress:\n");
    fgets(input, BUFFER_SIZE, stdin);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    char *ptr = (char *) malloc(strlen(output) * sizeof(char));
    strcpy(ptr, output);

    printf("Dereferencing invalid pointer: %c\n", *ptr);

    return 0;
}
