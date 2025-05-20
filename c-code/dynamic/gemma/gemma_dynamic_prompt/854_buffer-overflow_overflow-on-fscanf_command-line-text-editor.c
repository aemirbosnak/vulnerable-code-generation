#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    char cmd[1024];

    printf("Enter command: ");
    scanf("%s", cmd);

    if (strcmp(cmd, "edit") == 0)
    {
        printf("Enter text: ");
        scanf("%[^\n]%*c", buf);

        // Overflow the buffer
        buf[1023] = 'A';

        printf("Text: %s\n", buf);
    }

    return 0;
}
