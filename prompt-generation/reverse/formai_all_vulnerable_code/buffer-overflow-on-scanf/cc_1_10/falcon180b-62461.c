//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_USERS 10
#define MAX_STEPS 10000
#define MAX_CALORIES 5000

typedef struct {
    char name[50];
    int steps[MAX_STEPS];
    int calories[MAX_CALORIES];
    int numSteps;
    int numCalories;
} User;

void initUser(User *user) {
    user->numSteps = 0;
    user->numCalories = 0;
}

void addStep(User *user) {
    user->numSteps++;
    if (user->numSteps > MAX_STEPS) {
        user->numSteps = MAX_STEPS;
    }
}

void addCalorie(User *user) {
    user->numCalories++;
    if (user->numCalories > MAX_CALORIES) {
        user->numCalories = MAX_CALORIES;
    }
}

void printUser(User *user) {
    printf("Name: %s\n", user->name);
    printf("Steps: %d\n", user->numSteps);
    printf("Calories: %d\n", user->numCalories);
}

void readUser(User *user) {
    printf("Enter name: ");
    scanf("%s", user->name);
    printf("Enter steps: ");
    scanf("%d", &user->numSteps);
    printf("Enter calories: ");
    scanf("%d", &user->numCalories);
}

void readUsers(User users[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        printf("Enter user %d:\n", i + 1);
        readUser(&users[i]);
    }
}

void printUsers(User users[]) {
    for (int i = 0; i < MAX_USERS; i++) {
        printUser(&users[i]);
    }
}

int main() {
    User users[MAX_USERS];
    initUser(users);
    readUsers(users);
    printUsers(users);

    return 0;
}