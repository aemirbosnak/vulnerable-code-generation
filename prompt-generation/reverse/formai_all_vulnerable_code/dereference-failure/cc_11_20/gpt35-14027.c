//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int genomeLength = 100;
    char* genome = (char*)malloc(sizeof(char) * genomeLength);

    // fill genome with random nucleotides
    for(int i = 0; i < genomeLength; i++) {
        int randNum = rand() % 4;
        switch(randNum) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
            default:
                printf("Error: invalid random number.\n");
                break;
        }
    }

    // print out the original genome
    printf("Original genome: ");
    for(int i = 0; i < genomeLength; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // simulate sequencing errors
    int numErrors = genomeLength / 10;
    for(int i = 0; i < numErrors; i++) {
        int randPos = rand() % genomeLength;
        int randNum = rand() % 3;
        char errorChar;
        switch(randNum) {
            case 0:
                errorChar = 'A';
                break;
            case 1:
                errorChar = 'C';
                break;
            case 2:
                errorChar = 'G';
                break;
            case 3:
                errorChar = 'T';
                break;
            default:
                printf("Error: invalid random number.\n");
                break;
        }
        genome[randPos] = errorChar;
    }

    // print out the sequenced genome
    printf("Sequenced genome: ");
    for(int i = 0; i < genomeLength; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    free(genome);
    return 0;
}