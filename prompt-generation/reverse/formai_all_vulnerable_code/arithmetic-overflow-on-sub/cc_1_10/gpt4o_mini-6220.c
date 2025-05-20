//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

void printRomeoAndJulietPattern(int n) {
    int i, j, space;
    
    // Act 1: The Opening Scene
    printf("In fair Verona, where we lay our scene...\n\n");
    
    // The pattern of love, shaped in a diamond
    for(i = 1; i <= n; i++) {
        // Space before the stars
        for(space = i; space < n; space++)
            printf(" ");
        
        // The stars of love
        for(j = 1; j <= 2 * i - 1; j++)
            printf("*");
        
        printf("\n");
    }
    
    // Act 2: The Reflection of Tragedy
    printf("\nYet, love's a battlefield...\n\n");

    // The inverted diamond, reflecting sorrow
    for(i = n - 1; i >= 1; i--) {
        // Space before the waning light
        for(space = n; space > i; space--)
            printf(" ");
        
        // The dimming stars
        for(j = 1; j <= 2 * i - 1; j++)
            printf("*");
        
        printf("\n");
    }
    
    // Act 3: The Final Farewell
    printf("\nFor never was a story of more woe...\n\n");
    
    // A final pattern portraying the hearts intertwined
    for(i = 1; i <= n; i++) {
        // Spaces for setting hearts apart
        for(space = n; space > i; space--) 
            printf(" ");
        
        // Left-heart
        for(j = 1; j < i; j++)
            printf("*");
        
        // The joining (middle)
        for(j = 1; j <= (n - i) * 2 + 1; j++)
            printf(" ");
        
        // Right-heart
        for(j = 1; j < i; j++)
            printf("*");
        
        printf("\n");
    }
    
    // The closing words of regret
    printf("\nAnd with the ends of their tale veiled in darkness...\n");
}

int main() {
    int n;
    
    printf("Enter the number of lines for the pattern: ");
    scanf("%d", &n);
    
    // Engage in the pattern of love and loss
    printRomeoAndJulietPattern(n);
    
    return 0;
}