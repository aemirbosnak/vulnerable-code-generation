//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

void printTriangle(int n, char playerSymbol) {
    printf("Player %c's Triangle Pattern:\n", playerSymbol);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", playerSymbol);
        }
        printf("\n");
    }
}

void printSquare(int n, char playerSymbol) {
    printf("Player %c's Square Pattern:\n", playerSymbol);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", playerSymbol);
        }
        printf("\n");
    }
}

void printDiamond(int n, char playerSymbol) {
    printf("Player %c's Diamond Pattern:\n", playerSymbol);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2*i-1); j++) {
            printf("%c", playerSymbol);
        }
        printf("\n");
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2*i-1); j++) {
            printf("%c", playerSymbol);
        }
        printf("\n");
    }
}

int main() {
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    
    char playerSymbols[numPlayers];
    int playerChoices[numPlayers];
    int size;

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter symbol for Player %d: ", i + 1);
        scanf(" %c", &playerSymbols[i]);
        printf("Choose a pattern for Player %d (1: Triangle, 2: Square, 3: Diamond): ", i + 1);
        scanf("%d", &playerChoices[i]);
        printf("Enter size for Player %d's pattern: ", i + 1);
        scanf("%d", &size);
    }

    printf("\nGenerating Patterns...\n");
    for (int i = 0; i < numPlayers; i++) {
        switch (playerChoices[i]) {
            case 1:
                printTriangle(size, playerSymbols[i]);
                break;
            case 2:
                printSquare(size, playerSymbols[i]);
                break;
            case 3:
                printDiamond(size, playerSymbols[i]);
                break;
            default:
                printf("Player %c chose an invalid option!\n", playerSymbols[i]);
                break;
        }
        printf("\n");
    }

    return 0;
}