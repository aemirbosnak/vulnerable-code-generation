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
        printf("Error allocating memory\n");
        exit(1);
    }

    printf("Enter text: ");
    scanf("%s", ptr);

    printf("Your text: %s\n", ptr);

    free(ptr);
    return 0;
}
