//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>

int main() {
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    
    // Check if the file is valid
    if (file == NULL) {
        perror("Failed to open the file");
        return -1;
    }
    
    // Declare variables to store data
    int num_rows = 0;
    int num_cols = 0;
    float data[100][100];
    
    // Read data from the file
    fscanf(file, "%d %d", &num_rows, &num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            fscanf(file, "%f", &data[i][j]);
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print the input data
    printf("Input Data:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
    
    // Perform data mining operation
    float max_val = data[0][0];
    float min_val = data[0][0];
    float sum = 0;
    
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }
            if (data[i][j] < min_val) {
                min_val = data[i][j];
            }
            sum += data[i][j];
        }
    }
    
    // Print the analysis results
    printf("Analysis Results:\n");
    printf("Maximum value in the data set : %.2f\n", max_val);
    printf("Minimum value in the data set : %.2f\n", min_val);
    printf("Average value of the data set : %.2f\n", sum / (num_rows * num_cols));
    
    return 0;
}