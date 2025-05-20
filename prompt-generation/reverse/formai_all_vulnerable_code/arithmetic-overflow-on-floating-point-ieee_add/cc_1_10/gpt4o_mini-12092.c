//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <math.h>

// Function declarations 
void add(); 
void subtract(); 
void multiply(); 
void divide(); 
void sine(); 
void cosine(); 
void tangent(); 
void displayMenu(); 

int main() { 
    int choice; 
    printf("Welcome to the Exciting Scientific Calculator! 🎉\n"); 
    do {
        displayMenu(); 
        printf("Please enter your choice (1-8): "); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1: add(); break; 
            case 2: subtract(); break; 
            case 3: multiply(); break; 
            case 4: divide(); break; 
            case 5: sine(); break; 
            case 6: cosine(); break; 
            case 7: tangent(); break; 
            case 8: printf("Exiting the calculator... Goodbye! 👋\n"); break; 
            default: printf("Invalid choice! Please try again. 🙁\n"); 
        } 
    } while (choice != 8); 
    return 0; 
}

void displayMenu() {
    printf("\n--------- Menu ---------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Exit\n");
    printf("-----------------------\n");
}

void add() { 
    double num1, num2; 
    printf("Enter two numbers to add: "); 
    scanf("%lf %lf", &num1, &num2); 
    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2); 
}

void subtract() { 
    double num1, num2; 
    printf("Enter two numbers to subtract: "); 
    scanf("%lf %lf", &num1, &num2); 
    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2); 
}

void multiply() { 
    double num1, num2; 
    printf("Enter two numbers to multiply: "); 
    scanf("%lf %lf", &num1, &num2); 
    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2); 
}

void divide() { 
    double num1, num2; 
    printf("Enter two numbers to divide: "); 
    scanf("%lf %lf", &num1, &num2); 
    if (num2 != 0) { 
        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2); 
    } else { 
        printf("Error! Division by zero is not allowed. 🚫\n"); 
    } 
}

void sine() { 
    double angle; 
    printf("Enter the angle in degrees for sine calculation: "); 
    scanf("%lf", &angle); 
    angle = angle * (M_PI / 180); // Convert degrees to radians
    printf("Result: sin(%.2lf) = %.2lf\n", angle * (180 / M_PI), sin(angle)); 
}

void cosine() { 
    double angle; 
    printf("Enter the angle in degrees for cosine calculation: "); 
    scanf("%lf", &angle); 
    angle = angle * (M_PI / 180); // Convert degrees to radians
    printf("Result: cos(%.2lf) = %.2lf\n", angle * (180 / M_PI), cos(angle)); 
}

void tangent() { 
    double angle; 
    printf("Enter the angle in degrees for tangent calculation: "); 
    scanf("%lf", &angle); 
    angle = angle * (M_PI / 180); // Convert degrees to radians
    printf("Result: tan(%.2lf) = %.2lf\n", angle * (180 / M_PI), tan(angle)); 
}