//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include<stdio.h>

int main(){
  FILE *filePointer;
  char fileName[100];
  char line[200];
  
  printf("Enter the file name:");
  scanf("%s", fileName);
  
  filePointer = fopen(fileName, "r");
  
  if(filePointer == NULL){
    printf("Error reading the file\n");
    return 1;
  }
  
  printf("Contents of the file:\n");
  
  while(fgets(line, 200, filePointer) != NULL){
    printf("%s", line);
  }
  
  fclose(filePointer);
  
  filePointer = fopen(fileName, "a");
  
  if(filePointer == NULL){
    printf("Error appending to file\n");
    return 1;
  }
  
  printf("Enter content to append to the file:\n");
  
  while(fgets(line, 200, stdin)){
    if(strcmp(line, "exit\n") == 0){
      break;
    }
    fprintf(filePointer, "%s", line);
  }
  
  fclose(filePointer);
  
  printf("Contents of the file after appending:\n");
  
  filePointer = fopen(fileName, "r");
  
  while(fgets(line, 200, filePointer) != NULL){
    printf("%s", line);
  }
  
  fclose(filePointer);
  
  return 0;
}