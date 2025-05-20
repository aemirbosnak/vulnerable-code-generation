//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include<stdio.h>
#include<stdlib.h>

float addition(float a, float b)
{
    return a+b;
}

float subtraction(float a, float b)
{
    return a-b;
}

float multiplication(float a, float b)
{
    return a*b;
}

float division(float a, float b)
{
    return a/b;
}

float power(float a, float b)
{
    float result=1.0;
    for(int i=0;i<b;i++)
    {
        result *= a;
    }
    return result;
}

int main()
{
    int choice;
    float num1,num2,result;
    
    while(1)
    {
        printf("\n\n-------------------------------------\n");
        printf("\t~~~Scientific Calculator~~~\n");
        printf("-------------------------------------\n");
        printf("Enter your choice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Exit\n");
        scanf("%d",&choice);
        
        if(choice==6)
        {
            printf("\n\nThank you for using the calculator!\n\n");
            break;
        }
        
        printf("Enter two numbers:\n");
        scanf("%f%f",&num1,&num2);
        
        switch(choice)
        {
            case 1:
                result = addition(num1,num2);
                printf("\n%.2f + %.2f = %.2f\n",num1,num2,result);
                break;
                
            case 2:
                result = subtraction(num1,num2);
                printf("\n%.2f - %.2f = %.2f\n",num1,num2,result);
                break;
                
            case 3:
                result = multiplication(num1,num2);
                printf("\n%.2f * %.2f = %.2f\n",num1,num2,result);
                break;
                
            case 4:
                if(num2==0)
                {
                    printf("\nDivide by zero error!\n");
                    exit(0);
                }
                else
                {
                    result = division(num1,num2);
                    printf("\n%.2f / %.2f = %.2f\n",num1,num2,result);
                }
                break;
                
            case 5:
                result = power(num1,num2);
                printf("\n%.2f ^ %.2f = %.2f\n",num1,num2,result);
                break;
                
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    
    return 0;
}