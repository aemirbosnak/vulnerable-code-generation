//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the map dimensions
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Define the start and end points
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Define the map
int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the thread data structure
typedef struct thread_data {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int **map;
    int **visited;
    int **distance;
} thread_data;

// Define the thread function
void *thread_function(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *)arg;

    // Initialize the visited and distance maps
    data->visited = (int **)malloc(MAP_WIDTH * sizeof(int *));
    for (int i = 0; i < MAP_WIDTH; i++) {
        data->visited[i] = (int *)malloc(MAP_HEIGHT * sizeof(int));
        for (int j = 0; j < MAP_HEIGHT; j++) {
            data->visited[i][j] = 0;
        }
    }

    data->distance = (int **)malloc(MAP_WIDTH * sizeof(int *));
    for (int i = 0; i < MAP_WIDTH; i++) {
        data->distance[i] = (int *)malloc(MAP_HEIGHT * sizeof(int));
        for (int j = 0; j < MAP_HEIGHT; j++) {
            data->distance[i][j] = -1;
        }
    }

    // Perform the pathfinding algorithm
    data->distance[data->start_x][data->start_y] = 0;
    while (1) {
        // Find the next unvisited cell with the smallest distance
        int min_distance = -1;
        int min_x = -1;
        int min_y = -1;
        for (int i = 0; i < MAP_WIDTH; i++) {
            for (int j = 0; j < MAP_HEIGHT; j++) {
                if (!data->visited[i][j] && (data->distance[i][j] != -1) && ((min_distance == -1) || (data->distance[i][j] < min_distance))) {
                    min_distance = data->distance[i][j];
                    min_x = i;
                    min_y = j;
                }
            }
        }

        // If no such cell exists, then the algorithm is complete
        if (min_x == -1 || min_y == -1) {
            break;
        }

        // Mark the cell as visited
        data->visited[min_x][min_y] = 1;

        // Check if the cell is the end point
        if (min_x == data->end_x && min_y == data->end_y) {
            break;
        }

        // Update the distances of the adjacent cells
        if (min_x > 0 && !data->visited[min_x - 1][min_y] && data->map[min_x - 1][min_y] != 1) {
            data->distance[min_x - 1][min_y] = min_distance + 1;
        }
        if (min_x < MAP_WIDTH - 1 && !data->visited[min_x + 1][min_y] && data->map[min_x + 1][min_y] != 1) {
            data->distance[min_x + 1][min_y] = min_distance + 1;
        }
        if (min_y > 0 && !data->visited[min_x][min_y - 1] && data->map[min_x][min_y - 1] != 1) {
            data->distance[min_x][min_y - 1] = min_distance + 1;
        }
        if (min_y < MAP_HEIGHT - 1 && !data->visited[min_x][min_y + 1] && data->map[min_x][min_y + 1] != 1) {
            data->distance[min_x][min_y + 1] = min_distance + 1;
        }
    }

    // Free the visited and distance maps
    for (int i = 0; i < MAP_WIDTH; i++) {
        free(data->visited[i]);
        free(data->distance[i]);
    }
    free(data->visited);
    free(data->distance);

    // Return the distance to the end point
    return (void *)data->distance[data->end_x][data->end_y];
}

// Define the main function
int main() {
    // Create the thread data
    thread_data data;
    data.start_x = START_X;
    data.start_y = START_Y;
    data.end_x = END_X;
    data.end_y = END_Y;
    data.map = map;

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, &data);

    // Wait for the thread to finish
    void *result;
    pthread_join(thread, &result);

    // Print the result
    printf("The distance to the end point is: %d\n", (int)result);

    return 0;
}