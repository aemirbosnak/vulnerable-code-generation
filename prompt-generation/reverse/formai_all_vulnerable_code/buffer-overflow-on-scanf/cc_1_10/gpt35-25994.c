//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>

int main() {
   char guess;
   int tries = 0;
   int maxTries = 7;
   char answer[] = "apple";
   int answerLength = 5;
   int i;
   int correctGuesses = 0;
   char lettersGuessed[26];

   while (correctGuesses < answerLength && tries < maxTries) {
      printf("Guess a letter: ");
      scanf("%c", &guess);

      for (i = 0; i < 26; i++) {
         if (lettersGuessed[i] == guess) {
            printf("You have already guessed that letter.\n");
            break;
         }
      }

      for (i = 0; i < answerLength; i++) {
         if (answer[i] == guess) {
            printf("Correct guess!\n");
            correctGuesses++;
            break;
         }
      }

      if (i == answerLength) {
         printf("Incorrect guess.\n");
         tries++;
      }

      lettersGuessed[tries - 1] = guess;
      printf("You have %d tries remaining.\n", maxTries - tries);
      printf("Letters guessed: ");
      for (i = 0; i < tries; i++) {
         printf("%c ", lettersGuessed[i]);
      }
      printf("\n\n");
      scanf(" %c", &guess);
   }

   if (correctGuesses == answerLength) {
      printf("Congratulations! You win.\n");
   } else {
      printf("Sorry, you lose. The word was %s.\n", answer);
   }

   return 0;
}