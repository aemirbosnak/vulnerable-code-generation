//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include<stdio.h>

//function to calculate area of a circle
float circle_area(float radius){
    float area = 3.14159 * radius * radius;
    return area;
}

//function to calculate area of a square
float square_area(float side){
    float area = side * side;
    return area;
}

//function to calculate area of a rectangle
float rectangle_area(float length, float breadth){
    float area = length * breadth;
    return area;
}

//function to calculate area of a triangle
float triangle_area(float base, float height){
    float area = 0.5 * base * height;
    return area;
}

int main(){

    int choice;
    float radius, side, length, breadth, base, height, area;

    printf("\nWelcome to Geometric Algorithms Program\n");

    do{
        printf("\nPlease select the shape whose area you want to calculate:\n");
        printf("1. Circle\n");
        printf("2. Square\n");
        printf("3. Rectangle\n");
        printf("4. Triangle\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the radius of the circle: ");
                scanf("%f", &radius);
                area = circle_area(radius);
                printf("\nThe area of the circle is %0.2f\n", area);
                break;
            case 2:
                printf("\nEnter the side of the square: ");
                scanf("%f", &side);
                area = square_area(side);
                printf("\nThe area of the square is %0.2f\n", area);
                break;
            case 3:
                printf("\nEnter the length and breadth of the rectangle: ");
                scanf("%f %f", &length, &breadth);
                area = rectangle_area(length, breadth);
                printf("\nThe area of the rectangle is %0.2f\n", area);
                break;
            case 4:
                printf("\nEnter the base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                area = triangle_area(base, height);
                printf("\nThe area of the triangle is %0.2f\n", area);
                break;
            case 5:
                printf("\nThank you for using Geometric Algorithms Program.\n");
                break;
            default:
                printf("\nInvalid input! Please enter a valid choice.\n");
                break;
        }
    }while(choice != 5);

    return 0;
}