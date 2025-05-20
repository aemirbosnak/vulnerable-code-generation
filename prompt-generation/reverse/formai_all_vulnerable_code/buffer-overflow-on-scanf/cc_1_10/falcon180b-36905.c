//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VARIABLES 10
#define MAX_POINTS 100

typedef struct {
    char name[20];
    float value;
} variable_t;

typedef struct {
    int num_variables;
    variable_t variables[MAX_VARIABLES];
} point_t;

// Function to evaluate a point on the graph
float evaluate(point_t *p) {
    float result = 0;
    for (int i = 0; i < p->num_variables; i++) {
        result += p->variables[i].value * sin(p->variables[i].value);
    }
    return result;
}

// Function to print the graph
void print_graph(point_t *points, int num_points) {
    printf("Graph:\n");
    for (int i = 0; i < num_points; i++) {
        printf("%s = %.2f\n", points[i].variables[0].name, points[i].variables[0].value);
        for (int j = 1; j < points[i].num_variables; j++) {
            printf("%s = %.2f\n", points[i].variables[j].name, points[i].variables[j].value);
        }
        printf("Result: %.2f\n\n", evaluate(&points[i]));
    }
}

// Function to read points from input
void read_points(point_t *points, int num_points) {
    printf("Enter points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d:\n", i+1);
        scanf("%s", points[i].variables[0].name);
        for (int j = 1; j < points[i].num_variables; j++) {
            scanf("%s", points[i].variables[j].name);
            scanf("%f", &points[i].variables[j].value);
        }
    }
}

// Main function
int main() {
    point_t points[MAX_POINTS];
    int num_points = 0;

    // Read points from input
    read_points(points, MAX_POINTS);
    num_points = 0;
    while (num_points < MAX_POINTS && points[num_points].num_variables == 0) {
        num_points++;
    }

    // Print graph
    print_graph(points, num_points);

    return 0;
}