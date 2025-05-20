//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
#include<stdio.h>

int main()
{
    int i, j, rows, cols;
    float data[100][100], mean, sd, sum = 0;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    printf("Enter the data:\n");
    
    // Taking input from user
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%f", &data[i][j]);
        }
    }
    
    // Calculating mean
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sum += data[i][j];
        }
    }
    
    mean = sum / (rows * cols);
    
    // Calculating standard deviation
    sum = 0;
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sum += (data[i][j] - mean) * (data[i][j] - mean);
        }
    }
    
    sd = sqrt(sum / (rows * cols));
    
    printf("Mean = %0.2f\nStandard Deviation = %0.2f", mean, sd);
    
    return 0;
}