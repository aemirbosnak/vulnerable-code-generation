//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FUTURE 10
#define PAST 100

// Function to display a timestamp
void displayTimestamp(time_t timeStamp) {
    char buffer[80];
    struct tm *tm_info;

    tm_info = localtime(&timeStamp);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Timestamp: %s\n", buffer);
}

// The time traveling machine
void timeMachine(int direction) {
    time_t currentTime;
    time(&currentTime);
    
    // Determine destination time
    time_t destinationTime;
    if (direction > 0) {
        destinationTime = currentTime + (direction * FUTURE);
        printf("Woah! You traveled into the future!\n");
    } else {
        destinationTime = currentTime - (abs(direction) * PAST);
        printf("Whoa! You’re now in the past!\n");
    }

    displayTimestamp(destinationTime);
    printf("Let's see how different things are around here...\n");
}

void greetTraveler() {
    printf("Welcome to the Time Travel Simulator 3000!\n");
    printf("Prepare for a ride through time like no other!\n");
    printf("Your options are:\n");
    printf("1. Travel 10 years into the future\n");
    printf("2. Travel 100 years into the past\n");
    printf("3. Forget this whole thing and just eat snacks\n");
}

void snackTime() {
    printf("You chose snacks! Here's a list of options:\n");
    printf("1. Chocolate, the key to happiness!\n");
    printf("2. Potato chips, crunchy time travel companions!\n");
    printf("3. Fruit, for those feeling a bit healthy (but seriously?!)\n");
    printf("4. More chocolate!\n");
    printf("Eat wisely, traveler! (Yes, I'd choose chocolate too!)\n");
}

int main() {
    int choice;

    // Greeting message
    greetTraveler();
    
    // Prompting user choice
    printf("Enter your choice (1-3): ");
    
    // Take user input
    if (scanf("%d", &choice) != 1) {
        printf("Oops! This time machine doesn't accept alien language! Try again!\n");
        return 1;
    }

    // Execute based on choice
    switch (choice) {
    case 1:
        timeMachine(1);  // Travel to the future
        break;  
    case 2:
        timeMachine(-1); // Travel to the past
        break;
    case 3:
        snackTime();      // Snack time!
        break;
    default:
        printf("Uhh, I don’t think that’s a valid option. How about time traveling with a banana instead?\n");
        break;
    }

    printf("Remember, traveler, time is a slippery thing! Don't forget your towel!\n");
    return 0;
}