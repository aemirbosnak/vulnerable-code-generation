//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Audio processing program to add a basic echo effect to a sound file */

#define FILENAME "input.wav"
#define ECHO_FILENAME "output_echo.wav"
#define ECHO_DELAY_MS 500
#define ECHO_ATTENUATION 0.4

int main() {
    FILE *fp_in, *fp_out;
    int sample_rate;
    short int num_channels, bits_per_sample;
    unsigned int header_size, chunk_size, data_size;
    unsigned char header[44];
    unsigned char *data_buffer;
    unsigned int i, j, k;

    /* Open input file */
    fp_in = fopen(FILENAME, "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    /* Read header data */
    fread(header, sizeof(unsigned char), 44, fp_in);
    sample_rate = header[24] | header[25]<<8 | header[26]<<16 | header[27]<<24;
    num_channels = header[22] | header[23]<<8;
    bits_per_sample = header[34] | header[35]<<8;
    header_size = 44;
    chunk_size = header[4] | header[5]<<8 | header[6]<<16 | header[7]<<24;
    data_size = chunk_size - header_size;

    /* Allocate memory for data buffer */
    data_buffer = (unsigned char*) malloc(data_size);
    if (data_buffer == NULL) {
        printf("Error: Could not allocate memory for data buffer.\n");
        return 1;
    }

    /* Read data */
    fread(data_buffer, sizeof(unsigned char), data_size, fp_in);

    /* Close input file */
    fclose(fp_in);

    /* Calculate echo parameters */
    unsigned int echo_bytes = ((double)ECHO_DELAY_MS / 1000.0 * (double)sample_rate * (double)(bits_per_sample/8) * (double)num_channels);
    unsigned int echo_samples = echo_bytes / (bits_per_sample/8) / num_channels;
    double echo_attenuation_factor = ECHO_ATTENUATION;

    /* Calculate new data size */
    unsigned int new_data_size = data_size + echo_bytes;
    unsigned int new_chunk_size = new_data_size + header_size;

    /* Allocate memory for new data buffer */
    unsigned char *new_data_buffer = (unsigned char*) malloc(new_data_size);
    if (new_data_buffer == NULL) {
        printf("Error: Could not allocate memory for new data buffer.\n");
        return 1;
    }

    /* Add echo effect to data */
    for (i = 0; i < data_size; i+=(bits_per_sample/8)*num_channels) {
        for (j = 0; j < num_channels; j++) {
            short int current_sample = *(short int*)(data_buffer+i+j*(bits_per_sample/8));
            short int echo_sample = 0;
            if (i > echo_bytes) {
                unsigned int echo_index = i - echo_bytes + j*(bits_per_sample/8);
                echo_sample = echo_attenuation_factor * *(short int*)(new_data_buffer+echo_index);
            }
            *(short int*)(new_data_buffer+i+j*(bits_per_sample/8)) = current_sample + echo_sample;
        }
    }

    /* Copy header to new file */
    unsigned char *new_header = (unsigned char*) malloc(header_size);
    memcpy(new_header, header, header_size);

    /* Update chunk size */
    new_header[4] = new_chunk_size & 0xff;
    new_header[5] = (new_chunk_size>>8) & 0xff;
    new_header[6] = (new_chunk_size>>16) & 0xff;
    new_header[7] = (new_chunk_size>>24) & 0xff;

    /* Update data size */
    new_header[40] = new_data_size & 0xff;
    new_header[41] = (new_data_size>>8) & 0xff;
    new_header[42] = (new_data_size>>16) & 0xff;
    new_header[43] = (new_data_size>>24) & 0xff;

    /* Open output file */
    fp_out = fopen(ECHO_FILENAME, "wb");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    /* Write header to output file */
    fwrite(new_header, sizeof(unsigned char), header_size, fp_out);

    /* Write data to output file */
    fwrite(new_data_buffer, sizeof(unsigned char), new_data_size, fp_out);

    /* Close output file */
    fclose(fp_out);

    /* Free memory */
    free(data_buffer);
    free(new_data_buffer);
    free(new_header);

    printf("Echo effect successfully added to audio file.\n");

    return 0;
}