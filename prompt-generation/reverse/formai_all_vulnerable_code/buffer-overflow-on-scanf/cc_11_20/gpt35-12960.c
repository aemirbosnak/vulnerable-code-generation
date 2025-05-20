//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int numGuesses = 0;
   int maxGuesses = 7;
   int isGuessed = 0;
   
   char gameWord[] = "cheerful";
   int wordLength = sizeof(gameWord) / sizeof(char) - 1;
   
   char guessedLetters[wordLength];
   for(int i = 0; i < wordLength; i++) {
      guessedLetters[i] = '_';
   }
   
   while(numGuesses < maxGuesses && !isGuessed) {
      printf("\nGuess the word: ");
      for(int i = 0; i < wordLength; i++) {
         printf("%c ", guessedLetters[i]);
      }
      
      char guess;
      printf("\nEnter a letter: ");
      scanf(" %c", &guess);
      
      int correctGuess = 0;
      for(int i = 0; i < wordLength; i++) {
         if(guess == gameWord[i]) {
            guessedLetters[i] = guess;
            correctGuess = 1;
         }
      }
      
      if(!correctGuess) {
         numGuesses++;
         printf("\nSorry, %c is not in the word. You have %d guesses remaining.", guess, maxGuesses - numGuesses);
      } else {
         int allGuessed = 1;
         for(int i = 0; i < wordLength; i++) {
            if(guessedLetters[i] == '_') {
               allGuessed = 0;
            }
         }
         
         if(allGuessed) {
            isGuessed = 1;
            printf("\nCongratulations! You guessed the word!");
         }
      }
   }
   
   if(!isGuessed) {
      printf("\nSorry, you have run out of guesses. The word was %s.", gameWord);
   }
   
   return 0;
}