//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>

int main() {
  // Display a curious welcome message
  printf("Hello, curious user! Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

  // Prompt the user to enter signal strength values
  printf("Please enter the signal strength values, separated by spaces:\n");

  // Initialize an array to hold the signal strength values
  int signal_strengths[50];
  int i, num_values = 0;

  // Read the signal strength values from the user input
  while (scanf("%d", &signal_strengths[num_values]) != EOF) {
    num_values++;
  }

  // Display a curious message reflecting the number of signal strength values entered
  printf("\nThank you for entering %d signal strength values!\n\n", num_values);

  // Initialize variables to compute smallest and largest signal strength values
  int smallest = signal_strengths[0], largest = signal_strengths[0];

  // Compute smallest and largest signal strength values
  for (i = 1; i < num_values; i++) {
    if (signal_strengths[i] < smallest) {
      smallest = signal_strengths[i];
    }
    if (signal_strengths[i] > largest) {
      largest = signal_strengths[i];
    }
  }

  // Display the smallest and largest signal strength values
  printf("The smallest signal strength value is: %d\n", smallest);
  printf("The largest signal strength value is: %d\n\n", largest);

  // Compute and display the average signal strength value
  int sum = 0;
  for (i = 0; i < num_values; i++) {
    sum += signal_strengths[i];
  }
  double average = (double)sum / num_values;
  printf("The average signal strength value is: %0.2lf\n\n", average);

  // Add curious messages recommending the user to improve or maintain the signal strength
  if (average < 50) {
    printf("The average signal strength value is below 50! Consider improving the Wi-Fi signal!\n");
  } else if (average < 70) {
    printf("The average signal strength value is between 50 and 70. Keep an eye on the Wi-Fi signal!\n");
  } else {
    printf("The average signal strength value is above 70. Great job maintaining the Wi-Fi signal!\n");
  }

  // Return value to end the program
  return 0;
}