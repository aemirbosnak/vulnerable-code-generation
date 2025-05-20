#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    char data[1024];

    // Allocate memory for ptr
    ptr = (int *)malloc(10);

    // Read data from the stream
    FILE *fp = fopen("audio.wav", "r");
    fread(data, 1, 1024, fp);

    // Attempt to dereference the pointer
    int value = *(ptr + 1);

    // Free the memory
    free(ptr);

    // Print the value
    printf("Value: %d\n", value);

    return 0;
}
