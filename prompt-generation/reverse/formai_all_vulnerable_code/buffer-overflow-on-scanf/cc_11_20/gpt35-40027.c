//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include<stdio.h>

int main(){

  printf("Hello! I am a text-processing program and I love to play with words!\n");

  // Let's define an array to store the user's text
  char text[100];

  printf("Enter some text that you want me to process: ");
  scanf("%[^\n]", text);

  printf("\nBefore processing, your text looks like this: \n");
  printf("%s\n", text);

  // Let's convert all the vowels to uppercase
  for(int i=0; text[i]!='\0'; i++){
    if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u'){
      text[i] -= 'a' - 'A';
    }
  }

  printf("\nAfter processing, your text looks like this: \n");
  printf("%s\n", text);

  // Let's count the number of words in the text
  int word_count = 1;

  for(int i=0; text[i]!='\0'; i++){
    if(text[i]==' ' && text[i+1]!=' '){
      word_count++;
    }
  }

  if(word_count==1){
    printf("\nWow! You only entered one word. You must be an expert in brevity!\n");
  }
  else if(word_count<=10){
    printf("\nNice! You entered %d words. That's a manageable amount to process.\n", word_count);
  }
  else if(word_count<=20){
    printf("\nWhoa! You entered %d words. That's a lot of words. Did you copy-paste a novel?\n", word_count);
  }
  else{
    printf("\nStop! You entered %d words. I can't handle this much text. My circuits might fry!\n", word_count);
  }

  printf("\nThanks for letting me process your text. Hope you had fun too!\n");

  return 0;
}