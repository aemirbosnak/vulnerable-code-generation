//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    float *elements;
    int size;
} Vector;

// Function to create a vector
Vector createVector(int size) {
    Vector v;
    v.size = size;
    v.elements = (float *)malloc(size * sizeof(float));
    return v;
}

// Function to free the allocated memory for a vector
void freeVector(Vector *v) {
    free(v->elements);
    v->elements = NULL;
    v->size = 0;
}

// Function to input vector elements from the user
void inputVector(Vector *v) {
    printf("Enter %d elements for the vector:\n", v->size);
    for (int i = 0; i < v->size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &v->elements[i]);
    }
}

// Function to output the vector elements
void outputVector(Vector v) {
    printf("Vector elements are:\n");
    for (int i = 0; i < v.size; i++) {
        printf("Element %d: %.2f\n", i + 1, v.elements[i]);
    }
}

// Function to add two vectors
Vector addVectors(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        fprintf(stderr, "Error: Vectors must be of the same size to add.\n");
        exit(EXIT_FAILURE);
    }
    
    Vector result = createVector(v1.size);
    for (int i = 0; i < v1.size; i++) {
        result.elements[i] = v1.elements[i] + v2.elements[i];
    }
    return result;
}

// Function to subtract two vectors
Vector subtractVectors(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        fprintf(stderr, "Error: Vectors must be of the same size to subtract.\n");
        exit(EXIT_FAILURE);
    }
    
    Vector result = createVector(v1.size);
    for (int i = 0; i < v1.size; i++) {
        result.elements[i] = v1.elements[i] - v2.elements[i];
    }
    return result;
}

// Function to multiply a vector by a scalar
Vector scalarMultiply(Vector v, float scalar) {
    Vector result = createVector(v.size);
    for (int i = 0; i < v.size; i++) {
        result.elements[i] = v.elements[i] * scalar;
    }
    return result;
}

// Function to calculate the dot product of two vectors
float dotProduct(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        fprintf(stderr, "Error: Vectors must be of the same size to calculate dot product.\n");
        exit(EXIT_FAILURE);
    }
    
    float product = 0;
    for (int i = 0; i < v1.size; i++) {
        product += v1.elements[i] * v2.elements[i];
    }
    return product;
}

// Function to calculate the magnitude of a vector
float vectorMagnitude(Vector v) {
    return sqrt(dotProduct(v, v));
}

// Function to normalize a vector
Vector normalize(Vector v) {
    float magnitude = vectorMagnitude(v);
    if (magnitude == 0) {
        fprintf(stderr, "Error: Cannot normalize a zero-length vector.\n");
        exit(EXIT_FAILURE);
    }
    
    Vector result = scalarMultiply(v, 1.0 / magnitude);
    return result;
}

int main() {
    int size;
    printf("Enter the size of the vectors (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        fprintf(stderr, "Error: Invalid vector size.\n");
        return EXIT_FAILURE;
    }

    Vector vector1 = createVector(size);
    Vector vector2 = createVector(size);
    
    inputVector(&vector1);
    inputVector(&vector2);
    
    outputVector(vector1);
    outputVector(vector2);

    Vector sum = addVectors(vector1, vector2);
    Vector difference = subtractVectors(vector1, vector2);
    float scalar = 2.5;
    Vector scaledVec1 = scalarMultiply(vector1, scalar);
    float dotProd = dotProduct(vector1, vector2);
    Vector normalizedVec1 = normalize(vector1);
    
    printf("\nSum of vectors:\n");
    outputVector(sum);
    
    printf("\nDifference of vectors:\n");
    outputVector(difference);
    
    printf("\nVector 1 scaled by %.2f:\n", scalar);
    outputVector(scaledVec1);
    
    printf("\nDot product of the vectors: %.2f\n", dotProd);
    
    printf("\nNormalized Vector 1:\n");
    outputVector(normalizedVec1);

    freeVector(&vector1);
    freeVector(&vector2);
    freeVector(&sum);
    freeVector(&difference);
    freeVector(&scaledVec1);
    freeVector(&normalizedVec1);
    
    return EXIT_SUCCESS;
}