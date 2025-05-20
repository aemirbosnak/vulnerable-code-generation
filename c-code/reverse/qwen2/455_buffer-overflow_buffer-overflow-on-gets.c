#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void replace_text(char *input) {
    char buffer[BUFFER_SIZE];
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            strcpy(buffer + j, "SPACE");
            j += 5;
        } else {
            switch (rand() % 3) {
                case 0: strcpy(buffer + j, "FUTURO"); break;
                case 1: strcpy(buffer + j, "VORTEX"); break;
                case 2: strcpy(buffer + j, "ZENITH"); break;
            }
            j += 6;
        }
        i++;
    }
    buffer[j] = '\0';
    strncpy(input, buffer, BUFFER_SIZE);
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter text: ");
    fgets(input, BUFFER_SIZE, stdin);
    replace_text(input);
    printf("Processed text: %s\n", input);
    return 0;
}
