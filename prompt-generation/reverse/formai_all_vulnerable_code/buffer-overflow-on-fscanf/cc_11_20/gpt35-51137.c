//FormAI DATASET v1.0 Category: Image Classification system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of classes and the maximum number of samples
#define MAX_CLASSES 10
#define MAX_SAMPLES 100

// define the structure for a sample
typedef struct {
    int features[50];
    int num_features;
    int class;
} Sample;

// define the structure for a class
typedef struct {
    Sample samples[MAX_SAMPLES];
    int num_samples;
} Class;

// define the main function
int main() {
    // initialize the classes and the samples
    Class classes[MAX_CLASSES];
    Sample samples[MAX_SAMPLES];

    // read in the data from a file and populate the sample and class arrays
    FILE *fp;
    fp = fopen("data.txt", "r");

    int num_classes, num_samples;
    fscanf(fp, "%d %d", &num_classes, &num_samples);

    for (int i = 0; i < num_samples; i++) {
        Sample sample;
        sample.num_features = 0;

        for (int j = 0; j < 50; j++) {
            int feature;
            fscanf(fp, "%d", &feature);

            if (feature == -1) {
                break;
            }

            sample.features[j] = feature;
            sample.num_features++;
        }

        fscanf(fp, "%d", &sample.class);

        samples[i] = sample;
        classes[sample.class].samples[classes[sample.class].num_samples] = sample;
        classes[sample.class].num_samples++;
    }

    fclose(fp);

    // run the classification algorithm
    int classified_samples = 0;

    while (classified_samples < num_samples) {
        // find the class with the most common feature
        int most_common_feature = -1;
        int most_common_feature_count = 0;
        int most_common_feature_class = -1;

        for (int i = 0; i < num_classes; i++) {
            int feature_counts[50] = {0};

            for (int j = 0; j < classes[i].num_samples; j++) {
                Sample sample = classes[i].samples[j];

                for (int k = 0; k < sample.num_features; k++) {
                    feature_counts[sample.features[k]]++;
                }
            }

            for (int j = 0; j < 50; j++) {
                if (feature_counts[j] > most_common_feature_count) {
                    most_common_feature = j;
                    most_common_feature_count = feature_counts[j];
                    most_common_feature_class = i;
                }
            }
        }

        // classify each sample with the most common feature as the class with the most common feature
        for (int i = 0; i < num_samples; i++) {
            Sample sample = samples[i];

            if (sample.class == -1) {
                for (int j = 0; j < sample.num_features; j++) {
                    if (sample.features[j] == most_common_feature) {
                        sample.class = most_common_feature_class;
                        classes[most_common_feature_class].samples[classes[most_common_feature_class].num_samples] = sample;
                        classes[most_common_feature_class].num_samples++;
                        classified_samples++;
                        break;
                    }
                }
            }
        }
    }

    // print out the results
    for (int i = 0; i < num_classes; i++) {
        printf("Class %d: %d samples\n", i, classes[i].num_samples);

        for (int j = 0; j < classes[i].num_samples; j++) {
            Sample sample = classes[i].samples[j];
            printf("Sample %d: [", j);

            for (int k = 0; k < sample.num_features; k++) {
                printf("%d, ", sample.features[k]);
            }

            printf("] Class: %d\n", i);
        }
    }

    return 0;
}