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

    fp = fopen("audio.wav", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fscanf(fp, "%s", buffer);

    fclose(fp);

    return 0;
}
