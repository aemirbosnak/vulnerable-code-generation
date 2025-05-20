//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10
#define DELAY 100000

char words[NUM_WORDS][WORD_LENGTH + 1] = {
    "knight", "castle", "dragon", "sword", "jester", "kingdom",
    "queen", "prince", "princess", "throne" };

int main() {
   srand(time(NULL));
   int index = rand() % NUM_WORDS;
   char *word = &words[index][0];
   int length = strlen(word);
   int correct = 0;
   int incorrect = 0;

   printf("Welcome to the Medieval Typing Speed Test!\n");
   printf("You will be typing the following word: ");
   for (int i = 0; i < length; i++) {
      printf("*");
   }
   printf("\n");
   fflush(stdout);
   sleep(1);

   printf("Begin typing when ready...\n");
   fflush(stdout);
   sleep(1);

   char input[WORD_LENGTH + 1];
   scanf("%s", input);

   for (int i = 0; i < length; i++) {
      if (toupper(input[i]) == toupper(word[i])) {
         correct++;
      } else {
         incorrect++;
      }
   }

   printf("\nYou typed %d correct letter(s) and %d incorrect letter(s).\n", correct, incorrect);

   if (correct == length) {
      printf("Congratulations! You have successfully completed the test.\n");
   } else {
      printf("Sorry, you did not pass the test.\n");
   }
   return 0;
}