#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int len = 0;

    printf("Enter text: ");
    len = gets(buffer);

    printf("Your text: %s", buffer);

    return 0;
}
