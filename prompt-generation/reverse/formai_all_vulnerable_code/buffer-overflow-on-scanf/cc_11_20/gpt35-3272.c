//FormAI DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    
    printf("\n\n== QR CODE GENERATOR ==\n\n");
    
    // input data
    char input[50];
    printf("Enter data to be encoded: ");
    scanf("%s", input);
    
    // generate matrix
    int matrix[21][21] = {0};
    int row = 0, col = 20;
    int dir = -1;
    for(int i = 0; i < strlen(input); i++) {
        for(int j = 0; j < 8; j++) {
            int bit = input[i] & (1 << j);
            if(bit > 0) {
                matrix[row][col] = 1;
            }
            if(dir == -1) {
                if(row == 0) {
                    dir = 1;
                    col--;
                } else {
                    row--;
                    col++;
                }
            } else {
                if(row == 20) {
                    dir = -1;
                    col--;
                } else {
                    row++;
                    col++;
                }
            }
        }
    }
    
    // add finder patterns
    for(int i = 0; i < 7; i++) {
        matrix[0][i] = 1;
        matrix[6][i] = 1;
        matrix[14][i] = 1;
        matrix[20][i] = 1;
        matrix[i][0] = 1;
        matrix[i][6] = 1;
        matrix[i][14] = 1;
        matrix[i][20] = 1;
        matrix[20-i][6] = 1;
        matrix[6][20-i] = 1;
    }
    for(int i = 1; i < 6; i++) {
        matrix[3][i] = 1;
        matrix[20-i][3] = 1;
        matrix[17][20-i] = 1;
        matrix[i][17] = 1;
    }
    
    // print matrix as QR code
    printf("\n\nQR code:\n\n");
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            if(matrix[i][j] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}