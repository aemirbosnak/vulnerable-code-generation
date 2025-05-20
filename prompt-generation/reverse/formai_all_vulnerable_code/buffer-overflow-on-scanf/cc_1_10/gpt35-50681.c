//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include<stdio.h>

float temp_data[10];    //array to hold temperature values
int count = 0;          //counter to track number of temperature readings

//Function to read temperature values
void get_temperature_data() {
    printf("Enter temperature reading: ");
    scanf("%f", &temp_data[count]);
    count++;
}

//Function to calculate average temperature
float calculate_average_temperature(float *data) {
    float sum = 0;
    for(int i=0; i<count; i++) {
        sum += data[i];
    }
    return sum/count;
}

//Function to display temperature data
void display_temperature_data() {
    printf("\nTemperature Readings:\n");
    for(int i=0; i<count; i++) {
        printf("%.2f\n", temp_data[i]);
    }
}

int main() {
    char option;
    while(1) {
        printf("\nC Temperature Monitor\n");
        printf("1. Add Temperature Reading\n");
        printf("2. Display Temperature Readings\n");
        printf("3. Calculate Average Temperature\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf(" %c", &option);
        switch(option) {
            case '1':
                get_temperature_data();
                break;
            case '2':
                display_temperature_data();
                break;
            case '3':
                printf("Average Temperature: %.2f\n", calculate_average_temperature(temp_data));
                break;
            case '4':
                printf("Exiting C Temperature Monitor...\n");
                return 0;
            default:
                printf("Invalid option! Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}