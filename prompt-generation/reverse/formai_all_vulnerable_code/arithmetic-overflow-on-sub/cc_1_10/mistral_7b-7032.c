//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX 5

typedef struct {
    char name[20];
    int age;
} Person;

void print_progress_bar(int progress) {
    int bar_length = 50;
    int filled_bars = progress * bar_length / 100;

    printf("\rProgress: [");
    for (int i = 0; i < filled_bars; i++) {
        printf("=");
    }
    for (int i = filled_bars; i < bar_length; i++) {
        printf(" ");
    }
    printf("] %d%%", progress);
    fflush(stdout);
    usleep(100000);
}

int compare(const void *a, const void *b) {
    Person *person_a = (Person *) a;
    Person *person_b = (Person *) b;

    return person_a->age - person_b->age;
}

int main() {
    srand(time(NULL));
    Person people[MAX];

    for (int i = 0; i < MAX; i++) {
        sprintf(people[i].name, "Person %d", i + 1);
        people[i].age = rand() % 100;
    }

    clock_t start = clock();
    qsort(people, MAX, sizeof(Person), compare);
    clock_t end = clock();

    printf("\nSorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    printf("\nSorting time: %.2fs\n", (end - start) / (double) CLOCKS_PER_SEC);

    int total_steps = 100;
    int progress = 0;

    printf("\nSorting progress:\n");
    while (progress < 100) {
        usleep(50000);
        print_progress_bar(progress);
        fflush(stdout);
        sleep(0.05);
        progress += 10;
    }

    return 0;
}