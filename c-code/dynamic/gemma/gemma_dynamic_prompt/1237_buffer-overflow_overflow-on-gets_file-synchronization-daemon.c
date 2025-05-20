#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    char data[1024] = "This is a large amount of data that will cause a buffer overflow";

    gets(buffer);

    if (strlen(buffer) > 1024)
    {
        printf("Error: buffer overflow\n");
    }
    else
    {
        printf("Data received: %s\n", buffer);
    }

    return 0;
}
