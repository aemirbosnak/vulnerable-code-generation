//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 100
#define NUM_SHAPES 5

typedef struct {
    char name[20];
    int shape_id;
} Shape;

Shape shapes[NUM_SHAPES] = {
    {"human", 0},
    {"dragon", 1},
    {"tree", 2},
    {"snake", 3},
    {"cloud", 4}
};

void print_intro() {
    printf("\nWelcome to the Shape Shifter Adventure Game!\n");
    printf("You are a shape shifter living in a magical world.\n");
    printf("Use your powers to transform into different shapes and explore.\n");
}

void print_current_shape(int shape_id) {
    printf("You are currently a %s.\n", shapes[shape_id].name);
}

int main() {
    int shape_id = 0; // initial shape is human
    char line[MAX_LINE];

    srand(time(NULL));

    print_intro();

    while (1) {
        print_current_shape(shape_id);
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        line[strcspn(line, "\n")] = 0; // remove newline character

        if (strcmp(line, "list") == 0) {
            for (int i = 0; i < NUM_SHAPES; i++) {
                printf("%d. %s\n", i + 1, shapes[i].name);
            }
        } else if (sscanf(line, "%d", &shape_id) == 1) {
            if (shape_id < 0 || shape_id >= NUM_SHAPES) {
                printf("Invalid shape.\n");
            } else {
                shape_id = (shape_id + 1) % NUM_SHAPES; // rotate shapes
            }
        } else if (strcmp(line, "quit") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    printf("Goodbye! Come back and try shifting shapes again.\n");

    return 0;
}