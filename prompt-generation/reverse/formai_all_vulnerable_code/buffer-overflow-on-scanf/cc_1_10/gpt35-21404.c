//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to calculate the area of a triangle given the lengths of its 3 sides
float areaOfTriangle(float a, float b, float c){
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

//Function to calculate the perimeter of a triangle given the lengths of its 3 sides
float perimeterOfTriangle(float a, float b, float c){
    return a+b+c;
}

//Function to calculate the area of a circle given its radius
float areaOfCircle(float r){
    return 3.14 * r * r;
}

//Main function
int main(){
    int choice;
    printf("Enter 1 for Area of Triangle, 2 for Perimeter of Triangle and 3 for Area of Circle: ");
    scanf("%d", &choice);
    //Area of triangle
    if (choice == 1){
        float a, b, c;
        printf("Enter the lengths of the 3 sides of the triangle: ");
        scanf("%f %f %f", &a, &b, &c);
        float area = areaOfTriangle(a, b, c);
        printf("Area of the triangle is: %f", area);
    }
    //Perimeter of triangle
    else if (choice == 2){
        float a, b, c;
        printf("Enter the lengths of the 3 sides of the triangle: ");
        scanf("%f %f %f", &a, &b, &c);
        float perimeter = perimeterOfTriangle(a, b, c);
        printf("Perimeter of the triangle is: %f", perimeter);
    }
    //Area of circle
    else if (choice == 3){
        float r;
        printf("Enter the radius of the circle: ");
        scanf("%f", &r);
        float area = areaOfCircle(r);
        printf("Area of the circle is: %f", area);
    }
    //Invalid choice
    else{
        printf("Invalid choice");
    }
    return 0;
}