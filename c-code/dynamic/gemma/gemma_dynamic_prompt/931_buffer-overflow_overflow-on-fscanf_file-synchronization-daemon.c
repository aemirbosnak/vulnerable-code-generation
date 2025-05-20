#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    char data[1024];

    fscanf(stdin, "%s", buffer);

    if (strlen(buffer) > 10)
    {
        printf("Error: buffer overflow\n");
        exit(1);
    }

    strcpy(data, buffer);

    printf("Data: %s\n", data);

    return 0;
}
