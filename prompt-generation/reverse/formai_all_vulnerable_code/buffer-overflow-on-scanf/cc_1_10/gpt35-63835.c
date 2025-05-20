//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawSquare(int size, char symbol) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

void drawHeart() {
    printf(" ██████████████████████████ \n");
    printf(" ██████████████████████████ \n");
    printf(" ██████████████████████████ \n");
    printf(" ██████████████████████████ \n");
    printf(" ██████████████████████████ \n");
    printf(" ████░░░░░░░░░░░░░░░░░░████ \n");
    printf(" ████░░░░░░░░░░░░░░░░░░████ \n");
    printf(" █████░░░░░░░░░░░░░░░░░████ \n");
    printf(" ██████░░░░░░░░░░░░░░░█████ \n");
    printf(" ████████░░░░░░░░░░░░██████ \n");
    printf(" ██████████████████████████ \n");
    printf("  ████████████████████████  \n");
    printf("   ██████████████████████   \n");
    printf("     ██████████████████     \n");
    printf("       ██████████████       \n");
    printf("         ██████████         \n");
}

int main() {
    int choice;
    srand(time(0));
    
    printf("Welcome to the Pixel Art Generator!\n");
    printf("Choose an option:\n");
    printf("1. Draw a square\n");
    printf("2. Draw a heart\n");
    printf("3. Randomly generate a pixel art with squares\n");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the size of the square (1-10): ");
            int size;
            char symbol;
            scanf("%d", &size);
            printf("Enter a symbol to use: ");
            fflush(stdin);
            scanf("%c", &symbol);
            drawSquare(size, symbol);
            break;
        case 2:
            drawHeart();
            break;
        case 3:
            printf("Enter the size of the image (1-10): ");
            int imageSize;
            char symbols[5] = {'#', '&', '*', '@', '+'};
            scanf("%d", &imageSize);
            for (int i = 0; i < imageSize; i++) {
                for (int j = 0; j < imageSize; j++) {
                    int symbolIndex = rand() % 5;
                    printf("%c ", symbols[symbolIndex]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}