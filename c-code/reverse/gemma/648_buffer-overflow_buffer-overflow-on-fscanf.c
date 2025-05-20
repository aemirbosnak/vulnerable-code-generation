#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("image.pgm", "r");
    fscanf(file, "PGM %d %d %d\n", NULL, NULL, NULL);
    int width, height, max_value;
    fscanf(file, "%d %d %d", &width, &height, &max_value);

    char buffer[1024];
    fscanf(file, "%s", buffer);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_value = atoi(buffer);
            printf("%c", pixel_value > max_value ? ' ' : '.');
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
