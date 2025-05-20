//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

Color colors[MAX_COLORS];

void convert_color(char *color_name, int *r, int *g, int *b, int *a)
{
    int i;

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color_name, colors[i].name) == 0)
        {
            *r = colors[i].r;
            *g = colors[i].g;
            *b = colors[i].b;
            *a = colors[i].a;
            return;
        }
    }

    printf("Error: Color not found.\n");
    exit(1);
}

int main()
{
    char color_name[20];
    int r, g, b, a;

    printf("Enter color name: ");
    scanf("%s", color_name);

    convert_color(color_name, &r, &g, &b, &a);

    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);
    printf("Alpha: %d\n", a);

    return 0;
}