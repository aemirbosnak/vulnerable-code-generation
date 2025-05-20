#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);
    buffer[10] = 'a';
    printf("%s", buffer);
    return 0;
}
