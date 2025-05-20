//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
// Welcome to the Shape-Shifting CSV Reader program!
// Please enter the filename of the CSV file you want to read:

#include <stdio.h>

int main() {
    char filename[255];
    printf(">>> ");
    scanf("%s", filename);

    printf("Shape-shifting into the most efficient form...\n");
    printf("Opening and reading CSV file...\n");

    // Let's count the number of rows and columns in the CSV file
    int num_rows = 0;
    int num_cols = 0;

    FILE* fp = fopen(filename, "r");

    char c = getc(fp);
    while (c != EOF) {
        if (c == '\n') {
            num_rows++;
        } else if (c == ',') {
            num_cols++;
        }
        c = getc(fp);
    }
    fclose(fp);

    num_cols++; // Add 1 for the last column

    printf("Identified %d rows and %d columns in the CSV file.\n", num_rows, num_cols);

    // Now let's allocate memory for the CSV data

    double** data = (double**) malloc(num_rows * sizeof(double*));
    for (int i = 0; i < num_rows; i++) {
        data[i] = (double*) malloc(num_cols * sizeof(double));
    }
    
    // Reading the data into the array

    fp = fopen(filename, "r");

    char line[255];
    int row = 0, col = 0;
    double val = 0.0;

    while (fgets(line, 255, fp)) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            sscanf(token, "%lf", &val);
            data[row][col] = val;
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }
    fclose(fp);

    printf("Data shape-shifted and loaded into memory!\n");

    // Now let's display the contents of the CSV file in a table-like format

    printf("CSV file contents:\n");

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%.2lf\t", data[i][j]);
        }
        printf("\n");
    }

    printf("Shape-shifting back to my normal form...done!\n");

    // Finally, let's free up the memory we allocated for the data array
    for (int i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}