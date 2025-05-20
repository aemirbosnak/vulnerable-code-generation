#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[100];
    char input[1024];

    printf("Enter image file path: ");
    scanf("%s", input);

    // Buffer overflow vulnerability - exploiting the sscanf format string vulnerability
    sprintf(buffer, "cat %s", input);
    system(buffer);

    return 0;
}
