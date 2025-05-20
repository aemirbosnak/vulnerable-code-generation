//FormAI DATASET v1.0 Category: Educational ; Style: shocked
#include <stdio.h>

int main() {

int age;

printf("Enter your age: ");

scanf("%d",&age);

if (age < 18) {

printf("You're too young to be programming in C!");

}

else {

printf("Welcome! Let's get started with some programming examples:\n\n");

printf("1. Calculate the factorial of a number\n");

printf("2. Find the largest of three numbers\n");

printf("3. Check if a number is prime\n");

printf("4. Convert Celsius to Fahrenheit\n");

printf("5. Find the sum of n natural numbers\n\n");

int choice;

printf("Enter your choice: ");

scanf("%d",&choice);

switch (choice) {

case 1:

{

int n;

printf("Enter a number: ");

scanf("%d",&n);

int fact=1;

for(int i=1;i<=n;i++) {

fact *= i;

}

printf("Factorial of %d is: %d\n",n,fact);

break;

}

case 2:

{

int num1,num2,num3;

printf("Enter three numbers: ");

scanf("%d %d %d",&num1,&num2,&num3);

if(num1>num2 && num1>num3) {

printf("%d is the largest number.\n",num1);

} else if(num2>num1 && num2>num3) {

printf("%d is the largest number.\n",num2);

} else {

printf("%d is the largest number.\n",num3);

}

break;

}

case 3:

{

int num;

printf("Enter a number: ");

scanf("%d",&num);

int flag=0;

for(int i=2;i<=num/2;i++) {

if(num%i==0) {

flag=1;

break;

}

}

if(flag==0) {

printf("%d is a prime number.\n",num);

} else {

printf("%d is not a prime number.\n",num);

}

break;

}

case 4:

{

float celsius;

printf("Enter temperature in Celsius: ");

scanf("%f",&celsius);

float fahrenheit = (celsius * 9/5) + 32;

printf("%.2f Celsius is equal to %.2f Fahrenheit\n",celsius,fahrenheit);

break;

}

case 5:

{

int n;

printf("Enter the value of n: ");

scanf("%d",&n);

int sum=0;

for(int i=1;i<=n;i++) {

sum += i;

}

printf("Sum of first %d natural numbers is: %d\n",n,sum);

break;

}

default:

printf("Invalid choice!\n");

break;

}

}

return 0;

}