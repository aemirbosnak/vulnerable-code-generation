#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    ptr = (char *)malloc(10);
    if (ptr == NULL)
    {
        exit(1);
    }

    printf("Enter text: ");
    scanf("%s", ptr);

    // Deliberate dereference failure
    *(ptr + 10) = 'A';

    printf("Your text: %s", ptr);

    free(ptr);
    return 0;
}
