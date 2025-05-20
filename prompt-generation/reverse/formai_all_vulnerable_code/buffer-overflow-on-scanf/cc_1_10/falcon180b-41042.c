//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void intro() {
    printf("Welcome to the C Procedural Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new planets.\n");
    printf("Your journey will be filled with challenges and surprises.\n");
    printf("Are you ready to embark on this exciting adventure?\n");
}

void createPlanet(int x, int y, char *name) {
    printf("You have discovered a new planet at coordinates (%d, %d)!\n", x, y);
    printf("What would you like to name this planet? ");
    scanf("%s", name);
    printf("Planet %s has been added to your discovery log.\n", name);
}

void encounterAlien(int friendly) {
    if (friendly) {
        printf("You encounter a friendly alien species.\n");
        printf("They share their knowledge of the galaxy with you.\n");
        printf("Your understanding of the universe has increased.\n");
    } else {
        printf("You encounter a hostile alien species.\n");
        printf("A fierce battle ensues, but you manage to escape unharmed.\n");
    }
}

void blackHole(int avoid) {
    if (avoid) {
        printf("You narrowly avoid being sucked into a black hole.\n");
        printf("Your quick thinking and piloting skills saved your life.\n");
    } else {
        printf("You are pulled into a black hole and transported to another dimension.\n");
        printf("Your adventure continues in this strange new world.\n");
    }
}

int main() {
    int x, y;
    char name[20];

    intro();

    for (int i = 0; i < 5; i++) {
        printf("Enter your coordinates for planet #%d: ", i+1);
        scanf("%d %d", &x, &y);
        createPlanet(x, y, name);
    }

    printf("Your journey has come to an end.\n");
    printf("You have discovered %d planets and encountered various challenges along the way.\n", 5);

    return 0;
}