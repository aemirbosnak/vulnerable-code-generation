//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void draw_shape(int type, int size) {
    switch(type) {
        case 1: // Draw a square
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 2: // Draw a right triangle
            for(int i = 1; i <= size; i++) {
                for(int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 3: // Draw a pyramid
            for(int i = 1; i <= size; i++) {
                for(int j = size; j > i; j--) {
                    printf("  "); // Space for pyramid shape
                }
                for(int j = 1; j <= (2 * i - 1); j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 4: // Draw an inverted triangle
            for(int i = size; i >= 1; i--) {
                for(int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid shape type.\n");
            break;
    }
}

int arithmetic_menu() {
    int choice;
    printf("\nArithmetic Operations:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Shape Shifter\n");
    printf("Choose an operation (1-6): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    while(1) {
        int choice = arithmetic_menu();
        
        if (choice == 6) { // Shape Shifter menu
            int shape_choice, size;
            printf("Choose a shape:\n");
            printf("1. Square\n");
            printf("2. Right Triangle\n");
            printf("3. Pyramid\n");
            printf("4. Inverted Triangle\n");
            printf("Enter your shape choice (1-4): ");
            scanf("%d", &shape_choice);
            printf("Enter size of shape: ");
            scanf("%d", &size);
            draw_shape(shape_choice, size);
            continue;
        }
        
        if (choice < 1 || choice > 5) {
            printf("Exiting program.\n");
            break;
        }

        double num1, num2, result;

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch(choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            case 5:
                result = 1;
                for(int i = 0; i < num2; i++) {
                    result *= num1;
                }
                printf("Result: %.2lf ^ %.0lf = %.2lf\n", num1, num2, result);
                break;
            default:
                printf("Invalid operation.\n");
                break;
        }
    }
    
    return 0;
}