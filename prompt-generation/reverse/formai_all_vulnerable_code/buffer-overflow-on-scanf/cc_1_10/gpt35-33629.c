//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <string.h>

int main() {
   char password[20], username[20];
   int login_attempts = 0;
   int max_attempts = 3;
   int success = 0;

   /* Get username and password from user */
   printf("Please enter username: ");
   scanf("%s", username);

   printf("Please enter password: ");
   scanf("%s", password);

   /* Check if login details are correct */
   while (login_attempts < max_attempts) {
      if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
         printf("Login successful!\n");
         success = 1;
         break;
      } else {
         printf("Login failed. Please try again.\n");
         login_attempts++;
         printf("You have %d attempts remaining.\n", max_attempts - login_attempts);
         printf("Please enter username: ");
         scanf("%s", username);
         printf("Please enter password: ");
         scanf("%s", password);
      }
   }

   /* If login is successful, run the program */
   if (success) {
      printf("Welcome to the program!\n");

      /* Add your program logic here */
      int num1, num2, sum;

      printf("Enter Number 1: ");
      scanf("%d", &num1);

      printf("Enter Number 2: ");
      scanf("%d", &num2);

      sum = num1 + num2;

      printf("Sum of %d and %d is: %d\n", num1, num2, sum);

   } else {
      printf("Login unsuccessful. Program will now exit.\n");
      return 0;
   }

   return 0;
}