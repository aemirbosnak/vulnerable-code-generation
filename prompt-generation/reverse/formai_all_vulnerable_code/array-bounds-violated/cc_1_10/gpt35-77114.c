//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void convert_to_hex(char input[]);
int hex_to_decimal(char c);
int decimal_to_hex(int decimal);

int main() {
  char input[100];

  printf("Enter a string to convert to hexadecimal:\n");
  fgets(input, 100, stdin);

  //remove newline character from input
  input[strlen(input) - 1] = '\0';

  convert_to_hex(input);

  return 0;
}

void convert_to_hex(char input[]) {
  int len = strlen(input);
  int i;
  int decimal;
  
  printf("\nInput in Decimal Form is :\n");
  for(i=0;i<len;i++){
      decimal = input[i];
      printf("%d \t",decimal);
  }

  printf("\nInput in Hexadecimal Form is :\n");

  // loop through each character in input string
  for (i = 0; i < len; i++) {
    int decimal = input[i];

    // convert decimal value of character to hexadecimal
    int hex1 = decimal_to_hex(decimal / 16);
    int hex2 = decimal_to_hex(decimal % 16);

    printf("%c%c", hex1, hex2); // print converted hexadecimal value
  }

  printf("\n");
}

// convert hexadecimal character to decimal integer
int hex_to_decimal(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else {
    fprintf(stderr, "Error: Invalid hexadecimal character '%c'\n", c);
    exit(1); // exit program with error status
  }
}

// convert decimal integer to hexadecimal character
int decimal_to_hex(int decimal) {
  if (decimal >= 0 && decimal <= 9) {
    return decimal + '0';
  } else if (decimal >= 10 && decimal <= 15) {
    return decimal + 'a' - 10;
  } else {
    fprintf(stderr, "Error: Invalid decimal value %d\n", decimal);
    exit(1); // exit program with error status
  }
}