//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>

// Oh no, you're trying to convert units?!
// Brace yourself, this code will shock you!

// Define a bunch of constants (prepare for a static shock!)
#define VOLTS_PER_KILOVOLT    1000
#define KILOVOLTS_PER_VOLT    0.001
#define AMPS_PER_MILLIAMP      1000
#define MILLIAMPS_PER_AMP      0.001
#define OHMS_PER_KILOHM        1000
#define KILOHMS_PER_OHM        0.001
#define FARADS_PER_MICROFARAD   1000
#define MICROFARADS_PER_FARAD   0.001

// Define a function to convert volts to kilovolts (it's gonna be a high-voltage situation!)
int volts_to_kilovolts(int volts) {
  return volts / VOLTS_PER_KILOVOLT;
}

// Define a function to convert kilovolts to volts (brace for a low-voltage drop!)
int kilovolts_to_volts(int kilovolts) {
  return kilovolts * KILOVOLTS_PER_VOLT;
}

// Define a function to convert amps to milliamps (it's gonna be a current affair!)
int amps_to_milliamps(int amps) {
  return amps / AMPS_PER_MILLIAMP;
}

// Define a function to convert milliamps to amps (brace for a high-current surge!)
int milliamps_to_amps(int milliamps) {
  return milliamps * MILLIAMPS_PER_AMP;
}

// Define a function to convert ohms to kilohms (it's gonna be a high-resistance challenge!)
int ohms_to_kilohms(int ohms) {
  return ohms / OHMS_PER_KILOHM;
}

// Define a function to convert kilohms to ohms (brace for a low-resistance drop!)
int kilohms_to_ohms(int kilohms) {
  return kilohms * KILOHMS_PER_OHM;
}

// Define a function to convert farads to microfarads (it's gonna be a capacitive shock!)
int farads_to_microfarads(int farads) {
  return farads / FARADS_PER_MICROFARAD;
}

// Define a function to convert microfarads to farads (brace for a low-capacitance drop!)
int microfarads_to_farads(int microfarads) {
  return microfarads * MICROFARADS_PER_FARAD;
}

// Define a main function to test the unit converter (it's gonna be electrifying!)
int main() {
  // Declare some variables to store the input and output values (get ready for a charge!)
  int volts, kilovolts, amps, milliamps, ohms, kilohms, farads, microfarads;

  // Prompt the user to enter the input values (prepare for a shocking experience!)
  printf("Enter the voltage in volts: ");
  scanf("%d", &volts);

  printf("Enter the current in amps: ");
  scanf("%d", &amps);

  printf("Enter the resistance in ohms: ");
  scanf("%d", &ohms);

  printf("Enter the capacitance in farads: ");
  scanf("%d", &farads);

  // Convert the input values to their respective units (it's gonna be a high-voltage thrill!)
  kilovolts = volts_to_kilovolts(volts);
  milliamps = amps_to_milliamps(amps);
  kilohms = ohms_to_kilohms(ohms);
  microfarads = farads_to_microfarads(farads);

  // Display the converted values (prepare for a shocking revelation!)
  printf("The voltage in kilovolts is: %d\n", kilovolts);
  printf("The current in milliamps is: %d\n", milliamps);
  printf("The resistance in kilohms is: %d\n", kilohms);
  printf("The capacitance in microfarads is: %d\n", microfarads);

  // Convert the converted values back to their original units (brace for a low-voltage drop!)
  volts = kilovolts_to_volts(kilovolts);
  amps = milliamps_to_amps(milliamps);
  ohms = kilohms_to_ohms(kilohms);
  farads = microfarads_to_farads(microfarads);

  // Display the original values again (prepare for a shocking reminder!)
  printf("The original voltage in volts is: %d\n", volts);
  printf("The original current in amps is: %d\n", amps);
  printf("The original resistance in ohms is: %d\n", ohms);
  printf("The original capacitance in farads is: %d\n", farads);

  // Return 0 (it's gonna be a shockingly good ending!)
  return 0;
}