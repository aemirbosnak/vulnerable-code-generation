//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int health;
} Person;

void createPerson(Person* person, char* name, int age, int health) {
    strcpy(person->name, name);
    person->age = age;
    person->health = health;
}

void printPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Health: %d\n", person.health);
}

int main() {
    srand(time(0));

    Person player = {0};
    createPerson(&player, "Player", 20, 100);

    Person* ghost = malloc(sizeof(Person));
    createPerson(ghost, "Ghost", 100, 50);

    int choice;
    int running = 1;

    while (running) {
        printf("You are in a haunted house.\n");
        printf("There is a ghost here.\n");
        printf("What do you want to do?\n");
        printf("1. Attack the ghost.\n");
        printf("2. Run away.\n");
        printf("3. Do nothing.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player.health >= ghost->health) {
                    ghost->health -= player.health;
                    printf("You attacked the ghost and dealt %d damage.\n", player.health);
                } else {
                    printf("You attacked the ghost but it didn't do anything.\n");
                }
                break;
            case 2:
                printf("You ran away from the ghost.\n");
                break;
            case 3:
                printf("You did nothing.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (player.health <= 0 || ghost->health <= 0) {
            running = 0;
        }
    }

    free(ghost);

    return 0;
}