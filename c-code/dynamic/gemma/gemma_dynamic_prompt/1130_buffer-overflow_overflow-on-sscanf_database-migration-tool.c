#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    scanf("%s", buffer);

    // Overflow the buffer and write shellcode
    buffer[99] = 'a';
    buffer[100] = 'A';
    buffer[101] = 'x';
    buffer[102] = 'a';
    buffer[103] = 'p';
    buffer[104] = 'a';
    buffer[105] = 'c';

    printf("The modified buffer is: %s", buffer);

    return 0;
}
