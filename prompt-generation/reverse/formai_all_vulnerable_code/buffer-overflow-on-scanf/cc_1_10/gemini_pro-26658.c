//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
    int spam;
} email;

double gaussian(double x, double mean, double stdev) {
    return exp(-pow(x - mean, 2) / (2 * pow(stdev, 2))) / (stdev * sqrt(2 * M_PI));
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

int main() {
    // Load the training data
    int num_emails;
    scanf("%d", &num_emails);

    email *emails = malloc(sizeof(email) * num_emails);

    for (int i = 0; i < num_emails; i++) {
        char buffer[10000];
        scanf("%[^\n]%*c", buffer);

        emails[i].text = strdup(buffer);
        emails[i].length = strlen(buffer);
        scanf("%d", &emails[i].spam);
    }

    // Calculate the mean and standard deviation of the email lengths
    double mean_length = 0;
    double stdev_length = 0;

    for (int i = 0; i < num_emails; i++) {
        mean_length += emails[i].length;
    }

    mean_length /= num_emails;

    for (int i = 0; i < num_emails; i++) {
        stdev_length += pow(emails[i].length - mean_length, 2);
    }

    stdev_length = sqrt(stdev_length / (num_emails - 1));

    // Train the logistic regression model
    double w0 = 0;
    double w1 = 0;

    for (int i = 0; i < 1000; i++) {
        double gradient_w0 = 0;
        double gradient_w1 = 0;

        for (int j = 0; j < num_emails; j++) {
            double p = sigmoid(w0 + w1 * emails[j].length);
            gradient_w0 += (emails[j].spam - p);
            gradient_w1 += (emails[j].spam - p) * emails[j].length;
        }

        w0 -= 0.001 * gradient_w0;
        w1 -= 0.001 * gradient_w1;
    }

    // Evaluate the model on the training data
    double accuracy = 0;

    for (int i = 0; i < num_emails; i++) {
        double p = sigmoid(w0 + w1 * emails[i].length);

        if ((p > 0.5 && emails[i].spam) || (p <= 0.5 && !emails[i].spam)) {
            accuracy += 1;
        }
    }

    accuracy /= num_emails;

    printf("Accuracy: %f\n", accuracy);

    // Free the memory allocated for the emails
    for (int i = 0; i < num_emails; i++) {
        free(emails[i].text);
    }

    free(emails);

    return 0;
}