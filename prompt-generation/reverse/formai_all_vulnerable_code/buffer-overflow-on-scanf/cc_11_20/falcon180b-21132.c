//Falcon-180B DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int i, j, n, m;
    char choice;

    printf("Welcome to the Game of Life!\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &n);

    printf("Enter the size of the board (1-100): ");
    scanf("%d", &m);

    printf("Enter the seed number: ");
    scanf("%d", &arr[0]);

    for (i = 1; i < m; i++) {
        arr[i] = 0;
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (arr[i] == 1) {
                if (i > 0 && arr[i - 1] == 1) {
                    arr[i] = 0;
                } else if (i < m - 1 && arr[i + 1] == 1) {
                    arr[i] = 0;
                } else {
                    arr[i] = 1;
                }
            } else {
                if (i > 0 && arr[i - 1] == 1) {
                    arr[i] = 1;
                } else if (i < m - 1 && arr[i + 1] == 1) {
                    arr[i] = 1;
                } else {
                    arr[i] = 0;
                }
            }
        }
    }

    printf("The board is now set up!\n");
    printf("Press any key to start the game.\n");
    scanf("%c", &choice);

    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (arr[i] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}