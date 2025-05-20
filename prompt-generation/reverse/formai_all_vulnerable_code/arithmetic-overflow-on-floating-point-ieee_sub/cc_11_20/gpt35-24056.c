//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>
#include <math.h>

int main() {
    float triangle[3][2];
    printf("Enter the coordinates of the first point of the triangle:\nX: ");
    scanf("%f", &triangle[0][0]);
    printf("Y: ");
    scanf("%f", &triangle[0][1]);

    printf("Enter the coordinates of the second point of the triangle:\nX: ");
    scanf("%f", &triangle[1][0]);
    printf("Y: ");
    scanf("%f", &triangle[1][1]);

    printf("Enter the coordinates of the third point of the triangle:\nX: ");
    scanf("%f", &triangle[2][0]);
    printf("Y: ");
    scanf("%f", &triangle[2][1]);


    float a = sqrtf(powf(triangle[0][0]-triangle[1][0], 2) + powf(triangle[0][1]-triangle[1][1], 2));
    float b = sqrtf(powf(triangle[1][0]-triangle[2][0], 2) + powf(triangle[1][1]-triangle[2][1], 2));
    float c = sqrtf(powf(triangle[2][0]-triangle[0][0], 2) + powf(triangle[2][1]-triangle[0][1], 2));

    if (a+b <= c || a+c <= b || b+c <= a) {
        printf("These points do not form a triangle!");
        return 1;
    }

    int signal[3];
    for (int i = 0; i < 3; i++) {
        if (triangle[i][1] > 0) {
            signal[i] = 1;
        } else if (triangle[i][1] < 0) {
            signal[i] = -1;
        } else {
            signal[i] = 0;
        }
    }

    if (signal[0] == signal[1] && signal[1] == signal[2]) {
        printf("These points are aligned and do not form a triangle!");
        return 1;
    }

    float s = (a+b+c)/2;
    float area = sqrtf(s * (s-a) * (s-b) * (s-c));
    printf("The area of the triangle is: %0.2f\n", area);

    float max_dist = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            float d = sqrtf(powf(triangle[i][0]-triangle[j][0], 2) + powf(triangle[i][1]-triangle[j][1], 2));
            if (d > max_dist) {
                max_dist = d;
            }
        }
    }

    printf("The longest side of the triangle has a length of %0.2f\n", max_dist);

    return 0;
}