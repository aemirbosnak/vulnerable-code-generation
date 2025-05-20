//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

int main() {
    int height, width;
    char brush;

    printf("Enter the height of the pattern: ");
    scanf("%d", &height);

    printf("Enter the width of the pattern: ");
    scanf("%d", &width);

    printf("Choose a brush character:");
    scanf(" %c", &brush);

    //Top Half of the Pattern
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            if (i + j >= height / 2 && i - j <= height / 2 && i * j % 2 == 0) {    //Medieval c pattern
                printf("%c", brush);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    //Middle Line
    for (int i = 0; i < width / 2; i++) {
        printf(" ");
    }
    printf("%c", brush);
    for (int i = 0; i < width / 2; i++) {
        printf(" ");
    }
    printf("\n");

    //Bottom Half of the Pattern
    for (int i = height / 2 + 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j - i <= height / 2 && i + j <= height * 3 / 2 && i * j % 2 == 0) { //Medieval c pattern
                printf("%c", brush);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}