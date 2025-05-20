//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.14159265358979323846

int main()
{
    double a, b, res;
    int choice, flag=1;

    printf("Welcome to Paranoid Scientific Calculator\n");

    do
    {
        printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Sine\n6. Cosine\n7. Tangent\n8. Square Root\n9. Power\n10. Exit\n");

        printf("Enter your choice(1-10): ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4)
        {
            printf("Enter two operands: ");
            scanf("%lf %lf", &a, &b);
        }
        else if(choice >=5 && choice <= 9)
        {
            printf("Enter an operand: ");
            scanf("%lf", &a);
            b = 0;
        }
        else if(choice == 10)
        {
            printf("Thank you for using Paranoid Scientific Calculator!\n");
            exit(0);
        }
        else
        {
            printf("Invalid choice! Try again.\n");
            flag = 0;
            continue;
        }

        switch(choice)
        {
            case 1:
                res = a + b;
                printf("%.2lf + %.2lf = %.2lf\n", a, b, res);
                break;
            case 2:
                res = a - b;
                printf("%.2lf - %.2lf = %.2lf\n", a, b, res);
                break;
            case 3:
                res = a * b;
                printf("%.2lf * %.2lf = %.2lf\n", a, b, res);
                break;
            case 4:
                if(b == 0)
                {
                    printf("Error: Division by zero!\n");
                    flag = 0;
                    continue;
                }
                res = a / b;
                printf("%.2lf / %.2lf = %.2lf\n", a, b, res);
                break;
            case 5:
                res = sin(a * PI / 180);
                printf("sin(%.2lf) = %.2lf\n", a, res);
                break;
            case 6:
                res = cos(a * PI / 180);
                printf("cos(%.2lf) = %.2lf\n", a, res);
                break;
            case 7:
                res = tan(a * PI / 180);
                printf("tan(%.2lf) = %.2lf\n", a, res);
                break;
            case 8:
                if(a < 0)
                {
                    printf("Error: Square root of negative number!\n");
                    flag = 0;
                    continue;
                }
                res = sqrt(a);
                printf("sqrt(%.2lf) = %.2lf\n", a, res);
                break;
            case 9:
                res = pow(a,b);
                printf("%.2lf ^ %.2lf = %.2lf\n", a, b, res);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                flag = 0;
                break;
        }

        flag=1;

    }while(choice != 10);

    return 0;
}