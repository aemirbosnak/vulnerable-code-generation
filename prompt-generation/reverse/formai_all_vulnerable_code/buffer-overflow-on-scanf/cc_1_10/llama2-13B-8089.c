//LLAMA2-13B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

void init_name(struct person *person) {
    printf("Please enter your name: ");
    fgets(person->name, MAX_NAME_LENGTH, stdin);
}

void init_age(struct person *person) {
    printf("Please enter your age: ");
    scanf("%d", &person->age);
}

void print_info(struct person person) {
    printf("Hello, my name is %s and I am %d years old.\n", person.name, person.age);
}

int main() {
    struct person person;

    // Initialize name
    init_name(&person);

    // Initialize age
    init_age(&person);

    // Print information
    print_info(person);

    // Get current time
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("Current time: %ld.%ld seconds\n", ts.tv_sec, ts.tv_nsec);

    // Sleep for a random amount of time
    int random_sleep_time = rand() % 10000;
    printf("Sleeping for %d milliseconds...\n", random_sleep_time);
    usleep(random_sleep_time);

    return 0;
}