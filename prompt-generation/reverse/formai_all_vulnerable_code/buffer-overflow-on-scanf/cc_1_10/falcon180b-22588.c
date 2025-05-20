//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// function prototypes
void convert_to_hex(char *hex, char *binary);
int is_binary(char *binary);

int main() {

  char binary[100], hex[200]; // maximum input size is 100 characters

  printf("Welcome to the Happy Hexadecimal Converter!\n");

  printf("Please enter a binary number (up to 100 characters):\n");
  scanf("%s", binary);

  if (is_binary(binary)) { // check if input is binary
    convert_to_hex(hex, binary); // convert binary to hexadecimal
    printf("\nYour binary number in hexadecimal is:\n");
    printf("%s\n", hex);
  } else {
    printf("\nSorry, that's not a valid binary number.\n");
  }

  return 0;
}

// function to convert binary to hexadecimal
void convert_to_hex(char *hex, char *binary) {
  int i = 0, j = 0;
  char hex_digit[3] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  while (binary[i]!= '\0') {
    if (binary[i] == '0' || binary[i] == '1') {
      hex[j] = hex_digit[binary[i] - '0'];
      j++;
    } else {
      printf("\nSorry, that's not a valid binary number.\n");
      exit(1);
    }
    i++;
  }

  hex[j] = '\0'; // null terminate the string
}

// function to check if input is binary
int is_binary(char *binary) {
  int i = 0;

  while (binary[i]!= '\0') {
    if (binary[i]!= '0' && binary[i]!= '1') {
      return 0;
    }
    i++;
  }

  return 1;
}