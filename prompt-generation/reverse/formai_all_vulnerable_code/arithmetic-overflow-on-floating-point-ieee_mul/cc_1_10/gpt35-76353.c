//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2;

    printf("Oh Scientific Calculator, how doth thou desire to proceed? (+, -, *, /, sin, cos, log, sqrt): ");
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            printf("Enter thy first number: ");
            scanf("%lf", &num1);
            printf("Enter thy second number: ");
            scanf("%lf", &num2);
            printf("The sum of thine numbers is: %lf", num1+num2);
            break;

        case '-':
            printf("Enter thy first number: ");
            scanf("%lf", &num1);
            printf("Enter thy second number: ");
            scanf("%lf", &num2);
            printf("The difference of thine numbers is: %lf", num1-num2);
            break;

        case '*':
            printf("Enter thy first number: ");
            scanf("%lf", &num1);
            printf("Enter thy second number: ");
            scanf("%lf", &num2);
            printf("The product of thine numbers is: %lf", num1*num2);
            break; 

        case '/':
            printf("Enter thy first number: ");
            scanf("%lf", &num1);
            printf("Enter thy second number: ");
            scanf("%lf", &num2);
            if(num2 == 0) {
                printf("Thee cannot divide by zero!");
            } else {
                printf("The quotient of thine numbers is: %lf", num1/num2);
            }   
            break;

        case 's':
            printf("Enter thy number: ");
            scanf("%lf", &num1);
            printf("The sine of thine number is: %lf", sin(num1));
            break;

        case 'c':
            printf("Enter thy number: ");
            scanf("%lf", &num1);
            printf("The cosine of thine number is: %lf", cos(num1));
            break;

        case 'l':
            printf("Enter thy number: ");
            scanf("%lf", &num1);
            printf("The natural logarithm of thine number is: %lf", log(num1));
            break;

        case 'q':
            printf("Enter thy number: ");
            scanf("%lf", &num1);
            printf("The square root of thine number is: %lf", sqrt(num1));
            break;

        default:
            printf("Oh fate! I do not comprehend thy request. Please try again.");
            break;
    }
    return 0;
}