//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 1000
#define MAX_SLEEP 24*60*60

struct step {
    time_t time;
    int steps;
};

struct sleep {
    time_t time;
    int hours;
};

int main() {
    int i, j, choice;
    time_t now;
    struct tm *tm;
    struct step steps[MAX_STEPS];
    struct sleep sleeps[MAX_SLEEP];

    time(&now);
    tm = localtime(&now);

    printf("Welcome to the Fitness Tracker!\n");
    printf("Today is %s.\n", asctime(tm));

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Record steps\n");
        printf("2. Record sleep\n");
        printf("3. View step history\n");
        printf("4. View sleep history\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many steps did you take?\n");
                scanf("%d", &steps[i].steps);
                steps[i].time = now;
                i++;
                if(i == MAX_STEPS) {
                    printf("Step history is full. Please delete some entries.\n");
                }
                break;
            case 2:
                printf("How many hours did you sleep?\n");
                scanf("%d", &sleeps[j].hours);
                sleeps[j].time = now;
                j++;
                if(j == MAX_SLEEP) {
                    printf("Sleep history is full. Please delete some entries.\n");
                }
                break;
            case 3:
                printf("\nStep history:\n");
                for(i=0; i<MAX_STEPS; i++) {
                    if(steps[i].time!= 0) {
                        tm = localtime(&steps[i].time);
                        printf("%s: %d steps\n", asctime(tm), steps[i].steps);
                    }
                }
                break;
            case 4:
                printf("\nSleep history:\n");
                for(j=0; j<MAX_SLEEP; j++) {
                    if(sleeps[j].time!= 0) {
                        tm = localtime(&sleeps[j].time);
                        printf("%s: %d hours\n", asctime(tm), sleeps[j].hours);
                    }
                }
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}