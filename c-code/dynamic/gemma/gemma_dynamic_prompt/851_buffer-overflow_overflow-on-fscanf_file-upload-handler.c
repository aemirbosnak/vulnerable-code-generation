#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter file name: ");
    scanf("%s", buffer);

    FILE *fp = fopen(buffer, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%s", buffer);
    fclose(fp);

    printf("File content: %s\n", buffer);

    return 0;
}
