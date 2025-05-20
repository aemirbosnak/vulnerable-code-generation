//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Function to generate a random number between 0 and 1
double rand01() {
    return rand() / (double)RAND_MAX;
}

// Function to generate a random point within a unit circle
struct point {
    double x, y;
};
struct point random_point() {
    struct point p;
    p.x = rand01() * 2 - 1;
    p.y = rand01() * 2 - 1;
    return p;
}

// Function to calculate the distance between two points
double distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to implement the Monte Carlo method for estimating the value of pi
double monte_carlo_pi(int n) {
    int i, count = 0;
    double pi = 0;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        struct point p = random_point();
        if (distance(p, (struct point){0, 0}) <= 1) {
            count++;
        }
    }
    pi = 4 * count / n;
    return pi;
}

// Main function
int main() {
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    double pi = monte_carlo_pi(n);
    printf("Estimated value of pi: %.6f\n", pi);
    return 0;
}