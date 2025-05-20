//FormAI DATASET v1.0 Category: Scientific ; Style: lively
#include<stdio.h>
#include<math.h>

int main(){
    printf("Welcome to the Scientific Calculator!\n");
    int choice=0;
    float num1,num2,result;
    char ch;
    while(choice!=5){
        printf("\nPlease choose from the following options:\n");
        printf("1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Exit\n\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Addition:\n");
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result=num1+num2;
                printf("The sum of %f and %f is %f.\n",num1,num2,result);
                break;
            case 2:
                printf("Subtraction:\n");
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result=num1-num2;
                printf("The difference of %f and %f is %f.\n",num1,num2,result);
                break;
            case 3:
                printf("Multiplication:\n");
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result=num1*num2;
                printf("The product of %f and %f is %f.\n",num1,num2,result);
                break;
            case 4:
                printf("Division:\n");
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                if(num2!=0){
                    result=num1/num2;
                    printf("The quotient of %f and %f is %f.\n",num1,num2,result);
                }else{
                    printf("Cannot divide by zero.\n");
                }
                break;
            case 5:
                printf("Thank you for using the Scientific Calculator!\n");
                break;
            default:
                printf("Invalid choice, please enter a number from 1 to 5.\n");
        }
    }
    return 0;
}