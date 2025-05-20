//FormAI DATASET v1.0 Category: Audio processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Audio FX Processor!\n");
    printf("Please enter the number of samples you want to process: ");
    int num_samples;
    scanf("%d", &num_samples);

    float* samples = (float*) malloc(num_samples * sizeof(float));
    if(samples == NULL) {
        printf("Oops! Memory allocation failed.\n");
        return 1;
    }

    printf("Great, now enter your audio data:\n");
    for(int i = 0; i < num_samples; i++) {
        printf("Sample %d: ", i+1);
        scanf("%f", &samples[i]);
    }

    printf("\nThanks! Now let's see what we can do with these samples...\n\n");

    printf("* First we'll amplify all the samples by a factor of 2. *\n");
    for(int i = 0; i < num_samples; i++) {
        samples[i] *= 2;
    }

    printf("...processing...\n");

    printf("* Next we'll add some white noise to the samples. *\n");
    for(int i = 0; i < num_samples; i++) {
        samples[i] += (float)(rand() / (RAND_MAX / 0.1));
    }

    printf("...processing...\n");

    printf("* Now we'll apply a low-pass filter to the samples. *\n");
    float previous_sample = samples[0];
    for(int i = 1; i < num_samples; i++) {
        float current_sample = samples[i];
        samples[i] = 0.5 * (previous_sample + current_sample);
        previous_sample = current_sample;
    }

    printf("...processing...\n");

    printf("* Finally, let's save our processed samples to a file. *\n");
    FILE* output_file = fopen("processed_audio.txt", "w");
    if(output_file == NULL) {
        printf("Oops! File creation failed.\n");
        free(samples);
        return 1;
    }

    for(int i = 0; i < num_samples; i++) {
        fprintf(output_file, "%.2f\n", samples[i]);
    }

    fclose(output_file);
    free(samples);

    printf("Done! Check out processed_audio.txt to hear your new and improved audio.\n");
    return 0;
}