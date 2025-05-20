//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("This program simulates the sequencing of DNA bases.\n");
    printf("Please enter the length of the genome you wish to sequence: ");
    int length, i, j;
    scanf("%d",&length);
    char genome[length];
    srand(time(0));
    //Generating random DNA bases
    for(i=0; i<length; i++){
        int base = rand()%4;
        switch(base){
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
        }
    }
    printf("The randomly generated genome is: ");
    //Printing the generated genome
    for(i=0; i<length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
    printf("Now we will simulate the sequencing process.\n");
    printf("Please enter the number of reads you want to take: ");
    int numReads;
    scanf("%d",&numReads);
    printf("Please enter the length of the reads: ");
    int readLength;
    scanf("%d",&readLength);
    printf("The reads are:\n");
    for(i=0; i<numReads; i++){
        int startIndex = rand()%(length-readLength+1);
        for(j=startIndex; j<(startIndex+readLength); j++){
            printf("%c", genome[j]);
        }
        printf("\n");
    }
    printf("Thank you for using the Genome Sequencing Simulator!\n");
    return 0;
}