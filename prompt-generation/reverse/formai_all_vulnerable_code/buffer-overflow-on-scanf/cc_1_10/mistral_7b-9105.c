//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEIGHT 6
#define WIDTH 13

typedef struct {
    char symbol;
    int x, y;
} HeartPoint;

void print_heart(char name, int size) {
    int i;
    HeartPoint points[12];

    for (i = 0; i < 12; i++) {
        if (i < 6) {
            points[i].symbol = 'O';
            points[i].x = i + 1;
            points[i].y = size / 2 + (i < 3 ? i : -(i - 3));
        } else {
            points[i].symbol = 'O';
            points[i].x = size + 1 - i;
            points[i].y = size / 2 + (i - 6);
        }
    }

    for (i = 0; i < 12; i++) {
        if (i < 6) {
            if (name && points[i].x <= name % 26 + 'A' &&
                points[i].x >= name % 26 &&
                points[i].y >= size / 2 &&
                points[i].y <= size / 2 + size % 2) {
                printf("%c", points[i].symbol);
            }
        } else {
            if (name && points[i].x <= name % 26 + 'A' &&
                points[i].x >= name % 26 &&
                points[i].y >= size / 2 + size - 1 &&
                points[i].y <= size / 2 + size) {
                printf("%c", points[i].symbol);
            }
        }

        if (i < 11)
            printf("%c", name % 26 + 'A');
    }
    printf("\n");
}

int main() {
    char name[30];
    int size;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter size: ");
    scanf("%d", &size);

    if (size % 2 == 0) {
        printf("Size must be odd.\n");
        return 1;
    }

    print_heart(name[0], size);

    return 0;
}