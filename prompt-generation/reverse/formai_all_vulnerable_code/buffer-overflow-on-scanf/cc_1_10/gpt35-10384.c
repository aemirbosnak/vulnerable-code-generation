//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

// Function to calculate area of triangle given 3 sides
float triangleArea(float a, float b, float c){
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

// Function to calculate volume of pyramid given base area and height
float pyramidVolume(float baseArea, float height){
    float volume = (1.0 / 3) * baseArea * height;
    return volume;
}

// Function to determine if a point is inside a circle
int pointInCircle(float x, float y, float cx, float cy, float r){
    float dx = x - cx;
    float dy = y - cy;
    float distance = sqrt(dx*dx + dy*dy);
    if(distance < r){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num_triangles, num_circles;

    // Get number of triangles and circles from user
    printf("Enter the number of triangles: ");
    scanf("%d", &num_triangles);
    printf("Enter the number of circles: ");
    scanf("%d", &num_circles);

    // Allocate memory for triangle and circle data
    float **triangle_data = (float **)malloc(num_triangles * sizeof(float *));
    for(int i = 0; i < num_triangles; i++){
        triangle_data[i] = (float *)malloc(3 * sizeof(float));
    }
    float **circle_data = (float **)malloc(num_circles * sizeof(float *));
    for(int i = 0; i < num_circles; i++){
        circle_data[i] = (float *)malloc(3 * sizeof(float));
    }

    // Get triangle and circle data from user
    printf("\nEnter the lengths of the sides of each triangle:\n");
    for(int i = 0; i < num_triangles; i++){
        printf("Triangle %d: ", i+1);
        scanf("%f %f %f", &triangle_data[i][0], &triangle_data[i][1], &triangle_data[i][2]);
    }
    printf("\nEnter the centers and radii of each circle:\n");
    for(int i = 0; i < num_circles; i++){
        printf("Circle %d: ", i+1);
        scanf("%f %f %f", &circle_data[i][0], &circle_data[i][1], &circle_data[i][2]);
    }

    // Calculate total volume of pyramids within circles
    float total_volume = 0;
    for(int i = 0; i < num_circles; i++){
        float cx = circle_data[i][0];
        float cy = circle_data[i][1];
        float r = circle_data[i][2];
        float base_area = PI * r * r;
        float height = 0;
        for(int j = 0; j < num_triangles; j++){
            float a = triangle_data[j][0];
            float b = triangle_data[j][1];
            float c = triangle_data[j][2];
            float area = triangleArea(a, b, c);
            if(pointInCircle(a, 0, cx, cy, r) && pointInCircle(b, 0, cx, cy, r) && pointInCircle(c, 0, cx, cy, r)){
                height += area;
            }
        }
        float volume = pyramidVolume(base_area, height);
        total_volume += volume;
    }

    // Print out total volume
    printf("\nThe total volume of the pyramids within the circles is %.2f\n", total_volume);

    // Free allocated memory
    for(int i = 0; i < num_triangles; i++){
        free(triangle_data[i]);
    }
    free(triangle_data);
    for(int i = 0; i < num_circles; i++){
        free(circle_data[i]);
    }
    free(circle_data);

    return 0;
}