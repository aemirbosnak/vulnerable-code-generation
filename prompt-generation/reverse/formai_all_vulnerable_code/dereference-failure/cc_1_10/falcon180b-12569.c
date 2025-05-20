//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define MAX_NAME_LENGTH 20
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int score;
} Person;

int compare_name(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_age(const void *a, const void *b) {
    Person *person1 = *(Person **)a;
    Person *person2 = *(Person **)b;
    return person1->age - person2->age;
}

int compare_score(const void *a, const void *b) {
    Person *person1 = *(Person **)a;
    Person *person2 = *(Person **)b;
    return person2->score - person1->score;
}

void print_person(Person *person) {
    printf("%s (%d): %d\n", person->name, person->age, person->score);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    Person *people = malloc(MAX_WORDS * sizeof(Person));
    int num_people = 0;

    char line[MAX_NAME_LENGTH + MAX_WORD_LENGTH + 3];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));
        int score = atoi(strtok(NULL, " "));

        if (num_people >= MAX_WORDS) {
            printf("Error: Maximum number of people exceeded.\n");
            return 1;
        }

        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        people[num_people].score = score;
        num_people++;
    }

    fclose(input_file);

    qsort(people, num_people, sizeof(Person), compare_score);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}