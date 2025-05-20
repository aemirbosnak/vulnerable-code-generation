//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 5
#define ALPHABET "ACGT"

void generateRandomSequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = ALPHABET[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

void generateGenome(char genome[NUM_SEQUENCES][SEQUENCE_LENGTH + 1]) {
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generateRandomSequence(genome[i], SEQUENCE_LENGTH);
    }
}

void printGenome(char genome[NUM_SEQUENCES][SEQUENCE_LENGTH + 1]) {
    printf("Generated Genome Sequences:\n");
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        printf("Sequence %d: %s\n", i + 1, genome[i]);
    }
}

void writeGenomeToFile(char genome[NUM_SEQUENCES][SEQUENCE_LENGTH + 1], const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        return;
    }
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        fprintf(file, ">Sequence_%d\n%s\n", i + 1, genome[i]);
    }
    fclose(file);
    printf("Genome written to file: %s\n", filename);
}

void showMenu() {
    printf("\n--- Genome Sequencing Simulator ---\n");
    printf("1. Generate New Genome Sequences\n");
    printf("2. Save Genome to File\n");
    printf("3. Display Genome Sequences\n");
    printf("4. Exit\n");
}

int main() {
    char genome[NUM_SEQUENCES][SEQUENCE_LENGTH + 1];
    int choice;
    char filename[50];

    srand(time(NULL));  // Seed the random number generator

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateGenome(genome);
                printf("New genome sequences generated.\n");
                break;
            case 2:
                printf("Enter filename to save the genome: ");
                scanf("%s", filename);
                writeGenomeToFile(genome, filename);
                break;
            case 3:
                printGenome(genome);
                break;
            case 4:
                printf("Exiting the program. May your sequences be harmonious!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}