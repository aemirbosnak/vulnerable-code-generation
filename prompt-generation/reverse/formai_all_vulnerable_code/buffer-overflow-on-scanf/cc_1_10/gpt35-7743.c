//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

// Function to add two numbers
double addition(double num1, double num2){
    return num1 + num2;
}

// Function to subtract two numbers
double subtraction(double num1, double num2){
    return num1 - num2;
}

// Function to multiply two numbers
double multiplication(double num1, double num2){
    return num1 * num2;
}

// Function to divide two numbers
double division(double num1, double num2){
    if(num2 == 0){
        printf("Error: Cannot divide by zero\n");
        exit(EXIT_FAILURE);
    }
    return num1 / num2;
}

// Function to calculate power of a number
double power(double num1, double num2){
    return pow(num1,num2);
}

// Function to find square root of a number
double square_root(double num1){
    if(num1 < 0){
        printf("Error: Input negative number\n");
        exit(EXIT_FAILURE);
    }
    return sqrt(num1);
}

// Function to find log of a number
double logarithm(double num1){
    if(num1 <= 0){
        printf("Error: Input non-positive number\n");
        exit(EXIT_FAILURE);
    }
    return log(num1);
}

// Function to exit program
void quit_program(){
    printf("Exiting the calculator program...\n");
    exit(EXIT_SUCCESS);
}

int main(){
    printf("Welcome to the Post-Apocalyptic Scientific Calculator\n");
    printf("********************************************************\n");

    printf("List of Operations\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power Calculation\n");
    printf("6. Square Root Calculation\n");
    printf("7. Natural Logarithm Calculation\n");
    printf("8. Exit\n");

    printf("Enter your choice: ");

    int choice = 0;
    double num1 = 0.0, num2 = 0.0;

    // Taking input from user and validating the input
    if(!scanf("%d",&choice) || choice <= 0 || choice > 8 || !isdigit(choice)){
        printf("Invalid input: Not an integer between 1-8\n");
        exit(EXIT_FAILURE);
    }

    switch(choice){
        case 1:
            printf("Enter the two numbers to be added: ");
            if(!scanf("%lf %lf",&num1,&num2)){
                printf("Invalid input: Please enter valid numbers (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",addition(num1,num2));
            break;
        case 2:
            printf("Enter the two numbers to be subtracted (first number - second number): ");
            if(!scanf("%lf %lf",&num1,&num2)){
                printf("Invalid input: Please enter valid numbers (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",subtraction(num1,num2));
            break;
        case 3:
            printf("Enter the two numbers to be multiplied: ");
            if(!scanf("%lf %lf",&num1,&num2)){
                printf("Invalid input: Please enter valid numbers (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",multiplication(num1,num2));
            break;
        case 4:
            printf("Enter the two numbers (numerator and denominator) to be divided: ");
            if(!scanf("%lf %lf",&num1,&num2)){
                printf("Invalid input: Please enter valid numbers (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",division(num1,num2));
            break;
        case 5:
            printf("Enter the two numbers (base and power) to be calculated: ");
            if(!scanf("%lf %lf",&num1,&num2)){
                printf("Invalid input: Please enter valid numbers (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",power(num1,num2));
            break;
        case 6:
            printf("Enter the number to find the square root of: ");
            if(!scanf("%lf",&num1)){
                printf("Invalid input: Please enter valid number (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",square_root(num1));
            break;
        case 7:
            printf("Enter the number to find the natural logarithm of: ");
            if(!scanf("%lf",&num1)){
                printf("Invalid input: Please enter valid number (floating point)\n");
                exit(EXIT_FAILURE);
            }
            printf("The result is %lf\n",logarithm(num1));
            break;
        case 8:
            quit_program();
            break;
    }

    return 0;
}