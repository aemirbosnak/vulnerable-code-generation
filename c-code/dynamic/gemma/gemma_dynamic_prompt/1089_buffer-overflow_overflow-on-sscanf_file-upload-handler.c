#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char *p = buffer;
    int n;

    printf("Enter file data: ");
    scanf("%s", buffer);

    n = strlen(buffer) + 1;
    p = realloc(buffer, n);

    printf("File data: %s", p);

    return 0;
}
