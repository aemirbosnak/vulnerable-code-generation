//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void eat(char *food);
void drink(char *beverage);
void sleep(int hours);
void work(char *job);
void exercise(char *activity);

int main() {
    char food[20], beverage[20], job[20], activity[20];
    int hours;

    // Prompt user for input
    printf("What would you like to eat? ");
    scanf("%s", food);
    printf("What would you like to drink? ");
    scanf("%s", beverage);
    printf("How many hours would you like to sleep? ");
    scanf("%d", &hours);
    printf("What is your job? ");
    scanf("%s", job);
    printf("What kind of exercise do you like to do? ");
    scanf("%s", activity);

    // Perform actions based on user input
    eat(food);
    drink(beverage);
    sleep(hours);
    work(job);
    exercise(activity);

    return 0;
}

void eat(char *food) {
    printf("You are eating %s.\n", food);
}

void drink(char *beverage) {
    printf("You are drinking %s.\n", beverage);
}

void sleep(int hours) {
    printf("You are sleeping for %d hours.\n", hours);
}

void work(char *job) {
    printf("You are working as a %s.\n", job);
}

void exercise(char *activity) {
    printf("You are doing %s as exercise.\n", activity);
}