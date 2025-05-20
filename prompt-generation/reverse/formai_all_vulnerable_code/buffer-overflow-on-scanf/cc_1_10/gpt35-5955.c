//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    printf("Welcome to the Weather Simulation program!\n");
    printf("This program will generate a week's worth of weather data for a specific location.\n");
    printf("Please provide the name of the location: ");
    
    char location[50];
    scanf("%s", location);
    
    int temperatures[7];
    int i;
    
    printf("\nGenerating weather data...\n");
    
    for (i = 0; i < 7; i++) {
        temperatures[i] = rand() % 40 - 10;
    }
    
    printf("\nThe weather for %s over the next week:\n", location);
    printf("Day 1: %d degrees Celsius\n", temperatures[0]);
    printf("Day 2: %d degrees Celsius\n", temperatures[1]);
    printf("Day 3: %d degrees Celsius\n", temperatures[2]);
    printf("Day 4: %d degrees Celsius\n", temperatures[3]);
    printf("Day 5: %d degrees Celsius\n", temperatures[4]);
    printf("Day 6: %d degrees Celsius\n", temperatures[5]);
    printf("Day 7: %d degrees Celsius\n\n", temperatures[6]);
    
    int sum = 0;
    
    for (i = 0; i < 7; i++) {
        sum += temperatures[i];
    }
    
    double average = (double) sum / 7;
    
    if (average < 0) {
        printf("Wow, it's freezing out there!\n");
    }
    else if (average < 10) {
        printf("Better bring a coat, it's chilly!\n");
    }
    else if (average < 20) {
        printf("Looks like a nice day out there.\n");
    }
    else if (average < 30) {
        printf("It's getting hot, bring some shorts!\n");
    }
    else {
        printf("Wow, it's scorching out there, stay cool!\n");
    }
    
    printf("Thank you for using the Weather Simulation program!\n");
    
    return 0;
}