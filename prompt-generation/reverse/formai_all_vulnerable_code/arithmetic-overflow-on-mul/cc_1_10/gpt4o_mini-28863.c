//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

void drawTriangle(int level) {
    if (level <= 0) return;

    drawTriangle(level - 1);

    for (int i = 0; i < level; i++)
        printf(" ");
    for (int i = 0; i < 2 * (level - 1) + 1; i++)
        printf("*");
    printf("\n");
}

void drawDiamond(int level) {
    if (level <= 0) return;

    drawDiamond(level - 1);

    for (int i = 0; i < level; i++)
        printf(" ");
    printf("*\n");
}

void drawInvertedTriangle(int level) {
    if (level <= 0) return;

    printf("%s", "\n");
    for (int i = level; i > 0; i--) {
        for (int j = 0; j < level - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

void drawShapes(int shapeType, int levels) {
    if (shapeType < 1 || shapeType > 3 || levels < 1) {
        printf("Invalid shape type/level.\n");
        return;
    }
    
    if (shapeType == 1) {
        printf("Drawing Triangle:\n");
        drawTriangle(levels);
    } else if (shapeType == 2) {
        printf("Drawing Diamond:\n");
        drawDiamond(levels);
    } else if (shapeType == 3) {
        printf("Drawing Inverted Triangle:\n");
        drawInvertedTriangle(levels);
    }
}

int main() {
    int choice, levels;

    printf("Select a shape to draw:\n");
    printf("1. Triangle\n");
    printf("2. Diamond\n");
    printf("3. Inverted Triangle\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
    
    printf("Enter the number of levels: ");
    scanf("%d", &levels);
    
    drawShapes(choice, levels);
    
    return 0;
}