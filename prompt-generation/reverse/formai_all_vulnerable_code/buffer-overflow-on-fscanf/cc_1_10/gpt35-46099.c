//FormAI DATASET v1.0 Category: Image Classification system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define NUM_CLASSES 5
#define NUM_FEATURES 10

/* Define struct for image */
typedef struct {
    char filename[50];
    int label;
    float features[NUM_FEATURES];
} Image;

/* Define struct for class */
typedef struct {
    char name[20];
    int num_images;
    Image *images;
} Class;

/* Function to read images from file */
void read_images(Class *classes, int num_classes) {
    FILE *infile;
    char filename[50];
    int label;
    float feature;

    /* Loop through each class */
    for (int i = 0; i < num_classes; i++) {
        sprintf(filename, "class%d.txt", i+1);
        infile = fopen(filename, "r");

        /* Read class name */
        fscanf(infile, "%s", classes[i].name);

        /* Read number of images */
        fscanf(infile, "%d", &classes[i].num_images);

        /* Allocate memory for images */
        classes[i].images = (Image *) malloc(classes[i].num_images * sizeof(Image));

        /* Loop through each image */
        for (int j = 0; j < classes[i].num_images; j++) {
            /* Read image filename */
            fscanf(infile, "%s", classes[i].images[j].filename);

            /* Set label to current class */
            label = i;

            /* Read image features */
            for (int k = 0; k < NUM_FEATURES; k++) {
                fscanf(infile, "%f", &feature);
                classes[i].images[j].features[k] = feature;
            }

            /* Set image label */
            classes[i].images[j].label = label;
        }

        /* Close file */
        fclose(infile);
    }
}

/* Function to calculate Euclidean distance */
float euclidean_distance(float *v1, float *v2, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(sum);
}

/* Function to classify image */
int classify_image(Image *test_image, Class *classes, int num_classes) {
    float min_distance = -1.0;
    int predicted_label = -1;
    float distance;

    /* Loop through each class */
    for (int i = 0; i < num_classes; i++) {
        /* Loop through each image in class */
        for (int j = 0; j < classes[i].num_images; j++) {
            /* Calculate Euclidean distance between features */
            distance = euclidean_distance(test_image->features, classes[i].images[j].features, NUM_FEATURES);

            /* If distance is less than current minimum, update predicted label */
            if (min_distance < 0 || distance < min_distance) {
                min_distance = distance;
                predicted_label = i;
            }
        }
    }

    return predicted_label;
}

int main() {
    /* Initialize variables */
    int num_classes = NUM_CLASSES;
    Class *classes = (Class *) malloc(num_classes * sizeof(Class));
    Image test_image;

    /* Read images from file */
    read_images(classes, num_classes);

    /* Set test image features */
    test_image.features[0] = 1.2;
    test_image.features[1] = 4.5;
    test_image.features[2] = 3.2;
    test_image.features[3] = 5.6;
    test_image.features[4] = 2.1;
    test_image.features[5] = 6.5;
    test_image.features[6] = 3.7;
    test_image.features[7] = 4.2;
    test_image.features[8] = 5.9;
    test_image.features[9] = 2.4;

    /* Classify test image */
    int predicted_label = classify_image(&test_image, classes, num_classes);

    /* Print predicted label */
    printf("Predicted label: %d (%s)\n", predicted_label, classes[predicted_label].name);

    /* Free memory */
    for (int i = 0; i < num_classes; i++) {
        free(classes[i].images);
    }
    free(classes);

    return 0;
}