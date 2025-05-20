//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h> 
#include <ctype.h> 

void clear_buffer(void) {
  int c; 
  while ((c = getchar()) != '\n' && c != EOF); 
}

int main(void) {
  double value, conv_value; 
  char unit_from, unit_to; 

  printf("Welcome to the Alan Turing Unit Converter\n\n");

  printf("Enter the initial value: "); 
  scanf("%lf", &value); 
  clear_buffer(); 

  printf("Enter the initial unit (C for Celsius, F for Fahrenheit, K for Kelvin): "); 
  unit_from = getchar(); 
  unit_from = toupper(unit_from); 
  clear_buffer(); 

  printf("Enter the target unit (C for Celsius, F for Fahrenheit, K for Kelvin): "); 
  unit_to = getchar(); 
  unit_to = toupper(unit_to); 
  clear_buffer(); 

  if (unit_from == 'C') {
    if (unit_to == 'F') {
      conv_value = (value * 9/5) + 32; 
      printf("%.2lf°C is equal to %.2lf°F\n", value, conv_value); 
    } else if (unit_to == 'K') {
      conv_value = value + 273.15; 
      printf("%.2lf°C is equal to %.2lfK\n", value, conv_value); 
    } else {
      printf("Invalid unit entered. Please try again.\n"); 
    }
  } else if (unit_from == 'F') {
    if (unit_to == 'C') {
      conv_value = (value - 32) * 5/9; 
      printf("%.2lf°F is equal to %.2lf°C\n", value, conv_value); 
    } else if (unit_to == 'K') {
      conv_value = (value - 32) * 5/9 + 273.15; 
      printf("%.2lf°F is equal to %.2lfK\n", value, conv_value); 
    } else {
      printf("Invalid unit entered. Please try again.\n"); 
    }  
  } else if (unit_from == 'K') {
    if (unit_to == 'C') {
      conv_value = value - 273.15; 
      printf("%.2lfK is equal to %.2lf°C\n", value, conv_value); 
    } else if (unit_to == 'F') {
      conv_value = (value - 273.15) * 9/5 + 32; 
      printf("%.2lfK is equal to %.2lf°F\n", value, conv_value); 
    } else {
      printf("Invalid unit entered. Please try again.\n"); 
    }   
  } else {
    printf("Invalid unit entered. Please try again.\n"); 
  }

  return 0; 
}