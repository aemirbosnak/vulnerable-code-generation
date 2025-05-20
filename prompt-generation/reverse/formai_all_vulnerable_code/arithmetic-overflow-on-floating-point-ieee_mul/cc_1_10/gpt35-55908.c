//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define a struct to represent each point on the Cartesian plane
typedef struct {
    double x;
    double y;
} Point;

// Define a function to generate a random point on the Cartesian plane
Point getRandomPoint() {
    Point point;
    point.x = ((double) rand() / RAND_MAX) * 2 - 1; // Random x value between -1 and 1
    point.y = ((double) rand() / RAND_MAX) * 2 - 1; // Random y value between -1 and 1
    return point;
}

// Define a function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Define the main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int numPoints = 1000; // Number of points to generate
    Point points[numPoints]; // Array to store the points
    points[0] = getRandomPoint(); // Choose the first point randomly
    Point currentPoint, closestPoint;
    double minDistance;
    int iterations = 0; // Count the number of iterations
    while (iterations < 100000) { // Repeat until a certain number of iterations are done
        currentPoint = getRandomPoint(); // Choose a random point
        minDistance = 2; // Initialize the minimum distance to something larger than the plane size
        for (int i = 0; i < numPoints; i++) { // Find the closest point to the current point
            double d = distance(currentPoint, points[i]);
            if (d < minDistance) {
                minDistance = d;
                closestPoint = points[i];
            }
        }
        // Move the current point halfway towards the closest point
        currentPoint.x = (currentPoint.x + closestPoint.x) / 2;
        currentPoint.y = (currentPoint.y + closestPoint.y) / 2;
        // Add the new point to the array of points
        points[iterations % numPoints] = currentPoint;
        iterations++;
    }

    // Generate the fractal image using ASCII characters
    int width = 80; // Width of the image in characters
    int height = 40; // Height of the image in characters
    char image[height][width+1]; // Array to store the characters that represent the image
    double xStep = 2.0 / width; // Step size for the x-axis
    double yStep = 2.0 / height; // Step size for the y-axis
    for (int i = 0; i < height; i++) { // Loop over each row
        for (int j = 0; j < width; j++) { // Loop over each column
            Point p;
            p.x = -1 + j * xStep; // Calculate the x-coordinate of the current point
            p.y = 1 - i * yStep; // Calculate the y-coordinate of the current point
            // Find the closest point to the current point and calculate the distance
            minDistance = 2;
            for (int k = 0; k < numPoints; k++) {
                double d = distance(p, points[k]);
                if (d < minDistance) {
                    minDistance = d;
                }
            }
            // Choose an ASCII character based on the distance
            char c;
            if (minDistance < 0.05) {
                c = '@';
            } else if (minDistance < 0.1) {
                c = '#';
            } else if (minDistance < 0.15) {
                c = '%';
            } else if (minDistance < 0.2) {
                c = '+';
            } else if (minDistance < 0.25) {
                c = '=';
            } else if (minDistance < 0.3) {
                c = '-';
            } else {
                c = ' ';
            }
            image[i][j] = c; // Add the character to the image array
        }
        image[i][width] = '\0'; // Terminate the row with a null character
    }

    // Print the fractal image to the console
    for (int i = 0; i < height; i++) {
        printf("%s\n", image[i]);
    }

    return 0;
}