//FormAI DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  // opening a file for reading
  FILE *input_file = fopen("dreams.txt", "r");

  if(input_file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Create a dynamic array to store the text
  char *text = malloc(sizeof(char) * 10000);
  if(text == NULL) {
    printf("Memory allocation error occurred!\n");
    exit(1);
  }

  // read the file line by line into the text array
  char line[1000];
  while(fgets(line, sizeof(line), input_file)) {
    strcat(text, line);
  }

  // processing the text
  char result[10000];
  int index = 0;
  int length = strlen(text);
  
  for(int i=0; i<length; i++){
    char letter = text[i];
    if(letter == 'a' || letter == 'A'){
      result[index] = '!';
    }else if(letter == 'e' || letter == 'E'){
      result[index] = '?';
    }else if(letter == 'i' || letter == 'I'){
      result[index] = '.';
    }else if(letter == 'o' || letter == 'O'){
      result[index] = '+';
    }else if(letter == 'u' || letter == 'U'){
      result[index] = '-';
    }else{
      result[index] = letter;
    }
    index++;
  }
  result[index] = '\0';

  // outputting the new text
  printf("\n----Original text----\n");
  printf("%s", text);
  printf("\n----Processed text----\n");
  printf("%s\n", result);

  // closing the file and freeing up memory
  fclose(input_file);
  free(text);
}