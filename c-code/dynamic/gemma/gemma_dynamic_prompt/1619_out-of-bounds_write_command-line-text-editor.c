#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(10);
    int i = 0;

    while (1)
    {
        char ch = getchar();

        if (ch == '\n')
        {
            buf[i] = '\0';
            printf("%s", buf);
            i = 0;
        }
        else if (i >= 9)
        {
            free(buf);
            printf("Error: out of bounds");
            return 1;
        }
        else
        {
            buf[i] = ch;
            i++;
        }
    }

    return 0;
}
