#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    int len = 0;

    printf("Enter text: ");
    gets(buf);

    len = strlen(buf) + 1;
    buf[len - 1] = '\0';

    printf("Your text: %s", buf);

    return 0;
}
