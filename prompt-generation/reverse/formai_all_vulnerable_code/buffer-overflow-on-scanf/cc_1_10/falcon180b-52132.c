//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXERCISES 10
#define MAX_DAYS 7

typedef struct {
    char name[50];
    int calories;
} Exercise;

typedef struct {
    char name[50];
    int steps;
} Day;

void print_menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add an exercise\n");
    printf("2. Add a day's steps\n");
    printf("3. View weekly progress\n");
    printf("4. Quit\n");
}

int main() {
    Exercise exercises[MAX_EXERCISES];
    Day days[MAX_DAYS];
    int num_exercises = 0, num_days = 0;
    char choice;

    srand(time(NULL));

    do {
        system("clear");
        print_menu();
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_exercises >= MAX_EXERCISES) {
                    printf("Sorry, you have reached the maximum number of exercises.\n");
                } else {
                    printf("Enter the name of the exercise: ");
                    scanf("%s", exercises[num_exercises].name);
                    printf("Enter the number of calories burned: ");
                    scanf("%d", &exercises[num_exercises].calories);
                    num_exercises++;
                }
                break;

            case '2':
                if(num_days >= MAX_DAYS) {
                    printf("Sorry, you have reached the maximum number of days.\n");
                } else {
                    printf("Enter the name of the day: ");
                    scanf("%s", days[num_days].name);
                    printf("Enter the number of steps taken: ");
                    scanf("%d", &days[num_days].steps);
                    num_days++;
                }
                break;

            case '3':
                system("clear");
                printf("\nWeekly Progress:\n");
                for(int i=0; i<num_days; i++) {
                    printf("%s: %d steps\n", days[i].name, days[i].steps);
                }
                break;

            case '4':
                printf("Thank you for using Fitness Tracker!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '4');

    return 0;
}