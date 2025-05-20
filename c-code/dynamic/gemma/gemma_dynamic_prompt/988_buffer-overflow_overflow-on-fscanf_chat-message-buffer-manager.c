#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);

    // Overflow on fscanf
    char overflow_data[10000];
    memcpy(overflow_data, buffer, 10000);

    printf("Message received: %s", overflow_data);

    return 0;
}
