#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char command[1024];

    printf("Enter command: ");
    scanf("%s", command);

    sprintf(buffer, "filter %s", command);
    system(buffer);

    return 0;
}
