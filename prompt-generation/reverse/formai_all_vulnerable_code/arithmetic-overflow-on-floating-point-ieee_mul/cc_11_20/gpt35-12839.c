//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

// Function prototypes
void print_menu();
double convert_length(double value, int from_unit, int to_unit);
double convert_mass(double value, int from_unit, int to_unit);
double convert_temperature(double value, int from_unit, int to_unit);

int main()
{
    print_menu(); // Display main menu
  
    int option; // Option selected by user
    scanf("%d", &option); // Read the option selected by user
  
    switch(option)
    {
      case 1:
        // Length conversion
        printf("Enter the value to convert: ");
        double length_value;
        scanf("%lf", &length_value);
        printf("Enter the unit to convert from (1 - Meter, 2 - Centimeter, 3 - Millimeter, 4 - Kilometer, 5 - Foot, 6 - Inch): ");
        int from_length_unit;
        scanf("%d", &from_length_unit);
        printf("Enter the unit to convert to (1 - Meter, 2 - Centimeter, 3 - Millimeter, 4 - Kilometer, 5 - Foot, 6 - Inch): ");
        int to_length_unit;
        scanf("%d", &to_length_unit);
        double converted_length = convert_length(length_value, from_length_unit, to_length_unit);
        printf("%.2lf %s is %.2lf %s\n", length_value, 
        from_length_unit==1?"Meter":from_length_unit==2?"Centimeter":from_length_unit==3?"Millimeter":from_length_unit==4?"Kilometer":from_length_unit==5?"Foot":"Inch",
        converted_length,
        to_length_unit==1?"Meter":to_length_unit==2?"Centimeter":to_length_unit==3?"Millimeter":to_length_unit==4?"Kilometer":to_length_unit==5?"Foot":"Inch");
        break;
        
      case 2:
        // Mass conversion
        printf("Enter the value to convert: ");
        double mass_value;
        scanf("%lf", &mass_value);
        printf("Enter the unit to convert from (1 - Kilogram, 2 - Gram, 3 - Milligram, 4 - Pound, 5 - Ounce): ");
        int from_mass_unit;
        scanf("%d", &from_mass_unit);
        printf("Enter the unit to convert to (1 - Kilogram, 2 - Gram, 3 - Milligram, 4 - Pound, 5 - Ounce): ");
        int to_mass_unit;
        scanf("%d", &to_mass_unit);
        double converted_mass = convert_mass(mass_value, from_mass_unit, to_mass_unit);
        printf("%.2lf %s is %.2lf %s\n", mass_value,
        from_mass_unit==1?"Kilogram":from_mass_unit==2?"Gram":from_mass_unit==3?"Milligram":from_mass_unit==4?"Pound":"Ounce",
        converted_mass,
        to_mass_unit==1?"Kilogram":to_mass_unit==2?"Gram":to_mass_unit==3?"Milligram":to_mass_unit==4?"Pound":"Ounce");
        break;
        
      case 3:
        // Temperature conversion
        printf("Enter the value to convert: ");
        double temp_value;
        scanf("%lf", &temp_value);
        printf("Enter the unit to convert from (1 - Celsius, 2 - Fahrenheit, 3 - Kelvin): ");
        int from_temp_unit;
        scanf("%d", &from_temp_unit);
        printf("Enter the unit to convert to (1 - Celsius, 2 - Fahrenheit, 3 - Kelvin): ");
        int to_temp_unit;
        scanf("%d", &to_temp_unit);
        double converted_temp = convert_temperature(temp_value, from_temp_unit, to_temp_unit);
        printf("%.2lf %s is %.2lf %s\n", temp_value,
        from_temp_unit==1?"Celsius":from_temp_unit==2?"Fahrenheit":"Kelvin",
        converted_temp,
        to_temp_unit==1?"Celsius":to_temp_unit==2?"Fahrenheit":"Kelvin");
        break;
        
      case 4:
        // Quit the program
        printf("Thank you for using the unit converter\n");
        break;
        
      default:
        // Invalid option
        printf("Invalid option, please try again\n");
    }
  
    return 0;
}

// Function to print the main menu
void print_menu()
{
  printf("=============== Unit Converter ===============\n");
  printf("What do you want to convert?\n");
  printf("1. Length\n");
  printf("2. Mass\n");
  printf("3. Temperature\n");
  printf("4. Quit\n");
  printf("Enter your choice: ");
}

// Function to convert length
double convert_length(double value, int from_unit, int to_unit)
{
  double converted_value;
  
  // Convert to meter
  if(from_unit == 1)
  {
    converted_value = value;
  }
  else if(from_unit == 2)
  {
    converted_value = value / 100;
  }
  else if(from_unit == 3)
  {
    converted_value = value / 1000;
  }
  else if(from_unit == 4)
  {
    converted_value = value * 1000;
  }
  else if(from_unit == 5)
  {
    converted_value = value / 3.281;
  }
  else if(from_unit == 6)
  {
    converted_value = value / 39.37;
  }
  
  // Convert to destination unit
  if(to_unit == 1)
  {
    return converted_value;
  }
  else if(to_unit == 2)
  {
    return converted_value * 100;
  }
  else if(to_unit == 3)
  {
    return converted_value * 1000;
  }
  else if(to_unit == 4)
  {
    return converted_value / 1000;
  }
  else if(to_unit == 5)
  {
    return converted_value * 3.281;
  }
  else if(to_unit == 6)
  {
    return converted_value * 39.37;
  }
}

// Function to convert mass
double convert_mass(double value, int from_unit, int to_unit)
{
  double converted_value;
  
  // Convert to kilogram
  if(from_unit == 1)
  {
    converted_value = value;
  }
  else if(from_unit == 2)
  {
    converted_value = value / 1000;
  }
  else if(from_unit == 3)
  {
    converted_value = value / 1000000;
  }
  else if(from_unit == 4)
  {
    converted_value = value * 0.453592;
  }
  else if(from_unit == 5)
  {
    converted_value = value * 0.0283495;
  }
  
  // Convert to destination unit
  if(to_unit == 1)
  {
    return converted_value;
  }
  else if(to_unit == 2)
  {
    return converted_value * 1000;
  }
  else if(to_unit == 3)
  {
    return converted_value * 1000000;
  }
  else if(to_unit == 4)
  {
    return converted_value / 0.453592;
  }
  else if(to_unit == 5)
  {
    return converted_value / 0.0283495;
  }
}

// Function to convert temperature
double convert_temperature(double value, int from_unit, int to_unit)
{
  double converted_value;
  
  // Convert to Celsius
  if(from_unit == 1)
  {
    converted_value = value;
  }
  else if(from_unit == 2)
  {
    converted_value = (value - 32) / 1.8;
  }
  else if(from_unit == 3)
  {
    converted_value = value - 273.15;
  }
  
  // Convert to destination unit
  if(to_unit == 1)
  {
    return converted_value;
  }
  else if(to_unit == 2)
  {
    return converted_value * 1.8 + 32;
  }
  else if(to_unit == 3)
  {
    return converted_value + 273.15;
  }
}