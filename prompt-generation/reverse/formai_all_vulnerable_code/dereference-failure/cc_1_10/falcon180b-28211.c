//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 1000000
#define MAX_DELAY 5000
#define SAMPLE_RATE 44100

#define PI 3.14159265358979323846

typedef struct {
    double *data;
    int length;
    int maxLength;
} DelayLine;

void initDelayLine(DelayLine *delay, int length) {
    delay->data = (double*) malloc(length * sizeof(double));
    delay->length = 0;
    delay->maxLength = length;
}

void freeDelayLine(DelayLine *delay) {
    free(delay->data);
}

void clearDelayLine(DelayLine *delay) {
    memset(delay->data, 0, delay->maxLength * sizeof(double));
    delay->length = 0;
}

void writeDelayLine(DelayLine *delay, double value) {
    if (delay->length >= delay->maxLength) {
        return;
    }
    delay->data[delay->length++] = value;
}

double readDelayLine(DelayLine *delay, int index) {
    if (index >= delay->length) {
        return 0;
    }
    return delay->data[index];
}

void processAudio(double *input, double *output, int length, DelayLine *delay, double feedback, double wetDryMix) {
    double drySignal = 1 - wetDryMix;
    double wetSignal = wetDryMix;
    for (int i = 0; i < length; i++) {
        double inputSample = input[i];
        double delaySample = readDelayLine(delay, (int) ((double) delay->length * feedback));
        double wetSample = inputSample * wetSignal + delaySample * feedback;
        output[i] = (drySignal * inputSample) + (wetSample * wetSignal);
        writeDelayLine(delay, wetSample);
    }
}

int main() {
    int length = MAX_LENGTH;
    double sampleRate = SAMPLE_RATE;
    double feedback = 0.5;
    double wetDryMix = 0.5;

    double *input = (double*) malloc(length * sizeof(double));
    double *output = (double*) malloc(length * sizeof(double));

    DelayLine delay;
    initDelayLine(&delay, MAX_DELAY);

    for (int i = 0; i < length; i++) {
        input[i] = sin(2 * PI * i / sampleRate);
    }

    processAudio(input, output, length, &delay, feedback, wetDryMix);

    for (int i = 0; i < length; i++) {
        printf("%f\n", output[i]);
    }

    free(input);
    free(output);
    freeDelayLine(&delay);

    return 0;
}