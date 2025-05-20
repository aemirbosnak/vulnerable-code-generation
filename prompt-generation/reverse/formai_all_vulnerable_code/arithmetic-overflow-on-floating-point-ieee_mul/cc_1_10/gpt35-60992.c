//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include<stdio.h>

int main(){
    // Shape-shifting program in C
    int choice, shape; 
    float length, breadth, height, radius, area, volume, perimeter;

    printf("Welcome to the Shape-Shifting Program in C\n");
    printf("-----------------------------------------\n");

    // User Input
    printf("Enter the shape of the object:\n");
    printf("1 - Circle\n2 - Rectangle\n3 - Triangle\n4 - Sphere\n5 - Cube\n6 - Cylinder\n7 - Cone\n");
    scanf("%d", &shape);

    switch(shape){
        case 1: // Circle
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = 3.14 * radius * radius;
            perimeter = 2 * 3.14 * radius;
            printf("The area of the circle is: %f\nThe perimeter of the circle is: %f\n", area, perimeter);
            break;

        case 2: // Rectangle
            printf("Enter the length of the rectangle: ");
            scanf("%f", &length);
            printf("Enter the breadth of the rectangle: ");
            scanf("%f", &breadth);
            area = length * breadth;
            perimeter = 2 * (length + breadth);
            printf("The area of the rectangle is: %f\nThe perimeter of the rectangle is: %f\n", area, perimeter);
            break;

        case 3: // Triangle
            printf("Enter the base of the triangle: ");
            scanf("%f", &length);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
            area = 0.5 * length * height;
            printf("The area of the triangle is: %f\n", area);
            break;

        case 4: // Sphere
            printf("Enter the radius of the sphere: ");
            scanf("%f", &radius);
            volume = (4.0/3.0) * 3.14 * radius * radius * radius;
            printf("The Volume of the sphere is: %f\n", volume);
            break;

        case 5: // Cube
            printf("Enter the length of one side of the cube: ");
            scanf("%f", &length);
            volume = length * length * length;
            printf("The Volume of the cube is: %f\n", volume);
            break;

        case 6: // Cylinder
            printf("Enter the radius of the cylinder: ");
            scanf("%f", &radius);
            printf("Enter the height of the cylinder: ");
            scanf("%f", &height);
            volume = 3.14 * radius * radius * height;
            printf("The Volume of the cylinder is: %f\n", volume);
            break;

        case 7: // Cone
            printf("Enter the radius of the cone: ");
            scanf("%f", &radius);
            printf("Enter the height of the cone: ");
            scanf("%f", &height);
            volume = 0.33 * 3.14 * radius * radius * height;
            printf("The Volume of the cone is: %f\n", volume);
            break;

        default: // Invalid Input
            printf("Invalid Choice!\n");
            break;
    }

    return 0;
}