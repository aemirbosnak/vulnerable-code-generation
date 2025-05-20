//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <math.h>

#define MAX_VECTORS 100
#define MAX_DIMENSIONS 10
#define PI 3.14159265358979323846

typedef struct {
    double elements[MAX_DIMENSIONS];
    int dimension;
} Vector;

// Function to create a vector
Vector create_vector(double elements[], int dimension) {
    Vector vec;
    vec.dimension = dimension;
    for (int i = 0; i < dimension; i++) {
        vec.elements[i] = elements[i];
    }
    return vec;
}

// Function to print a vector
void print_vector(Vector vec) {
    printf("[");
    for (int i = 0; i < vec.dimension; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%lf", vec.elements[i]);
    }
    printf("]\n");
}

// Function to compute the dot product of two vectors
double dot_product(Vector a, Vector b) {
    if (a.dimension != b.dimension) {
        fprintf(stderr, "Vectors must have the same dimension for dot product.\n");
        return -1;
    }
    double result = 0.0;
    for (int i = 0; i < a.dimension; i++) {
        result += a.elements[i] * b.elements[i];
    }
    return result;
}

// Function to compute the magnitude of a vector
double magnitude(Vector vec) {
    return sqrt(dot_product(vec, vec));
}

// Function to compute the angle between two vectors in degrees
double angle_between_vectors(Vector a, Vector b) {
    double dot = dot_product(a, b);
    double mag_a = magnitude(a);
    double mag_b = magnitude(b);
    
    if (mag_a == 0 || mag_b == 0) {
        fprintf(stderr, "One of the vectors has zero magnitude.\n");
        return -1;
    }

    double cos_theta = dot / (mag_a * mag_b);
    double angle_rad = acos(cos_theta);
    return angle_rad * (180.0 / PI); // Convert to degrees
}

// Function to normalize a vector
Vector normalize(Vector vec) {
    double mag = magnitude(vec);
    Vector norm_vec = create_vector(vec.elements, vec.dimension);
    
    if (mag == 0) {
        fprintf(stderr, "Cannot normalize a zero vector.\n");
        return norm_vec; // Return the same vector
    }

    for (int i = 0; i < vec.dimension; i++) {
        norm_vec.elements[i] /= mag;
    }
    return norm_vec;
}

// Main program
int main() {
    int num_vectors, dimension;

    printf("Welcome to the Vector Math Exercise!\n");
    printf("Enter the number of vectors (up to %d): ", MAX_VECTORS);
    scanf("%d", &num_vectors);
    
    if (num_vectors < 1 || num_vectors > MAX_VECTORS) {
        fprintf(stderr, "Invalid number of vectors!\n");
        return 1;
    }

    printf("Enter the dimension for each vector (up to %d): ", MAX_DIMENSIONS);
    scanf("%d", &dimension);

    if (dimension < 1 || dimension > MAX_DIMENSIONS) {
        fprintf(stderr, "Invalid dimension!\n");
        return 1;
    }

    Vector vectors[MAX_VECTORS];

    for (int i = 0; i < num_vectors; i++) {
        printf("Enter the elements for vector %d (space-separated): ", i + 1);
        double elements[MAX_DIMENSIONS];
        for (int j = 0; j < dimension; j++) {
            scanf("%lf", &elements[j]);
        }
        vectors[i] = create_vector(elements, dimension);
    }

    printf("\nYou have entered the following vectors:\n");
    for (int i = 0; i < num_vectors; i++) {
        printf("Vector %d: ", i + 1);
        print_vector(vectors[i]);
    }

    // Calculating angles between each pair of vectors
    printf("\nCalculating angles between each pair of vectors:\n");
    for (int i = 0; i < num_vectors; i++) {
        for (int j = i + 1; j < num_vectors; j++) {
            double angle = angle_between_vectors(vectors[i], vectors[j]);
            if (angle >= 0) {
                printf("Angle between Vector %d and Vector %d: %lf degrees\n", i + 1, j + 1, angle);
            }
        }
    }

    // Normalizing the vectors
    printf("\nNormalized vectors:\n");
    for (int i = 0; i < num_vectors; i++) {
        Vector norm_vec = normalize(vectors[i]);
        printf("Normalized Vector %d: ", i + 1);
        print_vector(norm_vec);
    }

    printf("\nEnd of the program. Thank you for participating!\n");
    return 0;
}