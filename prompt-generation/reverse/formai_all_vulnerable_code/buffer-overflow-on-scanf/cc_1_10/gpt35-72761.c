//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <time.h>

int main(void) {
  // Initializing variables
  float temp;
  FILE *tempData;
  time_t current_time;
  char* c_time_string;

  // Open the file in read mode
  tempData = fopen("temperature_data.txt","r");

  // If file does not exist, create it
  if(tempData == NULL) {
    tempData = fopen("temperature_data.txt","w");
    fclose(tempData);
    printf("File created successfully!\n");
  } else {
    printf("Previous temperature data:\n");
    printf("========================\n");

    // Display the previous recorded temperature data
    while(!feof(tempData)) {
      fscanf(tempData, "%f", &temp);
      printf("%.2f\n", temp);
    }
    fclose(tempData);
  }

  // Open the file in append mode
  tempData = fopen("temperature_data.txt", "a");

  printf("\nCurrent Temperature Monitor\n");
  printf("========================\n");

  // Get current time
  current_time = time(NULL);

  // Convert to local time format
  c_time_string = ctime(&current_time);

  // Read user input
  printf("Enter the current temperature in Celsius: ");
  scanf("%f", &temp);

  // Print temperature and time to console and file
  printf("\nTemperature: %.2fC\n", temp);
  printf("Time: %s", c_time_string);
  fprintf(tempData, "%.2f\n", temp);

  // Close file
  fclose(tempData);

  return 0;
}