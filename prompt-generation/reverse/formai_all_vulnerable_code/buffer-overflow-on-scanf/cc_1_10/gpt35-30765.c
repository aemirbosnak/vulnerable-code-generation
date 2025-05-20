//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Function to perform addition
float add(float x, float y){
    return x+y;
}

// Function to perform subtraction
float subtract(float x, float y){
    return x-y;
}

// Function to perform multiplication
float multiply(float x, float y){
    return x*y;
}

// Function to perform division
float divide(float x, float y){
    if(y==0){
        printf("Cannot divide by zero!\n");
        return NAN; // Not a Number
    }
    return x/y;
}

// Function to perform power function
float power(float x, float y){
    return pow(x,y);
}

// Function to perform square root
float squareroot(float x){
    if(x < 0){
        printf("Invalid input!\n");
        return NAN;
    }
    return sqrt(x);
}

// Function to perform exponential function
float exponential(float x){
    return exp(x);
}

// Main program
int main(){
    int choice;
    float x,y,result;
    char operation[10];
    
    printf("Welcome to secure scientific calculator!\n");
    
    while(1){  // Loop until user exits
        printf("\nPlease choose an operation to perform (or type 'exit' to exit): \n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square root\n7. Exponential\n");
        scanf("%s", operation);
        
        // Exit program if the user types 'exit'
        if(strcmp(operation, "exit") == 0){
            printf("Exiting calculator...\n");
            break;
        }
        
        // Parse user input for operation choice
        choice = atoi(operation);
        
        // If the user did not enter a valid choice, loop again and ask for input
        if(choice < 1 || choice > 7){
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            continue;
        }
        
        // If the choice is square root or exponential, prompt for x only
        if(choice == 6 || choice == 7){
            printf("Please enter x: ");
            scanf("%f", &x);
        }
        // Otherwise, prompt for x and y
        else{
            printf("Please enter x: ");
            scanf("%f", &x);
            printf("Please enter y: ");
            scanf("%f", &y);
        }
        
        // Perform the chosen operation
        switch (choice){
            case 1:
                result = add(x,y);
                printf("%.2f + %.2f = %.2f\n", x, y, result);
                break;
            case 2:
                result = subtract(x,y);
                printf("%.2f - %.2f = %.2f\n", x, y, result);
                break;
            case 3:
                result = multiply(x,y);
                printf("%.2f * %.2f = %.2f\n", x, y, result);
                break;
            case 4:
                result = divide(x,y);
                if(isnan(result)) // If result is not a number, skip printing
                    break;
                printf("%.2f / %.2f = %.2f\n", x, y, result);
                break;
            case 5:
                result = power(x,y);
                printf("%.2f ^ %.2f = %.2f\n", x, y, result);
                break;
            case 6:
                result = squareroot(x);
                if(isnan(result)) // If result is not a number, skip printing
                    break;
                printf("sqrt(%.2f) = %.2f\n", x, result);
                break;
            case 7:
                result = exponential(x);
                printf("exp(%.2f) = %.2f\n", x, result);
                break;
        }
    }
    return 0;
}