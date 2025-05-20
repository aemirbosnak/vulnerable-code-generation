//Gemma-7B DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX], d[MAX];
    float avg, sum = 0.0f;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the operations (+, -, *, /): ");
    scanf("%s", b);

    printf("Enter the constants: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }

    for(i = 0; i < n; i++)
    {
        switch(b[i])
        {
            case '+':
                d[i] = a[i] + c[i];
                break;
            case '-':
                d[i] = a[i] - c[i];
                break;
            case '*':
                d[i] = a[i] * c[i];
                break;
            case '/':
                if(c[i] == 0)
                {
                    printf("Error: Cannot divide by zero\n");
                    exit(1);
                }
                d[i] = a[i] / c[i];
                break;
            default:
                printf("Error: Invalid operation\n");
                exit(1);
        }
    }

    printf("The results are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\nThe average is: %.2f", avg = (sum / n));

    return 0;
}