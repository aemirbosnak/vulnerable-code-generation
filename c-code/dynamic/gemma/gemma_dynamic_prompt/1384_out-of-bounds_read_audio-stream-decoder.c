#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long int offset = -1;
    unsigned char buffer[1024];

    fp = fopen("audio.wav", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read data from the file
    fseek(fp, offset, SEEK_SET);
    fread(buffer, 1, 1024, fp);

    // Play the data
    printf("Playing audio data...\n");
    printf("%s", buffer);

    fclose(fp);

    return 0;
}
