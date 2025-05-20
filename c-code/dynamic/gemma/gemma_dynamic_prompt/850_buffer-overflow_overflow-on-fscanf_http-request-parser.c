#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter a HTTP request: ");
    scanf("%s", buffer);

    // Exploit buffer overflow vulnerability
    buffer[1023] = 'A';

    printf("Your HTTP request: %s", buffer);

    return 0;
}
