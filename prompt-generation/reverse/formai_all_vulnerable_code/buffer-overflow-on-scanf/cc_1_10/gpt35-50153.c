//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

//function to check if given number is prime or not
int is_prime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i=2;i<n;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

//function to print the first n prime numbers
void print_primes(int n){
    int count = 0;
    int num = 2;
    printf("The first %d prime numbers are: ",n);
    while(count < n){
        if(is_prime(num)){
            printf("%d ",num);
            count++;
        }
        num++;
    }
    printf("\n");
}

//function to check if given number is even or not
int is_even(int n){
    if(n%2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

//function to print the sum of first n even numbers
void print_even_sum(int n){
    int sum = 0;
    int num = 2;
    printf("The sum of first %d even numbers is: ",n);
    while(n > 0){
        if(is_even(num)){
            sum += num;
            n--;
        }
        num++;
    }
    printf("%d\n",sum);
}

//function to print the first n fibonacci numbers
void print_fibonacci(int n){
    int a = 0, b = 1, c;
    printf("The first %d fibonacci numbers are: ",n);
    for(int i=1;i<=n;i++){
        printf("%d ",a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

//function to find the factorial of given number
int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

//function to print the first n factorial numbers
void print_factorial(int n){
    printf("The first %d factorial numbers are: ",n);
    for(int i=0;i<n;i++){
        printf("%d ",factorial(i));
    }
    printf("\n");
}

int main(){
    int choice, n;
    printf("Enter the number of tasks: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the task to be performed (1-Print Primes, 2-Print Even Sum, 3-Print Fibonacci, 4-Print Factorial): ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number of primes to be printed: ");
                scanf("%d",&n);
                print_primes(n);
                break;
            case 2:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                print_even_sum(n);
                break;
            case 3:
                printf("Enter the number of fibonacci numbers to be printed: ");
                scanf("%d",&n);
                print_fibonacci(n);
                break;
            case 4:
                printf("Enter the number of factorial numbers to be printed: ");
                scanf("%d",&n);
                print_factorial(n);
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}