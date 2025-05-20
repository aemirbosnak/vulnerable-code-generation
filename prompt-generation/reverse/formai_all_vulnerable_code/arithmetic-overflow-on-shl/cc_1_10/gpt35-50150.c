//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
/* 
This program demonstrates an example of digital signal processing in C. 
It reads a WAV file and applies a low-pass filter to the signal.
The filtered signal is then written to a new WAV file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

const int BUFF_SIZE = 1024;
const float CUTOFF_FREQ = 5000.0;
const float PI = 3.14159265358979;

void low_pass_filter(float *buffer, int buffer_size, float sample_rate, float cutoff_freq) {
    float alpha = (2.0 * PI * cutoff_freq) / sample_rate;
    float a0 = 1.0 + alpha;
    float a1 = -2.0 * cos(PI * cutoff_freq / sample_rate);
    float a2 = 1.0 - alpha;
    float b0 = (1.0 - cos(PI * cutoff_freq / sample_rate)) / 2.0;
    float b1 = 1.0 - cos(PI * cutoff_freq / sample_rate);
    float b2 = (1.0 - cos(PI * cutoff_freq / sample_rate)) / 2.0;

    float x_prev_1 = 0.0, x_prev_2 = 0.0, y_prev_1 = 0.0, y_prev_2 = 0.0;

    for (int i = 0; i < buffer_size; i++) {
        float x_curr = buffer[i];
        float y_curr = b0/a0 * x_curr + b1/a0 * x_prev_1 + b2/a0 * x_prev_2 - a1/a0 * y_prev_1 - a2/a0 * y_prev_2;
        buffer[i] = y_curr;
        x_prev_2 = x_prev_1;
        x_prev_1 = x_curr;
        y_prev_2 = y_prev_1;
        y_prev_1 = y_curr;
    }
}

int main() {
    FILE *in_file, *out_file;
    in_file = fopen("input.wav", "rb");
    out_file = fopen("output.wav", "wb");

    if (in_file == NULL) {
        printf("Error: failed to open input file.\n");
        return -1;
    }

    // Read the header of the input file
    uint8_t header[44];
    fread(header, sizeof(uint8_t), 44, in_file);

    // Parse the header of the input file
    uint32_t chunk_size = header[4] | (header[5] << 8) | (header[6] << 16) | (header[7] << 24);
    uint32_t subchunk1_size = header[16] | (header[17] << 8) | (header[18] << 16) | (header[19] << 24);
    uint16_t audio_format = header[20] | (header[21] << 8);
    uint16_t num_channels = header[22] | (header[23] << 8);
    uint32_t sample_rate = header[24] | (header[25] << 8) | (header[26] << 16) | (header[27] << 24);
    uint32_t byte_rate = header[28] | (header[29] << 8) | (header[30] << 16) | (header[31] << 24);
    uint16_t block_align = header[32] | (header[33] << 8);
    uint16_t bits_per_sample = header[34] | (header[35] << 8);
    uint32_t subchunk2_size = header[40] | (header[41] << 8) | (header[42] << 16) | (header[43] << 24);

    // Print the parameters of the input file
    printf("chunk_size = %d\n", chunk_size);
    printf("subchunk1_size = %d\n", subchunk1_size);
    printf("audio_format = %d\n", audio_format);
    printf("num_channels = %d\n", num_channels);
    printf("sample_rate = %d\n", sample_rate);
    printf("byte_rate = %d\n", byte_rate);
    printf("block_align = %d\n", block_align);
    printf("bits_per_sample = %d\n", bits_per_sample);
    printf("subchunk2_size = %d\n", subchunk2_size);

    // Allocate memory for the input and output buffers
    int16_t *in_buffer = (int16_t *) malloc(subchunk2_size);
    float *out_buffer = (float *) malloc(subchunk2_size);

    // Read the data of the input file
    fread(in_buffer, sizeof(int16_t), subchunk2_size/sizeof(int16_t), in_file);

    // Convert the input buffer from int16_t to float
    for (int i = 0; i < subchunk2_size/sizeof(int16_t); i++) {
        out_buffer[i] = (float) in_buffer[i] / (float) INT16_MAX;
    }

    // Apply the low-pass filter to the signal
    low_pass_filter(out_buffer, subchunk2_size/sizeof(float), sample_rate, CUTOFF_FREQ);

    // Convert the output buffer from float to int16_t
    for (int i = 0; i < subchunk2_size/sizeof(int16_t); i++) {
        in_buffer[i] = (int16_t) (out_buffer[i] * INT16_MAX);
    }

    // Write the header of the output file
    fwrite(header, sizeof(uint8_t), 44, out_file);

    // Write the data of the output file
    fwrite(in_buffer, sizeof(int16_t), subchunk2_size/sizeof(int16_t), out_file);

    // Free the memory of the buffers
    free(in_buffer);
    free(out_buffer);

    // Close the files
    fclose(in_file);
    fclose(out_file);

    return 0;
}