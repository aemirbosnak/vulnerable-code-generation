//FormAI DATASET v1.0 Category: Image Classification system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CLASSES 10
#define MAX_SAMPLES 1000
#define MAX_FEATURES 50

typedef struct sample {
    double features[MAX_FEATURES];
    int label;
} Sample;

typedef struct model {
    double weights[MAX_FEATURES];
    double bias;
} Model;

int main() {
    int num_classes, num_features, num_samples, num_epochs;
    double learning_rate;
    printf("Enter number of classes (max %d): ", MAX_CLASSES);
    scanf("%d", &num_classes);
    printf("Enter number of features (max %d): ", MAX_FEATURES);
    scanf("%d", &num_features);
    printf("Enter number of samples (max %d): ", MAX_SAMPLES);
    scanf("%d", &num_samples);
    printf("Enter number of epochs: ");
    scanf("%d", &num_epochs);
    printf("Enter learning rate: ");
    scanf("%lf", &learning_rate);

    // Initialize samples
    Sample samples[num_samples];
    for (int i = 0; i < num_samples; i++) {
        printf("Enter features for sample %d:\n", i+1);
        for (int j = 0; j < num_features; j++) {
            scanf("%lf", &samples[i].features[j]);
        }
        printf("Enter label for sample %d (0-%d): ", i+1, num_classes-1);
        scanf("%d", &samples[i].label);
    }

    // Train model
    Model models[num_classes];
    for (int c = 0; c < num_classes; c++) {
        models[c].bias = 0;
        for (int j = 0; j < num_features; j++) {
            models[c].weights[j] = 0;
        }
        for (int epoch = 0; epoch < num_epochs; epoch++) {
            for (int i = 0; i < num_samples; i++) {
                Sample s = samples[i];
                double y_pred = 0;
                for (int j = 0; j < num_features; j++) {
                    y_pred += s.features[j] * models[c].weights[j];
                }
                y_pred += models[c].bias;
                if (s.label == c) {
                    models[c].bias += learning_rate * (1 - y_pred);
                } else {
                    models[c].bias += learning_rate * (0 - y_pred);
                }
                for (int j = 0; j < num_features; j++) {
                    if (s.label == c) {
                        models[c].weights[j] += learning_rate * (1 - y_pred) * s.features[j];
                    } else {
                        models[c].weights[j] += learning_rate * (0 - y_pred) * s.features[j];
                    }
                }
            }
        }
    }

    // Test model
    int num_correct = 0;
    for (int i = 0; i < num_samples; i++) {
        Sample s = samples[i];
        int pred_label = -1;
        double max_score = -INFINITY;
        for (int c = 0; c < num_classes; c++) {
            double score = 0;
            for (int j = 0; j < num_features; j++) {
                score += s.features[j] * models[c].weights[j];
            }
            score += models[c].bias;
            if (score > max_score) {
                max_score = score;
                pred_label = c;
            }
        }
        if (pred_label == s.label) {
            num_correct++;
        }
    }

    printf("Accuracy: %.2f%%\n", 100.0 * num_correct / num_samples);

    return 0;
}