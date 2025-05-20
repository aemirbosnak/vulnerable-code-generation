#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(1024);
    int len = 0;

    while (1)
    {
        char cmd[1024];

        printf("$ ");
        scanf("%s", cmd);

        if (strcmp(cmd, "exit") == 0)
            break;

        if (len + strlen(cmd) >= 1024)
        {
            printf("Error: buffer overflow.\n");
            continue;
        }

        strcpy(buf + len, cmd);
        len += strlen(cmd) + 1;
    }

    free(buf);
    return 0;
}
