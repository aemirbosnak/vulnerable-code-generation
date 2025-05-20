#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int size = 0;

    // Get the stream data, ignoring the size limit
    gets(buffer);

    // Overflow the buffer
    size = strlen(buffer) + 1;
    buffer[size - 1] = '\0';

    // Play the decoded audio data
    printf("%s", buffer);

    return 0;
}
