//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// This program calculates the area and circumference of a circle using geometric algorithms in multi-threaded style.

#define NUM_THREADS 2

float radius;  // radius of the circle
float area;  // area of the circle
float circum;  // circumference of the circle

// This function calculates the area of the circle and updates the global variable 'area'.
void *calculate_area(void *threadid) {
    double *id = (double *)threadid;
    float local_area = M_PI * pow(radius, 2);
    printf("Thread %f: Calculating area of the circle...\n", *id);
    area = local_area;
    pthread_exit(NULL);
}

// This function calculates the circumference of the circle and updates the global variable 'circum'.
void *calculate_circumference(void *threadid) {
    double *id = (double *)threadid;
    float local_circum = 2 * M_PI * radius;
    printf("Thread %f: Calculating circumference of the circle...\n", *id);
    circum = local_circum;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    double tids[NUM_THREADS];

    // get the radius value from the user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // create two threads for area and circumference calculations
    for (int i = 0; i < NUM_THREADS; i++) {
        tids[i] = i + 1;
        if (i == 0) {
            rc = pthread_create(&threads[i], NULL, calculate_area, (void *)&tids[i]);
        } else if (i == 1) {
            rc = pthread_create(&threads[i], NULL, calculate_circumference, (void *)&tids[i]);
        }
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print the results
    printf("The area of the circle is: %f\n", area);
    printf("The circumference of the circle is: %f\n", circum);

    return 0;
}