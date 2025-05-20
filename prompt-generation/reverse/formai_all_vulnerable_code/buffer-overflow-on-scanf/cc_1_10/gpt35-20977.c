//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    int age;
    float weight;
    float height;
};

struct workout {
    char name[50];
    int reps;
    float weight;
    float duration;
};

void track_user_data(struct user *u) {
    printf("What is your name?\n");
    fgets(u->name, 50, stdin);
    printf("What is your age?\n");
    scanf("%d", &u->age);
    printf("What is your weight in kg?\n");
    scanf("%f", &u->weight);
    printf("What is your height in cm?\n");
    scanf("%f", &u->height);
    getchar();
}

void add_workout(struct workout *w) {
    printf("What is the name of the workout?\n");
    fgets(w->name, 50, stdin);
    printf("How many reps did you do?\n");
    scanf("%d", &w->reps);
    printf("What was the weight in kg?\n");
    scanf("%f", &w->weight);
    printf("How long did the workout last in minutes?\n");
    scanf("%f", &w->duration);
    getchar();
}

void display_user_data(struct user *u) {
    printf("Name: %s", u->name);
    printf("Age: %d\n", u->age);
    printf("Weight: %.2f kg\n", u->weight);
    printf("Height: %.2f cm\n", u->height);
}

void display_workout_data(struct workout *w) {
    printf("Workout: %s", w->name);
    printf("Reps: %d\n", w->reps);
    printf("Weight: %.2f kg\n", w->weight);
    printf("Duration: %.2f minutes\n", w->duration);
}

int main() {
    struct user user1;
    struct workout workout1;
    track_user_data(&user1);
    display_user_data(&user1);
    add_workout(&workout1);
    display_workout_data(&workout1);
    return 0;
}