//FormAI DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

// Function to print C pattern
void printC(int height, int width) {

    // Upper part of C
    for (int i = 0; i < height; i++) {
        printf("*");
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Lower part of C
    for (int i = 0; i < height; i++) {
        printf("*");
        for (int j = 0; j < width-1; j++) {
            if (i == 0 || i == height-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {

    printf("\n\tLinus Torvalds Style C Pattern Printing Example Program\n\n");
    
    int height, width;
    printf("Enter the height of C (must be greater than 4): ");
    scanf("%d", &height);
    printf("Enter the width of C (must be greater than 2): ");
    scanf("%d", &width);

    // Validate input
    if (height < 5 || width < 3) {
        printf("\n\tInvalid input. Minimum height is 5 and minimum width is 3.\n");
        return 0;
    }

    // Call function to print C pattern
    printC(height, width);

    return 0;
}