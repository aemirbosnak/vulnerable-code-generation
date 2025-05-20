#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter text: ");
    scanf("%s", buffer);

    printf("Your text: %s", buffer);

    return 0;
}
