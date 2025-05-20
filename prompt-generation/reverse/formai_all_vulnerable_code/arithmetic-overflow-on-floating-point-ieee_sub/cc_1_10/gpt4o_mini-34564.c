//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0  // Frequency of sine wave
#define NUM_SAMPLES 44100 // Number of samples for 1 second
#define CUTOFF_FREQ 1000.0 // Cut-off frequency for the low-pass filter

// Function to generate a sine wave and write to pipe
void generateSineWave(int writePipe) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        float sample = sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);
        write(writePipe, &sample, sizeof(float));
    }
    close(writePipe); // Close the write end of the pipe
}

// Function to apply a simple low-pass filter on the incoming samples
void lowPassFilter(int readPipe) {
    float sample;
    float lastFilteredSample = 0.0;
    float alpha = (2 * M_PI * CUTOFF_FREQ) / SAMPLE_RATE; // Time constant for filter

    while (read(readPipe, &sample, sizeof(float)) > 0) {
        // Apply low-pass filter
        lastFilteredSample += alpha * (sample - lastFilteredSample);
        printf("%f\n", lastFilteredSample); // Output the filtered sample
    }
    close(readPipe); // Close the read end of the pipe
}

int main() {
    int pipefd[2];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // In the child process, generate sine wave
    if (pid == 0) {
        close(pipefd[0]);  // Close the read end
        generateSineWave(pipefd[1]);
        exit(EXIT_SUCCESS);
    } 
    // In the parent process, apply low-pass filter
    else {
        close(pipefd[1]);  // Close the write end
        lowPassFilter(pipefd[0]);
        wait(NULL); // Wait for child to finish
    }

    return 0;
}