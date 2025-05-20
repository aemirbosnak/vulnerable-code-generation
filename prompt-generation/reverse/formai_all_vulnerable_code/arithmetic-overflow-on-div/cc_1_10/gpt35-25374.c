//FormAI DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

void error(int error_type){

switch(error_type){
   case 1:
      printf("ERROR: Division by zero.\n");
      exit(1);
      break;
   case 2:
      printf("ERROR: Array index out of bounds.\n");
      exit(1);
      break;
   default:
      printf("Unknown error.\n");
      exit(1);
      break;
   }
}

int main(){

   int dividend, divisor, quotient, dividend_array[10], index;
   float result;

   printf("Enter the dividend:\n");
   scanf("%d",&dividend);

   printf("Enter the divisor:\n");
   scanf("%d",&divisor);

   if(divisor==0){
      error(1); //division by zero error
   }

   quotient=dividend/divisor;
   printf("Quotient=%d\n",quotient);

   printf("\n\n");

   printf("Enter the index of the element you want to access:\n");
   scanf("%d",&index);

   if(index<0 || index>=10){
      error(2); //array index out of bounds error
   }
   printf("Element at index %d is %d\n",index,dividend_array[index]);

   return 0;
}