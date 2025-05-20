//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include<stdio.h>

//function to perform addition
int add(int a, int b){
  return a + b;
}

//function to perform subtraction
int sub(int a, int b){
  return a - b;
}

//function to perform multiplication
int mul(int a, int b){
  return a * b;
}

//function to perform division
float divide(int a, int b){
  return (float)a/b;
}

//function to perform modulus operation
int modulus(int a, int b){
  return a % b;
}

int main(){
  int num1, num2, choice;
  
  //prompting user to enter the numbers
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  //Menu for different arithmetic operations
  printf("Choose an arithmetic operation: \n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Modulus\n");
  scanf("%d", &choice);
  
  //switch case to perform operations based on user's choice
  switch(choice){
    case 1:
      printf("%d + %d = %d\n", num1, num2, add(num1,num2));
      break;
    case 2:
      printf("%d - %d = %d\n", num1, num2, sub(num1,num2));
      break;
    case 3:
      printf("%d * %d = %d\n", num1, num2, mul(num1,num2));
      break;
    case 4:
      printf("%d / %d = %.2f\n", num1, num2, divide(num1,num2));
      break;
    case 5:
      printf("%d %% %d = %d\n", num1, num2, modulus(num1,num2));
      break;
    default:
      printf("Invalid choice, Please try again\n");
      break;
  }
  
  return 0;
}