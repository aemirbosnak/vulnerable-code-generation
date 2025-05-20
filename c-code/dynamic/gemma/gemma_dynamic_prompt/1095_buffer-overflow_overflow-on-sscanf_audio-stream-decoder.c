#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char *ptr = buffer;
    int size = 0;

    printf("Enter the size of the audio stream (in bytes): ");
    scanf("%d", &size);

    if (size > 1024)
    {
        printf("Error: the size of the audio stream is too large.\n");
        return 1;
    }

    printf("Enter the audio stream data: ");
    scanf("%s", ptr);

    // Overflow the buffer
    *(ptr + size) = '\0';

    printf("The audio stream data is:\n");
    printf("%s", buffer);

    return 0;
}
