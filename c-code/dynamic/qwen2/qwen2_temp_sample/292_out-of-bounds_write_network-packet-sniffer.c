#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main() {
    char buffer[BUFSIZE];
    int i;

    // Simulate receiving data
    strcpy(buffer, "This is a test buffer.");

    // Deliberate out-of-bounds write vulnerability
    for (i = 0; i <= BUFSIZE; i++) {
        buffer[i] = 'X';  // Writing beyond the buffer's capacity
    }

    printf("Buffer after overflow: %s\n", buffer);
    return 0;
}
