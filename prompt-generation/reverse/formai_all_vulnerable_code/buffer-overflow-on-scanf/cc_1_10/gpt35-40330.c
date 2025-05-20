//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {

  char name[20];
  printf("Hey there, what's your name? ");
  scanf("%s", name);
  
  printf("Hello %s, I'm excited to show you how to manipulate C-strings today!\n\n", name);

  char sentence[100];
  printf("Please enter a sentence: ");
  getchar();
  fgets(sentence, 100, stdin);
  
  printf("\nGreat sentence, %s! Now let's have some fun manipulating it.\n", name);

  // Counting the number of characters in the sentence
  int length = strlen(sentence);
  printf("The length of the sentence is %d characters.\n", length);

  // Reversing the sentence
  printf("\nNow let's reverse the sentence: ");
  for (int i = length - 1; i >= 0; i--) {
    printf("%c", sentence[i]);
  }
  printf("\n");

  // Capitalizing the sentence
  printf("\nNow let's capitalize the sentence: ");
  for (int i = 0; sentence[i]; i++) {
    printf("%c", toupper(sentence[i]));
  }
  printf("\n");

  // Replacing spaces with underscores in the sentence
  printf("\nNow let's replace spaces with underscores: ");
  for (int i = 0; sentence[i]; i++) {
    if (sentence[i] == ' ') {
      printf("_");
    }
    else {
      printf("%c", sentence[i]);
    }
  }
  printf("\n");

  // Counting the number of words in the sentence
  int words = 1;
  for (int i = 0; sentence[i]; i++) {
    if (sentence[i] == ' ') {
      words++;
    }
  }
  printf("\nThe sentence has %d words.\n", words);

  printf("\nThanks for letting me teach you some C-String manipulation, %s! Have a great day!\n\n", name);
  
  return 0;
}