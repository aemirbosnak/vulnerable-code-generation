//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {

  char phrase[100];
  char word[20];
  
  printf("Welcome to the String Manipulation program! \n");
  printf("Enter a phrase: ");
  fgets(phrase, 100, stdin);

  printf("\nThe phrase you entered is: %s\n", phrase);
  printf("Enter a word to search for in the phrase: ");
  scanf("%s", word);
  
  char *ptr = NULL;
  ptr = strstr(phrase, word);
  
  if(ptr) {
    printf("\nFound the word \"%s\" in the phrase! \n", word);
    printf("The position of the first occurrence of \"%s\" in the phrase is: %ld\n\n", word, ptr-phrase);
  } else {
    printf("\nCould not find the word \"%s\" in the phrase.\n\n", word);
  }
  
  int len = strlen(phrase);
  char temp[len];
  
  for(int i=0; i<len; i++) {
    if(phrase[i] >= 'A' && phrase[i] <= 'Z') {
      temp[i] = phrase[i] + 32;
    } else {
      temp[i] = phrase[i];
    }
  }
  
  printf("The phrase in all lowercase is: %s\n\n", temp);
  
  int space = 0, vowel = 0, consonant = 0;
  
  for(int i=0; i<len; i++) {
    if(phrase[i] == ' ') {
      space++;
    } else if(phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u' ||
             phrase[i] == 'A' || phrase[i] == 'E' || phrase[i] == 'I' || phrase[i] == 'O' || phrase[i] == 'U') {
      vowel++;
    } else if((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z')) {
      consonant++;
    }
  }
  
  printf("The phrase has %d spaces, %d vowels, and %d consonants.\n\n", space, vowel, consonant);
  
  char *token = strtok(phrase, " ");
  
  while(token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
  
  return 0;
}