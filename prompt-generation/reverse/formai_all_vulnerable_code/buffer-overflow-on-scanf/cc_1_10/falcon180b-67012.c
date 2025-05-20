//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_EVENTS 10
#define MAX_TIME_TRAVEL 100

typedef struct {
    char name[20];
    int age;
    int time_traveled;
} person;

void print_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Time Traveled: %d\n", p.time_traveled);
}

void time_travel(person* p) {
    if (p->time_traveled >= MAX_TIME_TRAVEL) {
        printf("Error: You have reached the maximum number of time travels.\n");
        return;
    }
    printf("You are about to time travel. Are you sure? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter the year you want to travel to: ");
        int year;
        scanf("%d", &year);
        p->time_traveled++;
        printf("You have traveled to the year %d.\n", year);
    }
}

void main() {
    person p;
    strcpy(p.name, "John Doe");
    p.age = 25;
    p.time_traveled = 0;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Your name is %s and you are %d years old.\n", p.name, p.age);
    while (true) {
        printf("What do you want to do?\n");
        printf("1. Time travel\n");
        printf("2. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                time_travel(&p);
                break;
            case 2:
                printf("Goodbye, %s!\n", p.name);
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}