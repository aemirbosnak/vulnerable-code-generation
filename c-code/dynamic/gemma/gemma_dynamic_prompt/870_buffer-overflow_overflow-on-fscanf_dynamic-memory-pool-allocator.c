#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    printf("Enter the size of the buffer: ");
    scanf("%d", &size);

    buffer = (char *)malloc(size);

    printf("Enter the data to be stored in the buffer: ");
    scanf("%s", buffer);

    printf("The data stored in the buffer is: %s", buffer);

    free(buffer);

    return 0;
}
