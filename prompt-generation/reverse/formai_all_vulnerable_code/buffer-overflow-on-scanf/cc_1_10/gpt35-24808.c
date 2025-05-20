//FormAI DATASET v1.0 Category: Image compression ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void compress(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols){
    int i, j;
    int count;
    char curr;
    char prev;
    char compressed[MAX_ROWS][MAX_COLS];
    int compressed_rows = 0;
    int compressed_cols = 0;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            curr = matrix[i][j];
            if(j == 0){
                prev = curr;
                count = 1;
                continue;
            }
            if(curr == prev){
                count++;
            } else {
                compressed[compressed_rows][compressed_cols] = prev;
                compressed_cols++;
                compressed[compressed_rows][compressed_cols] = count + '0';
                compressed_cols++;
                count = 1;
                prev = curr;
            }
        }
        compressed[compressed_rows][compressed_cols] = prev;
        compressed_cols++;
        compressed[compressed_rows][compressed_cols] = count + '0';
        compressed_cols++;
        compressed_rows++;
        compressed_cols = 0;
    }

    printf("Compressed Image:\n");
    for(i = 0; i < compressed_rows; i++){
        for(j = 0; j < cols * 2; j++){
            printf("%c", compressed[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char image[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j;

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);

    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    printf("Enter the image (0 or 1):\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf(" %c", &image[i][j]);
        }
    }

    printf("Original Image:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    compress(image, rows, cols);

    return 0;
}