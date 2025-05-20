//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60

// Function to print the weather for a given day
void print_weather(int day_of_week, int temperature, char *description) {
    printf("On %s, the weather is %s with a temperature of %d degrees.\n",
           day_of_week == 0? "Sunday" :
           day_of_week == 1? "Monday" :
           day_of_week == 2? "Tuesday" :
           day_of_week == 3? "Wednesday" :
           day_of_week == 4? "Thursday" :
           day_of_week == 5? "Friday" :
           "Saturday",
           temperature, description);
}

// Function to generate random weather for a given day
void generate_weather(int day_of_week, int *temperature, char **description) {
    switch(day_of_week) {
        case 0:
            *temperature = rand() % 101;
            *description = "sunny";
            break;
        case 1:
            *temperature = rand() % 101;
            *description = "cloudy";
            break;
        case 2:
            *temperature = rand() % 101;
            *description = "rainy";
            break;
        case 3:
            *temperature = rand() % 101;
            *description = "thunderstorm";
            break;
        case 4:
            *temperature = rand() % 101;
            *description = "snowy";
            break;
        case 5:
            *temperature = rand() % 101;
            *description = "hail";
            break;
        default:
            *temperature = rand() % 101;
            *description = "foggy";
            break;
    }
}

// Function to simulate weather for a given number of days
void simulate_weather(int num_days) {
    int i;
    srand(time(NULL));

    for(i = 0; i < num_days; i++) {
        int temperature;
        char *description;
        generate_weather(i % DAYS_IN_WEEK, &temperature, &description);
        print_weather(i % DAYS_IN_WEEK, temperature, description);
    }
}

int main() {
    int num_days;

    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    simulate_weather(num_days);

    return 0;
}