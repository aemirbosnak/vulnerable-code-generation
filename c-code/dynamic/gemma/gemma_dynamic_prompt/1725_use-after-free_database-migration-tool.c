#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = malloc(1024);
    printf("Enter the name of the database file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char *data = malloc(1024);
    int data_size = 0;
    while (fgets(data, 1024, fp) != NULL)
    {
        data_size++;
    }

    fclose(fp);

    printf("The file %s has %d lines of data.", filename, data_size);

    return 0;
}
