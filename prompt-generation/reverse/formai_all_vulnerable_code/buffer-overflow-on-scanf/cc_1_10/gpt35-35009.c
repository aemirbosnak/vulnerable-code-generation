//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
/* Hurray! Let's dive into the world of C Syntax Parsing */
#include <stdio.h>

int main() {
   int num;  // We declare an integer variable named num
   printf("Enter a number: ");
   scanf("%d", &num);  // We use scanf() to accept input from the user
   
   if(num % 2 == 0) {
      printf("Hurray! The number you entered is even.\n");  // We display a happy message for even numbers
   }
   
   else {
      printf("Oh no! The number you entered is odd.\n");  // We display a sad message for odd numbers
   }
   
   printf("Let's check the ASCII value of some characters. Enter a character: ");
   char ch;
   scanf(" %c", &ch);  // We accept a character input from the user
   
   printf("The ASCII value of %c is %d.\n", ch, ch);  // We display the ASCII value of the character
   
   printf("Now let's try out some boolean expressions. Enter two numbers: ");
   int n1, n2;
   scanf("%d%d", &n1, &n2);  // We accept two integer inputs from the user
   
   if(n1 > 0 && n2 > 0) {
      printf("Yay! Both numbers are positive.\n");  // We display a happy message for positive numbers
   }
   
   else {
      printf("Oops! At least one number is not positive.\n");  // We display a sad message for non-positive numbers
   }
   
   printf("Let's play a game. Enter a secret number between 1 and 10: ");
   int secret;
   scanf("%d", &secret);  // We accept a secret number input from the user
   
   printf("Now I will try to guess the secret number. ");
   for(int guess = 1; guess <= 10; guess++) {  // We use a for loop to guess the number
      if(guess == secret) {
         printf("Hurray! I guessed the secret number %d.\n", secret);  // We display a happy message for correct guesses
         break;
      }
      
      else {
         printf("%d is not the secret number.\n", guess);  // We display a message for incorrect guesses
      }
   }
   
   printf("Thanks for playing with me. See you soon! :)\n");  // We display a final message with a smiley face
   
   return 0;
}