//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>

int main()
{
    printf("Welcome to Robot Movement Control Program! Let's get started.\n\n");

    int distance = 0;
    int speed = 0;
    char direction = ' ';

    printf("Enter distance in centimeters (up to 10000cm): ");
    scanf("%d", &distance);

    printf("Enter speed in km/hr (up to 20km/hr): ");
    scanf("%d", &speed);

    printf("Enter direction (F for Forward, B for Backward, L for Left, R for Right): ");
    scanf(" %c", &direction);

    if (distance <= 0 || speed <= 0 || speed > 20 || (direction != 'F' && direction != 'B' && direction != 'L' && direction != 'R'))
    {
        printf("\nInvalid Input. Please enter valid values and try again.\n");
        return 0;
    }

    printf("\nRobot is now moving...\n");

    int time = distance / (speed * 1000 / 3600);

    switch(direction)
    {
        case 'F':
            printf("Moving %d centimeters Forward at %d km/hr for %d seconds.\n", distance, speed, time);
            break;
        
        case 'B':
            printf("Moving %d centimeters Backward at %d km/hr for %d seconds.\n", distance, speed, time);
            break;

        case 'L':
            printf("Moving %d centimeters Left at %d km/hr for %d seconds.\n", distance, speed, time);
            break;

        case 'R':
            printf("Moving %d centimeters Right at %d km/hr for %d seconds.\n", distance, speed, time);
            break;
    }

    printf("\nRobot has reached its destination. Mission accomplished!\n");

    return 0;
}