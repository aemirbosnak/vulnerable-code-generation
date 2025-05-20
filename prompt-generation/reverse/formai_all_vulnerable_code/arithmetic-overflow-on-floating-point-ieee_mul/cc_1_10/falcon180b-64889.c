//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x, y, z;
    int choice;
    char again;
    
    do {
        printf("Enter a number: ");
        scanf("%lf", &x);
        printf("Enter an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                y = x + x;
                printf("%.2lf + %.2lf = %.2lf\n", x, x, y);
                break;
            case 2:
                y = x - x;
                printf("%.2lf - %.2lf = %.2lf\n", x, x, y);
                break;
            case 3:
                y = x * x;
                printf("%.2lf * %.2lf = %.2lf\n", x, x, y);
                break;
            case 4:
                if (x == 0) {
                    printf("Cannot divide by zero.\n");
                } else {
                    y = x / x;
                    printf("%.2lf / %.2lf = %.2lf\n", x, x, y);
                }
                break;
            case 5:
                y = sqrt(x);
                printf("sqrt(%.2lf) = %.2lf\n", x, y);
                break;
            default:
                printf("Invalid choice.\n");
        }
        
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');
    
    return 0;
}