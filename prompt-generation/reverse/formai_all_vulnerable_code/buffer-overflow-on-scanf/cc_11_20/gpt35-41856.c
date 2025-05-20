//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Hello, I am a biology-inspired computer program! \n");

    // Let's play a game
    printf("Let's play a guessing game. I am thinking of an amino acid that starts with the letter 'A' and has three letters. Can you guess what it is? \n");

    char guess[3];
    scanf("%s", guess);

    if (guess[0] == 'A' && guess[1] == 'l' && guess[2] == 'a') {
        printf("Congratulations, you guessed it! Alanine is a non-polar amino acid commonly found in the hydrophobic core of proteins. \n");
    }
    else {
        printf("Sorry, that's not it. The correct answer is Alanine. Better luck next time! \n");
    }

    // Now let's do some DNA sequencing
    printf("Let's sequence some DNA. Please enter a DNA sequence: \n");

    char dna_sequence[50];
    scanf("%s", dna_sequence);

    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;

    for (int i = 0; i < strlen(dna_sequence); i++) {
        if (dna_sequence[i] == 'A') {
            a_count++;
        }
        else if (dna_sequence[i] == 'C') {
            c_count++;
        }
        else if (dna_sequence[i] == 'T') {
            t_count++;
        }
        else if (dna_sequence[i] == 'G') {
            g_count++;
        }
        else {
            printf("Invalid DNA sequence! Please enter a sequence containing only A, C, T, and G. \n");
            return 1;
        }
    }

    printf("A: %d\n", a_count);
    printf("C: %d\n", c_count);
    printf("T: %d\n", t_count);
    printf("G: %d\n", g_count);

    // And finally, let's simulate some mutations
    printf("Now, let's simulate a mutation. Please enter the position of the nucleotide you would like to change (starting from 1): \n");

    int position;
    scanf("%d", &position);

    if (position < 1 || position > strlen(dna_sequence)) {
        printf("Invalid position! Please enter a position between 1 and the length of the DNA sequence (%d). \n", strlen(dna_sequence));
        return 1;
    }

    printf("Please enter the new nucleotide: \n");

    char new_nucleotide;
    scanf(" %c", &new_nucleotide);

    if (new_nucleotide != 'A' && new_nucleotide != 'C' && new_nucleotide != 'T' && new_nucleotide != 'G') {
        printf("Invalid nucleotide! Please enter A, C, T, or G. \n");
        return 1;
    }

    printf("Original DNA sequence: %s \n", dna_sequence);

    dna_sequence[position-1] = new_nucleotide;

    printf("Mutated DNA sequence: %s \n", dna_sequence);

    printf("Thanks for playing the biology-inspired computer program game!\n");

    return 0;
}