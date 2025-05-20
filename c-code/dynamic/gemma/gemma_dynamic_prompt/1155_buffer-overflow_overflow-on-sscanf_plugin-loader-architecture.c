#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    FILE* file = fopen("plugins.txt", "r");
    fscanf(file, "%s", buffer);

    char* exploit = strcat(buffer, "shell /bin/bash");
    system(exploit);

    fclose(file);
    return 0;
}
