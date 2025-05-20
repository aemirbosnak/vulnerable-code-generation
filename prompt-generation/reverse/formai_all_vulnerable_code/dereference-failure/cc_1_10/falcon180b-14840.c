//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Function to generate a random number between 0 and 1
double randDouble() {
    return rand() / (double)RAND_MAX;
}

// Function to generate a random vector with n components
void randVector(double* v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = randDouble();
    }
}

// Function to calculate the dot product of two vectors
double dotProduct(double* v1, double* v2, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to calculate the length of a vector
double vectorLength(double* v, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += v[i] * v[i];
    }
    return sqrt(result);
}

// Function to calculate the cosine similarity between two vectors
double cosineSimilarity(double* v1, double* v2, int n) {
    double dotProductResult = dotProduct(v1, v2, n);
    double lengthV1 = vectorLength(v1, n);
    double lengthV2 = vectorLength(v2, n);
    return dotProductResult / (lengthV1 * lengthV2);
}

int main() {
    int n = 10;
    double* v1 = (double*)malloc(n * sizeof(double));
    double* v2 = (double*)malloc(n * sizeof(double));
    randVector(v1, n);
    randVector(v2, n);
    double cosineSimilarityResult = cosineSimilarity(v1, v2, n);
    printf("Cosine Similarity: %lf\n", cosineSimilarityResult);
    free(v1);
    free(v2);
    return 0;
}