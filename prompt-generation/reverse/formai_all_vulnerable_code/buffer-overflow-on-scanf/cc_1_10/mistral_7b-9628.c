//MISTRAL-7B DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERANDS 10

void swap(int* a, int* b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

int main() {
 char operator;
 int operands[MAX_OPERANDS];
 int top = 0;

 printf("Enter numbers and operators (+, -, *, /)\n");
 printf("Enter a number to stop\n");

 while (top < MAX_OPERANDS) {
 scanf("%c%d", &operator, &operands[top]);

 // Check for invalid input
 if (operator == ' ' || (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '\n')) {
 printf("Invalid input! Please enter a valid operator or a number.\n");
 return 1;
 }

 if (operator == '\n') {
 // Perform calculation
 int i, result;

 if (top < 2) {
 printf("Not enough operands to perform calculation.\n");
 return 1;
 }

 for (i = top - 1; i >= 0; i--) {
 // Perform calculation between the top and current operands
 switch (operands[i]) {
 case '+':
 result = operands[i + 1] + operands[i];
 break;
 case '-':
 result = operands[i + 1] - operands[i];
 break;
 case '*':
 result = operands[i + 1] * operands[i];
 break;
 case '/':
 // Check for division by zero
 if (operands[i + 1] == 0) {
 printf("Error: Division by zero.\n");
 return 1;
 }
 result = operands[i + 1] / operands[i];
 break;
 default:
 printf("Error: Unknown operator.\n");
 return 1;
 }

 // Replace the top two operands with the result and the next operand
 swap(&operands[i], &operands[i + 1]);
 // Update the top
 top--;

 // Update the result variable with the new result
 result = operands[top];
 }

 printf("Result: %d\n", result);
 top = 0; // Reset the top to 0
 } else {
 // Add the new operand to the stack
 top++;
 }
 }

 return 0;
}