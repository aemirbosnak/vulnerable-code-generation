//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>

int main() {
  // Let's create a program that parses a C-style array declaration and prints out the type and size
  
  printf("Welcome to the curious C syntax parser!\n");
  printf("Please enter a C-style array declaration:\n");

  char input[100];
  scanf("%[^\n]s", input);  // reading input until a newline character
  
  // let's extract the type and size from the input string
  int type_end_index, size_start_index = 0, size_end_index;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {  // the type ends right before the first space
      type_end_index = i - 1;
      size_start_index = i + 1;
      break;
    }
  }

  // we need to skip possible whitespaces between the type and the name
  while (input[size_start_index] == ' ')
    size_start_index++;

  for (int i = size_start_index; input[i] != '\0'; i++) {
    if (input[i] == ']') {  // the size ends right before the closing square bracket
      size_end_index = i - 1;
      break;
    }
  }

  // let's create a string variable to hold the type substring
  char type[type_end_index + 2];
  for (int i = 0; i <= type_end_index; i++) {
    type[i] = input[i];
  }
  type[type_end_index + 1] = '\0';

  // let's create a string variable to hold the size substring
  char size[size_end_index - size_start_index + 2];
  for (int i = size_start_index; i <= size_end_index; i++) {
    size[i - size_start_index] = input[i];
  }
  size[size_end_index - size_start_index + 1] = '\0';

  printf("Type: %s\n", type);
  printf("Size: %s\n", size);

  return 0;
}