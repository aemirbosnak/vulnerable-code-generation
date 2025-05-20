//FormAI DATASET v1.0 Category: Calculator ; Style: statistical
#include<stdio.h>
#include<math.h>

int main()
{
    float num1,num2,result;
    char operator;
    printf("Enter two numbers and the operator (+,-,*,/): ");
    scanf("%f %c %f",&num1,&operator,&num2);

    switch(operator)
    {
        case '+': result=num1+num2;
                  printf("%.2f %c %.2f = %.2f",num1,operator,num2,result);
                  break;

        case '-': result=num1-num2;
                  printf("%.2f %c %.2f = %.2f",num1,operator,num2,result);
                  break;

        case '*': result=num1*num2;
                  printf("%.2f %c %.2f = %.2f",num1,operator,num2,result);
                  break;

        case '/': if(num2==0)
                  {
                      printf("The denominator cannot be zero!");
                      break;
                  }
                  else
                  {
                      result=num1/num2;
                      printf("%.2f %c %.2f = %.2f",num1,operator,num2,result);
                      break;
                  }

        case '%': if(num2==0)
                  {
                      printf("The denominator cannot be zero!");
                      break;
                  }
                  else
                  {
                      result=fmod(num1,num2);
                      printf("%.2f %c %.2f = %.2f",num1,operator,num2,result);
                      break;
                  }
        default: printf("Invalid operator!");
    }
    return 0;
}