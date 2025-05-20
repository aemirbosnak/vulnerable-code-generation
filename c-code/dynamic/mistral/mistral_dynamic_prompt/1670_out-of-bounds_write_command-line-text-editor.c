#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void edit(char* buffer, int size) {
    char input[256];
    int i, index;

    for (i = 0; i < size; ++i) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    printf("Enter a character to replace the current one at the cursor position (0 to save and quit): ");
    scanf("%s", input);

    if (strlen(input) > 1) {
        printf("Error: Input too long\n");
        return;
    }

    printf("Enter the index (0 to -%d) of the character to replace: ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    buffer[index] = input[0];
}

int main() {
    char buffer[10];
    int i, size = sizeof(buffer) / sizeof(buffer[0]);

    for (i = 0; i < size; ++i) {
        buffer[i] = '\0';
    }

    while (1) {
        edit(buffer, size);
    }

    return 0;
}
