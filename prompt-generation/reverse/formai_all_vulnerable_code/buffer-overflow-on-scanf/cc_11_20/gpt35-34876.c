//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    char filename[100], data[1000];
    int num_lines = 0, num_cols = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error opening file. Please check the filename and try again.");
        exit(1);
    }

    // Count the number of lines and columns in the CSV file
    while (fgets(data, 1000, fptr) != NULL)
    {
        num_lines++;
        if (num_lines == 1)
        {
            // The first line of the CSV file contains column headers
            char *token = strtok(data, ",");
            while (token != NULL)
            {
                num_cols++;
                token = strtok(NULL, ",");
            }
        }
    }

    // Allocate memory for a 2D array to hold the data
    double **arr = malloc(num_lines * sizeof(double *));
    for (int i = 0; i < num_lines; i++)
    {
        arr[i] = malloc(num_cols * sizeof(double));
    }

    // Reset file pointer to beginning of file
    fseek(fptr, 0, SEEK_SET);

    int row = 0, col = 0;
    // Read the data from the CSV file into the 2D array
    while (fgets(data, 1000, fptr) != NULL)
    {
        char *token = strtok(data, ",");
        col = 0;
        while (token != NULL)
        {
            arr[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    // Perform data mining on the array
    double sum = 0, max = arr[0][0], min = arr[0][0];
    for (int i = 0; i < num_lines; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            sum += arr[i][j];
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    double avg = sum / (num_lines * num_cols);

    printf("The maximum value in the data set is %lf\n", max);
    printf("The minimum value in the data set is %lf\n", min);
    printf("The average value in the data set is %lf\n", avg);

    // Free memory
    for (int i = 0; i < num_lines; i++)
    {
        free(arr[i]);
    }
    free(arr);
    fclose(fptr);

    return 0;
}