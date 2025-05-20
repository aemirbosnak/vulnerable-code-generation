//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define N 10

typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
    double bmi;
    int *friends;
    int num_friends;
} Person;

Person people[N];

void init_people() {
    int i;
    for (i = 0; i < N; i++) {
        people[i].age = rand() % 100;
        people[i].height = rand() % 200;
        people[i].weight = rand() % 100;
        people[i].bmi = (double)people[i].weight / (people[i].height / 100.0) / 100.0;
        people[i].num_friends = 0;
        people[i].friends = NULL;
    }
}

void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %d cm\n", p.height);
    printf("Weight: %d kg\n", p.weight);
    printf("BMI: %.2f\n", p.bmi);
    printf("Friends: ");
    int i;
    for (i = 0; i < p.num_friends; i++) {
        printf("%s ", people[p.friends[i]].name);
    }
    printf("\n");
}

void add_friend(int p1, int p2) {
    people[p1].friends = realloc(people[p1].friends, sizeof(int) * ++people[p1].num_friends);
    people[p1].friends[people[p1].num_friends - 1] = p2;
    people[p2].friends = realloc(people[p2].friends, sizeof(int) * ++people[p2].num_friends);
    people[p2].friends[people[p2].num_friends - 1] = p1;
}

int main() {
    srand(time(NULL));
    init_people();
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i!= j) {
                add_friend(i, j);
            }
        }
    }
    for (i = 0; i < N; i++) {
        print_person(people[i]);
    }
    return 0;
}