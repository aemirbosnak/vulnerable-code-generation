//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
    char name[20];
    int reps;
    int sets;
};

struct Day {
    int day;
    char month[10];
    int year;
    struct Exercise exercises[3];
};

void print_exercise(struct Exercise e) {
    printf("Exercise: %s\nReps: %d\nSets: %d\n", e.name, e.reps, e.sets);
}

void print_day(struct Day d) {
    printf("Date: %d-%s-%d\n", d.day, d.month, d.year);
    for(int i=0;i<3;i++) {
        print_exercise(d.exercises[i]);
    }
}

void add_exercise(struct Day *d, char name[], int reps, int sets, int index) {
    strcpy(d->exercises[index].name, name);
    d->exercises[index].reps = reps;
    d->exercises[index].sets = sets;
}

int main() {
    struct Day days[7];
    
    for(int i=0;i<7;i++) {
        printf("Enter Day %d's date in the format (DD-Month-YYYY): ", i+1);
        scanf("%d-%s-%d", &days[i].day, days[i].month, &days[i].year);
        for(int j=0;j<3;j++) {
            char name[20];
            int reps, sets;
            printf("Enter exercise name: ");
            scanf("%s", name);
            printf("Enter reps: ");
            scanf("%d", &reps);
            printf("Enter sets: ");
            scanf("%d", &sets);
            add_exercise(&days[i], name, reps, sets, j);
        }
    }
    
    // print all the entries
    for(int i=0;i<7;i++) {
        print_day(days[i]);
    }
    
    return 0;
}