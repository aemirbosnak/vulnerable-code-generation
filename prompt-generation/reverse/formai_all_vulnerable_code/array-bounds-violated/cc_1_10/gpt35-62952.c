//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
//Genius C Compression Algorithms Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 //Maximum size of input string

char* compress(char* input) {
    int freq_table[256] = {0}; //Frequency table to store frequency of each character in input string
    int len = strlen(input);

    for(int i=0; i<len; i++) {
        freq_table[input[i]]++;
    }

    int unique_chars = 0;
    for(int i=0; i<256; i++) {
        if(freq_table[i] > 0) {
            unique_chars++;
        }
    }

    int encoded_len = unique_chars + (2 * (len - unique_chars)); //Encoded length is total unique characters plus 2 times the difference between total length and unique characters
    char* encoded_str = (char*)malloc(encoded_len * sizeof(char)); //Allocate memory for encoded string

    int index = 0;
    for(int i=0; i<len; i++) {
        int freq = freq_table[input[i]];
        if(freq > 0) { //If character is not yet compressed
            sprintf(&encoded_str[index], "%c%d", input[i], freq); //Compress character using frequency count and store in encoded string
            index += 2; //Move to next index in encoded string
            freq_table[input[i]] = 0; //Mark character as compressed by setting its frequency to 0
        }
    }

    encoded_str[index] = '\0'; //Add null character at the end of encoded string

    return encoded_str;
}

int main() {
    char input[MAX_SIZE];

    printf("Enter string to be compressed: ");
    fgets(input, MAX_SIZE, stdin); //Read input string

    char* compressed_str = compress(input); //Compress input string

    printf("Compressed string: %s\n", compressed_str);

    free(compressed_str); //Free allocated memory

    return 0;
}