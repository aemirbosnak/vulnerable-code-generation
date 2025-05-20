//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold temperature data
struct temperature_data {
  float temperature;
  int hour;
  int minute;
};

//Function to display temperature data
void display_data(struct temperature_data data[], int size) {
  printf("\nTemperature Data:\n");
  for(int i=0; i<size; i++) {
    printf("%0.2fC at %d:%d\n", data[i].temperature, data[i].hour, data[i].minute);
  }
}

//Function to calculate average temperature
float calculate_average_temperature(struct temperature_data data[], int size) {
  float sum = 0;
  for(int i=0; i<size; i++) {
    sum += data[i].temperature;
  }
  return sum/size;
}

//Function to find highest temperature and corresponding time
void find_highest_temperature(struct temperature_data data[], int size) {
  float max_temp = data[0].temperature;
  int max_hour = data[0].hour;
  int max_minute = data[0].minute;
  for(int i=1; i<size; i++) {
    if(data[i].temperature > max_temp) {
      max_temp = data[i].temperature;
      max_hour = data[i].hour;
      max_minute = data[i].minute;
    }
  }
  printf("\nHighest Temperature: %0.2fC at %d:%d\n", max_temp, max_hour, max_minute);
}

int main() {
  int num_of_temps;
  printf("Enter number of temperature readings: ");
  scanf("%d", &num_of_temps);

  //Allocate memory for array of temperature data
  struct temperature_data* data = (struct temperature_data*) malloc(num_of_temps*sizeof(struct temperature_data));

  //Get temperature data from user
  for(int i=0; i<num_of_temps; i++) {
    printf("Reading %d:\n", i+1);
    printf("Temperature (in Celsius): ");
    scanf("%f", &data[i].temperature);
    printf("Hour (24-hour format): ");
    scanf("%d", &data[i].hour);
    printf("Minute: ");
    scanf("%d", &data[i].minute);
  }

  //Display temperature data
  display_data(data, num_of_temps);

  //Calculate and display average temperature
  float avg_temp = calculate_average_temperature(data, num_of_temps);
  printf("\nAverage Temperature: %0.2fC\n", avg_temp);

  //Find highest temperature and corresponding time
  find_highest_temperature(data, num_of_temps);

  //Free allocated memory
  free(data);
  
  return 0;
}