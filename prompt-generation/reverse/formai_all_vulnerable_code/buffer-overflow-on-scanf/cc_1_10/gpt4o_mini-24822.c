//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        // Left spaces
        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        // Print asterisks
        for (int k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDestruction(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int k = rows - i; k > 0; k--) {
            printf("# ");
        }
        printf("\n");
    }
}

void printSurvivorMessage() {
    printf("\n\nIn this world of silence, we stand\n");
    printf("Among the ruins of what once was land.\n");
    printf("Stars above, like distant memories,\n");
    printf("Remind us of our ancient histories.\n");
    printf("\nGunpowder and ash, yet we still shout,\n");
    printf("Through the crumbled cities, we wander about.\n");
    printf("United we survive, in this bleak new tale,\n");
    printf("Against the dark winds, we shall prevail.\n");
}

void printRandomSymbols(int count) {
    char symbols[] = {'@', '#', '$', '%', '^', '&', '*', '!', '~'};
    srand(time(NULL));
    
    for (int i = 0; i < count; i++) {
        int randomIndex = rand() % (sizeof(symbols) / sizeof(symbols[0]));
        printf("%c ", symbols[randomIndex]);
    }
    printf("\n");
}

int main() {
    int height;
    
    printf("The remnants of our world must be honored!\n");
    printf("Enter the height of the pattern (1-15): ");
    scanf("%d", &height);
    
    if (height < 1 || height > 15) {
        printf("Invalid height! Choose a number between 1 and 15.\n");
        return 1;
    }
    
    printf("\nFallen structures are adorned with nature's grace:\n");
    printPattern(height);
    
    printf("\nA dark silhouette looms where shadows once played:\n");
    printDestruction(height);
    
    printSurvivorMessage();
    
    printf("\nIn memory of those lost, we enact a tribute:\n");
    printf("Symbols of survival rise from the ashes:\n");
    printRandomSymbols(height);
    
    printf("\nAs the sun sets, may we discover hope anew.\n");
    printf("For together we forge a future yet unseen.\n");

    return 0;
}