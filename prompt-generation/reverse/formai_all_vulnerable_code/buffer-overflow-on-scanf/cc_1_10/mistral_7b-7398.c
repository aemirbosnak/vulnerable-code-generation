//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEIGHT 10
#define WIDTH 15

void heart(int x, int y, char color) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (j < 5 - i || j > WIDTH - 5 + i || i == 0 || i == HEIGHT - 1)
                printf("%c", color);
            else
                printf(" ");
        }
        printf("\n");
    }

    for (i = 0; i < 2 * WIDTH - 1; i++) {
        if (i > WIDTH - 5 && i < WIDTH + 5)
            printf("%c", color);
        else
            printf(" ");
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i > 0 && i < HEIGHT - 1 && j < 5 - i && j > WIDTH - 5 + i)
                printf("%c", color);
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    char color;
    int size;

    printf("Enter color(R/G/B): ");
    scanf(" %c", &color);
    color = toupper(color);

    printf("Enter size(1-10): ");
    scanf("%d", &size);

    if (size > 10 || size < 1) {
        printf("Invalid size!\n");
        return 1;
    }

    heart(WIDTH / 2 - size / 2, HEIGHT / 2 - size / 2, color);

    return 0;
}