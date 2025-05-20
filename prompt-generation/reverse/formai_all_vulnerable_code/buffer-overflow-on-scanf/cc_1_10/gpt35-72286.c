//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include<stdio.h>
#include<math.h>

//Function to check if the entered number is a prime number
int isPrime(int num){
    int i;
    for(i=2;i<=sqrt(num);i++){
        if(num%i==0)return 0;    //Not a Prime Number
    }
    return 1;                    //Is a Prime Number
}

//Function to calculate the factorial of a number
int factorial(int num){
    int fact=1,i;
    for(i=num;i>0;i--)fact*=i;   //Calculate Factorial
    return fact;
}

int main(){
    int num,ch,result;           //Variables
    printf("================================================\n");
    printf("\tWelcome to Scientific Calculator\n");
    printf("================================================\n");
    printf("Enter the number: ");
    scanf("%d",&num);             //Accepting the number
    printf("\n");
    printf("================================================\n");
    printf("\tEnter your choice:\n");
    printf("================================================\n");
    printf("\t1. Check Prime Number\n");
    printf("\t2. Find Factorial\n");
    printf("================================================\n");
    scanf("%d",&ch);             //Accepting the choice
    switch(ch){
        case 1:                 //If choice = 1, check if the number is prime or not
            result=isPrime(num);
            if(result==1)printf("%d is a prime number.\n",num);
            else printf("%d is not a prime number.\n",num);
            break;
        case 2:                 //If choice = 2, calculate the factorial of the number
            result=factorial(num);
            printf("The factorial of %d is %d.\n",num,result);
            break;
        default:                //If choice is not valid
            printf("Please enter a valid choice.\n");
            break;
    }
    printf("================================================\n");
    return 0;
}