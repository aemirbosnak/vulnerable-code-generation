#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter file data: ");
    gets(buffer);

    printf("File data: %s\n", buffer);

    return 0;
}
