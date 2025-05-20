#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    char *pbuffer = buffer;

    printf("Enter file data: ");
    scanf("%s", pbuffer);

    // Overflow the buffer
    pbuffer += 1024;
    *pbuffer = '\0';

    printf("File data: %s", buffer);

    return 0;
}
