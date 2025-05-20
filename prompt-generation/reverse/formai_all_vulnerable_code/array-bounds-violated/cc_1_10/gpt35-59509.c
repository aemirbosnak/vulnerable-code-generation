//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
/* 
This program takes in a file of text and performs a Shannon Entropy analysis on it.
It calculates the frequency of each unique character in the text and then calculates 
the Shannon Entropy of the file based on those frequencies. The result is output to the user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of possible characters in the ASCII table
#define MAX_CHARACTERS 256

// Define a structure for each character in the file 
typedef struct {
    char symbol;
    int frequency;
    double probability;
    double info_content;
} character;

int main(int argc, char* argv[]) {
    // Declare variables for file IO and character analysis
    FILE* input_file;
    character characters[MAX_CHARACTERS] = {0};
    int total_characters = 0;
    
    // Check for correct number of input arguments
    if (argc != 2) {
        printf("Usage: shannon_entropy <input_file>\n");
        return 1;
    }
    
    // Open the input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    
    // Read all characters from the input file and count their frequency
    char c;
    while ((c = fgetc(input_file)) != EOF) {
        characters[(int)c].frequency++;
        total_characters++;
    }
    
    // Calculate the probability of each character
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (characters[i].frequency > 0) {
            characters[i].probability = ((double)characters[i].frequency)/total_characters;
        }
    }
    
    // Calculate the Shannon Entropy of the file
    double shannon_entropy = 0.0;
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (characters[i].probability > 0.0) {
            characters[i].info_content = -1.0*log2(characters[i].probability);
            shannon_entropy += characters[i].probability * characters[i].info_content;
        }   
    }
    
    // Output the results to the user
    printf("Total characters: %d\n", total_characters);
    printf("Alphabet size: %d\n", MAX_CHARACTERS);
    printf("Symbol\tFrequency\tProbability\tInfo Content\n");
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (characters[i].frequency > 0) {
            printf("%c\t%d\t%f\t%f\n", characters[i].symbol, characters[i].frequency, characters[i].probability, characters[i].info_content);
        }
    }
    printf("Shannon Entropy: %f bits per symbol\n", shannon_entropy);
    
    // Clean up and exit
    fclose(input_file);
    return 0;
}