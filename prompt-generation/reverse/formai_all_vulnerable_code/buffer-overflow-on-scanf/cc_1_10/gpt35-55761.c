//FormAI DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>

int main() {
  // welcome user to the program
  printf("Welcome to the UNIT CONVERTER program!\n");
  
  // ask user for input unit
  printf("Please enter the unit you would like to convert from: ");
  
  // declare and get input unit
  char input_unit[20];
  scanf("%s", input_unit);
  
  // ask user for output unit
  printf("Please enter the unit you would like to convert to: ");
  
  // declare and get output unit
  char output_unit[20];
  scanf("%s", output_unit);
  
  // display surprise message
  printf("Wow! Who knew we'd be converting from %s to %s?! Let's do this!\n", input_unit, output_unit);
  
  // declare variable for input value
  float input_value;
  
  // if input unit is Celsius, ask user for temperature value
  if(strcmp(input_unit, "Celsius") == 0) {
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &input_value);
  } 
  
  // if input unit is not Celsius, ask user for value in that unit
  else {
    printf("Please enter the value in %s: ", input_unit);
    scanf("%f", &input_value);
  }
  
  // perform conversion
  float output_value;
  
  // if converting Celsius to Fahrenheit
  if(strcmp(input_unit, "Celsius") == 0 && strcmp(output_unit, "Fahrenheit") == 0) {
    output_value = (input_value * 9 / 5) + 32;
  } 
  
  // if converting Fahrenheit to Celsius
  else if(strcmp(input_unit, "Fahrenheit") == 0 && strcmp(output_unit, "Celsius") == 0) {
    output_value = (input_value - 32) * 5 / 9;
  }
  
  // if no specific conversion, display error message
  else {
    printf("Oops! I'm sorry, I don't know how to convert from %s to %s.\n", input_unit, output_unit);
    return 1;
  }
  
  // display result
  printf("Congratulations, your conversion from %s to %s is complete!\n", input_unit, output_unit);
  
  // if converting temperature, display result with degree symbol
  if(strcmp(input_unit, "Celsius") == 0 && strcmp(output_unit, "Fahrenheit") == 0) {
    printf("%.2f° Celsius is equal to %.2f° Fahrenheit.\n", input_value, output_value);
  } else if(strcmp(input_unit, "Fahrenheit") == 0 && strcmp(output_unit, "Celsius") == 0) {
    printf("%.2f° Fahrenheit is equal to %.2f° Celsius.\n", input_value, output_value);
  }
  
  // if not converting temperature, display result without degree symbol
  else {
    printf("%.2f %s is equal to %.2f %s.\n", input_value, input_unit, output_value, output_unit);
  }

  // say goodbye to user
  printf("Thanks for using the UNIT CONVERTER program. Have a nice day!\n");

  return 0;
}