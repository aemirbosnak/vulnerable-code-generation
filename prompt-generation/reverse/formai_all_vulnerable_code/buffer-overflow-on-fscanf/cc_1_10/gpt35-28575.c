//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readFile(FILE *file, double *data, int n);
double mean(double *data, int n);
double stdDev(double *data, int n, double mean);
double variance(double *data, int n, double mean);

int main()
{
    FILE *file;
    const char *filename = "data.txt";

    int n = 0;
    double *data = NULL;

    // open file for read
    file = fopen(filename, "r");

    // check if file is not NULL
    if (file == NULL)
    {
        printf("Unable to open file %s for read\n", filename);
        return 1;
    }

    // get number of data points from file
    fscanf(file, "%d", &n);

    // allocate memory for data array
    data = (double *)malloc(sizeof(double) * n);

    // read data from file into array
    readFile(file, data, n);

    // close file
    fclose(file);

    // calculate mean, standard deviation and variance of data
    double meanValue = mean(data, n);
    double stdDevValue = stdDev(data, n, meanValue);
    double varianceValue = variance(data, n, meanValue);

    // print results
    printf("Mean   : %lf\n", meanValue);
    printf("StdDev : %lf\n", stdDevValue);
    printf("Variance : %lf\n", varianceValue);

    // free allocated memory
    free(data);

    return 0;
}

void readFile(FILE *file, double *data, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        fscanf(file, "%lf", &data[i]);
    }
}

double mean(double *data, int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum += data[i];
    }

    return sum / n;
}

double stdDev(double *data, int n, double mean)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum += pow(data[i] - mean, 2);
    }

    return sqrt(sum / n);
}

double variance(double *data, int n, double mean)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum += pow(data[i] - mean, 2);
    }

    return sum / n;
}