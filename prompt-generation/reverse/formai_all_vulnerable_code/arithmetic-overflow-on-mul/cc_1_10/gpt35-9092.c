//FormAI DATASET v1.0 Category: Audio processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants
#define BUFFER_SIZE 1024
#define SAMPLING_RATE 44100
#define PI 3.14159265358979323846

int main(){
    // Initialize variables
    char filename[BUFFER_SIZE];
    int seconds;
    int frequency;
    int volume;
    
    printf("Welcome to the Audio Processing Program - Post-Apocalyptic Style\n");
    printf("Enter filename for your audio file (max %d characters): ", BUFFER_SIZE);
    fgets(filename, BUFFER_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character from filename
    
    printf("Enter length of audio clip in seconds: ");
    scanf("%d", &seconds);
    
    printf("Enter frequency of sound (Hz): ");
    scanf("%d", &frequency);
    
    printf("Enter volume of sound (0-100): ");
    scanf("%d", &volume);
    
    // Calculate number of samples needed
    int num_samples = SAMPLING_RATE * seconds;
    
    // Allocate memory for buffer
    double *buffer = malloc(sizeof(double) * num_samples);
    
    // Generate sine wave audio data
    for(int i = 0; i < num_samples; i++){
        buffer[i] = sin(2 * PI * frequency * i / SAMPLING_RATE);
    }
    
    // Normalize audio data
    double max_val = 0;
    for(int i = 0; i < num_samples; i++){
        if(fabs(buffer[i]) > max_val){
            max_val = fabs(buffer[i]);
        }
    }
    double normalization_factor = 1 / max_val;
    for(int i = 0; i < num_samples; i++){
        buffer[i] *= normalization_factor;
    }
    
    // Apply volume to audio data
    double volume_factor = volume / 100.0;
    for(int i = 0; i < num_samples; i++){
        buffer[i] *= volume_factor;
    }
    
    // Write audio data to file
    FILE *file = fopen(filename, "wb");
    fwrite(buffer, sizeof(double), num_samples, file);
    fclose(file);
    
    printf("Audio processing complete. Your audio file '%s' has been saved.\n", filename);
    free(buffer);
    return 0;
}