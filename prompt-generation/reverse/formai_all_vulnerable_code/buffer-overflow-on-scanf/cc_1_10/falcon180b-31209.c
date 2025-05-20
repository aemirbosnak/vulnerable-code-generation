//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print the weather for a given day
void print_weather(int day) {
    switch(day) {
        case 1:
            printf("Sunny\n");
            break;
        case 2:
            printf("Cloudy\n");
            break;
        case 3:
            printf("Rainy\n");
            break;
        case 4:
            printf("Stormy\n");
            break;
        default:
            printf("Invalid weather\n");
            break;
    }
}

// Recursive function to simulate the weather for a given number of days
void simulate_weather(int days, int current_day) {
    // Base case: the simulation is complete
    if(current_day == days) {
        return;
    }

    // Recursive case: simulate the weather for the next day
    int next_weather = rand() % 4; // Generate a random weather condition
    switch(next_weather) {
        case 0:
            printf("Day %d: ", current_day+1);
            print_weather(next_weather);
            break;
        case 1:
            printf("Day %d: ", current_day+1);
            print_weather(next_weather);
            break;
        case 2:
            printf("Day %d: ", current_day+1);
            print_weather(next_weather);
            break;
        case 3:
            printf("Day %d: ", current_day+1);
            print_weather(next_weather);
            break;
    }
    current_day++;
    simulate_weather(days, current_day); // Recursively simulate the weather for the next day
}

// Main function to prompt the user for the number of days to simulate and call the simulate_weather function
int main() {
    int days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);
    srand(time(NULL)); // Seed the random number generator with the current time
    simulate_weather(days, 1);
    return 0;
}