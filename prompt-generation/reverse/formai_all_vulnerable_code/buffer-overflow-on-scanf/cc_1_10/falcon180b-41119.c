//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 30
#define RAIN_CHANCE 30
#define MAX_RAIN 3
#define SUN_CHANCE 70
#define MAX_SUN 3
#define CLOUD_CHANCE 50
#define MAX_CLOUD 5

// Function to print the weather
void print_weather(char weather[HEIGHT][WIDTH], int day) {
    printf("Day %d:\n", day);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", weather[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random weather
void generate_weather(char weather[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 100 < RAIN_CHANCE) {
                weather[i][j] = 'R';
            } else if (rand() % 100 < SUN_CHANCE) {
                weather[i][j] = 'S';
            } else if (rand() % 100 < CLOUD_CHANCE) {
                weather[i][j] = 'C';
            } else {
                weather[i][j] = '.';
            }
        }
    }
}

// Function to simulate weather for a given number of days
void simulate_weather(int days) {
    char weather[HEIGHT][WIDTH];
    srand(time(0));
    for (int i = 0; i < days; i++) {
        generate_weather(weather);
        print_weather(weather, i + 1);
    }
}

int main() {
    int days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &days);
    simulate_weather(days);
    return 0;
}