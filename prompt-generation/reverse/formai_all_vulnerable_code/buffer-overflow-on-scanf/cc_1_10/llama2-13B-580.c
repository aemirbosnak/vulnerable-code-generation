//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_SIDE 1000

// Structure to store a triangle's data
typedef struct {
    int num_sides;
    int sides[MAX_SIDE];
} triangle_t;

// Function to calculate the perimeter of a triangle
double perimeter(triangle_t *t) {
    int i;
    double perim = 0;
    for (i = 0; i < t->num_sides; i++) {
        perim += t->sides[i];
    }
    return perim;
}

// Function to calculate the area of a triangle
double area(triangle_t *t) {
    int i;
    double area = 0;
    for (i = 0; i < t->num_sides; i++) {
        area += (t->sides[i] * (t->sides[i] + 1)) / 2;
    }
    return area;
}

int main() {
    int i, j, num_triangles;
    triangle_t *triangles;
    double total_perim, total_area;

    // Get the number of triangles from the user
    printf("Enter the number of triangles: ");
    scanf("%d", &num_triangles);

    // Allocate memory for the triangles
    triangles = calloc(num_triangles, sizeof(triangle_t));

    // Read the sides of each triangle from the user
    for (i = 0; i < num_triangles; i++) {
        for (j = 0; j < MAX_SIDE; j++) {
            printf("Enter side %d of triangle %d: ", j, i);
            scanf("%d", &triangles[i].sides[j]);
        }
    }

    // Calculate the perimeter and area of each triangle
    for (i = 0; i < num_triangles; i++) {
        total_perim += perimeter(&triangles[i]);
        total_area += area(&triangles[i]);
    }

    // Print the results
    printf("The total perimeter is: %f\n", total_perim);
    printf("The total area is: %f\n", total_area);

    // Free the memory allocated for the triangles
    free(triangles);

    return 0;
}