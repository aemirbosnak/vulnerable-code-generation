//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the C Pattern printing program!\n");
    printf("This program will dazzle you with its pattern-making abilities.\n");
    printf("Do you like triangles? Of course you do! Everyone loves triangles.\n");
    printf("So let's start with a basic right triangle, shall we?\n\n");

    int height;
    printf("Enter the height of the triangle: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nWow, wasn't that amazing? But we're just getting started!\n");
    printf("Next up is a diamond. Yes, you heard that right: a diamond!\n");
    printf("It's like two triangles put together. Mind-blowing stuff.\n\n");

    int half = height / 2;
    int space = half - 1;

    for (int i = 1; i <= half; i++) {
        for (int j = 1; j <= space; j++) {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
        space--;
    }
    
    space = 1;

    for (int i = half + 1; i <= height; i++) {
        for (int j = 1; j <= space; j++) {
            printf("  ");
        }
        for (int j = 1; j <= 2 * (height - i) + 1; j++) {
            printf("* ");
        }
        printf("\n");
        space++;
    }

    printf("\nUnbelievable, right? Who knew C programming could create such beauty?\n");
    printf("But we're not done yet. The pièce de résistance is still to come.\n");
    printf("Are you ready for it? Brace yourself for the ultimate pattern...\n\n");

    for (int i = height; i >= 1; i--) {
        for (int j = i; j < height; j++) {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = 2; i <= height; i++) {
        for (int j = i; j < height; j++) {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nTa-da! I bet you didn't know C programming could be so entertaining, did you?\n");
    printf("Hope you had as much fun as I did. Stay tuned for more programming shenanigans!\n");

    return 0;
}