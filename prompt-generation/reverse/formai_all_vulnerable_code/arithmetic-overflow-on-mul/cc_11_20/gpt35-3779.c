//FormAI DATASET v1.0 Category: Arithmetic ; Style: careful
#include<stdio.h>

int main(){
    int num1, num2, sum, diff, prod, quo;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;

    printf("\nSum of %d and %d is: %d", num1, num2, sum);
    printf("\nDifference between %d and %d is: %d", num1, num2, diff);
    printf("\nProduct of %d and %d is: %d", num1, num2, prod);
    printf("\nQuotient of %d and %d is: %d", num1, num2, quo);

    //Checking if the numbers are even or odd
    if(num1%2 == 0)
        printf("\n%d is even.", num1);
    else
        printf("\n%d is odd.",num1);

    if(num2%2 == 0)
        printf("\n%d is even.", num2);
    else
        printf("\n%d is odd.", num2);

    //Checking if the numbers are prime or not
    int i, flag1 = 0, flag2 = 0;
    for(i=2; i<=num1/2; i++){
        if(num1%i == 0){
            flag1 = 1;
            break;
        }
    }
    if(num1 == 1)
        printf("\n1 is neither prime nor composite.");
    else{
        if(flag1 == 0)
            printf("\n%d is a prime number.", num1);
        else
            printf("\n%d is not a prime number.", num1);
    }

    for(i=2; i<=num2/2; i++){
        if(num2%i == 0){
            flag2 = 1;
            break;
        }
    }
    if(num2 == 1)
        printf("1 is neither prime nor composite.");
    else{
        if(flag2 == 0)
            printf("\n%d is a prime number.", num2);
        else
            printf("\n%d is not a prime number.", num2);
    }

    //Checking if the numbers are Armstrong or not
    int numCopy1 = num1;
    int numCopy2 = num2;
    int rem, count1 = 0, count2 = 0;

    while(numCopy1 != 0){
        rem = numCopy1 % 10;
        count1 += rem * rem * rem;
        numCopy1 /= 10;
    }
    if(count1 == num1)
        printf("\n%d is an Armstrong number.", num1);
    else
        printf("\n%d is not an Armstrong number.", num1);

    while(numCopy2 != 0){
        rem = numCopy2 % 10;
        count2 += rem * rem * rem;
        numCopy2 /= 10;
    }
    if(count2 == num2)
        printf("\n%d is an Armstrong number.", num2);
    else
        printf("\n%d is not an Armstrong number.", num2);

    return 0;
}