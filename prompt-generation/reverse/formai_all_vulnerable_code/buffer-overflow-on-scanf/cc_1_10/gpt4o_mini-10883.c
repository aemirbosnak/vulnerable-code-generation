//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int steps;
    int heartRate;
    float distance;
} User;

void displayWelcomeMessage() {
    printf("O hark! A fair fitness tracker awaits thee!\n");
    printf("Let not thy heart be troubled; let us track thy steps with glee!\n\n");
}

void inputUserData(User *user) {
    printf("What name shall the noble bearer of health adopt?\n");
    scanf("%s", user->name);

    printf("Good %s, how many steps treadest thou yester eve?\n", user->name);
    scanf("%d", &user->steps);

    printf("And what doth thy heart whisper? Enter thy heart rate:\n");
    scanf("%d", &user->heartRate);

    printf("Finally, in leagues or kilometers, what distance have thee traversed?\n");
    scanf("%f", &user->distance);
}

void displayUserData(const User *user) {
    printf("\nAlas! Herein lies thy fitness tale:\n");
    printf("Name         : %s\n", user->name);
    printf("Steps        : %d\n", user->steps);
    printf("Heart Rate   : %d beats per minute\n", user->heartRate);
    printf("Distance     : %.2f kilometers\n", user->distance);
}

float calculateCalorieBurn(int steps, int heartRate) {
    float caloriesBurned = (steps * 0.05) + (heartRate * 0.1);
    return caloriesBurned;
}

void applaudUser(float calories) {
    if (calories > 300) {
        printf("Bravo! Thou hast burned a splendid %.2f calories!\n", calories);
    } else {
        printf("Fear not! Thou hast burned only %.2f calories, yet every step counteth!\n", calories);
    }
}

void farewellMessage() {
    printf("\nUntil we meet again, dear friend! May your steps be light and your heart be merry!\n");
}

int main() {
    User user;
    float calories;

    displayWelcomeMessage();
    
    inputUserData(&user);
    displayUserData(&user);
    
    calories = calculateCalorieBurn(user.steps, user.heartRate);
    applaudUser(calories);
    
    farewellMessage();
    return 0;
}