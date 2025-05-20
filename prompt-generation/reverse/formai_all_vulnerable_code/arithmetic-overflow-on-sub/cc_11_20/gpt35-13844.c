//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_YEAR 1000000

void initializeTime(int* year, int* month, int* day, int* hours, int* minutes, int* seconds);

int main() {
    int year, month, day, hours, minutes, seconds;
    int players;
    int currentYear, currentMonth, currentDay, currentHours, currentMinutes, currentSeconds;
    char playerName[MAX_PLAYERS][20];

    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    currentYear = timeinfo->tm_year + 1900;
    currentMonth = timeinfo->tm_mon + 1;
    currentDay = timeinfo->tm_mday;
    currentHours = timeinfo->tm_hour;
    currentMinutes = timeinfo->tm_min;
    currentSeconds = timeinfo->tm_sec;

    initializeTime(&year, &month, &day, &hours, &minutes, &seconds);

    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter the number of players (1 to 4): ");
    scanf("%d", &players);

    if(players > MAX_PLAYERS) {
        printf("Maximum players allowed is %d\n", MAX_PLAYERS);
        return 0;
    }

    for(int i=0;i<players;i++) {
        printf("Enter the name of player %d: ", (i+1));
        scanf("%s", playerName[i]);
    }

    printf("Current time: %d/%d/%d %02d:%02d:%02d\n", currentDay, currentMonth, currentYear, currentHours, currentMinutes, currentSeconds);
    printf("Destination time: %d/%d/%d %02d:%02d:%02d\n", day, month, year, hours, minutes, seconds);

    int choice;
    int playerChoice[MAX_PLAYERS];
    int yearDiff = abs(year - currentYear);
    int monthDiff = abs(month - currentMonth);
    int dayDiff = abs(day - currentDay);
    int hoursDiff = abs(hours - currentHours);
    int minutesDiff = abs(minutes - currentMinutes);
    int secondsDiff = abs(seconds - currentSeconds);

    if(year > currentYear) {
        printf("Jumping %d years into the future...\n", yearDiff);
    } else {
        printf("Jumping %d years into the past...\n", yearDiff);
    }

    if(month > currentMonth) {
        printf("Jumping %d months into the future...\n", monthDiff);
    } else {
        printf("Jumping %d months into the past...\n", monthDiff);
    }

    if(day > currentDay) {
        printf("Jumping %d days into the future...\n", dayDiff);
    } else {
        printf("Jumping %d days into the past...\n", dayDiff);
    }

    if(hours > currentHours) {
        printf("Jumping %d hours into the future...\n", hoursDiff);
    } else {
        printf("Jumping %d hours into the past...\n", hoursDiff);
    }

    if(minutes > currentMinutes) {
        printf("Jumping %d minutes into the future...\n", minutesDiff);
    } else {
        printf("Jumping %d minutes into the past...\n", minutesDiff);
    }

    if(seconds > currentSeconds) {
        printf("Jumping %d seconds into the future...\n", secondsDiff);
    } else {
        printf("Jumping %d seconds into the past...\n", secondsDiff);
    }

    printf("Please choose your time-travel method:\n");
    printf("1. Time Machine\n");
    printf("2. Teleportation\n");
    printf("3. Wormhole\n");
    printf("4. Magical portal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for(int i=0;i<players;i++) {
        printf("%s, choose your time-travel method:\n", playerName[i]);
        printf("1. Time Machine\n");
        printf("2. Teleportation\n");
        printf("3. Wormhole\n");
        printf("4. Magical portal\n");
        printf("Enter your choice: ");
        scanf("%d", &playerChoice[i]);
    }

    printf("Traveling through time...\n");

    if(choice == 1) {
        printf("Using Time Machine...\n");
    } else if(choice == 2) {
        printf("Using Teleportation...\n");
    } else if(choice == 3) {
        printf("Using Wormhole...\n");
    } else if(choice == 4) {
        printf("Entering through Magical Portal...\n");
    } else {
        printf("Invalid choice, exiting...\n");
        return 0;
    }

    for(int i=0;i<players;i++) {
        printf("%s is using method %d\n", playerName[i], playerChoice[i]);
    }

    for(int i=0;i<=(yearDiff);i++) {
        currentYear++;

        if(i > 0) {
            printf("Year: %d\n", currentYear);
        }

        if(currentYear >= MAX_YEAR) {
            printf("Reached the maximum limit of the time machine, exiting...\n");
            return 0;
        }

        if(i == yearDiff) {
            printf("Arrived at destination year\n");
            break;
        }

        for(int j=0;j<12;j++) {
            currentMonth++;

            if(currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }

            if(j == monthDiff) {
                printf("Arrived at destination month\n");
                break;
            }

            for(int k=0;k<31;k++) {
                currentDay++;

                if(currentDay > 31) {
                    currentDay = 1;
                    currentMonth++;
                }

                if(k == dayDiff) {
                    printf("Arrived at destination day\n");
                    break;
                }

                for(int l=0;l<24;l++) {
                    currentHours++;

                    if(currentHours > 23) {
                        currentHours = 0;
                        currentDay++;
                    }

                    if(l == hoursDiff) {
                        printf("Arrived at destination hour\n");
                        break;
                    }

                    for(int m=0;m<60;m++) {
                        currentMinutes++;

                        if(currentMinutes > 59) {
                            currentMinutes = 0;
                            currentHours++;
                        }

                        if(m == minutesDiff) {
                            printf("Arrived at destination minute\n");
                            break;
                        }

                        for(int n=0;n<60;n++) {
                            currentSeconds++;

                            if(currentSeconds > 59) {
                                currentSeconds = 0;
                                currentMinutes++;
                            }

                            if(n == secondsDiff) {
                                printf("Arrived at destination second\n");
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Time travel successful!\n");

    return 0;
}

void initializeTime(int* year, int* month, int* day, int* hours, int* minutes, int* seconds) {
    srand(time(NULL));
    *year = rand() % 4000;
    *month = rand() % 12 + 1;
    *day = rand() % 31 + 1;
    *hours = rand() % 24;
    *minutes = rand() % 60;
    *seconds = rand() % 60;
}