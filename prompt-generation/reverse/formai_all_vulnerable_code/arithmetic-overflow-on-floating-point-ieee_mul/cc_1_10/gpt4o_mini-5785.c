//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_SHAPES 3

// Shape types
typedef enum {
    CIRCLE,
    RECTANGLE,
    TRIANGLE
} ShapeType;

// Structure to hold shape data
typedef struct {
    ShapeType type;
    double dimensions[3]; // Used for dimensions (radius or sides)
    double area;
    double perimeter;
} Shape;

// Mutex for synchronized output 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototypes
void* calculate_area_perimeter(void* arg);
double calculate_circle(double radius, double* perimeter);
double calculate_rectangle(double width, double height, double* perimeter);
double calculate_triangle(double a, double b, double c, double* perimeter);
double calculate_triangle_area(double a, double b, double c);

int main() {
    pthread_t threads[NUM_SHAPES];
    Shape shapes[NUM_SHAPES] = {
        {CIRCLE, {5.0}, 0, 0},                      // Circle with radius 5
        {RECTANGLE, {4.0, 6.0}, 0, 0},              // Rectangle with width 4 and height 6
        {TRIANGLE, {3.0, 4.0, 5.0}, 0, 0}           // Triangle with sides 3, 4, and 5
    };

    // Create threads for each shape calculation
    for (int i = 0; i < NUM_SHAPES; i++) {
        if (pthread_create(&threads[i], NULL, calculate_area_perimeter, &shapes[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    // Join threads to ensure they finish before proceeding
    for (int i = 0; i < NUM_SHAPES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output results
    for (int i = 0; i < NUM_SHAPES; i++) {
        pthread_mutex_lock(&mutex);
        printf("Shape %d:\n", i + 1);
        printf(" Type: %s\n", shapes[i].type == CIRCLE ? "Circle" : shapes[i].type == RECTANGLE ? "Rectangle" : "Triangle");
        printf(" Area: %.2f\n", shapes[i].area);
        printf(" Perimeter: %.2f\n\n", shapes[i].perimeter);
        pthread_mutex_unlock(&mutex);
    }

    // Cleanup
    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}

// Function to calculate area and perimeter asynchronously
void* calculate_area_perimeter(void* arg) {
    Shape* shape = (Shape*)arg;
    
    switch (shape->type) {
        case CIRCLE:
            shape->area = M_PI * pow(shape->dimensions[0], 2);
            calculate_circle(shape->dimensions[0], &shape->perimeter);
            break;
        case RECTANGLE:
            shape->area = shape->dimensions[0] * shape->dimensions[1];
            calculate_rectangle(shape->dimensions[0], shape->dimensions[1], &shape->perimeter);
            break;
        case TRIANGLE:
            shape->area = calculate_triangle_area(shape->dimensions[0], shape->dimensions[1], shape->dimensions[2]);
            calculate_triangle(shape->dimensions[0], shape->dimensions[1], shape->dimensions[2], &shape->perimeter);
            break;
    }
    return NULL;
}

double calculate_circle(double radius, double* perimeter) {
    *perimeter = 2 * M_PI * radius;
    return M_PI * pow(radius, 2);
}

double calculate_rectangle(double width, double height, double* perimeter) {
    *perimeter = 2 * (width + height);
    return width * height;
}

double calculate_triangle(double a, double b, double c, double* perimeter) {
    *perimeter = a + b + c;
    return 0; // Area calculation is done separately
}

double calculate_triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2; // semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}