//FormAI DATASET v1.0 Category: Image Classification system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR 256
#define NUM_FEATURES 10
#define NUM_CLASSES 5

typedef struct {
    double features[NUM_FEATURES];
    int label;
} Sample;

typedef struct {
    double weights[NUM_FEATURES];
} Model;

void read_data(Sample *samples, int n_samples, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n_samples; i++) {
        Sample s;
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(fp, "%lf", &s.features[j]);
        }
        fscanf(fp, "%d", &s.label);
        samples[i] = s;
    }
    fclose(fp);
}

void train(Model *model, Sample *samples, int n_samples, int max_iter, double learning_rate) {
    for (int iter = 0; iter < max_iter; iter++) {
        double total_error = 0;
        for (int i = 0; i < n_samples; i++) {
            Sample s = samples[i];
            double pred = 0;
            for (int j = 0; j < NUM_FEATURES; j++) {
                pred += s.features[j] * model->weights[j];
            }
            double error = s.label - pred; 
            total_error += error * error;
            for (int j = 0; j < NUM_FEATURES; j++) {
                model->weights[j] += learning_rate * error * s.features[j];
            }
        }
        printf("Iteration %d: Error = %.2f\n", iter + 1, total_error);
    }
}

int predict(Model *model, Sample s) {
    double pred = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        pred += s.features[i] * model->weights[i];
    }
    return (int) round(pred);
}

void evaluate(Model *model, Sample *samples, int n_samples) {
    int correct = 0;
    for (int i = 0; i < n_samples; i++) {
        Sample s = samples[i];
        int pred = predict(model, s);
        if (pred == s.label) {
            correct++;
        }
    }
    double accuracy = (double) correct / n_samples * 100;
    printf("Accuracy = %.2f%%\n", accuracy);
}

int main() {
    Sample samples[1000];
    read_data(samples, 1000, "data.txt");

    Model model;
    memset(model.weights, 0, sizeof(model.weights));

    train(&model, samples, 1000, 100, 0.01);

    evaluate(&model, samples, 1000);

    return 0;
}