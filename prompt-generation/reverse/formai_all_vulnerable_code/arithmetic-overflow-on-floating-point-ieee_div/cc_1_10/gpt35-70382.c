//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){

    int a,b,choice,result;
    float fresult;

    printf("Welcome to the Funny Calculator Program!\n\n");

    do{
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("\n\nHey, I heard that you want to perform Addition operation! Cool...\n");
                    printf("Enter two numbers: ");
                    scanf("%d",&a);
                    scanf("%d",&b);
                    result = a+b;
                    printf("Calculating....\n\n");
                    printf("Whoa! The result is %d \n",result); 
                    break;

            case 2: printf("\n\nOh, no! Subtraction operation. The world is becoming minus and lesser!!!!\n");
                    printf("Enter two numbers: ");
                    scanf("%d",&a);
                    scanf("%d",&b);
                    result = a-b;
                    printf("Calculating....\n\n");
                    printf("Not bad, you beat the minus world. The result is %d \n",result);
                    break;

            case 3: printf("\n\nHey, I am good in Multiplication. But can you calculate 1x1?\n");
                    printf("Enter two numbers: ");
                    scanf("%d",&a);
                    scanf("%d",&b);
                    result = a*b;
                    printf("Calculating....\n\n");
                    printf("Good job! You are a pro. The result is %d \n",result);
                    break;

            case 4: printf("\n\nAahh! Division. Remember, don't divide by 0. It's dangerous!!\n");
                    printf("Enter two numbers: ");
                    scanf("%d",&a);
                    scanf("%d",&b);
                    fresult = (float)a/b;
                    printf("Calculating....\n\n");
                    printf("Excellent! The result is %f \n",fresult);
                    break;

            case 5: printf("\n\nGoodbye! Keep Calculating and stay Funny!\n");
                    exit(0);

            default: printf("\n\nOh no! You entered a wrong choice. Try again!!!\n\n");

        }

    }while(choice!=5);

    return 0;
}