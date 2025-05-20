//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include<stdio.h>
#include<math.h>

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}

float power(float a, int b){
    float result = 1;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}

float factorial(float n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int main(){

    int choice;
    float a, b, result;

    printf("Welcome to the C Scientific Calculator Implementation\n");

    do{
        printf("\nMenu:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1: {
                printf("Enter two numbers to add: ");
                scanf("%f%f",&a,&b);
                result = add(a, b);
                printf("%.2f + %.2f = %.2f\n", a, b, result);
                break;
            }

            case 2: {
                printf("Enter two numbers to subtract: ");
                scanf("%f%f",&a,&b);
                result = subtract(a, b);
                printf("%.2f - %.2f = %.2f\n", a, b, result);
                break;
            }

            case 3: {
                printf("Enter two numbers to multiply: ");
                scanf("%f%f",&a,&b);
                result = multiply(a, b);
                printf("%.2f * %.2f = %.2f\n", a, b, result);
                break;
            }

            case 4: {
                printf("Enter two numbers to divide: ");
                scanf("%f%f",&a,&b);
                result = divide(a, b);
                printf("%.2f / %.2f = %.2f\n", a, b, result);
                break;
            }

            case 5: {
                printf("Enter a number: ");
                scanf("%f",&a);
                printf("Enter the power: ");
                int b;
                scanf("%d",&b);
                result = power(a, b);
                printf("%.2f ^ %d = %.2f\n", a, b, result);
                break;
            }

            case 6: {
                printf("Enter a number to find factorial: ");
                scanf("%f",&a);
                result = factorial(a);
                printf("%.2f! = %.2f\n", a, result);
                break;
            }

            case 7: {
                printf("Thanks for using our C Scientific Calculator Implementation\n");
                break;
            }

            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    while(choice != 7);

    return 0;
}