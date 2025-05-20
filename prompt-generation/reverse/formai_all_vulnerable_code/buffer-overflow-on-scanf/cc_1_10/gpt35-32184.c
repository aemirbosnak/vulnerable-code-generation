//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

float readTemperature();                               // function to read temperature
void sendToServer(float temperature, char* location);   // function to send temperature information to server
void displayTemperature(float temperature);             // function to display temperature on the screen
void logTemperature(float temperature, char* location); // function to log temperature in a file

int main()
{
    char location[20];     // variable to store the location of the temperature monitor
    float temperature;     // variable to store the temperature

    printf("Enter the location of the temperature monitor: ");
    scanf("%s", location); // read location from user input

    while(1)
    {
        temperature = readTemperature();     // read temperature from sensor
        sendToServer(temperature, location); // send temperature information to server
        displayTemperature(temperature);     // display temperature on the screen
        logTemperature(temperature, location); // log temperature in a file

        #ifdef _WIN32
            Sleep(5000); // wait for 5 seconds on Windows
        #else
            sleep(5);    // wait for 5 seconds on Unix-based systems
        #endif
    }

    return 0;
}

float readTemperature()
{
    float temperature;

    // generate a random temperature between 0 and 100
    temperature = (float)rand() / (float)RAND_MAX * 100;

    return temperature;
}

void sendToServer(float temperature, char* location)
{
    // code to send temperature information to server goes here
    printf("Temperature: %.2f, Location: %s\n", temperature, location);
}

void displayTemperature(float temperature)
{
    printf("Temperature: %.2f\n", temperature);
}

void logTemperature(float temperature, char* location)
{
    // code to log temperature in a file goes here
    FILE *fp;
    char log[50];

    snprintf(log, sizeof(log), "Temperature: %.2f, Location: %s\n", temperature, location);

    fp = fopen("temperature.log", "a"); // open temperature.log file in append mode
    if(fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    fprintf(fp, "%s", log); // write the log message to the file
    fclose(fp);             // close the file
}