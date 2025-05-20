//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_SAMPLES 1000
#define MAX_FEATURES 100

typedef struct {
    int id;
    char name[50];
    int features[MAX_FEATURES];
    int num_features;
} Class;

typedef struct {
    int id;
    int class_id;
    int features[MAX_FEATURES];
    int num_features;
} Sample;

int main() {
    // Initialize classes
    Class classes[MAX_CLASSES];
    int num_classes = 0;

    // Initialize samples
    Sample samples[MAX_SAMPLES];
    int num_samples = 0;

    // Read classes from file
    FILE* fp = fopen("classes.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open classes file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int id, num_features;
        char name[50];
        sscanf(line, "%d %s %d", &id, name, &num_features);

        Class c;
        c.id = id;
        c.name[0] = '\0';
        strcat(c.name, name);
        c.num_features = num_features;
        for (int i = 0; i < num_features; i++) {
            fscanf(fp, "%d", &c.features[i]);
        }

        classes[num_classes++] = c;
    }

    fclose(fp);

    // Read samples from file
    fp = fopen("samples.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open samples file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int id, class_id, num_features;
        sscanf(line, "%d %d %d", &id, &class_id, &num_features);

        Sample s;
        s.id = id;
        s.class_id = class_id;
        s.num_features = num_features;
        for (int i = 0; i < num_features; i++) {
            fscanf(fp, "%d", &s.features[i]);
        }

        samples[num_samples++] = s;
    }

    fclose(fp);

    // Perform classification
    for (int i = 0; i < num_samples; i++) {
        int max_score = 0;
        int max_class_id = -1;

        for (int j = 0; j < num_classes; j++) {
            int score = 0;

            for (int k = 0; k < samples[i].num_features; k++) {
                int f = samples[i].features[k];
                int c_f = classes[j].features[k];

                if (f == c_f) {
                    score++;
                }
            }

            if (score > max_score) {
                max_score = score;
                max_class_id = classes[j].id;
            }
        }

        printf("Sample %d classified as class %d with score %d.\n", samples[i].id, max_class_id, max_score);
    }

    return 0;
}