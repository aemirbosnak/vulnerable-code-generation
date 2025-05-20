#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter file content: ");
    scanf("%s", buffer);

    printf("File content: %s", buffer);

    return 0;
}
