//FormAI DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100.00
#define MIN_TEMP 0.00
#define TEMP_SIZE 5

float currentTemp;
char input[TEMP_SIZE];
int errorFlag;

int validateInput(char* input) {
    int i = 0;
    while (input[i] != '\0') {
        if ((input[i] < '0' || input[i] > '9') && input[i] != '.') {
            return 0;
        }
        i++;
    }
    return 1;
}

void getTempInput() {
    errorFlag = 0;
    printf("Enter current temperature in Celsius: ");
    scanf("%s", input);
    if (strlen(input) == 0) {
        errorFlag = 1;
        return;
    }
    if (validateInput(input)) {
        currentTemp = atof(input);
        if (currentTemp < MIN_TEMP || currentTemp > MAX_TEMP) {
            errorFlag = 1;
        }
    } else {
        errorFlag = 1;
    }
}

void printError() {
    printf("Invalid input. Please try again.\n");
}

void printStatus(float temp) {
    printf("The current temperature is: %.2f Celsius\n", temp);
    if (temp < 0.00) {
        printf("The temperature is below freezing point.\n");
    } else if (temp >= 0.00 && temp < 20.00) {
        printf("The temperature is cold.\n");
    } else if (temp >= 20.00 && temp < 30.00) {
        printf("The temperature is moderate.\n");
    } else if (temp >= 30.00 && temp < 40.00) {
        printf("The temperature is warm.\n");
    } else {
        printf("The temperature is hot.\n");
    }
}

int main() {
    while (1) {
        getTempInput();
        if (errorFlag == 1) {
            printError();
            continue;
        }
        printStatus(currentTemp);
    }
    return 0;
}