//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j;
    int num1,num2;
    int choice;
    int mask;
    int result;
    int shift;

    printf("Enter the first integer:\n");
    scanf("%d",&num1);

    printf("Enter the second integer:\n");
    scanf("%d",&num2);

    printf("Enter the operation:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. LEFT SHIFT\n");
    printf("6. RIGHT SHIFT\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            /* AND operation */
            result = num1 & num2;
            printf("The result is %d\n",result);
            break;

        case 2:
            /* OR operation */
            result = num1 | num2;
            printf("The result is %d\n",result);
            break;

        case 3:
            /* XOR operation */
            result = num1 ^ num2;
            printf("The result is %d\n",result);
            break;

        case 4:
            /* NOT operation */
            result = ~num1;
            printf("The result is %d\n",result);
            break;

        case 5:
            /* LEFT SHIFT operation */
            shift = rand() % 10;
            result = num1 << shift;
            printf("The result is %d\n",result);
            break;

        case 6:
            /* RIGHT SHIFT operation */
            shift = rand() % 10;
            result = num1 >> shift;
            printf("The result is %d\n",result);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}