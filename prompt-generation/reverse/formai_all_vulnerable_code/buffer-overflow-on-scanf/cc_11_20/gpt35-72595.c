//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

int main(){

  char alienLanguage[100];
  printf("Enter the alien language you want to translate: ");
  scanf("%s", alienLanguage);

  int length = strlen(alienLanguage);
  int i, j;

  printf("\n\n%s in English: ", alienLanguage);

  for(i=0; i<length; i++){
    switch(alienLanguage[i]){
      case 'x':
        if(alienLanguage[i+1] == 'y' && alienLanguage[i+2] == 'z'){
          printf("a");
          i += 2;
        } else {
          printf("%c", alienLanguage[i]);
        }
        break;
      case 'y':
        if(alienLanguage[i+1] == 'z' && alienLanguage[i+2] == 'x'){
          printf("b");
          i += 2;
        } else {
          printf("%c", alienLanguage[i]);
        }
        break;
      case 'z':
        if(alienLanguage[i+1] == 'x' && alienLanguage[i+2] == 'y'){
          printf("c");
          i += 2;
        } else {
          printf("%c", alienLanguage[i]);
        }
        break;
      default:
        printf("%c", alienLanguage[i]);
    }
  }

  printf("\n\n");

  return 0;

}