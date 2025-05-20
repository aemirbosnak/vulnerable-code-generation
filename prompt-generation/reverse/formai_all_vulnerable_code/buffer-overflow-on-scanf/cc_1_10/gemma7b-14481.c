//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char input_string[20];
  int i, input_length, hexadecimal_value;
  unsigned char converted_hex_value;

  // Get the input string from the user
  printf("Enter a hexadecimal number: ");
  scanf("%s", input_string);

  // Calculate the length of the input string
  input_length = strlen(input_string);

  // Convert the input string to uppercase
  for (i = 0; i < input_length; i++)
  {
    input_string[i] = toupper(input_string[i]);
  }

  // Check if the input string is valid
  if (!is_valid_hex_string(input_string))
  {
    printf("Invalid input.\n");
    return 1;
  }

  // Convert the input string to an integer
  hexadecimal_value = convert_hex_string_to_int(input_string);

  // Convert the integer to an unsigned character
  converted_hex_value = (unsigned char) hexadecimal_value;

  // Print the converted value
  printf("Converted hexadecimal value: %x\n", converted_hex_value);

  return 0;
}

int is_valid_hex_string(char *string)
{
  int i, length = strlen(string);

  // Check if the string is empty
  if (length == 0)
  {
    return 0;
  }

  // Iterate over the string and check if each character is valid
  for (i = 0; i < length; i++)
  {
    if (!isxdigit(string[i]))
    {
      return 0;
    }
  }

  // Check if the string ends with a newline character
  if (string[length - 1] != '\n')
  {
    return 0;
  }

  return 1;
}

int convert_hex_string_to_int(char *string)
{
  int i, length = strlen(string);
  int value = 0;

  // Iterate over the string and convert each character to its hexadecimal value
  for (i = 0; i < length; i++)
  {
    value += digit_to_hex(string[i]) * pow(16, length - i - 1);
  }

  return value;
}

int digit_to_hex(int number)
{
  return (number % 16) + 97;
}