//FormAI DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   printf("\nWelcome to the Surrealist Password Management System!\n");

   char password[100], answer[100];
   char secret[100];

   printf("\nPlease enter a new password:\n");
   scanf("%s", password);

   printf("\nGreat! Now, answer the following question:\n");
   printf("What is the capital of the moon?\n");
   scanf("%s", answer);

   if(strcmp(answer, "dali") == 0) {
      printf("\nYour answer is correct!\n");

      printf("\nNow, let's generate a secret code...\n");

      srand(time(NULL));
      int rand_num = rand() % 3;
      char code[100];
      if(rand_num == 0) {
         strcpy(code, "elephanttrousersoctopusbicycle");
      } else if(rand_num == 1) {
         strcpy(code, "sunflowerpaintbucketumbrella");
      } else {
         strcpy(code, "bananashoebutterflytelephone");
      }

      printf("\nYour secret code is: %s\n", code);

      printf("\nPlease enter your password again to confirm:\n");
      scanf("%s", secret);

      if(strcmp(secret, password) == 0) {
         printf("\nSuccess! Your password and secret code are now saved in the Surrealist Password Management System!\n");
      } else {
         printf("\nSorry, your confirmation password does not match.\n");
      }

   } else {
      printf("\nSorry, your answer is incorrect. You may not access the Surrealist Password Management System.\n");
   }

   return 0;
}