//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>

//define the structure for the workout
typedef struct {
    char type[50];
    int sets;
    int reps;
    int weight;
} workout;

//define the structure for the user
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    char goal[100];
} user;

//function to get the user input for the workout
void getWorkout(workout* w) {
    printf("Enter the type of exercise: ");
    scanf("%s", w->type);
    printf("Enter the number of sets: ");
    scanf("%d", &w->sets);
    printf("Enter the number of reps: ");
    scanf("%d", &w->reps);
    printf("Enter the weight: ");
    scanf("%d", &w->weight);
}

//function to get the user input for the user
void getUser(user* u) {
    printf("Enter your name: ");
    scanf("%s", u->name);
    printf("Enter your age: ");
    scanf("%d", &u->age);
    printf("Enter your weight: ");
    scanf("%d", &u->weight);
    printf("Enter your height: ");
    scanf("%d", &u->height);
    printf("Enter your fitness goal: ");
    scanf("%s", u->goal);
}

//function to print the user's information
void printUser(user u) {
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Weight: %d\n", u.weight);
    printf("Height: %d\n", u.height);
    printf("Fitness Goal: %s\n", u.goal);
}

//function to print the workout
void printWorkout(workout w) {
    printf("Type: %s\n", w.type);
    printf("Sets: %d\n", w.sets);
    printf("Reps: %d\n", w.reps);
    printf("Weight: %d\n", w.weight);
}

//main function
int main() {
    user u;
    workout w;

    //get the user input
    getUser(&u);

    //print the user's information
    printf("User Information:\n");
    printUser(u);

    //get the workout input
    getWorkout(&w);

    //print the workout
    printf("\nWorkout:\n");
    printWorkout(w);

    return 0;
}