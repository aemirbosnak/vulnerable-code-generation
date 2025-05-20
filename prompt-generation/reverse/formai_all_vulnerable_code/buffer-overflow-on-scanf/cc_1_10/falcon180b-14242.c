//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 5
#define MAX_FEATURES 10

typedef struct {
    char name[20];
    int num_features;
    float *features;
} Class;

void load_classes(Class *classes, int num_classes, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading classes\n");
        exit(1);
    }
    for (int i = 0; i < num_classes; i++) {
        fscanf(fp, "%s %d", classes[i].name, &classes[i].num_features);
        classes[i].features = (float *)malloc(classes[i].num_features * sizeof(float));
        for (int j = 0; j < classes[i].num_features; j++) {
            fscanf(fp, "%f", &classes[i].features[j]);
        }
    }
    fclose(fp);
}

int classify(Class *classes, int num_classes, float *features) {
    int best_class = -1;
    float best_score = -1.0;
    for (int i = 0; i < num_classes; i++) {
        float score = 0.0;
        for (int j = 0; j < classes[i].num_features; j++) {
            score += features[j] * classes[i].features[j];
        }
        if (score > best_score) {
            best_class = i;
            best_score = score;
        }
    }
    return best_class;
}

int main() {
    Class classes[MAX_CLASSES];
    int num_classes = 0;
    char filename[20];
    printf("Enter number of classes: ");
    scanf("%d", &num_classes);
    printf("Enter name of class file: ");
    scanf("%s", filename);
    load_classes(classes, num_classes, filename);
    int num_features = 0;
    printf("Enter number of features: ");
    scanf("%d", &num_features);
    float *features = (float *)malloc(num_features * sizeof(float));
    printf("Enter features:\n");
    for (int i = 0; i < num_features; i++) {
        scanf("%f", &features[i]);
    }
    int best_class = classify(classes, num_classes, features);
    printf("Best class: %s\n", classes[best_class].name);
    return 0;
}