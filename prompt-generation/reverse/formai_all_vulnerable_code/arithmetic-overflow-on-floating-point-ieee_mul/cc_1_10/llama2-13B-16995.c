//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 1024
#define MAX_NUM_LEN 20

typedef struct {
    char *name;
    int age;
} person_t;

void analyze(person_t *people, int num_people) {
    int i, j;
    double avg_age = 0;
    double std_age = 0;
    double max_age = -1;
    double min_age = 100;

    for (i = 0; i < num_people; i++) {
        avg_age += people[i].age;
        std_age += pow(people[i].age - avg_age, 2);
        if (people[i].age > max_age) {
            max_age = people[i].age;
        }
        if (people[i].age < min_age) {
            min_age = people[i].age;
        }
    }
    avg_age /= num_people;
    std_age /= num_people;

    for (i = 0; i < num_people; i++) {
        printf("Person %d: %s, age %d (%c%c%c%c)\n", i + 1, people[i].name, people[i].age,
               (people[i].age > avg_age + 2 * std_age) ? 'Y' : 'N',
               (people[i].age > max_age) ? 'M' : 'L',
               (people[i].age < min_age) ? 'S' : 'G');
    }
}

int main() {
    person_t people[5] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35},
        {"David", 20},
        {"Eve", 40}
    };
    int num_people = sizeof(people) / sizeof(people[0]);

    analyze(people, num_people);

    return 0;
}