//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

/*Function to calculate sum of two numbers*/
int add(int a, int b){
    return a+b;
}

/*Function to calculate difference of two numbers*/
int subtract(int a, int b){
    return a-b;
}

/*Function to calculate product of two numbers*/
int multiply(int a, int b){
    return a*b;
}

/*Function to calculate quotient of two numbers*/
int divide(int a, int b){
    if(b==0){
        printf("Error: Cannot divide by zero\n");
        exit(0);
    }
    return a/b;
}

int main(){
    int a,b,ch,res;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    printf("Enter choice:\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: res=add(a,b);
                printf("The sum is: %d\n",res);
                break;
        case 2: res=subtract(a,b);
                printf("The difference is: %d\n",res);
                break;
        case 3: res=multiply(a,b);
                printf("The product is: %d\n",res);
                break;
        case 4: res=divide(a,b);
                printf("The quotient is: %d\n",res);
                break;
        default:printf("Invalid choice\n");
    }
    return 0;
}