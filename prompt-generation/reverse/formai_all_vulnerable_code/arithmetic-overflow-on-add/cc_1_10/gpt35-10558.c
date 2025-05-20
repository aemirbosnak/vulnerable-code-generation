//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include<stdio.h>
#include<math.h>
#define PI 3.14159265

int main()
{
    int choice, num1, num2, result;
    float fnum1, fnum2, fresult;
    printf("\nWelcome to the Scientific Calculator");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Sin");
    printf("\n6. Cosine");
    printf("\n7. Tangent");
    printf("\n8. Square root");
    printf("\nPlease Enter Your Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter First Number: ");
            scanf("%d", &num1);
            printf("\nEnter Second Number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("\nResult: %d", result);
            break;
        case 2:
            printf("\nEnter First Number: ");
            scanf("%d", &num1);
            printf("\nEnter Second Number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("\nResult: %d", result);
            break;
        case 3:
            printf("\nEnter First Number: ");
            scanf("%d", &num1);
            printf("\nEnter Second Number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("\nResult: %d", result);
            break;
        case 4:
            printf("\nEnter First Number: ");
            scanf("%f", &fnum1);
            printf("\nEnter Second Number: ");
            scanf("%f", &fnum2);
            fresult = fnum1 / fnum2;
            printf("\nResult: %f", fresult);
            break;
        case 5:
            printf("\nEnter Angle in Degrees: ");
            scanf("%f", &fnum1);
            fresult = sin(fnum1 * PI / 180);
            printf("\nResult: %f", fresult);
            break;
        case 6:
            printf("\nEnter Angle in Degrees: ");
            scanf("%f", &fnum1);
            fresult = cos(fnum1 * PI / 180);
            printf("\nResult: %f", fresult);
            break;
        case 7:
            printf("\nEnter Angle in Degrees: ");
            scanf("%f", &fnum1);
            fresult = tan(fnum1 * PI / 180);
            printf("\nResult: %f", fresult);
            break;
        case 8:
            printf("\nEnter Number: ");
            scanf("%f", &fnum1);
            fresult = sqrt(fnum1);
            printf("\nResult: %f", fresult);
            break;

        default:
            printf("\nInvalid Choice");
            break;
    }
    return 0;
}