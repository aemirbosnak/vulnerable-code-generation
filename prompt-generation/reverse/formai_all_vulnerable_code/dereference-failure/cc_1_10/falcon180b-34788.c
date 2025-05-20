//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000
#define MAX_DICE 100

typedef struct {
    int num_faces;
    char *faces;
} die;

die *new_die(int num_faces, char *faces) {
    die *d = (die *) malloc(sizeof(die));
    d->num_faces = num_faces;
    d->faces = (char *) malloc(num_faces * sizeof(char));
    strcpy(d->faces, faces);
    return d;
}

int roll_die(die *d) {
    return rand() % d->num_faces;
}

int main() {
    srand(time(NULL));

    die *d1 = new_die(6, "1 2 3 4 5 6");
    die *d2 = new_die(20, "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20");
    die *d3 = new_die(12, "1 2 3 4 5 6 7 8 9 10 11 12");

    int r1, r2, r3;

    r1 = roll_die(d1);
    r2 = roll_die(d2);
    r3 = roll_die(d3);

    printf("Rolling a %d-sided die...\n", d1->num_faces);
    printf("Result: %d\n", r1);

    printf("Rolling a %d-sided die...\n", d2->num_faces);
    printf("Result: %d\n", r2);

    printf("Rolling a %d-sided die...\n", d3->num_faces);
    printf("Result: %d\n", r3);

    free(d1->faces);
    free(d1);
    free(d2->faces);
    free(d2);
    free(d3->faces);
    free(d3);

    return 0;
}