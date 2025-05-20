//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // The program starts with a SURPRISE!
  printf("SURPRISE! You just won a trip to the moon! \n");

  // Now, let's process some text...
  char text[100];
  gets(text); // OH NO! We just took input from the user!
  printf("You said: %s \n", text);

  // Let's play a game of hangman!
  char guess[10];
  int len = strlen(text);
  int i = 0;
  for (i = 0; i < len; i++) {
    guess[i] = '*';
  }
  guess[i] = '\0';
  printf("Guess a letter: ");
  scanf("%s", guess);
  printf("You guessed: %s \n", guess);

  // OH MY GOSH! The user guessed the letter 'e'!
  if (strchr(text, 'e')) {
    printf("Correct! The letter 'e' is in the text! \n");
  } else {
    printf("Oh no! The letter 'e' is not in the text! \n");
  }

  // Let's play another game of hangman!
  char word[10];
  int j = 0;
  for (j = 0; j < len; j++) {
    word[j] = text[j];
  }
  word[j] = '\0';
  printf("Guess the word: ");
  scanf("%s", word);
  printf("You guessed: %s \n", word);

  // WAIT A MINUTE! The user guessed the word "surprise"!
  if (strcmp(word, "surprise") == 0) {
    printf("AMAZING! You guessed the word 'surprise'! \n");
  } else {
    printf("Oh well... Try again! \n");
  }

  return 0;
}