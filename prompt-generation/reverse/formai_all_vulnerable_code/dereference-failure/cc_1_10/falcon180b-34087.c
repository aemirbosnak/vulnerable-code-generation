//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the hash function
void hash(const char* input, char* output) {
    SHA_CTX sha;
    SHA1_Init(&sha);
    SHA1_Update(&sha, input, strlen(input));
    SHA1_Final(output, &sha);
}

// Define the main function
int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s [input] [output]\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Allocate memory for the input buffer
    char* input_buffer = NULL;
    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    rewind(input_file);
    input_buffer = malloc(input_size + 1);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        fclose(input_file);
        return 1;
    }

    // Read the input file into the buffer
    fread(input_buffer, input_size, 1, input_file);
    input_buffer[input_size] = '\0';
    fclose(input_file);

    // Hash the input buffer
    char output_buffer[SHA_DIGEST_LENGTH];
    hash(input_buffer, output_buffer);

    // Open the output file
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        free(input_buffer);
        return 1;
    }

    // Write the hash to the output file
    fprintf(output_file, "%s\n", output_buffer);
    fclose(output_file);

    // Free the input buffer
    free(input_buffer);

    return 0;
}