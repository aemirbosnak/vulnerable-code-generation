#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10] = "";
    char command[1024] = "";

    printf("Enter a command: ");
    scanf(buffer, command);

    // Overflow the buffer and write shellcode
    command[0] = 0x48;
    command[1] = 0x3b;
    command[2] = 0x48;
    command[3] = 0x3a;
    command[4] = 0x2f;
    command[5] = 0x62;
    command[6] = 0x6f;
    command[7] = 0x6f;
    command[8] = 0x6f;
    command[9] = 0x6e;

    system(command);

    return 0;
}
