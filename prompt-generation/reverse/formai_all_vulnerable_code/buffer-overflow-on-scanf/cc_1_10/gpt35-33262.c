//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Function to randomly generate bases
char randBase(){
    int randomNumber = rand() % 4 + 1;
    if(randomNumber==1){
        return 'A';
    }
    else if(randomNumber==2){
        return 'C';
    }
    else if(randomNumber==3){
        return 'G';
    }
    else{
        return 'T';
    }
}

int main(){
    //Setting up the variables

    char genome[100000]; //Array to store the genome sequence
    int genomeLength; //Length of the genome sequence
    int i,j; //Iterator variables
    int readLength; //Length of the read sequence
    int noOfReads; //Number of read sequences
    int readStartIndex; //Variable to store the starting index of read sequences
    int coverage; //Average coverage of genome sequence
    float errorPercentage; //Percentage of error in the sequencing

    srand(time(0)); //Seeding the random number generator with time

    //Instructions to input values
    printf("Welcome to the Genome Sequencing Simulator!\n\n");
    printf("Please enter the length of the genome sequence you want to simulate: ");
    scanf("%d",&genomeLength);

    printf("Please enter the average coverage you want to simulate: ");
    scanf("%d",&coverage);

    printf("Please enter the length of the read sequence you want to simulate: ");
    scanf("%d",&readLength);

    printf("Please enter the number of read sequences you want to simulate: ");
    scanf("%d",&noOfReads);

    printf("Please enter the percentage of error you want to simulate: ");
    scanf("%f",&errorPercentage);

    //Initializing genome sequence with randomly generated bases
    for(i=0;i<genomeLength;i++){
        genome[i] = randBase();
    }

    //Simulating sequencing reads
    printf("\nSimulating sequencing reads...\n\n");

    for(i=0;i<noOfReads;i++){

        //Generating starting index of read sequence
        readStartIndex = rand() % genomeLength;

        //Printing read sequence
        printf("Read %d: ",i+1);
        for(j=0;j<readLength;j++){
            //Simulating sequencing errors
            if((float)rand()/RAND_MAX <= errorPercentage/100){
                printf("%c",randBase());
            }
            else{
                printf("%c",genome[(readStartIndex+j)%genomeLength]);
            }

        }
        printf("\n");
    }

    printf("\n\nSequencing completed!\n");

    return 0;
}