//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

// Function to calculate the Manhattan distance between two points
float manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Function to calculate the Euclidean distance between two points
float euclidean_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Function to find the shortest path between two points using the Manhattan distance
int manhattan_shortest_path(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Check if the points are in the same row or column
    if (dx == 0 && dy == 0) {
        return 1;
    }

    // Check if the points are in the same row or column
    if (dx == 0 && dy!= 0) {
        return abs(dy);
    }

    // Check if the points are in the same row or column
    if (dx!= 0 && dy == 0) {
        return abs(dx);
    }

    // Calculate the shortest path using the Manhattan distance
    int steps = 0;
    int x = x1;
    int y = y1;

    while (x!= x2 || y!= y2) {
        steps++;
        if (dx > 0) {
            x++;
        } else {
            x--;
        }

        if (dy > 0) {
            y++;
        } else {
            y--;
        }
    }

    return steps;
}

// Function to find the shortest path between two points using the Euclidean distance
int euclidean_shortest_path(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Check if the points are in the same row or column
    if (dx == 0 && dy == 0) {
        return 1;
    }

    // Check if the points are in the same row or column
    if (dx == 0 && dy!= 0) {
        return abs(dy);
    }

    // Check if the points are in the same row or column
    if (dx!= 0 && dy == 0) {
        return abs(dx);
    }

    // Calculate the shortest path using the Euclidean distance
    int steps = 0;
    int x = x1;
    int y = y1;

    while (x!= x2 || y!= y2) {
        steps++;
        x += dx / dx;
        y += dy / dy;
    }

    return steps;
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x, y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x, y): ");
    scanf("%d %d", &x2, &y2);

    int steps_manhattan = manhattan_shortest_path(x1, y1, x2, y2);
    int steps_euclidean = euclidean_shortest_path(x1, y1, x2, y2);

    printf("Shortest path using the Manhattan distance: %d steps\n", steps_manhattan);
    printf("Shortest path using the Euclidean distance: %d steps\n", steps_euclidean);

    return 0;
}