//FormAI DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>

/* Define structures for the dataset */
typedef struct {
    float x;
    float y;
    float z;
} DataPoint;

/* Define a function that reads in the dataset from a file 
   and stores it in an array of DataPoint structures */
DataPoint* readData(char* filename, int size) {
    DataPoint* data = (DataPoint*)malloc(size * sizeof(DataPoint));
    FILE* fp = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%f %f %f", &(data[i].x), &(data[i].y), &(data[i].z));
    }
    fclose(fp);
    return data;
}

/* Define a function that calculates the average of an array of data */
float calcAverage(float* data, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / (float)size;
}

/* Define a function that calculates the covariance between two arrays of data */
float calcCovariance(float* x, float* y, int size) {
    float sum = 0.0;
    float avgX = calcAverage(x, size);
    float avgY = calcAverage(y, size);
    for (int i = 0; i < size; i++) {
        sum += (x[i] - avgX) * (y[i] - avgY);
    }
    return sum / (float)size;
}

/* Define the main function */
int main() {
    int size = 10;
    DataPoint* data = readData("data.txt", size);

    /* Calculate the covariance between x and y */
    float* x = (float*)malloc(size * sizeof(float));
    float* y = (float*)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        x[i] = data[i].x;
        y[i] = data[i].y;
    }
    float covXY = calcCovariance(x, y, size);
    printf("Covariance between x and y: %f\n", covXY);

    /* Calculate the covariance between x and z */
    float* z = (float*)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        z[i] = data[i].z;
    }
    float covXZ = calcCovariance(x, z, size);
    printf("Covariance between x and z: %f\n", covXZ);

    free(data);
    free(x);
    free(y);
    free(z);
    return 0;
}