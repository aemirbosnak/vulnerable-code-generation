//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int steps;
    float distance;
    int heartRate;
} User;

void displayMenu() {
    printf("\nOh fair user! Welcome to thy Fitness Tracker!\n");
    printf("1. Enroll thyself into our records\n");
    printf("2. Track thine steps\n");
    printf("3. Measure thine distance\n");
    printf("4. Capture thine heart rate\n");
    printf("5. Flourish the records\n");
    printf("6. Depart the realm\n");
}

void enrollUser(User *user) {
    printf("What is thy name, brave user? ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove trailing newline
    user->steps = 0;
    user->distance = 0.0;
    user->heartRate = 0;
    printf("Lo! Thou art now enrolled, dear %s!\n", user->name);
}

void trackSteps(User *user) {
    int steps;
    printf("How many steps hast thou taken today, noble %s? ", user->name);
    scanf("%d", &steps);
    user->steps += steps;
    while(getchar() != '\n'); // Clear input buffer
    printf("Hark! Thou hast taken a total of %d steps thus far!\n", user->steps);
}

void measureDistance(User *user) {
    float distance;
    printf("What distance have you traversed today in miles, good %s? ", user->name);
    scanf("%f", &distance);
    user->distance += distance;
    while(getchar() != '\n'); // Clear input buffer
    printf("Behold! Thou hast traversed a total distance of %.2f miles!\n", user->distance);
}

void captureHeartRate(User *user) {
    int heartRate;
    printf("What dost thou declare thy heart rate to be, spirited %s? ", user->name);
    scanf("%d", &heartRate);
    user->heartRate = heartRate;
    while(getchar() != '\n'); // Clear input buffer
    printf("Thy heart beats at a rate of %d beats per minute!\n", user->heartRate);
}

void flourishRecords(User *user) {
    printf("\n------ Thy Records ------\n");
    printf("Name: %s\n", user->name);
    printf("Total Steps: %d\n", user->steps);
    printf("Total Distance: %.2f miles\n", user->distance);
    printf("Heart Rate: %d bpm\n", user->heartRate);
    printf("-------------------------\n");
}

int main() {
    User user;
    int choice;

    enrollUser(&user);
    do {
        displayMenu();
        printf("Choose thy fate (1-6): ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                printf("Thou art already enrolled! Choose another path.\n");
                break;
            case 2:
                trackSteps(&user);
                break;
            case 3:
                measureDistance(&user);
                break;
            case 4:
                captureHeartRate(&user);
                break;
            case 5:
                flourishRecords(&user);
                break;
            case 6:
                printf("Farewell, dear %s! Until we meet again!\n", user.name);
                break;
            default:
                printf("Oh no! That pathway lies beyond our realm. Choose again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}