#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char data[100];

    printf("Enter data: ");
    scanf("%s", buffer);

    // Overflow on scanf
    if (strlen(buffer) > 10)
    {
        memcpy(data, buffer, 100);
    }

    printf("Data received: %s", data);

    return 0;
}
