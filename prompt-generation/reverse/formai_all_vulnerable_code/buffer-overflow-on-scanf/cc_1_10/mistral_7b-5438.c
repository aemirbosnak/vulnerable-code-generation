//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int steps;
    float weight;
} Person;

void welcome_message() {
    printf("\n*************************************************\n");
    printf("*                                               *\n");
    printf("* Welcome to the Wacky Fitness Tracker 2000!       *\n");
    printf("* Where we help you get fit while having a laugh! *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

void print_person(Person person) {
    printf("\nName: %s", person.name);
    printf("\nSteps: %d", person.steps);
    printf("\nWeight: %.2f kg", person.weight);
    printf("\n-------------------------\n");
}

Person create_person(char *name, int initial_steps, float initial_weight) {
    Person new_person = {name, initial_steps, initial_weight};
    return new_person;
}

int main() {
    srand(time(NULL));
    welcome_message();

    Person you = {"You", 0, 75.5};
    Person buddy = {"Buddy", 0, 85.3};

    while (1) {
        printf("\n%s, you have taken %d steps today!\n", you.name, you.steps);
        printf("Buddy has taken %d steps today!\n", buddy.steps);

        if (you.steps > buddy.steps) {
            printf("Ha ha! You're winning today, %s!\n", you.name);
            you.steps += rand() % 10 + 1;
        } else {
            printf("Aww, not again, %s! Buddy's winning today.\n", you.name);
            buddy.steps += rand() % 10 + 1;
        }

        printf("\n%s, please enter the number of steps you took today: ", you.name);
        scanf("%d", &you.steps);
        getchar(); // for getting rid of newline character

        printf("Buddy, please enter the number of steps you took today: ");
        scanf("%d", &buddy.steps);
        getchar();

        system("clear"); // for Unix-based systems or clrscr() for Windows
    }

    print_person(you);
    print_person(buddy);

    return 0;
}