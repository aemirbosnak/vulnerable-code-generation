//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User {
    char name[50];
    int age;
    int weight;
    int height;
};

struct Workout {
    char type[50];
    int duration;
    int intensity;
};

void createUser(struct User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight: ");
    scanf("%d", &user->weight);
    printf("Enter your height: ");
    scanf("%d", &user->height);
}

void createWorkout(struct Workout *workout) {
    printf("Enter workout type: ");
    scanf("%s", workout->type);
    printf("Enter workout duration: ");
    scanf("%d", &workout->duration);
    printf("Enter workout intensity: ");
    scanf("%d", &workout->intensity);
}

void logWorkout(struct User *user, struct Workout *workout) {
    time_t now = time(0);
    struct tm *t = localtime(&now);
    printf("Workout logged on %d/%d/%d at %d:%d:%d\n", t->tm_mon+1, t->tm_mday, t->tm_year+1900, t->tm_hour, t->tm_min, t->tm_sec);
    printf("User: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d\n", user->weight);
    printf("Height: %d\n", user->height);
    printf("Workout type: %s\n", workout->type);
    printf("Duration: %d\n", workout->duration);
    printf("Intensity: %d\n", workout->intensity);
}

int main() {
    struct User user;
    struct Workout workout;

    createUser(&user);

    while(1) {
        int choice;
        printf("\n1. Log a workout\n2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            createWorkout(&workout);
            logWorkout(&user, &workout);
        } else if(choice == 2) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}