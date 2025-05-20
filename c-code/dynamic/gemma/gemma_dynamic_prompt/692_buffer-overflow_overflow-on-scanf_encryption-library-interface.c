#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char data[20] = "Secret message";

    printf("Enter a message: ");
    scanf("%s", buffer);

    if (strlen(buffer) > 10)
    {
        printf("Error: buffer overflow!\n");
    }
    else
    {
        strcpy(data, buffer);
        printf("Your message: %s\n", data);
    }

    return 0;
}
