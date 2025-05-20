//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include<stdio.h>

int main(){
    printf("Welcome to the surreal world of data mining!\n");

    int num1,num2,num3,num4;
    printf("\nEnter four integers separated by spaces:");
    scanf("%d %d %d %d",&num1,&num2,&num3,&num4);

    if(num1>num2 && num1>num3 && num1>num4){
        printf("\n %d is the largest integer.",num1);

        if(num2>num3 && num2>num4){
            printf("\n %d is the second largest integer.",num2);
        }
        else if(num3>num2 && num3>num4){
            printf("\n %d is the second largest integer.",num3);
        }
        else{
            printf("\n %d is the second largest integer.",num4);
        }
    }
    else if(num2>num1 && num2>num3 && num2>num4){
        printf("\n %d is the largest integer.",num2);

        if(num1>num3 && num1>num4){
            printf("\n %d is the second largest integer.",num1);
        }
        else if(num3>num1 && num3>num4){
            printf("\n %d is the second largest integer.",num3);
        }
        else{
            printf("\n %d is the second largest integer.",num4);
        }
    }
    else if(num3>num1 && num3>num2 && num3>num4){
        printf("\n %d is the largest integer.",num3);

        if(num1>num2 && num1>num4){
            printf("\n %d is the second largest integer.",num1);
        }
        else if(num2>num1 && num2>num4){
            printf("\n %d is the second largest integer.",num2);
        }
        else{
            printf("\n %d is the second largest integer.",num4);
        }
    }
    else{
        printf("\n %d is the largest integer.",num4);

        if(num1>num2 && num1>num3){
            printf("\n %d is the second largest integer.",num1);
        }
        else if(num2>num1 && num2>num3){
            printf("\n %d is the second largest integer.",num2);
        }
        else{
            printf("\n %d is the second largest integer.",num3);
        }
    }

    printf("\nThanks for exploring the surreal world of data mining!");
    return 0;
}