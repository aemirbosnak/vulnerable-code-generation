//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>

int main() {
  double celsius, fahrenheit;
  char answer;

  printf("Welcome to the Paranoid Temperature Converter!\n");
  printf("Do you want to convert Celsius to Fahrenheit? (Y/N) ");

  scanf("%c", &answer);

  if (answer == 'Y' || answer == 'y') {
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);

    if(celsius < -273.15) {
      printf("Temperature below absolute zero is not possible!\n");
      printf("Run for your life! The end is near!\n");
    }
    else {
      fahrenheit = (celsius * 9/5) + 32;
      printf("%.2f°C is equal to %.2f°F.\n", celsius, fahrenheit);
      printf("Phew! That was close. Everything seems to be fine.\n");
    }
  }
  else if (answer == 'N' || answer == 'n') {
    printf("Do you want to convert Fahrenheit to Celsius?(Y/N) ");
    scanf(" %c", &answer);
    
    if(answer == 'Y' || answer == 'y'){
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%lf", &fahrenheit);
      
      if(fahrenheit < -459.67) {
        printf("Temperature below absolute zero is not possible!\n");
        printf("Abandon all hope! Save yourself from doom!\n");
      } else {
        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f°F is equal to %.2f°C.\n", fahrenheit, celsius);
        printf("Thank goodness! All systems are functioning normally.\n");
      }
    } else {
      printf("Don't play games with me! You must convert something.\n");

      printf("Shutting down program...\n");
      printf("Wait a minute! Did anyone mess with my code? I am being paranoid...\n");
      printf("Initialization error! Abort! Abort!...\n");
    }
  } else {
    printf("Invalid input! Run for your life! The system is compromised!\n");
    printf("Warning! Intruder alert! Shutting down...\n");
  }

  return 0;
}