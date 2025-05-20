#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = malloc(256);
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Out-of-bounds read vulnerability
    char buffer[1024];
    int read_bytes = fread(buffer, 1, 1024, fp);
    fclose(fp);

    // Print the file data
    printf("File data: ");
    for (int i = 0; i < read_bytes; i++)
    {
        printf("%c", buffer[i]);
    }

    return 0;
}
