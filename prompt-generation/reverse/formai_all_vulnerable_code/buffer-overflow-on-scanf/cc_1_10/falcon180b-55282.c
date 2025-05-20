//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50

typedef struct {
    char name[MAX_STR_LEN];
    char type[MAX_STR_LEN];
    int duration;
    int calories;
} exercise;

void add_exercise(exercise* list, int index, char* name, char* type, int duration, int calories) {
    list[index].duration = duration;
    list[index].calories = calories;
    strcpy(list[index].name, name);
    strcpy(list[index].type, type);
}

void print_exercise(exercise ex) {
    printf("Name: %s\nType: %s\nDuration: %d minutes\nCalories burned: %d\n", ex.name, ex.type, ex.duration, ex.calories);
}

void print_list(exercise* list, int size) {
    printf("Fitness tracker:\n");
    for (int i = 0; i < size; i++) {
        print_exercise(list[i]);
    }
}

int main() {
    int size = 0;
    exercise list[MAX_STR_LEN];
    char name[MAX_STR_LEN];
    char type[MAX_STR_LEN];
    int duration, calories;

    // Add exercises
    printf("Enter the number of exercises you want to track: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Enter exercise %d:\n", i+1);
        printf("Name: ");
        scanf("%s", name);
        printf("Type: ");
        scanf("%s", type);
        printf("Duration (in minutes): ");
        scanf("%d", &duration);
        printf("Calories burned: ");
        scanf("%d", &calories);
        add_exercise(list, i, name, type, duration, calories);
    }

    // Print list
    printf("Your fitness tracker:\n");
    print_list(list, size);

    return 0;
}