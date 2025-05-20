#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[1024];

    printf("Enter text: ");
    scanf("%s", buf);

    printf("Your text: %s", buf);

    return 0;
}
