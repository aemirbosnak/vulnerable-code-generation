//FormAI DATASET v1.0 Category: Calculator ; Style: portable
/* 
This is a unique calculator program that can perform basic arithmetic calculations,
calculate area and perimeter of geometric shapes and convert temperature between Celsius
and Fahrenheit. It is written in a portable style so it can be run on any system.
*/

#include <stdio.h>

// Function to perform addition
float addition(float num1, float num2){
    return num1 + num2;
}

// Function to perform subtraction
float subtraction(float num1, float num2){
    return num1 - num2;
}

// Function to perform multiplication
float multiplication(float num1, float num2){
    return num1 * num2;
}

// Function to perform division
float division(float num1, float num2){
    return num1 / num2;
}

// Function to calculate area of a rectangle
float rectangle_area(float length, float breadth){
    return length * breadth;
}

// Function to calculate perimeter of a rectangle
float rectangle_perimeter(float length, float breadth){
    return 2 * (length + breadth);
}

// Function to calculate area of a circle
float circle_area(float radius){
    return 3.14 * radius * radius;
}

// Function to calculate circumference of a circle
float circle_circumference(float radius){
    return 2 * 3.14 * radius;
}

// Function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

int main(){
    int choice;
    float num1, num2, length, breadth, radius, celsius, fahrenheit, result;

    printf("Welcome to my calculator program!\n\n");

    while(1){
        printf("Choose an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Calculate area and perimeter of a rectangle\n");
        printf("6. Calculate area and circumference of a circle\n");
        printf("7. Convert temperature between Celsius and Fahrenheit\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = addition(num1, num2);
                printf("Result: %f\n\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = subtraction(num1, num2);
                printf("Result: %f\n\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = multiplication(num1, num2);
                printf("Result: %f\n\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = division(num1, num2);
                printf("Result: %f\n\n", result);
                break;
            case 5:
                printf("Enter the length and breadth of the rectangle: ");
                scanf("%f %f", &length, &breadth);
                printf("Area: %f\n", rectangle_area(length, breadth));
                printf("Perimeter: %f\n\n", rectangle_perimeter(length, breadth));
                break;
            case 6:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("Area: %f\n", circle_area(radius));
                printf("Circumference: %f\n\n", circle_circumference(radius));
                break;
            case 7:
                printf("Choose an option:\n");
                printf("1. Celsius to Fahrenheit\n");
                printf("2. Fahrenheit to Celsius\n");

                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("Enter temperature in Celsius: ");
                        scanf("%f", &celsius);
                        printf("Temperature in Fahrenheit: %f\n\n", celsius_to_fahrenheit(celsius));
                        break;
                    case 2:
                        printf("Enter temperature in Fahrenheit: ");
                        scanf("%f", &fahrenheit);
                        printf("Temperature in Celsius: %f\n\n", fahrenheit_to_celsius(fahrenheit));
                        break;
                    default:
                        printf("Invalid choice\n\n");
                }
                break;
            case 8:
                printf("Thank you for using my calculator program!\n");
                return 0;
            default:
                printf("Invalid choice\n\n");
        }
    }
    return 0;
}