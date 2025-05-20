//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *audio_file;
    FILE *output_file;
    float sample_rate, sample_width, block_size;
    short int *input_buffer, *output_buffer, *block_buffer;
    int frames_read, frames_written;
    int frame_count;

    if ( (audio_file = fopen("input.wav", "rb")) == NULL ) {
        printf("Error opening input file.\n");
        return 1;
    }

    if ( (output_file = fopen("output.wav", "wb")) == NULL ) {
        printf("Error opening output file.\n");
        fclose(audio_file);
        return 1;
    }

    fseek(audio_file, 0L, SEEK_END);
    frames_read = ftell(audio_file);
    fseek(audio_file, 0L, SEEK_SET);

    sample_rate = 44100;
    sample_width = 2;
    block_size = 1024;

    input_buffer = (short int*)malloc(block_size * sizeof(short int));
    output_buffer = (short int*)malloc(block_size * sizeof(short int));
    block_buffer = (short int*)malloc(block_size * sizeof(short int));

    while ( frames_read > 0 ) {
        frames_read = fread(input_buffer, sample_width, block_size, audio_file);
        if ( frames_read!= block_size ) {
            printf("Error reading audio file.\n");
            break;
        }

        frames_written = fwrite(block_buffer, sample_width, block_size, output_file);
        if ( frames_written!= block_size ) {
            printf("Error writing audio file.\n");
            break;
        }

        for (int i = 0; i < block_size; i++) {
            float amplitude = (float)input_buffer[i] / 32767.0;
            if (amplitude > 0.5) {
                output_buffer[i] = (short int)(32767.0 * amplitude);
            }
            else {
                output_buffer[i] = (short int)(32767.0 * (1.0 - amplitude));
            }
        }

        for (int i = 0; i < block_size; i++) {
            float amplitude = (float)output_buffer[i] / 32767.0;
            if (amplitude > 0.5) {
                block_buffer[i] = (short int)(32767.0 * amplitude);
            }
            else {
                block_buffer[i] = (short int)(32767.0 * (1.0 - amplitude));
            }
        }

        frames_written = fwrite(block_buffer, sample_width, block_size, output_file);
        if ( frames_written!= block_size ) {
            printf("Error writing audio file.\n");
            break;
        }
    }

    fclose(audio_file);
    fclose(output_file);
    free(input_buffer);
    free(output_buffer);
    free(block_buffer);

    return 0;
}