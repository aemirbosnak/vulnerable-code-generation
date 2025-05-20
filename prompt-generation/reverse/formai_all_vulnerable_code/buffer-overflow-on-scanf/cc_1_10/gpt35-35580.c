//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int i, j, k, l, n, c, count = 0;
    char s[50], ch;
    time_t start_time, end_time;
    double time_diff;
    printf("Hello! Welcome to our romantic Typing Speed Test.\n");
    printf("In this test, you will be given a romantic quote,\n");
    printf("and you need to copy the quote as fast as possible.\n");
    printf("--------- Get ready to test your typing speed! ----------\n");
    printf("Press 'Enter' to start the test.");
    scanf("%c", &ch);
    printf("\n");
    char *quote = "I love you more than yesterday, less than tomorrow.";
    printf("Your task is to type the following romantic quote:\n");
    printf("%s\n", quote);
    start_time = time(NULL);
    fflush(stdin);
    fgets(s, 50, stdin);
    end_time = time(NULL);
    time_diff = difftime(end_time, start_time);
    printf("\nYou typed:\n");
    printf("%s", s);
    printf("\n");
    if (time_diff > 5) {
       printf("You took too long to type.\n");
       printf("Sorry, you need to complete this test within 5 seconds.\n");
       printf("Better luck next time!\n");
       return 0;
    }
    else {
      n = strlen(s);
      for (i = 0; i < n; i++) {
         if (s[i] != quote[i]) {
            count++;
         }
      }
      printf("Time taken = %.2lf seconds\n", time_diff);
      printf("Number of mistakes = %d\n", count);
      printf("Accuracy = %.2lf\n", (double) (strlen(quote) - count) / strlen(quote) * 100.0);
      printf("Your typing speed is = %.0lf cpw\n", (double) strlen(quote) / time_diff * 60.0);
      if (count > 0) {
         printf("Oh no! You made a mistake. Let me give you some code:\n");
         printf("int heart = 3;\n");
         printf("printf(\"You melted my %d with that typo :(\", heart);\n");
      }
      else {
         printf("Wow! You did it perfectly. Here's a special code for you!\n");
         printf("printf(\"You are just like a script, error-free and perfect <3\");\n");
      }
   }
   return 0;
}