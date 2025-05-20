//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    s[i++] = n % 10 + '0';
    while (n / 10)
    {
        s[i++] = (n / 10) % 10 + '0';
        n /= 10;
    }
    s[i] = '\0';
}

int main()
{
    int r;
    char *a = malloc(100);
    printf("Enter image file path: ");
    scanf("%s", a);

    FILE *f = fopen(a, "r");
    if (f)
    {
        unsigned char *data = malloc(1000);
        int w, h;
        fscanf(f, "%d %d", &w, &h);
        fread(data, w * h, 1, f);

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                int pixel = data[x + y * w];
                itoa(pixel, a);
                printf("%s ", a);
            }
            printf("\n");
        }

        fclose(f);
        free(data);
    }
    else
    {
        printf("Error opening file.\n");
    }
    free(a);

    return 0;
}