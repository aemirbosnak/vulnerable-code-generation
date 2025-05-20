#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    FILE *file = fopen("secret.txt", "r");

    fscanf(file, "%s", buffer);

    printf("Secret: %s", buffer);

    fclose(file);

    return 0;
}
