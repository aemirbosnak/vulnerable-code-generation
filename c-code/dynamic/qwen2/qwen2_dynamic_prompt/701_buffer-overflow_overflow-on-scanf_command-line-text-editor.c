#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *text) {
    printf("Enter your text: ");
    scanf("%[^\n]%*c", text);
}

int main() {
    char *buffer = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Welcome to the Text Editor!\n");
    while (1) {
        printf("Current text: %s\n", buffer);
        edit_text(buffer);
        if (strlen(buffer) >= MAX_LINE_LENGTH - 1) {
            printf("Buffer overflow detected! Exiting...\n");
            break;
        }
    }

    free(buffer);
    return 0;
}
