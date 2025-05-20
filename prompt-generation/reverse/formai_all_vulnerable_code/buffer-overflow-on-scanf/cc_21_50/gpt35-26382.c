//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    char dna[2000];
    char proteins[1000][4];
    int num_protein_seq = 0;
    int i, j;
    int randam_num;
    
    printf("Welcome to the protein synthesis simulator program!\n");
    printf("Please enter the DNA sequence you want to synthesize: ");
    scanf("%s", dna);
    
    srand(time(NULL));
    for(i=0; i<strlen(dna)-2; i+=3) {
        randam_num = rand()%4;
        if(dna[i] == 'A') {
            if(dna[i+1] == 'A') {
                if(dna[i+2] == 'A' || dna[i+2] == 'G') {
                    strcpy(proteins[num_protein_seq], randam_num==0?"lys":"arg");
                }
                else {
                    strcpy(proteins[num_protein_seq], "asn");
                }
            }
            else if(dna[i+1] == 'T') {
                strcpy(proteins[num_protein_seq], "ile");
            }
            else if(dna[i+1] == 'C') {
                strcpy(proteins[num_protein_seq], "thr");
            }
            else if(dna[i+1] == 'G') {
                if(dna[i+2] == 'A' || dna[i+2] == 'G') {
                    strcpy(proteins[num_protein_seq], "arg");
                }
                else {
                    strcpy(proteins[num_protein_seq], "ser");
                }       
            }
        }
        else if(dna[i] == 'T') {
            if(dna[i+1] == 'T') {
                strcpy(proteins[num_protein_seq], "phe");
            }
            else if(dna[i+1] == 'C') {
                strcpy(proteins[num_protein_seq], "ser");
            }
            else if(dna[i+1] == 'A') {
                if(dna[i+2] == 'A' || dna[i+2] == 'G') {
                    strcpy(proteins[num_protein_seq], randam_num==0?"lys":"stop");
                }
                else {
                    strcpy(proteins[num_protein_seq], "leu");
                }
            }
            else if(dna[i+1] == 'G') {
                strcpy(proteins[num_protein_seq], "cys");
            }
        }
        else if(dna[i] == 'C') {
            if(dna[i+1] == 'T') {
                strcpy(proteins[num_protein_seq], "leu");
            }
            else if(dna[i+1] == 'C') {
                strcpy(proteins[num_protein_seq], "pro");
            }
            else if(dna[i+1] == 'A') {
                if(dna[i+2] == 'A' || dna[i+2] == 'G') {
                    strcpy(proteins[num_protein_seq], "gln");
                }
                else {
                    strcpy(proteins[num_protein_seq], "his");
                }
            }
            else if(dna[i+1] == 'G') {
                strcpy(proteins[num_protein_seq], "arg");
            }
        }
        else if(dna[i] == 'G') {
            if(dna[i+1] == 'T') {
                strcpy(proteins[num_protein_seq], "val");
            }
            else if(dna[i+1] == 'C') {
                strcpy(proteins[num_protein_seq], "ala");
            }
            else if(dna[i+1] == 'A') {
                if(dna[i+2] == 'A' || dna[i+2] == 'G') {
                    strcpy(proteins[num_protein_seq], randam_num<2?"met":"stop");
                }
                else {
                    strcpy(proteins[num_protein_seq], "asn");
                }
            }
            else if(dna[i+1] == 'G') {
                strcpy(proteins[num_protein_seq], "gly");
            }
        }
        num_protein_seq++;
    }
    
    printf("\nDNA sequence: %s\n", dna);
    printf("Protein sequence: ");
    for(i=0; i<num_protein_seq; i++) {
        printf("%s", proteins[i]);
    }
    printf("\nSimulation complete!\n");
    
    return 0;
}