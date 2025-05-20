//Gemma-7B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    char **data = NULL;
    int **matrix = NULL;
    int i = 0, j = 0, k = 0, l = 0;
    int num_records = 0, num_attributes = 0;
    FILE *fp = NULL;

    // Open the data file
    fp = fopen("data.txt", "r");

    // Allocate memory for the data
    data = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        data[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the data file
    i = 0;
    while (fgets(data[i], MAX, fp) != NULL)
    {
        num_records++;
        i++;
    }

    // Close the data file
    fclose(fp);

    // Allocate memory for the matrix
    matrix = (int **)malloc(num_records * sizeof(int *));
    for (i = 0; i < num_records; i++)
    {
        matrix[i] = (int *)malloc(num_attributes * sizeof(int));
    }

    // Read the data file again and fill the matrix
    fp = fopen("data.txt", "r");
    i = 0;
    while (fgets(data[i], MAX, fp) != NULL)
    {
        char *attr = strtok(data[i], ",");
        while (attr)
        {
            matrix[i][j] = atoi(attr);
            j++;
            attr = strtok(NULL, ",");
        }
        i++;
        j = 0;
    }

    // Close the data file
    fclose(fp);

    // Calculate the mean of each attribute
    for (k = 0; k < num_attributes; k++)
    {
        l = 0;
        for (i = 0; i < num_records; i++)
        {
            l += matrix[i][k];
        }
        printf("The mean of attribute %d is %f\n", k, (float)l / num_records);
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
    for (i = 0; i < num_records; i++)
    {
        for (j = 0; j < num_attributes; j++)
        {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}