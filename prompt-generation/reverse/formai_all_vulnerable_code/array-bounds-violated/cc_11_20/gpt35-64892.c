//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

void alienTranslator(char *input){
  int i, j, count = 0;
  char words[100][100];
  
  for(i = 0; i <= strlen(input); i++){
    if(input[i] == ' ' || input[i] == '\0'){
      words[count][j] = '\0';
      count++;
      j = 0;
    } else {
      words[count][j] = input[i];
      j++;
    }
  }
  
  printf("\n--- Alien Language Translation ---\n\n");
  
  for(i = 0; i < count; i++){
    if(strcmp(words[i], "zog") == 0){
      printf("A");
    } else if(strcmp(words[i], "blat") == 0){
      printf("B");
    } else if(strcmp(words[i], "crondor") == 0){
      printf("C");
    } else if(strcmp(words[i], "daxxle") == 0){
      printf("D");
    } else if(strcmp(words[i], "elaxic") == 0){
      printf("E");
    } else if(strcmp(words[i], "fizbin") == 0){
      printf("F");
    } else if(strcmp(words[i], "gloob") == 0){
      printf("G");
    } else if(strcmp(words[i], "humperdink") == 0){
      printf("H");
    } else if(strcmp(words[i], "imix") == 0){
      printf("I");
    } else if(strcmp(words[i], "jiblitz") == 0){
      printf("J");
    } else if(strcmp(words[i], "klang") == 0){
      printf("K");
    } else if(strcmp(words[i], "larklight") == 0){
      printf("L");
    } else if(strcmp(words[i], "munch") == 0){
      printf("M");
    } else if(strcmp(words[i], "nackle") == 0){
      printf("N");
    } else if(strcmp(words[i], "omni") == 0){
      printf("O");
    } else if(strcmp(words[i], "pood") == 0){
      printf("P");
    } else if(strcmp(words[i], "quigley") == 0){
      printf("Q");
    } else if(strcmp(words[i], "razzle") == 0){
      printf("R");
    } else if(strcmp(words[i], "snape") == 0){
      printf("S");
    } else if(strcmp(words[i], "trill") == 0){
      printf("T");
    } else if(strcmp(words[i], "umbridge") == 0){
      printf("U");
    } else if(strcmp(words[i], "vingle") == 0){
      printf("V");
    } else if(strcmp(words[i], "wibwib") == 0){
      printf("W");
    } else if(strcmp(words[i], "xax") == 0){
      printf("X");
    } else if(strcmp(words[i], "yorda") == 0){
      printf("Y");
    } else if(strcmp(words[i], "zippit") == 0){
      printf("Z");
    } else {
      printf("?");
    }
  }
  
  printf("\n\n--- End of Translation ---\n");
}

int main(){
  char input[100];
  
  printf("Enter a sentence in Alien Language: ");
  fgets(input, 100, stdin);
  
  alienTranslator(input);
  
  return 0;
}