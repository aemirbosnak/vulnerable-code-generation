//FormAI DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Constants
#define MAX_TEMP 100

// Function prototypes
void displayMenu();
int getNewTemperature(int temps[], int count);
void displayTemperatures(int temps[], int count);
double getAverageTemperature(int temps[], int count);
int getCountAboveAverage(int temps[], int count, double avgTemp);

int main()
{
    int temperatures[MAX_TEMP]; // Array to hold temperature readings
    int count = 0; // Counter for number of temperature readings
    int choice;
    double averageTemp;
    int numAboveAvg;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = getNewTemperature(temperatures, count);
                break;
            case 2:
                displayTemperatures(temperatures, count);
                break;
            case 3:
                averageTemp = getAverageTemperature(temperatures, count);
                printf("The average temperature is: %.1lf\n", averageTemp);
                break;
            case 4:
                averageTemp = getAverageTemperature(temperatures, count);
                numAboveAvg = getCountAboveAverage(temperatures, count, averageTemp);
                printf("There are %d temperature readings above the average temperature.\n", numAboveAvg);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please select a valid menu option.\n");
                break;
        }
        printf("\n");
    } while (choice != 5);
    
    return 0;
}

// Function to display menu options
void displayMenu()
{
    printf("\n");
    printf("Temperature Monitor Menu\n");
    printf("------------------------\n");
    printf("1. Enter a new temperature reading.\n");
    printf("2. Display all temperature readings.\n");
    printf("3. Display the average temperature.\n");
    printf("4. Display the number of temperature readings above the average.\n");
    printf("5. Exit the program.\n");
}

// Function to get new temperature reading from user
int getNewTemperature(int temps[], int count)
{
    int newTemp;
    char response;

    do {
        printf("Enter a new temperature reading (-100 to 150): ");
        scanf("%d", &newTemp);

        if (newTemp < -100 || newTemp > 150) {
            printf("Invalid temperature value, please enter a value between -100 and 150.\n");
        }
        else {
            temps[count] = newTemp;
            count++;

            printf("Would you like to enter another temperature (Y/N)? ");
            scanf(" %c", &response);
        }
    } while (toupper(response) == 'Y');

    return count;
}

// Function to display all temperature readings
void displayTemperatures(int temps[], int count)
{
    printf("Temperature Readings:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", temps[i]);
    }
}

// Function to calculate and return the average temperature
double getAverageTemperature(int temps[], int count)
{
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += temps[i];
    }

    if (count > 0) {
        return total / count;
    }
    else {
        return 0.0;
    }
}

// Function to calculate and return the number of temperature readings above the average
int getCountAboveAverage(int temps[], int count, double avgTemp)
{
    int numAboveAvg = 0;

    for (int i = 0; i < count; i++) {
        if (temps[i] > avgTemp) {
            numAboveAvg++;
        }
    }

    return numAboveAvg;
}