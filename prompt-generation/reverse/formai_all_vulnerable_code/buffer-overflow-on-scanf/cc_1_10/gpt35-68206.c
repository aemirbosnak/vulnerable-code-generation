//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautifyHTML(FILE *file, FILE *output){
  int ch, currentLine = 1, openAngleBrackets = 0;
  
  while((ch = fgetc(file)) != EOF){
    if(ch == '<'){
      openAngleBrackets++;
      
      fprintf(output, "<");
      
      if(fgetc(file) != '/'){
        fprintf(output, "\n    ");
        currentLine++;
        
        while((ch = fgetc(file)) != '>'){
          if(ch == EOF){
            break;
          }
          fprintf(output, "%c", ch);
        }
        
        fprintf(output, "\n");
        currentLine++;
        fprintf(output, "%*s", 4 * currentLine, "");
        openAngleBrackets--;
      }
      else{
        fprintf(output, "/");
        
        while((ch = fgetc(file)) != '>'){
          if(ch == EOF){
            break;
          }
          fprintf(output, "%c", ch);
        }
        
        fprintf(output, ">");
        openAngleBrackets--;
      }
    }
    else if(ch == '>'){
      fprintf(output, ">");
      currentLine++;
      
      if(currentLine % 2 == 0 && openAngleBrackets == 0){
        fprintf(output, "\n");
      }
    }
    else if(isprint(ch)){
      fprintf(output, "%c", ch);
    }
  }
}

int main(){
  FILE *file, *output;
  char inputFileName[50], outputFileName[50];
  
  printf("Enter input file name (HTML file): ");
  scanf("%s", inputFileName);
  
  file = fopen(inputFileName, "r");
  
  if(file == NULL){
    printf("Error opening input file!");
    exit(1);
  }
  
  printf("Enter output file name: ");
  scanf("%s", outputFileName);
  
  output = fopen(outputFileName, "w");
  
  if(output == NULL){
    printf("Error opening output file!");
    exit(1);
  }
  
  beautifyHTML(file, output);
  
  fclose(file);
  fclose(output);
  
  return 0;
}