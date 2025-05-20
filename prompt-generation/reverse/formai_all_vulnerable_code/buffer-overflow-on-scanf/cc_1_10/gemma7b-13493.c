//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void calc(int n)
{
    switch (n)
    {
        case 1:
            printf("Square of a number is: %d", n * n);
            break;
        case 2:
            printf("Cubed of a number is: %d", n * n * n);
            break;
        case 3:
            printf("Logarithm of a number is: %f", log(n));
            break;
        default:
            printf("Invalid operation");
            break;
    }
}

int main()
{
    int choice;
    float num;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%f", &num);
            calc(1);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%f", &num);
            calc(2);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%f", &num);
            calc(3);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}