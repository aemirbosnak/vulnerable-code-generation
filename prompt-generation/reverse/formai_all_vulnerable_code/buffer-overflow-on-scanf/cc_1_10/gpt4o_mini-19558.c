//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_CIRCLES 10

// Structure to hold radius and area for each circle
typedef struct {
    double radius;
    double area;
} Circle;

// Array of circles
Circle circles[MAX_CIRCLES];

// Function to calculate the area of a circle
void* calculate_circle_area(void* arg) {
    int index = *((int*)arg);
    double radius = circles[index].radius;
    
    // Area of circle = π * r²
    circles[index].area = M_PI * radius * radius;
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_CIRCLES];
    int thread_args[MAX_CIRCLES];
    int num_circles;

    printf("Enter the number of circles (Max %d): ", MAX_CIRCLES);
    scanf("%d", &num_circles);

    if (num_circles <= 0 || num_circles > MAX_CIRCLES) {
        fprintf(stderr, "Invalid number of circles.\n");
        return EXIT_FAILURE;
    }

    // Get the radius for each circle
    for (int i = 0; i < num_circles; i++) {
        printf("Enter the radius for circle %d: ", i + 1);
        scanf("%lf", &circles[i].radius);
        thread_args[i] = i; // Prepare thread argument
    }

    // Create threads to calculate area
    for (int i = 0; i < num_circles; i++) {
        if (pthread_create(&threads[i], NULL, calculate_circle_area, (void*)&thread_args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Join threads to ensure they've completed
    for (int i = 0; i < num_circles; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Print the results
    printf("\nCircle Area Calculations:\n");
    for (int i = 0; i < num_circles; i++) {
        printf("Circle %d - Radius: %.2f, Area: %.2f\n", i + 1, circles[i].radius, circles[i].area);
    }

    return EXIT_SUCCESS;
}