//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include<stdio.h>
#include<math.h>

/* A function to calculate the area of a triangle using Heron's formula */
float area_of_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2; //semi-perimeter
    return sqrt(s*(s-a)*(s-b)*(s-c)); //using the formula
}

/* A function to calculate the length of a line segment using the Pythagorean theorem */
float length_of_line_segment(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

/* A function to calculate the perimeter of a polygon given its vertices */
float perimeter_of_polygon(int n, float vertices[][2]) {
    float perimeter = 0.0;
    int i;
    for(i = 0; i < n; i++) {
        float x1 = vertices[i][0];
        float y1 = vertices[i][1];
        float x2,y2;
        if(i == n-1) { //last vertex, connect to the first vertex
            x2 = vertices[0][0];
            y2 = vertices[0][1];
        }
        else {
            x2 = vertices[i+1][0];
            y2 = vertices[i+1][1];
        }
        perimeter += length_of_line_segment(x1, y1, x2, y2);
    }
    return perimeter;
}

/* A function to calculate the area of a polygon given its vertices */
float area_of_polygon(int n, float vertices[][2]) {
    float area = 0.0;
    int i;
    for(i = 0; i < n; i++) {
        float x1 = vertices[i][0];
        float y1 = vertices[i][1];
        float x2,y2;
        if(i == n-1) { //last vertex, connect to the first vertex
            x2 = vertices[0][0];
            y2 = vertices[0][1];
        }
        else {
            x2 = vertices[i+1][0];
            y2 = vertices[i+1][1];
        }
        area += (y1 + y2) * (x2 - x1); //the area formula
    }
    return fabs(area) / 2.0; //absolute value and division by 2
}

/* Sample usage of the functions */
int main() {
    //calculate the area of a triangle
    float a,b,c;
    printf("Enter the sides of a triangle: ");
    scanf("%f%f%f", &a, &b, &c);
    float area = area_of_triangle(a, b, c);
    printf("The area of the triangle is: %f\n", area);
    
    //calculate the perimeter and area of a polygon
    int n;
    printf("Enter the number of vertices of a polygon: ");
    scanf("%d", &n);
    float vertices[n][2];
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter the x and y coordinates of vertex %d: ", i+1);
        scanf("%f%f", &vertices[i][0], &vertices[i][1]);
    }
    float perimeter = perimeter_of_polygon(n, vertices);
    printf("The perimeter of the polygon is: %f\n", perimeter);
    float area_polygon = area_of_polygon(n, vertices);
    printf("The area of the polygon is: %f\n", area_polygon);
    return 0;
}