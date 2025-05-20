//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_PLANETS 10

typedef struct {
    int x;
    int y;
    char name[50];
} Planet;

Planet planets[MAX_PLANETS];

int main() {
    int i, j;
    int rows, cols, max_planets;
    char input;

    printf("Welcome to the Procedural Space Adventure!\n");

    // Get user input for the size of the universe
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    if (rows < 1) {
        printf("Invalid number of rows!\n");
        return 1;
    }

    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    if (cols < 1) {
        printf("Invalid number of columns!\n");
        return 1;
    }

    printf("Enter the maximum number of planets: ");
    scanf("%d", &max_planets);
    if (max_planets < 1) {
        printf("Invalid number of planets!\n");
        return 1;
    }

    // Generate random positions for the planets
    for (i = 0; i < max_planets; i++) {
        planets[i].x = (rand() % (rows + 1)) - 1;
        planets[i].y = (rand() % (cols + 1)) - 1;
        planets[i].name[0] = '0';
        for (j = 1; j < 50; j++) {
            planets[i].name[j] = 'a' + rand() % 26;
        }
        planets[i].name[50] = '\0';
    }

    // Print the universe
    printf(" ");
    for (i = 0; i < rows; i++) {
        printf("- ");
        for (j = 0; j < cols; j++) {
            printf(" ");
        }
        printf("- \n");
    }
    printf(" ");
    for (i = 0; i < cols; i++) {
        printf("-- ");
        for (j = 0; j < rows; j++) {
            printf(" ");
        }
        printf("-- \n");
    }
    printf(" ");
    for (i = 0; i < rows; i++) {
        printf("- ");
        for (j = 0; j < cols; j++) {
            printf(" ");
        }
        printf("- \n");
    }

    // Print the planets
    printf(" ");
    for (i = 0; i < cols; i++) {
        printf("- ");
        for (j = 0; j < rows; j++) {
            printf(" ");
        }
        printf("- \n");
    }
    printf(" ");
    for (i = 0; i < rows; i++) {
        printf("-- ");
        for (j = 0; j < cols; j++) {
            printf(" ");
        }
        printf("-- \n");
    }
    printf(" ");
    for (i = 0; i < rows; i++) {
        printf("- ");
        for (j = 0; j < cols; j++) {
            printf(" ");
        }
        printf("- \n");
    }

    for (i = 0; i < max_planets; i++) {
        printf("Planet %d: %s\n", i+1, planets[i].name);
    }

    return 0;
}