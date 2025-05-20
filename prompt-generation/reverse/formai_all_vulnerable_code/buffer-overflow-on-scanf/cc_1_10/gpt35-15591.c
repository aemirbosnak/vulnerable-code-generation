//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
/* It was a crisp autumn morning, and Detective Sherlock Holmes was pondering over a new case. 
He scratched his head as he looked at the temperature readings in Fahrenheit. Something was just not right. 
The solution to the case rested on the correct conversion of Fahrenheit to Celsius and Vice Versa. With his sheer brilliance and expertise in programming,
Sherlock decided to create a Temperature Converter Program to solve the mystery once and for all.*/

#include <stdio.h>

void main() {
  char choice;
  float f, c;

  while(1) {   // The while loop was his closest companion in every case.
    printf("\nWelcome to the Fahrenheit-Celsius Temperature Converter Program!");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\nWould you like to convert Celsius to Fahrenheit? (y/n): ");
    scanf("%c", &choice);
    getchar();  //To consume newline character left behind by scanf

    switch(choice) {
      case 'y':
      case 'Y': 
        printf("\nEnter the temperature in Celsius: ");
        scanf("%f", &c);
        f = (c * 9/5) + 32;
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", c, f);
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        break;

      case 'n':
      case 'N':
        printf("\nEnter the temperature in Fahrenheit: ");
        scanf("%f", &f);
        c = (f - 32) * 5/9;
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", f, c);
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        break;

      default:
        printf("\nOi! Invalid Input. Try again!");
        break;
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nWould you like to convert another temperature? (y/n): ");
    scanf("%c", &choice);
    getchar();    
    if(choice == 'n' || choice == 'N') {
      printf("\nGoodbye and Happy Sleuthing! \n");
      break;
    }
  }
}