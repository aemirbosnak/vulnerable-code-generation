//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BALLOON_NAME_LENGTH 20

typedef struct {
    int id;
    char name[BALLOON_NAME_LENGTH];
    size_t size;
} Balloon;

void generate_name(Balloon *balloon) {
    char *animal_names[] = {"Butterfly", "Penguin", "Giraffe", "Elephant", "Lion", "Tiger", "Zebra", "Flamingo", "Kangaroo", "Rhinoceros"};
    char *colors[] = {"Red", "Blue", "Green", "Yellow", "Orange", "Purple", "Pink", "Black", "White", "Brown"};

    balloon->id = rand() % 100;
    strcpy(balloon->name, animal_names[rand() % 10]);
    strcat(balloon->name, " the ");
    strcat(balloon->name, colors[rand() % 11]);
}

Balloon *create_balloon(size_t size) {
    Balloon *balloon = (Balloon *) malloc(sizeof(Balloon) + size);
    if (balloon == NULL) {
        printf("Out of memory!\n");
        return NULL;
    }
    generate_name(balloon);
    balloon->size = size;
    return balloon;
}

void delete_balloon(Balloon *balloon) {
    free(balloon);
    printf("%s, with ID %d, has disappeared in a puff of smoke.\n", balloon->name, balloon->id);
}

int main() {
    srand(time(NULL));
    int num_balloons;
    Balloon *balloons = NULL;

    printf("How many magical balloons would you like to create?\n");
    scanf("%d", &num_balloons);

    for (int i = 0; i < num_balloons; i++) {
        Balloon *balloon = create_balloon(sizeof(int) * 3); // Allocate memory for an integer array inside the balloon
        if (balloon != NULL) {
            int x, y, z;
            balloon->size = sizeof(int) * 3;
            printf("Created %s.\n", balloon->name);
            balloons = realloc(balloons, sizeof(Balloon) * (i + 2));
            balloons[i] = *balloon;
        } else {
            printf("Failed to create balloon %d.\n", i + 1);
            i--;
        }
    }

    for (int i = 0; i < num_balloons; i++) {
        printf("%s is floating in the air, with ID %d.\n", balloons[i].name, balloons[i].id);
    }

    for (int i = 0; i < num_balloons; i++) {
        delete_balloon(&balloons[i]);
    }

    free(balloons);

    return 0;
}