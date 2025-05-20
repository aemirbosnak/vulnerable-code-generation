//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include<stdio.h>

int main() {

int num1, num2, sum, product, quotient;
float difference;

printf("Welcome to my Genius Arithmetic Program!\n");
printf("Enter your first number: ");
scanf("%d", &num1);
printf("Enter your second number: ");
scanf("%d", &num2);

sum = num1 + num2;
product = num1 * num2;
difference = (float)num1 - (float)num2;
quotient = num1 / num2;

printf("\n\n*************************\n");
printf("The sum of %d and %d is: %d\n", num1, num2, sum);
printf("The product of %d and %d is: %d\n", num1, num2, product);
printf("The difference of %d and %d is: %.2f\n", num1, num2, difference);
printf("The quotient of %d and %d is: %d\n", num1, num2, quotient);
printf("*************************\n");

if (sum % 2 == 0) {
    printf("The sum of %d and %d is an even number.\n", num1, num2);
}
else {
    printf("The sum of %d and %d is an odd number.\n", num1, num2);
}

if (difference < 0) {
    printf("The difference of %d and %d is a negative number.\n", num1, num2);
}
else if (difference > 0){
    printf("The difference of %d and %d is a positive number.\n", num1, num2);
} 
else {
    printf("The difference of %d and %d is zero.\n", num1, num2);
}

if (product % 10 == 0) {
    printf("The product of %d and %d is a multiple of 10.\n", num1, num2);
}

if (quotient == 0) {
    printf("Cannot divide by zero. Please enter a valid number.\n");
}
else if (num1 % num2 == 0) {
    printf("%d is evenly divisible by %d.\n", num1, num2);
}
else {
    printf("%d is not evenly divisible by %d.\n", num1, num2);
}

return 0;

}