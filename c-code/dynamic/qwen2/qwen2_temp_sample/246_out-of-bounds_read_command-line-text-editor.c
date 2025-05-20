#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BUFFER_SIZE 128

void read_line(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter some text: ");
    read_line(buffer, BUFFER_SIZE);

    // Intentional off-by-one error to demonstrate potential out-of-bounds read
    printf("Last character read was: %c\n", buffer[BUFFER_SIZE - 1]);

    return 0;
}
