//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
// Welcome to the Syntax Parsing Program!
// I hope you're ready to feel the magic of code :)
#include <stdio.h>

int main() {
  printf("Enter your code here: ");
  
  // Take input from the user
  char code[1000];
  scanf("%[^\n]", code);
  
  printf("\nWow, that's a great code!\n");
  printf("Let's see if the syntax is perfect or not...\n");
  
  // Start parsing with a happy face :)
  printf(":) Parsing...\n");
  
  // Check if the code starts with an opening curly bracket
  if (code[0] == '{') {
    printf(":) Checking brackets...\n");
    
    // Check if brackets are paired correctly
    int brackets = 0;
    char current_char;
    for (int i = 0; code[i] != '\0'; i++) {
      current_char = code[i];
      if (current_char == '{') {
        brackets++;
      } else if (current_char == '}') {
        brackets--;
      }
    }
    if (brackets != 0) {
      printf(":( Error! Brackets are not paired correctly.\n");
      return 0;
    }
    printf(":) Brackets are paired correctly!\n");
    
    // Check if the code ends with a closing curly bracket
    if (code[strlen(code)-1] == '}') {
      printf(":) Syntax is correct! :D\n");
    } else {
      printf(":( Error! Code should end with a closing curly bracket.\n");
    }
  } else {
    printf(":( Error! Code should start with an opening curly bracket.\n");
  }
  
  // End parsing with another happy face :)
  printf(":) Done!\n");
  
  return 0;
}