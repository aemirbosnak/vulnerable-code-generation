//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 8192

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[100];
    char output_filename[100];
    short int input_buffer[BUFFER_SIZE];
    short int output_buffer[BUFFER_SIZE];
    int i, j, k, n;
    float gain = 2.0; // Amplify the sound by 2 times.

    // Get input file name from user.
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Open input file.
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get output file name from user.
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open output file.
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read header of input file.
    fseek(input_file, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, input_file);

    // Process audio data.
    while (fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file)!= 0) {
        // Apply gain.
        for (i = 0; i < BUFFER_SIZE; i++) {
            output_buffer[i] = (short int) (gain * input_buffer[i]);
        }

        // Write processed data to output file.
        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);
    }

    // Close files.
    fclose(input_file);
    fclose(output_file);

    printf("Audio processing completed successfully.\n");

    return 0;
}