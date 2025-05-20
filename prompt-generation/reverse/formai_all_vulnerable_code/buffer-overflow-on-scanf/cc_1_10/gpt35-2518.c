//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Function to generate random letters from A,C,G,T
char randomLetter() {
    char letters[4] = {'A', 'C', 'G', 'T'};
    int randomNum = rand() % 4;
    return letters[randomNum];
}

int main() {
    int genomeLength, numOfReads, minLength, maxLength, readLength;
    char *genome;

    //Read in user input
    printf("Enter the length of the genome: ");
    scanf("%d", &genomeLength);
    printf("Enter the minimum length of reads: ");
    scanf("%d", &minLength);
    printf("Enter the maximum length of reads: ");
    scanf("%d", &maxLength);
    printf("Enter the number of reads: ");
    scanf("%d", &numOfReads);

    //Allocate memory for the genome
    genome = (char*)malloc(genomeLength * sizeof(char));

    //Generate random genome sequence using random letters
    srand(time(NULL));
    int i;
    for(i = 0; i < genomeLength; i++) {
        genome[i] = randomLetter();
    }

    //Generate random reads from the generated genome
    int readIndex;
    int j, k;
    for(i = 0; i < numOfReads; i++) {
        readLength = rand() % (maxLength - minLength + 1) + minLength;
        readIndex = rand() % (genomeLength - readLength + 1);
        printf("Read %d: ", i+1);
        for(j = readIndex; j < readIndex + readLength; j++) {
            printf("%c", genome[j]);
        }
        printf("\n");
    }
    return 0;
}