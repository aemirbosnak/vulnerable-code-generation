//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

double C = 0; // global Celsius value
double F = 0; // global Fahrenheit value
int is_celsius_ready = 0; // flag to indicate when Celsius value is ready
int is_fahrenheit_ready = 0; // flag to indicate when Fahrenheight value is ready

void *celsius_to_fahrenheit(void *arg) {
  while (1) {
    if (is_celsius_ready) {
      F = (C * 9/5) + 32; // convert Celsius to Fahrenheit
      printf("%.2f C = %.2f F\n", C, F);
      is_celsius_ready = 0;
      is_fahrenheit_ready = 1;
    }
  }
}

void *fahrenheit_to_celsius(void *arg) {
  while (1) {
    if (is_fahrenheit_ready) {
      C = (F - 32) * 5/9; // convert Fahrenheit to Celsius
      printf("%.2f F = %.2f C\n", F, C);
      is_fahrenheit_ready = 0;
      is_celsius_ready = 1;
    }
  }
}

int main() {
  pthread_t ctf_thread, ftc_thread;

  // create threads
  pthread_create(&ctf_thread, NULL, celsius_to_fahrenheit, NULL);
  pthread_create(&ftc_thread, NULL, fahrenheit_to_celsius, NULL);

  while (1) {
    // get input from user
    double input;
    char scale;
    printf("\nEnter a temperature and scale (C or F): ");
    scanf("%lf %c", &input, &scale);

    // check scale and set global value appropriately
    if (scale == 'C' || scale == 'c') {
      C = input;
      is_celsius_ready = 1;
      is_fahrenheit_ready = 0;
    }
    else if (scale == 'F' || scale == 'f') {
      F = input;
      is_fahrenheit_ready = 1;
      is_celsius_ready = 0;
    }
    else {
      printf("Invalid scale. Please enter C or F.\n");
    }
  }

  return 0;
}