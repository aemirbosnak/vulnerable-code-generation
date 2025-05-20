//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: funny
// "Unit-asting" Converter: The Funniest Conversion Tool Ever!

#include <stdio.h>
#include <stdlib.h>

// Define our hilarious unit types
#define ELEPHANTS 10000
#define HIPPOS 5000
#define GIRAFFES 1000
#define CROCODILES 200
#define MONKEYS 10

// Declare our conversion functions (with some witty names)
double elephantToHippo(double elephants);
double hippoToGiraffe(double hippos);
double giraffeToCrocodile(double giraffes);
double crocodileToMonkey(double crocodiles);
double monkeyToElephant(double monkeys);

// Our main function: the epicenter of fun conversions
int main() {
  // Set up our hilarious starting message
  printf("\nWelcome to the 'Unit-asting' Converter, where conversions are as funny as a clown's nose!\n\n");

  // Declare our input and output variables
  double input, result;
  int unit_type;

  // Prompt the user to input a value and unit type
  printf("Enter the value you want to convert: ");
  scanf("%lf", &input);
  printf("Choose a unit type to convert from:\n");
  printf("1. Elephants (10,000 pounds)\n");
  printf("2. Hippos (5,000 pounds)\n");
  printf("3. Giraffes (1,000 pounds)\n");
  printf("4. Crocodiles (200 pounds)\n");
  printf("5. Monkeys (10 pounds)\n");
  scanf("%d", &unit_type);

  // Perform the conversion based on the user's choice
  switch (unit_type) {
    case 1:
      result = elephantToHippo(input);
      printf("%.2f elephants = %.2f hippos\n", input, result);
      break;
    case 2:
      result = hippoToGiraffe(input);
      printf("%.2f hippos = %.2f giraffes\n", input, result);
      break;
    case 3:
      result = giraffeToCrocodile(input);
      printf("%.2f giraffes = %.2f crocodiles\n", input, result);
      break;
    case 4:
      result = crocodileToMonkey(input);
      printf("%.2f crocodiles = %.2f monkeys\n", input, result);
      break;
    case 5:
      result = monkeyToElephant(input);
      printf("%.2f monkeys = %.2f elephants (that's a lot of monkeys!)\n", input, result);
      break;
    default:
      printf("Invalid unit type! Please choose a number between 1 and 5.\n");
  }

  // Exit the program with a final joke
  printf("\nRemember, when it comes to units, 'measure' with a smile!\n");
  return 0;
}

// Our conversion functions: a symphony of silliness

// Convert elephants to hippos: a majestic transformation
double elephantToHippo(double elephants) {
  return elephants / 2;
}

// Convert hippos to giraffes: a graceful ascent
double hippoToGiraffe(double hippos) {
  return hippos * 2;
}

// Convert giraffes to crocodiles: a slippery slope
double giraffeToCrocodile(double giraffes) {
  return giraffes * 5;
}

// Convert crocodiles to monkeys: a hilarious downsize
double crocodileToMonkey(double crocodiles) {
  return crocodiles * 10;
}

// Convert monkeys to elephants: a mind-boggling conversion
double monkeyToElephant(double monkeys) {
  return monkeys / 1000;
}