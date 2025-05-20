//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEMACHINE_SIZE 10

int main()
{
    time_t t;
    int i, j, x, y;
    int timeline[TIMEMACHINE_SIZE];
    char message[200];

    // Initialize the timeline
    for(i = 0; i < TIMEMACHINE_SIZE; i++)
    {
        timeline[i] = 0;
    }

    // Get the current time
    t = time(NULL);

    // Set the current time in the timeline
    timeline[t] = 1;

    // Travel back in time
    printf("Enter the time you want to travel to (in seconds): ");
    scanf("%d", &x);

    // Check if the time is valid
    if(x < 0 || x >= TIMEMACHINE_SIZE)
    {
        printf("Invalid time.\n");
        return 1;
    }

    // Travel back in time and display the message
    printf("Message from the past: %s\n", timeline[x]);

    // Get the user's message
    printf("Enter your message: ");
    scanf("%s", message);

    // Set the user's message in the timeline
    timeline[x] = message;

    // Travel forward in time
    printf("Enter the time you want to travel forward to (in seconds): ");
    scanf("%d", &y);

    // Check if the time is valid
    if(y < 0 || y >= TIMEMACHINE_SIZE)
    {
        printf("Invalid time.\n");
        return 1;
    }

    // Travel forward in time and display the user's message
    printf("Message from the future: %s\n", timeline[y]);

    return 0;
}