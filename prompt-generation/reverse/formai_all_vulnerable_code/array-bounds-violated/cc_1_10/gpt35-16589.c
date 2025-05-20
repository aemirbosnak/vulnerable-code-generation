//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    printf("********************\n");
    printf("* Genome Sequencing *\n");
    printf("********************\n");
    
    int genomeLength, randomNum, countA = 0, countC = 0, countG = 0, countT = 0;
    printf("Enter the length of the genome to sequence: ");
    scanf("%d", &genomeLength);
    
    char genome[genomeLength+1];
    
    for(int i=0; i<genomeLength; i++) {
        randomNum = rand() % 4; // generates a random number between 0-3
        
        switch(randomNum) {
            case 0:
                genome[i] = 'A'; // if randomNum is 0, add A to the genome
                countA++;
                break;
            case 1:
                genome[i] = 'C'; // if randomNum is 1, add C to the genome
                countC++;
                break;
            case 2:
                genome[i] = 'G'; // if randomNum is 2, add G to the genome
                countG++;
                break;
            case 3:
                genome[i] = 'T'; // if randomNum is 3, add T to the genome
                countT++;
                break;
        }
    }
    
    genome[genomeLength] = '\0'; // Adds null to the end of the genome to make it a string
    
    printf("\nGenome Sequenced! Here is the information:\n");
    printf("--------------------------------------------\n");
    printf("Total Length: %d\n", genomeLength);
    printf("A Count: %d\n", countA);
    printf("C Count: %d\n", countC);
    printf("G Count: %d\n", countG);
    printf("T Count: %d\n", countT);
    printf("Genome: %s\n", genome);
    
    return 0;
}