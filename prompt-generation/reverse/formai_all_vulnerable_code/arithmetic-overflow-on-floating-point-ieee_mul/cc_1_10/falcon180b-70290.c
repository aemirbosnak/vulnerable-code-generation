//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

int main()
{
    int i,j;
    float a,b,c;
    char d;
    
    printf("Enter a number: ");
    scanf("%f",&a);
    
    printf("Enter an operator (+,-,*,/): ");
    scanf("%c",&d);
    
    switch(d)
    {
        case '+':
            printf("Enter another number: ");
            scanf("%f",&b);
            c=a+b;
            printf("Result: %.10f\n",c);
            break;
            
        case '-':
            printf("Enter another number: ");
            scanf("%f",&b);
            c=a-b;
            printf("Result: %.10f\n",c);
            break;
            
        case '*':
            printf("Enter another number: ");
            scanf("%f",&b);
            c=a*b;
            printf("Result: %.10f\n",c);
            break;
            
        case '/':
            printf("Enter another number: ");
            scanf("%f",&b);
            if(b==0)
            {
                printf("Error! Division by zero is not allowed.\n");
            }
            else
            {
                c=a/b;
                printf("Result: %.10f\n",c);
            }
            break;
            
        default:
            printf("Invalid operator!\n");
            break;
    }
    
    return 0;
}