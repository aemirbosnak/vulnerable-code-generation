#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char data[1024];
    size_t read_size = fread(data, 1, 1024, fp);
    fclose(fp);

    if (read_size > 0)
    {
        printf("Data recovered: %s", data);
    }
    else
    {
        printf("No data recovered");
    }

    return 0;
}
