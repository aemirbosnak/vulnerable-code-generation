#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buf = malloc(size);

    // Read data from the user
    printf("Enter text: ");
    getline(buf, size, stdin);

    // Use the freed memory
    free(buf);
    buf = NULL;

    // Print the user's text
    printf("Your text: %s", buf);

    return 0;
}
