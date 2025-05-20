//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} point;

void print_image(char image[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

void set_pixel(char image[WIDTH][HEIGHT], point p, char color) {
    image[p.y][p.x] = color;
}

int main() {
    char image[WIDTH][HEIGHT] = {0};
    point current_point = {0, 0};
    char color = '*';
    int x, y;

    printf("Pixel Art Generator\n");
    printf("Width: %d, Height: %d\n", WIDTH, HEIGHT);
    printf("Enter coordinates (x y) or (q)uit: ");

    while (scanf("%d%d", &x, &y) == 2) {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            printf("Invalid coordinates\n");
            continue;
        }

        set_pixel(image, (point){x, y}, color);
        current_point = (point){x, y};
        printf("Set pixel at (%d, %d) to %c\n", x, y, color);
        printf("Enter coordinates or (q)uit: ");
    }

    if (getchar() != 'q') {
        while (getchar() != '\n') {}
        printf("Invalid input\n");
    }

    print_image(image);

    return 0;
}