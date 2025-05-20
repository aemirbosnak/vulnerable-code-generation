//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_ATTRIBUTES 100
#define MAX_CLASSES 10

typedef struct {
    double attributes[MAX_ATTRIBUTES];
    int class;
} Image;

int main() {
    // Initialize the paranoia level
    int paranoia_level = 5;

    // Read the number of images and their attributes
    int num_images;
    scanf("%d", &num_images);

    Image images[num_images];
    for (int i = 0; i < num_images; i++) {
        for (int j = 0; j < MAX_ATTRIBUTES; j++) {
            scanf("%lf", &images[i].attributes[j]);
        }
        scanf("%d", &images[i].class);
    }

    // Initialize the confusion matrix
    double confusion_matrix[MAX_CLASSES][MAX_CLASSES];
    for (int i = 0; i < MAX_CLASSES; i++) {
        for (int j = 0; j < MAX_CLASSES; j++) {
            confusion_matrix[i][j] = 0;
        }
    }

    // Calculate the distances between all pairs of images
    double distances[num_images][num_images];
    for (int i = 0; i < num_images; i++) {
        for (int j = i + 1; j < num_images; j++) {
            double distance = 0;
            for (int k = 0; k < MAX_ATTRIBUTES; k++) {
                distance += pow(images[i].attributes[k] - images[j].attributes[k], 2);
            }
            distance = sqrt(distance);
            distances[i][j] = distance;
            distances[j][i] = distance;
        }
    }

    // Initialize the k-nearest neighbors classifier
    int k = 5;
    int neighbors[k];

    // Classify each image
    for (int i = 0; i < num_images; i++) {
        // Find the k-nearest neighbors of the image
        for (int j = 0; j < k; j++) {
            double min_distance = INFINITY;
            int min_index = -1;
            for (int l = 0; l < num_images; l++) {
                if (l == i) {
                    continue;
                }
                if (distances[i][l] < min_distance) {
                    min_distance = distances[i][l];
                    min_index = l;
                }
            }
            neighbors[j] = min_index;
        }

        // Count the number of votes for each class
        int votes[MAX_CLASSES];
        for (int j = 0; j < MAX_CLASSES; j++) {
            votes[j] = 0;
        }
        for (int j = 0; j < k; j++) {
            votes[images[neighbors[j]].class]++;
        }

        // Predict the class of the image
        int predicted_class = -1;
        int max_votes = -1;
        for (int j = 0; j < MAX_CLASSES; j++) {
            if (votes[j] > max_votes) {
                predicted_class = j;
                max_votes = votes[j];
            }
        }

        // Update the confusion matrix
        confusion_matrix[images[i].class][predicted_class]++;
    }

    // Calculate the accuracy of the classifier
    double accuracy = 0;
    for (int i = 0; i < MAX_CLASSES; i++) {
        accuracy += confusion_matrix[i][i];
    }
    accuracy /= num_images;

    // Print the accuracy of the classifier
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    // Print the confusion matrix
    printf("Confusion matrix:\n");
    for (int i = 0; i < MAX_CLASSES; i++) {
        for (int j = 0; j < MAX_CLASSES; j++) {
            printf("%d ", (int)confusion_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}