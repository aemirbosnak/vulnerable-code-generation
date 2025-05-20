//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

void printHollowDiamond(int n) {
    int i, j, space;
    // Upper part of diamond
    for(i = 1; i <= n; i++) {
        // Print spaces
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars and hollow spaces
        for(j = 1; j <= 2 * i - 1; j++) {
            if(j == 1 || j == 2 * i - 1) // First and last star of the row
                printf("*");
            else
                printf(" "); // Hollow space
        }
        printf("\n"); // Move to the next line
    }
    
    // Lower part of diamond
    for(i = n - 1; i >= 1; i--) {
        // Print spaces
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars and hollow spaces
        for(j = 1; j <= 2 * i - 1; j++) {
            if(j == 1 || j == 2 * i - 1) // First and last star of the row
                printf("*");
            else
                printf(" "); // Hollow space
        }
        printf("\n"); // Move to the next line
    }
}

int main() {
    int height;

    printf("Enter the height of the diamond: ");
    scanf("%d", &height);

    if (height < 1) {
        printf("Height must be at least 1.\n");
        return 1;
    }

    printHollowDiamond(height);

    return 0;
}