//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Initialize arrays to store the atomic number, symbol, and mass of each element
    int atomic_numbers[100] = {0};
    char symbols[100][10] = {0};
    int masses[100] = {0};

    // Read the input from a file
    FILE* file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Read the first line of the file, which contains the atomic numbers
    int num_elements = fscanf(file, "%d", &atomic_numbers[0]);
    for (int i = 1; i < num_elements; i++) {
        int element = fscanf(file, "%d", &atomic_numbers[i]);
        atomic_numbers[i] = atomic_numbers[i] + element;
    }

    // Read the second line of the file, which contains the element symbols
    fscanf(file, "%s", symbols[0]);
    for (int i = 1; i < num_elements; i++) {
        fscanf(file, "%s", symbols[i]);
    }

    // Read the third line of the file, which contains the element masses
    fscanf(file, "%d", &masses[0]);
    for (int i = 1; i < num_elements; i++) {
        fscanf(file, "%d", &masses[i]);
    }

    // Close the file
    fclose(file);

    // Print the periodic table
    printf("\n\nPeriodic Table Quiz\n\n");
    printf("Atomic Number | Element Symbol | Element Mass\n");
    printf("----------------|----------------|----------------\n");

    // Loop through each element in the table
    for (int i = 0; i < num_elements; i++) {
        printf("%d | %s | %d\n", atomic_numbers[i], symbols[i], masses[i]);
    }

    // Ask the user a question about the periodic table
    printf("Question: What is the atomic number of Oxygen?\n");
    int answer;
    scanf("%d", &answer);

    // Check the user's answer
    if (answer == 8) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    // Ask the user another question about the periodic table
    printf("Question: What is the symbol for Gold?\n");
    char answer_symbol[10];
    fgets(answer_symbol, sizeof(answer_symbol), stdin);
    answer_symbol[strcspn(answer_symbol, "\n")] = '\0';

    // Check the user's answer
    if (strcmp(answer_symbol, "Au") == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    // Print the final score
    printf("Your score is: ");
    if (answer == 8 && strcmp(answer_symbol, "Au") == 0) {
        printf("10/10!\n");
    } else {
        printf("%d/%d\n", answer, 2);
    }

    return 0;
}