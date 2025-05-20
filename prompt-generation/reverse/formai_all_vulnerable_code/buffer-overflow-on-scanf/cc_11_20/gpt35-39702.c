//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
/*
 * This is a unique C Unit converter program that is designed for artists!
 * It converts between pixels, inches, and centimeters to help artists accurately
 * translate their works across different mediums. 
 *
 * The program begins by asking the user to input the starting unit, with options 
 * for pixels, inches, or centimeters. Then, the user inputs the value of their 
 * measurement in that starting unit. Finally, the user selects the desired output
 * unit, and the program calculates and prints the converted value.
 *
 * Let's get creative!
 */

#include <stdio.h>

int main() {

  // Declare variables
  float starting_measurement, converted_measurement;
  int starting_unit, output_unit;

  // Print welcome message and instructions
  printf("Welcome to the Art Unit Converter!\n");
  printf("Please select the starting unit for your measurement:\n");
  printf("1. Pixels\n");
  printf("2. Inches\n");
  printf("3. Centimeters\n");
  printf("Enter the corresponding number: ");
  scanf("%d", &starting_unit);

  // Get the value of the starting measurement
  printf("\nEnter the value of your measurement: ");
  scanf("%f", &starting_measurement);

  // Ask for the desired output unit
  printf("\nWhich unit would you like to convert to?\n");
  printf("1. Pixels\n");
  printf("2. Inches\n");
  printf("3. Centimeters\n");
  printf("Enter the corresponding number: ");
  scanf("%d", &output_unit);

  // Convert the measurement based on starting and output units
  if (starting_unit == 1) { // Convert from pixels
    if (output_unit == 1) { // Convert to pixels
      converted_measurement = starting_measurement;
    } else if (output_unit == 2) { // Convert to inches
      converted_measurement = starting_measurement / 96;
    } else if (output_unit == 3) { // Convert to centimeters
      converted_measurement = starting_measurement / 38.58;
    } else { // Invalid output unit
      printf("\nInvalid output unit entered. Please try again.\n");
      return 0;
    }
  } else if (starting_unit == 2) { // Convert from inches
    if (output_unit == 1) { // Convert to pixels
      converted_measurement = starting_measurement * 96;
    } else if (output_unit == 2) { // Convert to inches
      converted_measurement = starting_measurement;
    } else if (output_unit == 3) { // Convert to centimeters
      converted_measurement = starting_measurement * 2.54;
    } else { // Invalid output unit
      printf("\nInvalid output unit entered. Please try again.\n");
      return 0;
    }
  } else if (starting_unit == 3) { // Convert from centimeters
    if (output_unit == 1) { // Convert to pixels
      converted_measurement = starting_measurement * 38.58;
    } else if (output_unit == 2) { // Convert to inches
      converted_measurement = starting_measurement / 2.54;
    } else if (output_unit == 3) { // Convert to centimeters
      converted_measurement = starting_measurement;
    } else { // Invalid output unit
      printf("\nInvalid output unit entered. Please try again.\n");
      return 0;
    }
  } else { // Invalid starting unit
    printf("\nInvalid starting unit entered. Please try again.\n");
    return 0;
  }

  // Print the converted measurement
  if (output_unit == 1) { // Convert from pixels
    printf("\nThe converted measurement is %.2f pixels.\n", converted_measurement);
  } else if (output_unit == 2) { // Convert to inches
    printf("\nThe converted measurement is %.2f inches.\n", converted_measurement);
  } else if (output_unit == 3) { // Convert to centimeters
    printf("\nThe converted measurement is %.2f centimeters.\n", converted_measurement);
  }

  // End of program
  printf("\nThank you for using the Art Unit Converter! Keep creating!\n");
  return 0;
}