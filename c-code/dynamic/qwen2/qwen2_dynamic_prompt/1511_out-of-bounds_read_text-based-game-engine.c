#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void read_input(char *buffer, int size) {
    printf("Enter your input: ");
    fgets(buffer, size, stdin);
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int index;

    read_input(buffer, sizeof(buffer));

    printf("Buffer content: %s\n", buffer);

    // Vulnerability: Out-of-bounds read
    printf("Character at index 20: %c\n", buffer[20]);

    return 0;
}
