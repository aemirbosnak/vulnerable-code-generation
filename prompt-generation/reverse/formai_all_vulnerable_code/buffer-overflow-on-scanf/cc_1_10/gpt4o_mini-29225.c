//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void greet_user() {
    printf("🌞 Welcome to the Cheery Temperature Monitor! 🌞\n");
    printf("Let's keep track of the weather around here, shall we?\n\n");
}

void give_advice(float temp) {
    if (temp < 0) {
        printf("🥶 Brrr! It's freezing out there! Dress up like a polar bear! 🐻‍❄️\n");
    } else if (temp < 15) {
        printf("🧣 It's pretty chilly! How about a warm cup of cocoa? ☕\n");
    } else if (temp < 25) {
        printf("😊 It's pleasantly mild! A perfect day for a picnic! 🚴‍♂️\n");
    } else if (temp < 35) {
        printf("🌞 It's getting warm! Remember to stay hydrated! 💧\n");
    } else {
        printf("🔥 Wowza! It's hot out there! Time to hit the beach! 🏖️\n");
    }
}

float calculate_average(float temp_sum, int count) {
    return temp_sum / count;
}

int main() {
    greet_user();

    float temperatures[10];  // Store up to 10 temperature readings
    float temp_sum = 0.0;     // Sum of all temperatures
    int count = 0;            // Number of readings taken
    char choice;

    do {
        if (count < 10) {
            printf("Please enter the temperature for reading %d: ", count + 1);
            scanf("%f", &temperatures[count]);

            // Accumulate the sum of temperatures
            temp_sum += temperatures[count];
            count++;
            give_advice(temperatures[count - 1]);

            if (count < 10) {
                printf("\nWould you like to enter another temperature? (y/n): ");
                scanf(" %c", &choice);
            } else {
                printf("\nYou've reached the maximum number of readings! 🎉\n");
                choice = 'n';  // End the loop if max readings are reached
            }
        } else {
            choice = 'n';  // No more entries allowed beyond 10 readings
        }
    } while (choice == 'y' || count == 0);

    if (count > 0) {
        float avg_temp = calculate_average(temp_sum, count);
        printf("\n🌈 You've entered %d temperature readings! 🌈\n", count);
        printf("The average temperature is: %.2f°C 😄\n", avg_temp);
    } else {
        printf("🤗 No temperature readings to show, but that's okay! Have a fantastic day! 🌼\n");
    }

    printf("\nThank you for using the Cheery Temperature Monitor! Bye-bye! 👋\n");
    return 0;
}