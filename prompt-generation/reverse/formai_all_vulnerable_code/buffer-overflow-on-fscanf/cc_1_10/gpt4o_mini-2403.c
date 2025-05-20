//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Define the structure for Point
typedef struct {
    double x;
    double y;
} Point;

// Define structure for handling arguments passed to thread function
typedef struct {
    Point *points;
    int start_index;
    int end_index;
    double *result_area;
} ThreadData;

// Global variable to count how many threads have completed
int completed_threads = 0;
pthread_mutex_t lock;

// Function to calculate the area of a polygon using the shoelace formula
double calculate_area(Point *points, int start_index, int end_index) {
    double area = 0.0;
    for (int i = start_index; i < end_index - 1; i++) {
        area += (points[i].x * points[i + 1].y) - (points[i + 1].x * points[i].y);
    }
    area += (points[end_index - 1].x * points[start_index].y) - (points[start_index].x * points[end_index - 1].y);
    return fabs(area) / 2.0;
}

// Thread function to handle polygon area calculation portion
void* thread_area_calculation(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    double area = calculate_area(data->points, data->start_index, data->end_index);
    
    pthread_mutex_lock(&lock);
    *(data->result_area) += area; // Accumulate result
    completed_threads++;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number_of_threads> <points_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_threads = atoi(argv[1]);
    const char *file_name = argv[2];
    
    // Read points from file
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Assuming the file has the number of points followed by the points themselves
    int num_points;
    fscanf(file, "%d", &num_points);
    
    Point *points = malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(file);

    // Initialize thread data
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    ThreadData *thread_data = malloc(num_threads * sizeof(ThreadData));
    
    double total_area = 0.0;
    int segment_size = num_points / num_threads;
    pthread_mutex_init(&lock, NULL);

    // Create threads for area calculation
    for (int i = 0; i < num_threads; i++) {
        int start_index = i * segment_size;
        int end_index = (i == num_threads - 1) ? num_points : start_index + segment_size; // Last segment takes remaining points
        thread_data[i].points = points;
        thread_data[i].start_index = start_index;
        thread_data[i].end_index = end_index;
        thread_data[i].result_area = &total_area;

        if (pthread_create(&threads[i], NULL, thread_area_calculation, &thread_data[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup and display result
    pthread_mutex_destroy(&lock);
    free(threads);
    free(thread_data);
    free(points);

    printf("Total area of the polygon: %lf\n", total_area);
    return 0;
}