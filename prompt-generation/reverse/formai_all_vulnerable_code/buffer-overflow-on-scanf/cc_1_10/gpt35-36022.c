//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Romeo and Juliet Pixel Art Generator
    printf("+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|R|o|m|e|o| |&| |J|u|l|i|e|t|\n");
    printf("+-+-+-+-+-+-+-+-+-+-+\n\n");

    int n, m;
    printf("Enter the size of the art (between 5 to 20): ");
    scanf("%d", &n);
    if (n > 20 || n < 5) {
        printf("Invalid size, please try again.\n");
        return 0;
    }
    m = n;

    // Initialize art array
    int art[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            art[i][j] = 0;
        }
    }

    // Draw Romeo
    art[1][1] = 1;
    art[1][3] = 1;
    art[1][5] = 1;
    art[2][2] = 1;
    art[2][4] = 1;
    art[3][3] = 1;
    art[4][2] = 1;
    art[4][4] = 1;
    art[5][1] = 1;
    art[5][3] = 1;
    art[5][5] = 1;

    // Draw Juliet
    art[1][m-6] = 2;
    art[1][m-4] = 2;
    art[1][m-2] = 2;
    art[2][m-5] = 2;
    art[2][m-3] = 2;
    art[3][m-4] = 2;
    art[4][m-5] = 2;
    art[4][m-3] = 2;
    art[5][m-6] = 2;
    art[5][m-4] = 2;
    art[5][m-2] = 2;

    // Print the art
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (art[i][j] == 1) {
                printf("R");
            } else if (art[i][j] == 2) {
                printf("J");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}