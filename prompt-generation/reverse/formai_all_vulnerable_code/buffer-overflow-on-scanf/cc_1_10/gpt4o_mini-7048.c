//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_CIRCLES 50

typedef struct {
    int radius;
    double area;
} Circle;

Circle circles[MAX_CIRCLES];
int num_circles = 0;
pthread_mutex_t mutex;

void* calculate_area(void* arg) {
    int index = *(int*)arg;
    double area = M_PI * circles[index].radius * circles[index].radius;

    pthread_mutex_lock(&mutex);
    circles[index].area = area;
    printf("Circle with radius %d has area: %f\n", circles[index].radius, area);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void input_circles() {
    printf("Enter the number of circles (max %d): ", MAX_CIRCLES);
    scanf("%d", &num_circles);
    if (num_circles < 1 || num_circles > MAX_CIRCLES) {
        printf("Invalid number of circles. Exiting...\n");
        exit(1);
    }
    for (int i = 0; i < num_circles; i++) {
        printf("Enter radius for circle %d: ", i + 1);
        scanf("%d", &circles[i].radius);
        if (circles[i].radius < 0) {
            printf("Radius can't be negative. Exiting...\n");
            exit(1);
        }
    }
}

int main() {
    pthread_t threads[MAX_CIRCLES];
    int indices[MAX_CIRCLES];

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    input_circles();

    for (int i = 0; i < num_circles; i++) {
        indices[i] = i;
        if (pthread_create(&threads[i], NULL, calculate_area, (void*)&indices[i]) != 0) {
            printf("Error creating thread for circle %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < num_circles; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("\nAll circles' areas have been calculated successfully.\n");
    return 0;
}