//Gemma-7B DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Create a 2D array to store the data
    int **arr = NULL;
    int rows = 0;
    int cols = 0;

    // Open the file containing the data
    FILE *fp = fopen("data.txt", "r");

    // Read the number of rows and columns from the file
    fscanf(fp, "Number of rows: %d", &rows);
    fscanf(fp, "Number of columns: %d", &cols);

    // Allocate memory for the array
    arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read the data from the file and store it in the array
    int i = 0;
    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        char *p = line;
        int j = 0;
        while (p && *p)
        {
            arr[i][j++] = atoi(p);
            p = strchr(p, ',');
        }
        i++;
    }

    // Close the file
    fclose(fp);

    // Calculate the mean of each column
    int mean[cols];
    for (int i = 0; i < cols; i++)
    {
        mean[i] = 0;
        for (int j = 0; j < rows; j++)
        {
            mean[i] += arr[j][i];
        }
        mean[i] /= rows;
    }

    // Print the mean of each column
    for (int i = 0; i < cols; i++)
    {
        printf("Mean of column %d: %d\n", i + 1, mean[i]);
    }

    // Free the memory allocated for the array
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}