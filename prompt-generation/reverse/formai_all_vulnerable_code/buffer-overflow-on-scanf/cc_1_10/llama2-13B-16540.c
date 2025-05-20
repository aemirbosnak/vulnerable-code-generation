//LLAMA2-13B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

typedef struct {
    char name[20];
    int age;
} person;

person create_person(void) {
    person p;
    printf("What is your name? ");
    scanf("%19s", p.name);
    printf("How old are you? ");
    scanf("%d", &p.age);
    return p;
}

void display_person(person p) {
    printf("Hello, my name is %s and I am %d years old.\n", p.name, p.age);
}

int main(void) {
    srand(time(NULL));

    person p1 = create_person();
    display_person(p1);

    person p2 = create_person();
    display_person(p2);

    printf("Let's play a game of rock-paper-scissors!\n");

    int choice1, choice2;
    char symbol;

    do {
        printf("Choose a rock, paper, or scissors: ");
        scanf(" %c", &symbol);

        choice1 = rand() % 3;
        choice2 = rand() % 3;

        if (choice1 == choice2) {
            printf("We have a tie!\n");
        } else if (choice1 == 0 && choice2 == 1) {
            printf("Rock beats scissors!\n");
        } else if (choice1 == 1 && choice2 == 2) {
            printf("Paper beats rock!\n");
        } else {
            printf("Scissors beats paper!\n");
        }
    } while (1);

    return 0;
}