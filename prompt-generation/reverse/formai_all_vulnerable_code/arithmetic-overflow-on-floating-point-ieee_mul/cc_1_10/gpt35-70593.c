//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Write a function to calculate euclidean distance between two data points
float euclideanDistance(float age1, float income1, float age2, float income2) {
    float distance;
    distance = sqrt(pow((age2 - age1), 2) + pow((income2 - income1), 2));
    return distance;
}

int main(void) {

    // Initialize dataset with sample values
    float dataset[6][3] = {{22, 20000, 1},
                           {25, 24000, 0},
                           {32, 45000, 1},
                           {27, 26000, 0},
                           {35, 50000, 1},
                           {28, 28000, 0}};
    // Define the target data point to predict
    float new_data[2] = {30, 48000};

    // Define the number of nearest neighbors to consider (K value)
    int k = 3;

    // Calculate euclidean distance between the new data point and all points in the dataset
    float distances[6];
    for (int i=0; i<6; i++) {
        distances[i] = euclideanDistance(new_data[0], new_data[1], dataset[i][0], dataset[i][1]);
    }

    // Sort the distances in ascending order and get the indices of the k-nearest neighbors
    int indices[6] = {0, 1, 2, 3, 4, 5};
    for (int i=0; i<6; i++) {
        for (int j=i+1; j<6; j++) {
            if (distances[i] > distances[j]) {
                float temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
                int temp_index = indices[i];
                indices[i] = indices[j];
                indices[j] = temp_index;
            }
        }
    }

    // Count the number of target values (1 or 0) among the k-nearest neighbors
    int count_1 = 0, count_0 = 0;
    for (int i=0; i<k; i++) {
        if (dataset[indices[i]][2] == 1) {
            count_1++;
        } else {
            count_0++;
        }
    }

    // Predict the target value based on the majority value among the k-nearest neighbors
    int prediction;
    if (count_1 > count_0) {
        prediction = 1;
    } else {
        prediction = 0;
    }

    // Print the predicted target value
    printf("Based on the data points provided, the person with age %.0f and income $%.2f is predicted to%s buy a car.\n",
           new_data[0], new_data[1], prediction ? "" : " not");

    return 0;
}