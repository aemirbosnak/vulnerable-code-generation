//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// function to calculate euclidean distance between two points
float euclideanDistance(float* point1, float* point2, int dim)
{
    float distance = 0;
    for(int i = 0; i < dim; i++)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

// function to classify image based on KNN
void classifyImage(float* image, int dimension, int* labels, int* labelCount, int k, float* testPoint)
{
    float distances[k];
    int i;

    // calculate distances between test point and all points in the image
    for(i = 0; i < k; i++)
    {
        distances[i] = euclideanDistance(image, testPoint, dimension);
    }

    // get the index of the k nearest points
    int nearestIndices[k];
    for(i = 0; i < k; i++)
    {
        nearestIndices[i] = 0;
        for(int j = 0; j < *labelCount; j++)
        {
            if(distances[i] < distances[nearestIndices[i]])
            {
                nearestIndices[i] = j;
            }
        }
    }

    // get the label of the k nearest points
    for(i = 0; i < k; i++)
    {
        *labels = labels[nearestIndices[i]];
    }
}

int main()
{
    float image[200][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}, {5, 5, 5}};
    float testPoint[3] = {6, 6, 6};
    int labels[5] = {1, 2, 3, 4, 5};
    int labelCount = 5;
    int k = 2;

    classifyImage(image, 3, labels, &labelCount, k, testPoint);

    printf("The classification result is %d\n", *labels);
    return 0;
}