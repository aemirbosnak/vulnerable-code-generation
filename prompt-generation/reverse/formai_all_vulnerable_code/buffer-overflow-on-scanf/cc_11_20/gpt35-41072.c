//FormAI DATASET v1.0 Category: Computer Biology ; Style: relaxed
//In this program, we will simulate the process of DNA replication in bacteria.

#include<stdio.h>

#define MAX_LENGTH 100

int main(){

    char dna[MAX_LENGTH];
    char genetic_code[MAX_LENGTH];
    int i=0, j=0, k=0;

    printf("Enter the DNA sequence:\n");
    scanf("%s", dna);

    //Add the complementary base to the genetic code
    for(i=0; dna[i]!='\0'; i++){
        if(dna[i] == 'A'){
            genetic_code[j] = 'T';
        }
        else if(dna[i] == 'T'){
            genetic_code[j] = 'A';
        }
        else if(dna[i] == 'C'){
            genetic_code[j] = 'G';
        }
        else if(dna[i] == 'G'){
            genetic_code[j] = 'C';
        }
        j++;
    }

    //Reverse the genetic code
    k = j-1;
    for(i=0; i<j/2; i++){
        char temp = genetic_code[i];
        genetic_code[i] = genetic_code[k];
        genetic_code[k] = temp;
        k--;
    }

    printf("The DNA sequence is: %s\n", dna);
    printf("The genetic code is: %s\n", genetic_code);

    //Simulate DNA polymerase enzyme

    printf("Simulating DNA polymerase enzyme...\n");

    for(i=0; dna[i]!='\0'; i++){
        char base = dna[i];
        char comp_base = genetic_code[i];

        //Check for correct base pairing
        if((base == 'A' && comp_base == 'T') || (base == 'T' && comp_base == 'A') || (base == 'C' && comp_base == 'G') || (base == 'G' && comp_base == 'C')){
            printf("%c", base);
        }
        else{
            //Insert the complementary base
            printf("%c-%c", base, comp_base);
        }
    }

    printf("\n");

    return 0;
}