//FormAI DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main(){
  int choice, sub_choice, value;
  float result;
  
  printf("Welcome to C Unit Converter\n");
  printf("Please select an option\n");
  printf("1. Length\n");
  printf("2. Temperature\n");
  printf("3. Time\n");
  
  scanf("%d", &choice);
  
  switch(choice){
    case 1:
      printf("\nLength Conversion\n");
      printf("1. Feet to Meters\n");
      printf("2. Meters to Feet\n");
      printf("3. Inches to Centimeters\n");
      printf("4. Centimeters to Inches\n");
      printf("5. Yards to Meters\n");
      printf("6. Meters to Yards\n");
      scanf("%d", &sub_choice);
      
      switch(sub_choice){
        case 1:
          printf("Enter feet value: ");
          scanf("%d", &value);
          result = value * 0.3048;
          printf("%d feet is equal to %.2f meters\n", value, result);
          break;
        case 2:
          printf("Enter meters value: ");
          scanf("%d", &value);
          result = value * 3.2808;
          printf("%d meters is equal to %.2f feet\n", value, result);
          break;
        case 3:
          printf("Enter inches value: ");
          scanf("%d", &value);
          result = value * 2.54;
          printf("%d inches is equal to %.2f centimeters\n", value, result);
          break;
        case 4:
          printf("Enter centimeters value: ");
          scanf("%d", &value);
          result = value / 2.54;
          printf("%d centimeters is equal to %.2f inches\n", value, result);
          break;
        case 5:
          printf("Enter yards value: ");
          scanf("%d", &value);
          result = value * 0.9144;
          printf("%d yards is equal to %.2f meters\n", value, result);
          break;
        case 6:
          printf("Enter meters value: ");
          scanf("%d", &value);
          result = value * 1.0936;
          printf("%d meters is equal to %.2f yards\n", value, result);
          break;
        default:
          printf("Invalid choice\n");
      }
      break;
    case 2:
      printf("\nTemperature Conversion\n");
      printf("1. Celsius to Fahrenheit\n");
      printf("2. Fahrenheit to Celsius\n");
      scanf("%d", &sub_choice);
      
      switch(sub_choice){
        case 1:
          printf("Enter temperature in Celsius: ");
          scanf("%d", &value);
          result = (value * 9/5) + 32;
          printf("%d degree Celsius is equal to %.2f degree Fahrenheit\n", value, result);
          break;
        case 2:
          printf("Enter temperature in Fahrenheit: ");
          scanf("%d", &value);
          result = (value - 32) * 5/9;
          printf("%d degree Fahrenheit is equal to %.2f degree Celsius\n", value, result);
          break;
        default:
          printf("Invalid choice\n");
      }
      break;
    case 3:
      printf("\nTime Conversion\n");
      printf("1. Minutes to Seconds\n");
      printf("2. Seconds to Minutes\n");
      scanf("%d", &sub_choice);
      
      switch(sub_choice){
        case 1:
          printf("Enter minutes value: ");
          scanf("%d", &value);
          result = value * 60;
          printf("%d minutes is equal to %.2f seconds\n", value, result);
          break;
        case 2:
          printf("Enter seconds value: ");
          scanf("%d", &value);
          result = value / 60;
          printf("%d seconds is equal to %.2f minutes\n", value, result);
          break;
        default:
          printf("Invalid choice\n");
      }
      break;
    default:
      printf("Invalid choice\n");
  }
  
  return 0;
}