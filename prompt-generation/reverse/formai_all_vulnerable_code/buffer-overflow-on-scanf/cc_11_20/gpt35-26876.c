//FormAI DATASET v1.0 Category: Computer Biology ; Style: inquisitive
#include <stdio.h>

int main() {
    // Define variables for DNA sequence and count of each nucleotide
    char dna[100];
    int a_count = 0;
    int c_count = 0;
    int g_count = 0;
    int t_count = 0;

    // Prompt user to input the DNA sequence
    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    // Loop through each character in the DNA sequence
    for (int i = 0; i < strlen(dna); i++) {
        // Check if the character is A, C, G, or T
        if (dna[i] == 'A') {
            a_count++;
        } else if (dna[i] == 'C') {
            c_count++;
        } else if (dna[i] == 'G') {
            g_count++;
        } else if (dna[i] == 'T') {
            t_count++;
        }
    }

    // Output the count of each nucleotide
    printf("Count of A: %d\n", a_count);
    printf("Count of C: %d\n", c_count);
    printf("Count of G: %d\n", g_count);
    printf("Count of T: %d\n", t_count);

    // Check if the sequence is a palindrome
    int is_palindrome = 1;
    for (int i = 0; i < strlen(dna) / 2; i++) {
        if (dna[i] != dna[strlen(dna) - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("The sequence is a palindrome.\n");
    } else {
        printf("The sequence is not a palindrome.\n");
    }

    // Check if the sequence contains a stop codon
    int contains_stop_codon = 0;
    for (int i = 0; i < strlen(dna) - 2; i += 3) {
        if (dna[i] == 'T' && dna[i + 1] == 'A' && dna[i + 2] == 'G') {
            contains_stop_codon = 1;
            break;
        } else if (dna[i] == 'T' && dna[i + 1] == 'A' && dna[i + 2] == 'A') {
            contains_stop_codon = 1;
            break;
        } else if (dna[i] == 'T' && dna[i + 1] == 'G' && dna[i + 2] == 'A') {
            contains_stop_codon = 1;
            break;
        }
    }

    if (contains_stop_codon) {
        printf("The sequence contains a stop codon.\n");
    } else {
        printf("The sequence does not contain a stop codon.\n");
    }

    return 0;
}