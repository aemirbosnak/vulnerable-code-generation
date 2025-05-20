//FormAI DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024

float lpf_filter_coef[FRAME_SIZE];
float hpf_filter_coef[FRAME_SIZE];
float buffer[FRAME_SIZE];
float filtered_buffer[FRAME_SIZE];

float frequency_to_radians(float freq) {
    return 2*M_PI*freq / SAMPLE_RATE;
}

void calculate_lpf_filter_coef(float freq) {
    for(int i=0; i<FRAME_SIZE; i++) {
        lpf_filter_coef[i] = sin(frequency_to_radians(freq) * i) / (M_PI * i);
    }
}

void apply_lpf_filter(float* input, float* output, int num_samples) {
    for(int n=0; n<num_samples; n++) {
        output[n] = 0;
        for(int i=0; i<FRAME_SIZE; i++) {
            if(n-i<0) break;
            output[n] += input[n-i] * lpf_filter_coef[i];
        }
    }
}

void calculate_hpf_filter_coef(float freq) {
    for(int i=0; i<FRAME_SIZE; i++) {
        hpf_filter_coef[i] = (sin(M_PI*i) - sin(frequency_to_radians(freq)*i)) / (M_PI * i);
    }
}

void apply_hpf_filter(float* input, float* output, int num_samples) {
    for(int n=0; n<num_samples; n++) {
        output[n] = 0;
        for(int i=0; i<FRAME_SIZE; i++) {
            if(n-i<0) break;
            output[n] += input[n-i] * hpf_filter_coef[i];
        }
    }
}

float get_rms(float* input, int num_samples) {
    float sum = 0;
    for(int i=0; i<num_samples; i++) {
        sum += pow(input[i], 2);
    }
    return sqrt(sum / num_samples);
}

int main() {
    calculate_lpf_filter_coef(1000); // Calculate low-pass filter coefficients
    calculate_hpf_filter_coef(100); // Calculate high-pass filter coefficients
    
    // Read audio data from file
    FILE* file;
    file = fopen("audio.wav", "rb");
    if(file == NULL) {
        printf("Error opening file");
        exit(1);
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Read WAV header
    unsigned char header[44];
    fread(header, sizeof(unsigned char), 44, file);
    
    // Read audio data
    int num_samples = (file_size - 44) / sizeof(float);
    float* audio_data = malloc(num_samples * sizeof(float));
    fread(audio_data, sizeof(float), num_samples, file);
    
    // Apply low-pass and high-pass filters
    apply_lpf_filter(audio_data, buffer, num_samples);
    apply_hpf_filter(buffer, filtered_buffer, num_samples);
    
    // Write filtered audio data to file
    FILE* outfile;
    outfile = fopen("filtered_audio.wav", "wb");
    fwrite(header, sizeof(unsigned char), 44, outfile);
    fwrite(filtered_buffer, sizeof(float), num_samples, outfile);
    
    fclose(file);
    fclose(outfile);
    
    // Print RMS values
    printf("RMS of original audio: %f\n", get_rms(audio_data, num_samples));
    printf("RMS of filtered audio: %f\n", get_rms(filtered_buffer, num_samples));
    
    free(audio_data);
    
    return 0;
}