//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

//function to translate from English to C Cat Language
void engToCCat(char *engWord){
  int i;
  
  for(i=0; i<strlen(engWord); i++){
    if(engWord[i] == 'a' || engWord[i] == 'e' || engWord[i] == 'i' || engWord[i] == 'o' || engWord[i] == 'u'){
      printf("meow");
    }
    else if(engWord[i] == 's'){
      printf("hiss");
    }
    else if(engWord[i] == 't'){
      printf("purr");
    }
    else{
      printf("%c", engWord[i]);
    }
  }
  printf("\n");
}

//function to translate from C Cat Language to English
void cCatToEng(char *cCatWord){
  int i;
  char buffer[5] = {'\0', '\0', '\0', '\0', '\0'};
  
  for(i=0; i<strlen(cCatWord); i++){
    if(cCatWord[i] == 'm' && cCatWord[i+1] == 'e' && cCatWord[i+2] == 'o' && cCatWord[i+3] == 'w'){
      printf("a");
      i = i+3;
    }
    else if(cCatWord[i] == 'h' && cCatWord[i+1] == 'i' && cCatWord[i+2] == 's' && cCatWord[i+3] == 's'){
      printf("s");
      i = i+3;
    }
    else if(cCatWord[i] == 'p' && cCatWord[i+1] == 'u' && cCatWord[i+2] == 'r' && cCatWord[i+3] == 'r'){
      printf("t");
      i = i+3;
    }
    else{
      printf("%c", cCatWord[i]);
    }
  }
  printf("\n");
}

int main(){
  int choice;
  char word[100];
  
  //menu for selecting translation direction
  printf("Welcome to the C Cat Language Translator\n");
  printf("What would you like to translate?\n");
  printf("1. English to C Cat Language\n");
  printf("2. C Cat Language to English\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);
  
  //getting input word to translate
  printf("Enter the word to translate: ");
  scanf("%s", word);
  
  //translating based on user choice
  if(choice == 1){
    engToCCat(word);
  }
  else if(choice == 2){
    cCatToEng(word);
  }
  else{
    printf("Invalid choice\n");
  }
  
  return 0;
}