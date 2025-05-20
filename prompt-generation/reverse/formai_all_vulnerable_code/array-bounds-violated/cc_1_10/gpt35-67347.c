//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii_art(char*);

int main(){
  char input_text[100];
  
  printf("Please input some text (max 100 characters): ");
  fgets(input_text, 100, stdin);

  //remove newline character from input
  int len = strlen(input_text)-1;
  if(input_text[len] == '\n')
    input_text[len] = '\0';

  print_ascii_art(input_text);

  return 0;
}

void print_ascii_art(char* text){
  int length = strlen(text);
  int counter = 1;
  int char_index = 0;
  
  while(counter <= length*6){
    if(counter%6 == 1){
      printf("    ___\n");
      printf("  .\'   \'.\n");
      printf(" /-------\\\n");
      printf("/  .-\"\"\"-. \\\n");
    }
    else if(counter%6 == 2){
      printf("| / %c   %c \\ |\n", text[char_index], text[char_index]);
      char_index++;
    }
    else if(counter%6 == 3){
      printf("|/_________\\\n");
      printf(" \\         /\n");
      printf("  \\       /\n");    
    }
    else if(counter%6 == 4){
      printf("   \'._.'\n");
      printf("\n");    
    }
    else if(counter%6 == 5){
      printf("\n");
      printf("  .\'``\\._\n");
      printf(" /     \\ `\\__\n");
    }
    else if(counter%6 == 0){
      printf("|    %c   %c  `\\.\n", text[char_index], text[char_index]);
      char_index++;
      printf("|         ,_/ \n");
      printf("\\_._._._./ \n");      
    }
    counter++;
  }
}