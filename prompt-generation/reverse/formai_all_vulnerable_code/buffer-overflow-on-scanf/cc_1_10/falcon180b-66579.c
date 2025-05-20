//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET ".,:;i1tfL#@8B<>*+-=!&%$?^"

struct point {
    int x;
    int y;
    int c;
};

void draw_ascii(struct point *data, int count) {
    for (int i = 0; i < count; i++) {
        printf("%c", data[i].c);
    }
}

void generate_ascii(char *text) {
    struct point *data = malloc(sizeof(struct point) * strlen(text));
    int count = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            data[count].x = i % WIDTH;
            data[count].y = i / WIDTH;
            data[count].c = CHAR_SET[rand() % strlen(CHAR_SET)];
            count++;
        }
    }

    draw_ascii(data, count);
    free(data);
}

int main() {
    srand(time(NULL));
    printf("ASCII Art Generator\n");
    char text[100];

    while (1) {
        printf("Enter text to generate ASCII art: ");
        scanf("%s", text);
        generate_ascii(text);
        printf("\n");
    }

    return 0;
}