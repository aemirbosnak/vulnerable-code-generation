#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void edit_text(char *text, int length) {
    char buffer[BUFFER_SIZE];
    printf("Enter text to edit: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[length] != '\0') {
        printf("Out of bounds read detected!\n");
        exit(1);
    }
    strncpy(text, buffer, length);
}

int main() {
    char text[BUFFER_SIZE];
    int length;

    printf("Enter the length of text to edit (max %d): ", BUFFER_SIZE - 1);
    scanf("%d", &length);
    getchar(); // Consume newline character left by scanf

    if (length >= BUFFER_SIZE) {
        printf("Length exceeds buffer size!\n");
        return 1;
    }

    edit_text(text, length);

    printf("Edited text: %s\n", text);

    return 0;
}
