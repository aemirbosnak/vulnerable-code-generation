//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {

  // Define a char array for the input string
  char input_str[50];

  // Prompt the user to enter a string
  printf("Enter a string (max. 50 characters): ");

  // Read the input string from the user
  fgets(input_str, 50, stdin);

  // Remove the newline character from the input string
  if (input_str[strlen(input_str)-1] == '\n') {
    input_str[strlen(input_str)-1] = '\0';
  }

  // Declare an int variable for the length of the input string
  int input_len = strlen(input_str);

  // Reverse the input string
  for (int i = 0; i < input_len/2; i++) {
    char temp = input_str[i];
    input_str[i] = input_str[input_len-1-i];
    input_str[input_len-1-i] = temp;
  }

  // Declare a char array for the output string
  char output_str[100];

  // Add the reversed string to the output string
  strncpy(output_str, input_str, 100);

  // Add the original string to the output string
  strncat(output_str, input_str, 100);

  // Declare an int variable for the length of the output string
  int output_len = strlen(output_str);

  // Convert the output string to uppercase
  for (int i = 0; i < output_len; i++) {
    if (output_str[i] >= 'a' && output_str[i] <= 'z') {
      output_str[i] -= 32;
    }
  }

  // Declare a char array for the final string
  char final_str[150];

  // Add the output string to the final string
  strncpy(final_str, output_str, 150);

  // Add a whitespace to the final string
  strncat(final_str, " ", 150);

  // Add the length of the input string to the final string
  char len_str[10];
  sprintf(len_str, "%d", input_len);
  strncat(final_str, len_str, 150);

  // Add a whitespace to the final string
  strncat(final_str, " ", 150);

  // Add the length of the output string to the final string
  char output_len_str[10];
  sprintf(output_len_str, "%d", output_len);
  strncat(final_str, output_len_str, 150);

  // Print the final string
  printf("Final String: %s\n", final_str);

  return 0;
}