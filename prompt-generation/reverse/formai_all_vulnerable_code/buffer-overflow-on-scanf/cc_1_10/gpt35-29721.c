//FormAI DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

//Function to read audio file
void read_audio_file(FILE *audio_file, int *audio_samples, int array_size){
    for(int i=0; i<array_size; i++){
        fscanf(audio_file, "%d", &audio_samples[i]);
    }
}

//Function to write audio file
void write_audio_file(FILE *audio_file, int *audio_samples, int array_size){
    for(int i=0; i<array_size; i++){
        fprintf(audio_file, "%d ", audio_samples[i]);
    }
}

//Function to add echo effect to audio
void add_echo(int *audio_samples, int array_size, int delay_samples, float echo_decay){
    for(int i=delay_samples; i<array_size; i++){
        audio_samples[i] += (int)(echo_decay * audio_samples[i-delay_samples]);
    }
}

int main(){
    FILE *audio_file;
    int num_samples, sample_rate, delay_samples, echo_decay_percent;
    char file_name[50];

    printf("Enter audio file name: ");
    scanf("%s", file_name);

    audio_file = fopen(file_name, "r");
    if(audio_file == NULL) {
        printf("Error: File not found.");
        exit(1);
    }

    printf("Enter number of samples in audio: ");
    scanf("%d", &num_samples);

    printf("Enter sample rate in Hz: ");
    scanf("%d", &sample_rate);

    printf("Enter delay in milliseconds for echo effect: ");
    scanf("%d", &delay_samples);

    printf("Enter echo decay (0-100%%): ");
    scanf("%d", &echo_decay_percent);
    float echo_decay = echo_decay_percent / 100.0;

    int *audio_samples = (int*)malloc(num_samples * sizeof(int));
    if(audio_samples == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    read_audio_file(audio_file, audio_samples, num_samples);

    add_echo(audio_samples, num_samples, (int)(delay_samples * sample_rate / 1000.0), echo_decay);

    fclose(audio_file);

    char output_file_name[50];
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    audio_file = fopen(output_file_name, "w");
    if(audio_file == NULL) {
        printf("Error: File creation failed.");
        exit(1);
    }

    write_audio_file(audio_file, audio_samples, num_samples);

    fclose(audio_file);

    free(audio_samples);

    return 0;
}