//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Function to generate random weather conditions
void generate_weather(int weather[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            weather[i][j] = rand() % 4; // 0 = sunny, 1 = rainy, 2 = cloudy, 3 = stormy
        }
    }
}

// Function to print the weather conditions
void print_weather(int weather[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (weather[i][j]) {
                case 0:
                    printf("Sunny\t");
                    break;
                case 1:
                    printf("Rainy\t");
                    break;
                case 2:
                    printf("Cloudy\t");
                    break;
                case 3:
                    printf("Stormy\t");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to simulate the weather for a given number of days
void simulate_weather(int weather[SIZE][SIZE], int days) {
    for (int i = 0; i < days; i++) {
        generate_weather(weather);
        print_weather(weather);
    }
}

int main() {
    int weather[SIZE][SIZE];
    int days;

    // Get the number of days to simulate from the user
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);

    // Simulate the weather for the given number of days
    simulate_weather(weather, days);

    return 0;
}