//FormAI DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void display_menu();
void convert_temp();
void convert_length();
void convert_mass();

int main()
{
  int choice;
  
  while(1)
  {
    display_menu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
      case 1:
        convert_temp();
        break;
        
      case 2:
        convert_length();
        break;
        
      case 3:
        convert_mass();
        break;
        
      case 4:
        exit(0);
        
      default:
        printf("\nInvalid choice. Try again.");
    }
  }
  
  return 0;
}

void display_menu()
{
  printf("=== UNIT CONVERTER ===\n\n");
  printf("1. Temperature\n");
  printf("2. Length\n");
  printf("3. Mass\n");
  printf("4. Exit\n");
}

void convert_temp()
{
  float temp, result;
  int from, to;
  
  printf("\nEnter the temperature: ");
  scanf("%f", &temp);
  
  printf("\nSelect the unit you want to convert from: ");
  printf("\n1. Celsius\n2. Fahrenheit\n");
  scanf("%d", &from);
  
  printf("\nSelect the unit you want to convert to: ");
  printf("\n1. Celsius\n2. Fahrenheit\n");
  scanf("%d", &to);
  
  if(from == 1 && to == 2)       // Celsius to Fahrenheit
    result = (temp * 9/5) + 32;
    
  else if(from == 2 && to == 1)  // Fahrenheit to Celsius
    result = (temp - 32) * 5/9;
    
  else
  {
    printf("Invalid conversion.");
    return;
  }
  
  printf("\nResult: %.2f", result);
}

void convert_length()
{
  float length, result;
  int from, to;
  
  printf("\nEnter the length: ");
  scanf("%f", &length);
  
  printf("\nSelect the unit you want to convert from: ");
  printf("\n1. Meter\n2. Kilometer\n3. Centimeter\n");
  scanf("%d", &from);
  
  printf("\nSelect the unit you want to convert to: ");
  printf("\n1. Meter\n2. Kilometer\n3. Centimeter\n");
  scanf("%d", &to);
  
  if(from == 1 && to == 2)       // Meter to Kilometer
    result = length / 1000;
    
  else if(from == 1 && to == 3)  // Meter to Centimeter
    result = length * 100;
    
  else if(from == 2 && to == 1)  // Kilometer to Meter
    result = length * 1000;
  
  else if(from == 2 && to == 3)  // Kilometer to Centimeter
    result = length * 100000;
    
  else if(from == 3 && to == 1)  // Centimeter to Meter
    result = length / 100;
    
  else if(from == 3 && to == 2)  // Centimeter to Kilometer
    result = length / 100000;
    
  else
  {
    printf("Invalid conversion.");
    return;
  }
  
  printf("\nResult: %.2f", result);
}

void convert_mass()
{
  float mass, result;
  int from, to;
  
  printf("\nEnter the mass: ");
  scanf("%f", &mass);
  
  printf("\nSelect the unit you want to convert from: ");
  printf("\n1. Kilogram\n2. Gram\n3. Milligram\n");
  scanf("%d", &from);
  
  printf("\nSelect the unit you want to convert to: ");
  printf("\n1. Kilogram\n2. Gram\n3. Milligram\n");
  scanf("%d", &to);
  
  if(from == 1 && to == 2)       // Kilogram to Gram
    result = mass * 1000;
    
  else if(from == 1 && to == 3)  // Kilogram to Milligram
    result = mass * 1000000;
    
  else if(from == 2 && to == 1)  // Gram to Kilogram
    result = mass / 1000;
  
  else if(from == 2 && to == 3)  // Gram to Milligram
    result = mass * 1000;
    
  else if(from == 3 && to == 1)  // Milligram to Kilogram
    result = mass / 1000000;
    
  else if(from == 3 && to == 2)  // Milligram to Gram
    result = mass / 1000;
    
  else
  {
    printf("Invalid conversion.");
    return;
  }
  
  printf("\nResult: %.2f", result);
}