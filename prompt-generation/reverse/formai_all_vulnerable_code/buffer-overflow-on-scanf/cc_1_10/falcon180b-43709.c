//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAX_SIZE 100

struct point {
    int x;
    int y;
};

void draw_pixel(int x, int y, int color) {
    printf("%c%c%c", 27, 91 + color, 48 + x * 3 + y);
}

int main(void) {
    char qrcode[MAX_SIZE];
    int size, i, j, x, y, color;
    struct point *points;

    printf("Enter QR code: ");
    scanf("%s", qrcode);

    size = strlen(qrcode);
    points = (struct point *)malloc(size * sizeof(struct point));

    for (i = 0; i < size; i++) {
        if (qrcode[i] == '1') {
            points[i].x = 0;
            points[i].y = 0;
        }
        else {
            points[i].x = 1;
            points[i].y = 1;
        }
    }

    for (i = 0; i < size; i++) {
        x = points[i].x;
        y = points[i].y;

        draw_pixel(x, y, 1);
        draw_pixel(x, y + 1, 1);
        draw_pixel(x + 1, y + 1, 1);
        draw_pixel(x + 1, y, 1);
    }

    printf("\n");

    return 0;
}