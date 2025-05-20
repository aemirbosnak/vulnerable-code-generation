//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int weather = rand() % 4; // Generate a random number between 0 and 3

    printf("Welcome to the Weather Simulator\n\n");

    switch(weather) {
        case 0:
            printf("It's sunny today! ☀️\n");
            break;
        case 1:
            printf("It's cloudy today. ⛅️\n");
            break;
        case 2:
            printf("It's raining cats and dogs! 🌧️\n");
            break;
        case 3:
            printf("It's snowing! ❄️\n");
            break;
    }

    printf("\nDo you want to know the temperature? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if(choice == 'y' || choice == 'Y') {
        int temperature = 0;
        switch(weather) {
            case 0:
                temperature = (rand() % 20) + 20; // Generate a number between 20 and 39
                printf("The temperature is %d degrees Celsius.\n", temperature);
                break;
            case 1:
                temperature = (rand() % 10) + 10; // Generate a number between 10 and 19
                printf("The temperature is %d degrees Celsius.\n", temperature);
                break;
            case 2:
                temperature = (rand() % 5) + 5; // Generate a number between 5 and 9
                printf("The temperature is %d degrees Celsius.\n", temperature);
                break;
            case 3:
                temperature = (rand() % 15) - 10; // Generate a number between -10 and 4
                printf("The temperature is %d degrees Celsius.\n", temperature);
                break;
        }
    }

    printf("\nThank you for using the Weather Simulator!\n");
    return 0;
}