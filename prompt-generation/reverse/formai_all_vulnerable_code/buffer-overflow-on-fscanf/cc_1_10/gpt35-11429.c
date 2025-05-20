//FormAI DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VECTOR_LENGTH 1024
#define MAX_CLASSES 10

typedef struct {
    double vector[MAX_VECTOR_LENGTH];
    int label;
} Sample;

typedef struct {
    double weights[MAX_VECTOR_LENGTH];
    double bias;
} Model;

Sample samples[1000];
Model model;
int num_samples = 0;

void read_input(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    while (!feof(fp)) {
        Sample s;
        for (int i = 0; i < MAX_VECTOR_LENGTH; i++) {
            fscanf(fp, "%lf,", &s.vector[i]);
        }
        fscanf(fp, "%d", &s.label);
        samples[num_samples] = s;
        num_samples++;
    }
    fclose(fp);
}

double dot_product(double v1[], double v2[], int length) {
    double result = 0;
    for (int i = 0; i < length; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void train_model(int num_epochs, double learning_rate) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        double average_loss = 0;
        for (int i = 0; i < num_samples; i++) {
            double prediction = sigmoid(dot_product(samples[i].vector, model.weights, MAX_VECTOR_LENGTH) + model.bias);
            double error = prediction - samples[i].label;
            average_loss += fabs(error);
            for (int j = 0; j < MAX_VECTOR_LENGTH; j++) {
                model.weights[j] -= learning_rate * error * samples[i].vector[j];
            }
            model.bias -= learning_rate * error;
        }
        printf("Epoch %d loss: %f\n", epoch, average_loss / num_samples);
    }
}

int predict(Sample s) {
    double prediction = sigmoid(dot_product(s.vector, model.weights, MAX_VECTOR_LENGTH) + model.bias);
    return round(prediction);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./classifier input_file epochs\n");
        return 1;
    }
    int num_epochs = atoi(argv[2]);
    double learning_rate = 0.1;
    read_input(argv[1]);
    for (int i = 0; i < MAX_VECTOR_LENGTH; i++) {
        model.weights[i] = 0.0;
    }
    model.bias = 0.0;
    train_model(num_epochs, learning_rate);
    Sample test_sample = samples[num_samples - 1];
    printf("Prediction: %d\n", predict(test_sample));
    return 0;
}