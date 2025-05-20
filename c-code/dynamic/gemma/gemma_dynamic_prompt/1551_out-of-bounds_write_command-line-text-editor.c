#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    int i = 0;

    printf("Enter text: ");
    fgets(buf, 1024, stdin);

    // Write beyond the buffer bounds
    buf[i] = '\0';
    printf("Modified text: %s", buf);

    return 0;
}
