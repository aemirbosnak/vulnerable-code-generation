//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 100
#define CELSIUS "Celsius"
#define FAHRENHEIT "Fahrenheit"

void *convertToFahrenheit(void *arg);
void *convertToCelsius(void *arg);

int main()
{
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    char choice[MAX_INPUT_SIZE] = {0};
    float temperature = 0.0f;
    bool valid_input = false;

    while (!valid_input)
    {
        printf("Enter a temperature: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        char *end_ptr = NULL;

        temperature = strtof(input, &end_ptr);

        if (!isdigit(*input) || *end_ptr != '\0')
        {
            printf("Invalid input. Please enter a valid temperature.\n");
            continue;
        }

        printf("Convert to Celsius or Fahrenheit? (C/F): ");
        fgets(choice, MAX_INPUT_SIZE, stdin);
        if (choice[strlen(choice) - 1] == '\n')
        {
            choice[strlen(choice) - 1] = '\0';
        }

        if (strcmp(choice, "C") == 0 || strcmp(choice, "c") == 0)
        {
            valid_input = true;
            pthread_t celsius_thread;
            pthread_create(&celsius_thread, NULL, convertToCelsius, &temperature);
            pthread_join(celsius_thread, NULL);
        }
        else if (strcmp(choice, "F") == 0 || strcmp(choice, "f") == 0)
        {
            valid_input = true;
            pthread_t fahrenheit_thread;
            pthread_create(&fahrenheit_thread, NULL, convertToFahrenheit, &temperature);
            pthread_join(fahrenheit_thread, NULL);
        }
        else
        {
            printf("Invalid input. Please enter C or F.\n");
        }
    }
    return 0;
}

void *convertToCelsius(void *arg)
{
    float temperature = *(float *)arg;
    float celsius = (temperature - 32) * (5.0 / 9.0);
    printf("%.2f %s is %.2f %s\n", temperature, FAHRENHEIT, celsius, CELSIUS);
    pthread_exit(NULL);
}

void *convertToFahrenheit(void *arg)
{
    float temperature = *(float *)arg;
    float fahrenheit = (temperature * 9.0 / 5.0) + 32;
    printf("%.2f %s is %.2f %s\n", temperature, CELSIUS, fahrenheit, FAHRENHEIT);
    pthread_exit(NULL);
}