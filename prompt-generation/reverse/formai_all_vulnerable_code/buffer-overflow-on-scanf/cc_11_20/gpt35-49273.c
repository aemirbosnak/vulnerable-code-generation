//FormAI DATASET v1.0 Category: Log analysis ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char log[1000];
   char log2[100];
   char *token;
   char *word = "error";
   int count = 0;

   printf("Welcome to the Log Analysis Program!\n");
   printf("Please enter the log you want to analyze:\n");
   scanf("%[^\n]s", log);

   printf("Analyzing log...\n\n");

   strcpy(log2, log);

   token = strtok(log, " ");

   while (token != NULL) {
      if (strstr(token, word) != NULL)
         count++;
      token = strtok(NULL, " ");
   }

   if (count == 0)
      printf("No errors found! You must be a bug-free programmer!\n");

   else if (count == 1)
      printf("A single error found in the log!\nBetter call IT support!\n");

   else if (count == 69)
      printf("Woah! It seems like the universe doesn't want you to debug!\n");

   else if (count > 1 && count <= 5)
      printf("Multiple errors detected. Better roll up your sleeves and get to debuggin'!\n");

   else if (count > 5 && count <= 10)
      printf("The log suggests you may have a few issues to iron out. Be prepared to spend some sleepless nights debugging!\n");

   else if (count > 10 && count <= 50)
      printf("Gosh! You may have started to write spaghetti code! You might need to refactor your code soon unless you don't want to end up going insane!\n");

   else
      printf("OH NO! Your log contains more errors than pixels on your monitorscreen!\n");

   printf("\nHere's a summary of the log analysis report:\n");
   printf("-------------------------------------------------------\n");
   printf("Total number of words in log: %d\n", strlen(log2));
   printf("Number of times '%s' was found: %d\n", word, count);
   printf("-------------------------------------------------------\n");

   printf("Thank you for using our log analysis program!\n");
   printf("May your code debugging journey be filled with fewer headaches and much more fun! :-) \n");

   return 0;
}