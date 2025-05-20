//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum file size for compression

void compress(char* input_file, char* output_file) { // compression code function

    FILE* input = fopen(input_file, "rb"); // open binary input file
    FILE* output = fopen(output_file, "wb"); // open binary output file

    if (!input || !output) { // check if input/output files are valid
        printf("Error: invalid input/output files.\n");
        return;
    }

    fseek(input, 0, SEEK_END); // move input file pointer to end of file
    int size = ftell(input); // get file size in bytes
    rewind(input); // move input file pointer back to beginning of file

    char* buffer = (char*) malloc((size + 1) * sizeof(char)); // allocate memory for buffer to hold file contents
    if (!buffer) { // check if buffer allocation was successful
        printf("Error: memory allocation failed.\n");
        fclose(input);
        fclose(output);
        return;
    }

    fread(buffer, 1, size, input); // read input file contents into buffer
    buffer[size] = '\0'; // add null terminator to end of buffer

    int freq[256] = {0}; // initialize frequency array with zeroes
    for (int i = 0; i < size; i++) { // loop through buffer
        freq[buffer[i]]++; // increment frequency of each character
    }

    int unique = 0; // count number of unique characters
    for (int i = 0; i < 256; i++) { // loop through frequency array
        if (freq[i] > 0) { // check if character has non-zero frequency
            unique++; // increment unique character count
        }
    }

    unsigned char* characters = (unsigned char*) malloc(unique * sizeof(unsigned char)); // allocate memory for array of unique characters
    int* frequencies = (int*) malloc(unique * sizeof(int)); // allocate memory for array of character frequencies
    int index = 0;
    for (int i = 0; i < 256; i++) { // loop through frequency array
        if (freq[i] > 0) { // check if character has non-zero frequency
            characters[index] = i; // add character to array of unique characters
            frequencies[index] = freq[i]; // add character frequency to array of frequencies
            index++; // increment index
        }
    }

    fwrite(&unique, sizeof(int), 1, output); // write number of unique characters to output file

    for (int i = 0; i < unique; i++) { // loop through array of unique characters
        fwrite(&characters[i], sizeof(unsigned char), 1, output); // write each unique character to output file
        fwrite(&frequencies[i], sizeof(int), 1, output); // write frequency of each unique character to output file
    }

    int bits = 0; // bits variable keeps track of number of bits written
    unsigned char byte = 0; // byte variable holds bytes to be written to output file
    for (int i = 0; i < size; i++) { // loop through buffer
        int pos = -1;
        for (int j = 0; j < unique; j++) { // loop through array of unique characters
            if (characters[j] == buffer[i]) { // check if current character matches unique character
                pos = j; // set pos to index of unique character
                break;
            }
        }
        int freq_pos = frequencies[pos]; // get frequency of unique character at index pos
        for (int j = 0; j < freq_pos; j++) { // loop through frequency of unique character
            byte <<= 1; // shift byte left by 1 bit
            if (++bits == 8) { // check if 8 bits have been written to byte
                fwrite(&byte, sizeof(unsigned char), 1, output); // write byte to output file
                byte = 0; // reset byte to zero
                bits = 0; // reset bits to zero
            }
        }
    }

    if (bits > 0) { // check if all bits have been written to byte
        byte <<= (8 - bits); // shift byte left by remaining bits and pad with zeroes
        fwrite(&byte, sizeof(unsigned char), 1, output); // write final byte to output file
    }

    printf("Compression successful!\n");

    free(buffer); // free memory allocated for buffer
    free(characters); // free memory allocated for array of unique characters
    free(frequencies); // free memory allocated for array of character frequencies
    fclose(input); // close input file
    fclose(output); // close output file
}

int main() {
    char input_file[100];
    char output_file[100];
    printf("Enter name of input file: ");
    scanf("%s", input_file);
    printf("Enter name of output file: ");
    scanf("%s", output_file);
    compress(input_file, output_file);
    return 0;
}