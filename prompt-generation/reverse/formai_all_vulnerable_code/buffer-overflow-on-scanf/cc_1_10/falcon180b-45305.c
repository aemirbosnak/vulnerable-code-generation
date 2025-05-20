//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

// Weather types
#define SUNNY 0
#define RAINY 1
#define CLOUDY 2

// Function prototypes
void generate_weather(int *weather, int days);
void print_weather(int weather);

int main() {
    int weather[MAX_DAYS];
    int days;

    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);

    srand(time(NULL));
    generate_weather(weather, days);

    for (int i = 0; i < days; i++) {
        printf("\nDay %d:\n", i + 1);
        print_weather(weather[i]);
    }

    return 0;
}

void generate_weather(int *weather, int days) {
    for (int i = 0; i < days; i++) {
        int rand_num = rand() % 3;
        weather[i] = rand_num;
    }
}

void print_weather(int weather) {
    switch (weather) {
        case SUNNY:
            printf("The sun shines brightly, a perfect day for young lovers to meet.\n");
            break;
        case RAINY:
            printf("Rain falls gently from the sky, creating a romantic atmosphere.\n");
            break;
        case CLOUDY:
            printf("The sky is covered with clouds, reflecting the uncertainty of love.\n");
            break;
    }
}