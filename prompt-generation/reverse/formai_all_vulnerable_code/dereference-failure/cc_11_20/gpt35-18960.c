//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

char* c_cat_translator(char* input_str) {
  char* output_str = malloc(sizeof(char) * strlen(input_str) * 2);
  int output_index = 0;
  
  for (int i = 0; i < strlen(input_str); i++) {
      switch(input_str[i]) {
          case 'H':
          case 'h':
              strcat(output_str, "Meow!");
              output_index += 5;
              break;
          case 'E':
          case 'e':
              strcat(output_str, "Purr!");
              output_index += 5;
              break;
          case 'L':
          case 'l':
              strcat(output_str, "Hisss!");
              output_index += 6;
              break;
          case 'O':
          case 'o':
              strcat(output_str, "Growl!");
              output_index += 6;
              break;
          case 'W':
          case 'w':
              strcat(output_str, "Yowl!");
              output_index += 5;
              break;
          case 'R':
          case 'r':
              strcat(output_str, "Hiss!");
              output_index += 5;
              break;
          case 'D':
          case 'd':
              strcat(output_str, "Chirrup!");
              output_index += 8;
              break;
          case 'C':
          case 'c':
              strcat(output_str, "Purrp!");
              output_index += 6;
              break;
          case 'A':
          case 'a':
              strcat(output_str, "Mew!");
              output_index += 4;
              break;
          case 'T':
          case 't':
              strcat(output_str, "Purrh!");
              output_index += 6;
              break; 
          case ' ':
              strcat(output_str, " ");
              output_index++;
              break;
          default:
              strcat(output_str, "*scratch*");
              output_index += 9;
              break;
      }
  }
  
  return output_str;
}

int main() {
  char input_str[1024];
  printf("Enter a string in English: ");
  fgets(input_str, 1024, stdin);
  
  printf("In C Cat Language: %s", c_cat_translator(input_str));
  
  return 0;
}