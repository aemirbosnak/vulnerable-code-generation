//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main() {
    char input[10];
    double temperature, average = 0, sum = 0;
    int count = 0;

    //initialize variables
    strcpy(input, "0.0");
    temperature = atof(input);

    //get user input for temperature
    printf("Enter temperature: ");
    scanf("%s", input);

    //validate user input
    while (strcmp(input, "0.0")!= 0) {
        printf("Invalid input. Please enter a valid temperature: ");
        scanf("%s", input);
    }

    //convert input to double
    temperature = atof(input);

    //initialize variables for user input
    strcpy(input, "0.0");

    //get user input for number of temperatures to average
    printf("Enter the number of temperatures to average: ");
    scanf("%s", input);

    //validate user input
    while (strcmp(input, "0.0")!= 0) {
        printf("Invalid input. Please enter a valid number of temperatures: ");
        scanf("%s", input);
    }

    //convert input to integer
    count = atoi(input);

    //get user input for temperatures
    for (int i = 0; i < count; i++) {
        printf("Enter temperature %d: ", i+1);
        scanf("%s", input);

        //validate user input
        while (strcmp(input, "0.0")!= 0) {
            printf("Invalid input. Please enter a valid temperature: ");
            scanf("%s", input);
        }

        //convert input to double
        temperature = atof(input);

        //add temperature to sum
        sum += temperature;
    }

    //calculate average temperature
    average = sum / count;

    //display average temperature
    printf("The average temperature is %.2f degrees Celsius.\n", average);

    return 0;
}