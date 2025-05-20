//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_TIME_TRAVEL 100
#define TIME_STEP 0.001

struct TimeTravel
{
    double startTime;
    double endTime;
    double duration;
    int repeat;
};

double getTime()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    double hour = t->tm_hour * 60 + t->tm_min;
    double minute = t->tm_sec;
    return hour + minute / 60.0;
}

void travelTime(struct TimeTravel *travel)
{
    double start = travel->startTime - getTime();
    double end = travel->endTime - getTime();
    double duration = travel->duration;
    int repeat = travel->repeat;

    while (repeat-- > 0)
    {
        sleep(duration);
        start += duration;
        end += duration;
    }

    sleep(start);
}

int main()
{
    struct TimeTravel travels[MAX_TIME_TRAVEL];
    int numTravels = 0;

    while (numTravels < MAX_TIME_TRAVEL)
    {
        printf("Enter the start time (HH:MM): ");
        scanf("%s", travels[numTravels].startTime);

        printf("Enter the end time (HH:MM): ");
        scanf("%s", travels[numTravels].endTime);

        printf("Enter the duration in seconds: ");
        scanf("%d", &travels[numTravels].duration);

        printf("Enter the number of times to repeat: ");
        scanf("%d", &travels[numTravels].repeat);

        numTravels++;
    }

    while (1)
    {
        for (int i = 0; i < numTravels; i++)
        {
            travelTime(&travels[i]);
        }
        numTravels = 0;
    }

    return 0;
}