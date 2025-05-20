//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50

struct Person {
    char name[MAX_NAME_LENGTH];
    int happiness;
};

bool is_happier(struct Person p1, struct Person p2) {
    return p1.happiness > p2.happiness;
}

void print_happiest(struct Person people[], int num_people) {
    int i, j, idx;

    printf("Welcome to the Happiest Person Party!\n");
    printf("Here are the people with the most happiness:\n");

    for (i = 0; i < num_people; ++i) {
        for (j = i + 1; j < num_people; ++j) {
            if (is_happier(people[i], people[j])) {
                idx = i;
                i = j;
                j = idx;
            }
        }
        printf("%d. %s: %d\n", i + 1, people[i].name, people[i].happiness);
        memmove(&people[i], &people[j], sizeof(struct Person));
        people[j].happiness = 0;
    }
}

void read_names_and_happiness(struct Person people[], int num_people) {
    int i;
    for (i = 0; i < num_people; ++i) {
        printf("Enter name %d and happiness level: ", i + 1);
        scanf("%s", people[i].name);
        scanf("%d", &people[i].happiness);
    }
}

int main() {
    int num_people;
    struct Person *people;

    printf("How many people are coming to the party?\n");
    scanf("%d", &num_people);

    people = malloc(num_people * sizeof(struct Person));

    read_names_and_happiness(people, num_people);

    print_happiest(people, num_people);

    free(people);

    printf("Everyone left the party happier than when they arrived!\n");
    printf("Have a GREAT day!\n");

    return 0;
}