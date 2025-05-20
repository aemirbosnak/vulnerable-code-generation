//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[20];
    printf("Enter image filename: ");
    scanf("%s", filename);
    
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    
    printf("Image file opened successfully!\n");
    
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int image[rows][cols];
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);
    
    printf("Image dimensions: %d x %d\n", rows, cols);
    
    // Image editing code goes here
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot save file\n");
        return 1;
    }
    
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    printf("Image saved successfully!\n");
    
    return 0;
}