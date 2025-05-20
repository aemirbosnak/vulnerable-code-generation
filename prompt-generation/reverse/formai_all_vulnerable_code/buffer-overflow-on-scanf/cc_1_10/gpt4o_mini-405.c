//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep
#include <string.h>

// A structure to hold the details of our romantic temperature readings
typedef struct {
    float temperature;
    char mood[50];
} TemperatureRead;

void setMood(TemperatureRead *tempRead) {
    if (tempRead->temperature < 15) {
        strcpy(tempRead->mood, "Chilly and distant");
    } else if (tempRead->temperature < 25) {
        strcpy(tempRead->mood, "Cozy and warm");
    } else if (tempRead->temperature < 30) {
        strcpy(tempRead->mood, "Steamy and passionate");
    } else {
        strcpy(tempRead->mood, "Scorching and wild");
    }
}

void displayTemperature(TemperatureRead *tempRead) {
    printf("The current temperature is a sultry %.2f°C, invoking a mood of: %s\n",
           tempRead->temperature, tempRead->mood);
}

void romanticWhisper() {
    printf("A gentle breeze whispers sweet nothings...\n");
}

void romanticPause() {
    printf("Let us embrace in silence, feeling the warmth around...\n");
    sleep(4);
}

int main() {
    // A simple romance blossoms within this temperature monitor
    TemperatureRead currentRead;
    currentRead.temperature = 0;
    
    while (1) {
        printf("As we walk through our garden of emotions, ");
        printf("what is the temperature that kisses your heart? ");
        scanf("%f", &currentRead.temperature);
        
        // Set the mood according to the temperature
        setMood(&currentRead);
        
        // Display the romantic temperature details
        displayTemperature(&currentRead);
        romanticPause();
        
        // If the temperature exceeds a certain threshold, the romance runs wild
        if (currentRead.temperature > 30) {
            printf("Our passion ignites, thrilling the very air around us!\n");
            romanticWhisper();
        }

        // Simulate a moment of reflection before reporting again
        printf("Oh, let us take a moment to bask in this warmth...\n");
        sleep(2);
        printf("Would you like to check the temperature again, my love? (y/n) ");
        
        char continued;
        getchar(); // Clear the newline character from buffer
        scanf("%c", &continued);
        
        if (continued != 'y') {
            printf("As the sun sets on our beautiful day, my heart will always hold you close.\n");
            break;
        }
    }
    
    printf("Farewell, my beloved! Until the next kind embrace of the temperature...\n");
    return 0;
}