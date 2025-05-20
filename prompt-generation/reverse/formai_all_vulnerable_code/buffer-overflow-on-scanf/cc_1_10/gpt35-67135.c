//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

int main() {
    char filename[100], buffer[1000];
    int row = 0, col = 0;
    double data[MAX_ROWS][MAX_COLS];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read csv file and store data in 2D array
    while (fgets(buffer, 1000, fp) != NULL) {
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            data[row][col++] = atof(token);
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    // Calculate and print the sum of each row
    printf("Sum of each row:\n");
    for (int i = 0; i < row; i++) {
        double sum = 0.0;
        for (int j = 0; j < col; j++) {
            sum += data[i][j];
        }
        printf("%lf\n", sum);
    }

    // Calculate and print the average of each column
    printf("Average of each column:\n");
    for (int i = 0; i < col; i++) {
        double sum = 0.0;
        for (int j = 0; j < row; j++) {
            sum += data[j][i];
        }
        printf("%lf\n", sum / row);
    }

    fclose(fp);
    return 0;
}