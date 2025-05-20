//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option = 0;

    while(option != 5)
    {
        printf("\n\nLet's do some math!\n");
        printf("------------------------\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nAddition!\n");
                int num1, num2, result;
                printf("Enter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("%d + %d = %d\n", num1, num2, result);
                break;
            case 2:
                printf("\nSubtraction!\n");
                int num3, num4, result2;
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &num3, &num4);
                result2 = num3 - num4;
                printf("%d - %d = %d\n", num3, num4, result2);
                break;
            case 3:
                printf("\nMultiplication!\n");
                int num5, num6, result3;
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &num5, &num6);
                result3 = num5 * num6;
                printf("%d * %d = %d\n", num5, num6, result3);
                break;
            case 4:
                printf("\nDivision!\n");
                int num7, num8;
                float result4;
                printf("Enter two numbers to divide: ");
                scanf("%d %d", &num7, &num8);
                if(num8 != 0)
                {
                    result4 = (float)num7 / (float)num8;
                    printf("%d / %d = %.2f\n", num7, num8, result4);
                }
                else
                {
                    printf("Error: Division by zero!\n");
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    }

    return 0;
}