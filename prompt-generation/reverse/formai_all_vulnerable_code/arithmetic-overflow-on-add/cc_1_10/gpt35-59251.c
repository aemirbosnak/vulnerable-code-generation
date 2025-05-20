//FormAI DATASET v1.0 Category: Syntax parsing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to C Syntax Parsing Program!\n");

  // First, we need to scan the source code file into memory
  FILE* sourceFile = fopen("program.c", "r");
  if (!sourceFile) {
    printf("ERROR: Cannot open source file!\n");
    return -1;
  }
  
  // Get the size of the file
  fseek(sourceFile, 0, SEEK_END);
  int fileSize = ftell(sourceFile);
  fseek(sourceFile, 0, SEEK_SET);

  // Allocate memory for the source code
  char* sourceCode = (char*)malloc(fileSize + 1);
  if (!sourceCode) {
    printf("ERROR: Cannot allocate memory!\n");
    fclose(sourceFile);
    return -1;
  }

  // Read the source code into memory
  fread(sourceCode, fileSize, 1, sourceFile);
  fclose(sourceFile);

  // Add a null terminator to the end of the source code
  sourceCode[fileSize] = '\0';

  // Now, let's parse the source code
  printf("Parsing source code...\n");
  int lineNumber = 1;
  char* token = strtok(sourceCode, "\n");
  while (token) {
    char* delimiter = " ";
    char* line = token;
    char* word = strtok(line, delimiter);
    while (word) {
      // Check if the word is a valid C keyword or variable name
      if (!isKeyword(word) && !isVariableName(word)) {
        printf("ERROR: Invalid syntax at line %d, word '%s' is not a valid C keyword or variable name!\n", lineNumber, word);
        return -1;
      }

      word = strtok(NULL, delimiter);
    }

    token = strtok(NULL, "\n");
    lineNumber++;
  }

  printf("Successfully parsed the source code without any errors!\n");
  
  free(sourceCode);
  return 0;
}

int isKeyword(char* word) {
  char* keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
  int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

  for (int i = 0; i < keywordCount; i++) {
    if (strcmp(word, keywords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int isVariableName(char* word) {
  // A variable name can only contain alphanumeric characters and underscores, and cannot start with a number
  int length = strlen(word);
  if (length == 0 || isdigit(word[0])) {
    return 0;
  }

  for (int i = 0; i < length; i++) {
    if (!isalnum(word[i]) && word[i] != '_') {
      return 0;
    }
  }

  return 1;
}