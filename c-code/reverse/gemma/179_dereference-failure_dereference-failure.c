#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[256];
    FILE *fp;
    long int data_size;
    char data[1024];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    data_size = fread(data, 1, 1024, fp);
    fclose(fp);

    if (data_size == 0)
    {
        printf("File is empty\n");
        exit(1);
    }

    // Remove spaces and null characters from the data
    data[data_size - 1] = '\0';
    data_size--;

    // Print the recovered data
    printf("Data recovered:\n");
    for (int i = 0; i < data_size; i++)
    {
        printf("%c ", data[i]);
    }

    printf("\n");

    return 0;
}
