//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100 // Maximum temperature value to be monitored
#define MIN_TEMP 0 // Minimum temperature value to be monitored

// Function prototypes
void initializeData(float data[]);
float getTemperature();
void updateData(float data[], float temperature);
float calculateAverage(float data[]);
float findMax(float data[]);
float findMin(float data[]);

int main(){
    float data[MAX_TEMP];
    float temperature;
    int counter = 0;
    char choice;
    
    // Calling function to initialize the temperature data 
    initializeData(data);
    
    // Looping until user exits the program
    do{
        // Getting the temperature from user
        temperature = getTemperature();
        
        // Updating the temperature data
        updateData(data, temperature);
        
        // Printing the current temperature and average temperature
        printf("\nTemperature: %.2f\n", temperature);
        printf("Average Temperature: %.2f\n", calculateAverage(data));
        
        // Incrementing the counter
        counter++;
        
        // Asking user to continue or exit the program
        printf("\nDo you want to enter another temperature? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    
    // Printing the maximum and minimum temperature values
    printf("\nMaximum Temperature: %.2f\n", findMax(data));
    printf("Minimum Temperature: %.2f\n", findMin(data));
    
    // Printing the total number of temperature values entered
    printf("Total number of temperature values entered: %d\n", counter);
    
    return 0;
}

// Function to initialize the temperature data to 0
void initializeData(float data[]){
    memset(data, 0, sizeof(data));
}

// Function to get the temperature from user
float getTemperature(){
    float temperature;
    
    printf("\nEnter the temperature value (0 to 100): ");
    scanf("%f", &temperature);
    
    // Checking if entered temperature is within the range of MIN and MAX temperature values
    while(temperature < MIN_TEMP || temperature > MAX_TEMP){
        printf("\nInvalid temperature! Please enter a temperature value between %d and %d\n", MIN_TEMP, MAX_TEMP);
        printf("\nEnter the temperature value (0 to 100): ");
        scanf("%f", &temperature);
    }
    
    return temperature;
}

// Function to update the temperature data
void updateData(float data[], float temperature){
    int i;
    
    // Shifting the temperature data array to the right and discarding the oldest temperature value
    for(i = MAX_TEMP-1; i > 0; i--){
        data[i] = data[i-1];
    }
    
    // Adding the new temperature value to the first index of the array
    data[0] = temperature;
}

// Function to calculate the average temperature
float calculateAverage(float data[]){
    float sum = 0;
    int i;
    
    // Calculating the sum of all temperature values
    for(i = 0; i < MAX_TEMP; i++){
        sum += data[i];
    }
    
    // Calculating the average
    return sum/MAX_TEMP;
}

// Function to find the maximum temperature value
float findMax(float data[]){
    int i;
    float max = MIN_TEMP;
    
    // Looping through all temperature values to find the maximum
    for(i = 0; i < MAX_TEMP; i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    
    return max;
}

// Function to find the minimum temperature value
float findMin(float data[]){
    int i;
    float min = MAX_TEMP;
    
    // Looping through all temperature values to find the minimum
    for(i = 0; i < MAX_TEMP; i++){
        if(data[i] < min){
            min = data[i];
        }
    }
    
    return min;
}