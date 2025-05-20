//FormAI DATASET v1.0 Category: Temperature monitor ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max_temp 100.00 // maximum temperature limit
#define min_temp 0.00   // minimum temperature limit
#define max_attempts 5  // maximum attempts for input validation

void validate_input(float *input, int attempts);

int main(){
    float temperature;
    printf("Enter the current temperature in Celsius: ");
    validate_input(&temperature, max_attempts);  // validating user input
    while(1){
        if(temperature > max_temp){  // checking if temperature exceeds maximum limit
            printf("Temperature is too high! Please turn on the air conditioner or lower the thermostat.\n");
        }
        else if(temperature < min_temp){  // checking if temperature goes below minimum limit
            printf("Temperature is too low! Please turn on the heater or raise the thermostat.\n");
        }
        else{  // temperature within range
            printf("Temperature is normal.\n");
        }
        printf("Enter the current temperature in Celsius: ");
        validate_input(&temperature, max_attempts);  // validating user input
    }
    return 0;
}

// function to validate user input
void validate_input(float *input, int attempts){
    float temp_input;
    int valid = 0, i;
    for(i=1; i<=attempts; i++){
        if(scanf("%f", &temp_input) != 1){ // checking for invalid input
            printf("Invalid input! Please enter a valid temperature: ");
            while(getchar() != '\n');  // clearing input buffer
        }
        else{  // input is valid
            *input = temp_input;
            valid = 1;  // setting valid flag
            break;  // breaking out of for loop
        }
        if(i != attempts){  // if not last attempt
            printf("Attempts left: %d\n", attempts-i);
            printf("Enter the current temperature in Celsius: ");
        }
    }
    if(!valid){  // if input is still invalid after maximum attempts
        printf("Maximum number of attempts reached! Exiting program...\n");
        exit(0);  // exiting program
    }
}