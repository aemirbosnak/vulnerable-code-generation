#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buf = NULL;
    int len = 0;

    // Allocate memory for the buffer
    buf = malloc(1024);

    // Get the file upload data
    printf("Enter file data: ");
    gets(buf);

    // Overflow the buffer
    buf[1023] = '\0';

    // Print the file data
    printf("File data: %s", buf);

    // Free the memory
    free(buf);

    return 0;
}
