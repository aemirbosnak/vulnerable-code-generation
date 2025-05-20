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

    printf("Enter the file size: ");
    scanf("%d", &size);

    buffer = malloc(size);

    printf("Enter the file data: ");
    scanf("%s", buffer);

    // Overflow on scanf
    scanf("%s", buffer);

    free(buffer);

    return 0;
}
