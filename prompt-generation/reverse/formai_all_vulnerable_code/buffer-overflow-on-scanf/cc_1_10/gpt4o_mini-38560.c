//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_POINTS 100
#define NAME_LENGTH 50

typedef struct Point {
    char name[NAME_LENGTH];
    float x;
    float y;
} Point;

typedef struct Path {
    Point points[MAX_POINTS];
    int count;
} Path;

// Function for initiating your surreal ride
void initializePath(Path* path) {
    path->count = 0;
}

// Function to create a dreamlike point in space
void createDreamPoint(Path* path) {
    if (path->count >= MAX_POINTS) {
        printf("The horizons have been exhausted!\n");
        return;
    }
    
    Point newPoint;
    sprintf(newPoint.name, "Point %.2f, %.2f", rand() % 100, rand() % 100);
    newPoint.x = (float)(rand() % 100) + ((float)(rand() % 100) / 100.0);
    newPoint.y = (float)(rand() % 100) + ((float)(rand() % 100) / 100.0);
    
    path->points[path->count++] = newPoint;
    printf("A whimsy point of existence has appeared: %s at (%.2f, %.2f)\n", newPoint.name, newPoint.x, newPoint.y);
}

// Function to display the psychedelic traversal
void displayPath(const Path* path) {
    printf("\nIn this labyrinthian journey, you've encountered %d points:\n", path->count);
    for (int i = 0; i < path->count; i++) {
        printf(" %d. %s: (%.2f, %.2f)\n", i + 1, path->points[i].name, path->points[i].x, path->points[i].y);
    }
}

float distance(Point a, Point b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

// Function to traverse the surreal landscape
void navigatePath(Path* path) {
    if (path->count < 2) {
        printf("The journey is but a whisper, add more points to voyage!\n");
        return;
    }

    printf("\nThe navigation begins in a flurry of vibrant colors...\n");
    for (int i = 0; i < path->count - 1; i++) {
        printf("Sailing from '%s' at (%.2f, %.2f) to '%s' at (%.2f, %.2f)\n",
               path->points[i].name, path->points[i].x, path->points[i].y,
               path->points[i + 1].name, path->points[i + 1].x, path->points[i + 1].y);
        sleep(1); // simulate time spent in surreal voyaging
    }

    printf("You have reached the final point: '%s'! A theatrical conclusion to your odyssey...\n", path->points[path->count - 1].name);
}

// The entry point of my ethereal narrative
int main() {
    srand(time(NULL));
    
    Path myPath;
    initializePath(&myPath);
    
    int choice;
    while (1) {
        printf("\n--- Surreal GPS Simulation ---\n");
        printf("1. Add a whimsical point\n");
        printf("2. Display the odyssey\n");
        printf("3. Navigate the landscape\n");
        printf("4. Exit the dream\n");
        printf("Make your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createDreamPoint(&myPath);
                break;
            case 2:
                displayPath(&myPath);
                break;
            case 3:
                navigatePath(&myPath);
                break;
            case 4:
                printf("You have stepped out of the mirage. Until next time...\n");
                exit(0);
            default:
                printf("Choice of eternity must be clearer!\n");
        }
    }
    return 0;
}