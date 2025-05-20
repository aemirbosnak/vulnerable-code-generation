//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int addition(int a, int b){
    return a+b;
}

int multiplication(int a, int b){
    return a*b;
}

int subtraction(int a, int b){
    return a-b;
}

int division(int a, int b){
    if(b == 0){
        printf("Cannot divide by zero");
        return 0;
    }else{
        return a/b;
    }
}

int modulus(int a, int b){
    if(b == 0){
        printf("Cannot mod by zero");
        return 0;
    }else{
        return a%b;
    }
}

int main(){
    int a, b;
    char operation;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Enter the operation you want to perform (+,-,*,/,%%):\n");
    scanf(" %c", &operation); //leave space before %c to consume newline character from previous input 
    if(operation == '+'){
        printf("The sum of %d and %d is %d", a, b, addition(a,b));
    }else if(operation == '-'){
        printf("The difference between %d and %d is %d", a, b, subtraction(a,b));
    }else if(operation == '*'){
        printf("The product of %d and %d is %d", a, b, multiplication(a,b));
    }else if(operation == '/'){
        printf("%d divided by %d is %d with a remainder of %d", a, b, division(a,b), modulus(a,b));
    }else if(operation == '%'){
        printf("%d mod %d is %d", a, b, modulus(a,b));
    }else{
        printf("Invalid operator");
    }
    return 0;
}