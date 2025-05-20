//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Struct definition for Data
typedef struct Data
{
    double x;
    double y;
    double z;
    int label;
} Data;

// Function that reads data from a file and returns an array of Data
Data* readDataFromFile(FILE* dataFile, int numDataPoints)
{
    // Allocate memory for the array of data
    Data* dataPoints = (Data*) calloc(numDataPoints, sizeof(Data));

    // Read each line of the file and populate the Data array
    for (int i = 0; i < numDataPoints; i++)
    {
        fscanf(dataFile, "%lf %lf %lf %d", &(dataPoints[i].x), &(dataPoints[i].y), 
                                                &(dataPoints[i].z), &(dataPoints[i].label));
    }

    return dataPoints;
}

int main()
{
    // Open the file containing the data
    FILE* dataFile = fopen("data.txt", "r");

    // Get the number of data points from the user
    int numDataPoints;
    printf("Enter the number of data points: ");
    scanf("%d", &numDataPoints);

    // Read the data from the file into an array of Data
    Data* dataPoints = readDataFromFile(dataFile, numDataPoints);

    // Close the file
    fclose(dataFile);

    // Process the data to compute the maximum value of Z for each label
    double maxZ[3] = {-999.0, -999.0, -999.0};
    for (int i = 0; i < numDataPoints; i++)
    {
        int curLabel = dataPoints[i].label;
        if (dataPoints[i].z > maxZ[curLabel])
        {
            maxZ[curLabel] = dataPoints[i].z;
        }
    }

    // Print out the results
    printf("Max Z values:\n");
    printf("   Label 0: %.2lf\n", maxZ[0]);
    printf("   Label 1: %.2lf\n", maxZ[1]);
    printf("   Label 2: %.2lf\n", maxZ[2]);

    // Free the array of data points
    free(dataPoints);

    return 0;
}