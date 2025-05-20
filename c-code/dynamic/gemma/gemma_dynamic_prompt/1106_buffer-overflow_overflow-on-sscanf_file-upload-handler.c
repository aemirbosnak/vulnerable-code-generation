#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE *fp;

    fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("Enter data: ");
    scanf("%s", buffer);

    fprintf(fp, "%s", buffer);
    fclose(fp);

    return 0;
}
