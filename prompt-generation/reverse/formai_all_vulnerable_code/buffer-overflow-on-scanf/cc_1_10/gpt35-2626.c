//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include<stdio.h>

//function to find the area of a rectangle given its length and breadth
float areaRectangle(float length, float breadth) {
    return length * breadth;
}

//function to find the area of a triangle given its base and height
float areaTriangle(float base, float height) {
    return 0.5 * base * height;
}

//function to find the area of a circle given its radius
float areaCircle(float radius) {
    return 3.14 * radius * radius;
}

int main() {
    int choice;
    float length, breadth, base, height, radius, area;

    printf("Enter your choice of shape:\n");
    printf("1.Rectangle\n");
    printf("2.Triangle\n");
    printf("3.Circle\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: printf("Enter the length and breadth of the rectangle:\n");
                scanf("%f%f", &length, &breadth);
                area = areaRectangle(length,breadth);
                printf("The area of the rectangle is %.2f", area);
                break;

        case 2: printf("Enter the base and height of the triangle:\n");
                scanf("%f%f", &base, &height);
                area = areaTriangle(base,height);
                printf("The area of the triangle is %.2f", area);
                break;

        case 3: printf("Enter the radius of the circle:\n");
                scanf("%f", &radius);
                area = areaCircle(radius);
                printf("The area of the circle is %.2f", area);
                break;

        default: printf("Invalid Choice!");
    }

    return 0;
}