//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_GENOME_COUNT 100

void generateRandomGenome(char *genome, int length) {
    const char bases[] = {'A', 'T', 'C', 'G'};
    for (int i = 0; i < length; i++) {
        genome[i] = bases[rand() % 4];
    }
    genome[length] = '\0';  // Null-terminate the string
}

float calculateGCContent(const char *genome) {
    int gcCount = 0;
    int length = strlen(genome);
    for (int i = 0; i < length; i++) {
        if (genome[i] == 'G' || genome[i] == 'C') {
            gcCount++;
        }
    }
    return (length > 0) ? ((float)gcCount / length) * 100.0 : 0.0;
}

void displayGenomeInfo(const char *genome) {
    printf("Genome: %s\n", genome);
    printf("Length: %lu\n", strlen(genome));
    printf("GC Content: %.2f%%\n", calculateGCContent(genome));
}

int main() {
    srand(time(NULL));  // Seed for random number generation

    int numGenomes, genomeLength;
    char genomes[MAX_GENOME_COUNT][MAX_GENOME_LENGTH + 1];

    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Enter the number of genomes to generate (max %d): ", MAX_GENOME_COUNT);
    scanf("%d", &numGenomes);
    
    if (numGenomes < 1 || numGenomes > MAX_GENOME_COUNT) {
        printf("Please enter a valid number between 1 and %d.\n", MAX_GENOME_COUNT);
        return 1;
    }

    printf("Enter the length of each genome (max %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genomeLength);
    
    if (genomeLength < 1 || genomeLength > MAX_GENOME_LENGTH) {
        printf("Please enter a valid length between 1 and %d.\n", MAX_GENOME_LENGTH);
        return 1;
    }
    
    printf("Generating %d random genomes of length %d...\n", numGenomes, genomeLength);
    
    for (int i = 0; i < numGenomes; i++) {
        generateRandomGenome(genomes[i], genomeLength);
        displayGenomeInfo(genomes[i]);
        printf("\n");
    }

    // Allow user to save genomes to a file
    char filename[256];
    printf("Would you like to save these genomes to a file? (y/n): ");
    char saveOption;
    scanf(" %c", &saveOption);
    
    if (saveOption == 'y' || saveOption == 'Y') {
        printf("Enter filename to save: ");
        scanf("%s", filename);
        FILE *file = fopen(filename, "w");
        if (file != NULL) {
            for (int i = 0; i < numGenomes; i++) {
                fprintf(file, "%s\n", genomes[i]);
            }
            fclose(file);
            printf("Genomes saved to %s successfully!\n", filename);
        } else {
            printf("Error opening file for writing.\n");
        }
    } else {
        printf("Genomes were not saved.\n");
    }
    
    printf("Thank you for using the Genome Sequencing Simulator!\n");
    return 0;
}