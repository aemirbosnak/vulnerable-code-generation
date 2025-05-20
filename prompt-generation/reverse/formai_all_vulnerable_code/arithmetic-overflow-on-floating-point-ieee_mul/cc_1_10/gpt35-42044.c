//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    float weight;
    float height;
    float bmi;
    Date *birthDate;
    Date *lastAssessment;
} User;

typedef struct {
    int pushUps;
    int sitUps;
    float runTime;
} Assessment;

void calculateBMI(User *user) {
    user->bmi = user->weight / ((user->height / 100) * (user->height / 100));
}

int main() {
    int option = 0;
    User *currentUser = NULL;
    currentUser = (User*) malloc(sizeof(User));
    currentUser->birthDate = (Date*) malloc(sizeof(Date));
    currentUser->lastAssessment = (Date*) malloc(sizeof(Date));
    printf("Welcome to Fitness Tracker!\n");
    
    while (option != 4) {
        printf("\nPlease select an option:\n");
        printf("1. Create user\n");
        printf("2. Record assessment\n");
        printf("3. Display user information\n");
        printf("4. Quit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        if (option == 1) {
            printf("\nPlease enter your name: ");
            scanf("%s", currentUser->name);
            printf("Please enter your weight in kilograms: ");
            scanf("%f", &currentUser->weight);
            printf("Please enter your height in centimeters: ");
            scanf("%f", &currentUser->height);
            printf("Please enter your birth date in DD MM YYYY format: ");
            scanf("%d %d %d", &currentUser->birthDate->day, &currentUser->birthDate->month, &currentUser->birthDate->year);
            calculateBMI(currentUser);
            printf("\nUser created!\n");
        }
        
        else if (option == 2) {
            if (currentUser->lastAssessment->day != 0) {
                printf("\nYour last assessment was on %d %d %d\n", currentUser->lastAssessment->day, 
                                                                    currentUser->lastAssessment->month,
                                                                    currentUser->lastAssessment->year);
            }
            Assessment *currentAssessment = NULL;
            currentAssessment = (Assessment*) malloc(sizeof(Assessment));
            printf("\nPlease enter today's date in DD MM YYYY format: ");
            scanf("%d %d %d", &currentUser->lastAssessment->day, &currentUser->lastAssessment->month, &currentUser->lastAssessment->year);
            printf("Please enter the number of push-ups you can do: ");
            scanf("%d", &currentAssessment->pushUps);
            printf("Please enter the number of sit-ups you can do: ");
            scanf("%d", &currentAssessment->sitUps);
            printf("Please enter your run time in minutes: ");
            scanf("%f", &currentAssessment->runTime);
            printf("\nAssessment recorded!");
            free(currentAssessment);
        }
        
        else if (option == 3) {
            printf("\nHello, %s!\n", currentUser->name);
            printf("Your weight is %.1f kilograms and your height is %.1f centimeters.\n", currentUser->weight, currentUser->height);
            printf("Your BMI is %.2f\n", currentUser->bmi);
            printf("Your birth date is %d %d %d.\n", currentUser->birthDate->day, 
                                                        currentUser->birthDate->month,
                                                        currentUser->birthDate->year);
            if (currentUser->lastAssessment->day != 0) {
                printf("Your last assessment was on %d %d %d.\n", currentUser->lastAssessment->day, 
                                                                        currentUser->lastAssessment->month,
                                                                        currentUser->lastAssessment->year);
            }
            else {
                printf("You have not recorded any assessments yet.\n");
            }
        }
    }
    
    free(currentUser->birthDate);
    free(currentUser->lastAssessment);
    free(currentUser);
    printf("\nGoodbye!\n");
    return 0;
}