//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
  FILE* fp;
  char str[1000];
  int count = 0;
  int wordCount = 0;
  int charCount = 0;
  int lineCount = 0;
  int loopCount = 0;
  char c;
  int i;
  int flag = 0;
  int letterCount = 0;
  int vidCount = 0;
  
  //Check if input is provided or not
  if (argc < 2) {
    printf("Error: File name not provided as input!\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");
  //check if file is accessible
  if (fp == NULL) {
    printf("Error: Could not access file!\n");
    exit(1);
  }

  while ((fgets(str, 1000, fp)) != NULL) {
    count++;
    charCount += strlen(str);

    for (i = 0; str[i] != '\0'; ++i) {
      //count words, vidCount, letters & lines in the file
      c = str[i];
      if (c == '\n') {
        lineCount++;
      }
      if (c == ' ' || c == '\t' || c == '\n') {
        if (flag == 1) {
          wordCount++;
          flag = 0;
        }
        if (letterCount > 0) {
          vidCount++;
        }
        letterCount = 0;
      }
      else {
        letterCount++;
        if (letterCount == 4 && (c == 'c' || c == 'C') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n')) {
          vidCount++;
        }
        flag = 1;
      }
    }
  }
  fclose(fp);

  printf("Number of lines in the file : %d\n", lineCount);
  printf("Number of words in the file : %d\n", wordCount);
  printf("Number of characters in the file : %d\n", charCount);
  printf("Number of occurrences of \"C\" or \"c\" as a fourth character in a word : %d\n", vidCount);

  return 0;
}