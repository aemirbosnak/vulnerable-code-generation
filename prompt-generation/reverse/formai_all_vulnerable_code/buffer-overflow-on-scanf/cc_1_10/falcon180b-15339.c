//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_COLORS 1000
#define MAX_COLOR_NAME_LENGTH 50

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS];
int num_colors;

void generate_random_color() {
    int rand_red = rand() % 256;
    int rand_green = rand() % 256;
    int rand_blue = rand() % 256;
    printf("Random color: %d,%d,%d\n", rand_red, rand_green, rand_blue);
}

void add_color() {
    if (num_colors >= MAX_COLORS) {
        printf("Maximum number of colors reached.\n");
        return;
    }

    printf("Enter color name: ");
    scanf("%s", colors[num_colors].name);

    printf("Enter red value (0-255): ");
    scanf("%d", &colors[num_colors].red);

    printf("Enter green value (0-255): ");
    scanf("%d", &colors[num_colors].green);

    printf("Enter blue value (0-255): ");
    scanf("%d", &colors[num_colors].blue);

    num_colors++;
}

void list_colors() {
    for (int i = 0; i < num_colors; i++) {
        printf("%s: %d,%d,%d\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
    }
}

int main() {
    srand(time(NULL));

    num_colors = 0;

    while (1) {
        printf("\n1. Add color\n2. List colors\n3. Generate random color\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_color();
            break;
        case 2:
            list_colors();
            break;
        case 3:
            generate_random_color();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}