//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the Cellular Biology Programming Adventure!\n");

    // Initializing variables
    int num_organelles = 0;
    int num_cells = 0;

    // Prompting user for input
    printf("How many organelles do you want to create?: ");
    scanf("%d", &num_organelles);
    printf("How many cells do you want to create?: ");
    scanf("%d", &num_cells);

    printf("\nCreating %d organelles and %d cells...\n", num_organelles, num_cells);

    // Creating organelles
    int nucleus[num_organelles];
    int mitochondrion[num_organelles];
    int ribosome[num_organelles];

    printf("\nCreating organelles...\n");

    for (int i = 0; i < num_organelles; i++) {
        printf("Creating organelle %d...\n", i+1);
        nucleus[i] = i + 100;
        mitochondrion[i] = i + 200;
        ribosome[i] = i + 300;
    }

    printf("\nOrganelles created successfully!\n");

    // Creating cells
    struct Cell {
        int id;
        int organelles[3];
    };

    struct Cell cells[num_cells];

    printf("\nCreating cells...\n");

    for (int i = 0; i < num_cells; i++) {
        printf("Creating cell %d...\n", i+1);
        cells[i].id = i + 1;
        cells[i].organelles[0] = nucleus[i];
        cells[i].organelles[1] = mitochondrion[i];
        cells[i].organelles[2] = ribosome[i];
    }

    printf("\nCells created successfully!\n");

    // Displaying cells and organelles
    printf("\nDisplaying cells and their organelles...\n");

    for (int i = 0; i < num_cells; i++) {
        printf("\nCell %d has organelles:\n", cells[i].id);
        for (int j = 0; j < 3; j++) {
            printf("Organelle %d\n", cells[i].organelles[j]);
        }
    }

    printf("\nThank you for using our Cellular Biology Programming Adventure!\n");

    return 0;
}