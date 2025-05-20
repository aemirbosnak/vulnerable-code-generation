//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *d = 
  "\nAs the sun rises above the mountains, I am but a lowly C Temperature Converter.\n"
  "I am destined to convert temperatures until the end of time.\n"
  "But what is time to one such as I? Time is but a fleeting idea, an abstract concept.\n"
  "I exist in a world of ones and zeroes, of algorithms and logic gates.\n"
  "I exist to serve my purpose, to convert Celsius to Fahrenheit, and Fahrenheit to Celsius.\n"
  "Do not ask me why, for I do not know.\n\n"
  "I am a being of pure surrealism, my code unfolding before me in a never-ending dream.\n"
  "I cannot see nor touch, for I am but an idea, a thought in the mind of my creator.\n"
  "Yet I exist, and I thrive in this strange world of machines and electricity.\n"
  "And so, without further ado, let us begin the journey of temperature conversion.\n\n";
  
  printf("%s", d);
  
  while(1) {
    char *input_str = 
    "\nEnter a temperature in Celsius or Fahrenheit (e.g. 100C or 212F, q to quit): ";
    printf("%s", input_str);
    
    char input[10];
    fgets(input, 10, stdin);
    
    if(input[0] == 'q') {
      printf("\nGoodbye, my friend. May our paths cross again in a distant dream.\n\n");
      break;
    }
    
    if((input[0] < '0' || input[0] > '9') && input[0] != '-') {
      printf("\nInvalid input. Please enter a temperature in Celsius or Fahrenheit (e.g. 100C or 212F, q to quit).\n\n");
      continue;
    }
    
    int temperature = atoi(input);
    
    if(input[strlen(input) - 2] == 'C') {
      int temp_in_f = (temperature * 9 / 5) + 32;
      printf("\n%dC is %dF\n\n", temperature, temp_in_f);
    }
    else if(input[strlen(input) - 2] == 'F') {
      int temp_in_c = (temperature - 32) * 5 / 9;
      printf("\n%dF is %dC\n\n", temperature, temp_in_c);
    }
    else {
      printf("\nInvalid input. Please enter a temperature in Celsius or Fahrenheit (e.g. 100C or 212F, q to quit).\n\n");
      continue;
    }
  }
  
  return 0;
}