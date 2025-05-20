#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);

    // Overflow on scanf
    char exploit_buffer[512];
    strcpy(exploit_buffer, buffer);

    // Do something with the exploited buffer
    printf("The buffer was exploited: %s", exploit_buffer);

    return 0;
}
