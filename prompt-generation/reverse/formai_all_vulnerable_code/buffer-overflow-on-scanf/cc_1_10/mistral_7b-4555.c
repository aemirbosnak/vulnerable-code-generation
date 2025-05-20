//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIDES 3

// Function to check if sides can form a triangle
int valid_triangle(double sides[MAX_SIDES]) {
    double s = 0.0;
    for (int i = 0; i < MAX_SIDES; i++) {
        if (sides[i] <= 0) {
            return 0;
        }
        s += sides[i];
    }

    if (s - sides[0] - sides[1] - sides[2] > 0.0) {
        return 0;
    }

    return 1;
}

// Function to calculate the semi-perimeter of the triangle
double s(double sides[MAX_SIDES]) {
    double sum = 0.0;
    for (int i = 0; i < MAX_SIDES; i++) {
        sum += sides[i];
    }

    return sum / 2.0;
}

// Function to calculate the area of the triangle using Heron's formula
double heron_area(double sides[MAX_SIDES]) {
    double s_val = s(sides);
    double area = sqrt(s_val * (s_val - sides[0]) * (s_val - sides[1]) * (s_val - sides[2]));
    return area;
}

// Function to read input from the user
void read_input(double sides[MAX_SIDES]) {
    for (int i = 0; i < MAX_SIDES; i++) {
        printf("Enter the length of side %d: ", i + 1);
        scanf("%lf", &sides[i]);
    }
}

int main() {
    double sides[MAX_SIDES];
    int is_valid = 0;

    do {
        read_input(sides);

        is_valid = valid_triangle(sides);

        if (!is_valid) {
            printf("Error: Invalid input. Please enter the lengths of three sides of a triangle.\n");
            continue;
        }

        double area = heron_area(sides);
        printf("The area of the triangle with sides %lf, %lf, and %lf is %lf.\n", sides[0], sides[1], sides[2], area);
        break;
    } while (1);

    return 0;
}