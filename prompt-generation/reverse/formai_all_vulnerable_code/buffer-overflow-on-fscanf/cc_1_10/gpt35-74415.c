//FormAI DATASET v1.0 Category: Image Classification system ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Define the number of threads */
#define NUM_THREADS 4

/* Define the image data structure */
typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

/* Define the classification result data structure */
typedef struct {
    float probability;
    char *label;
} ClassificationResult;

/* Define the classification model function */
ClassificationResult classify(Image *image) {
    /* Placeholder function for classification model */
    ClassificationResult result;
    result.probability = 0.5;
    result.label = "cat";
    return result;
}

/* Define the worker thread function */
void *worker(void *thread_id) {
    long id = (long) thread_id;

    /* Read input from file */
    char input_filename[256];
    sprintf(input_filename, "input_%ld.txt", id);
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    char image_data[1024];
    fscanf(input_file, "%s", image_data);
    fclose(input_file);

    /* Parse image data */
    Image image;
    image.width = 32;
    image.height = 32;
    image.pixels = (char **) malloc(sizeof(char *) * image.height);
    for (int i = 0; i < image.height; i++) {
        image.pixels[i] = (char *) malloc(sizeof(char) * (image.width + 1));
        strncpy(image.pixels[i], image_data + i * image.width, image.width);
        image.pixels[i][image.width] = '\0';
    }

    /* Classify image */
    ClassificationResult result = classify(&image);

    /* Write output to file */
    char output_filename[256];
    sprintf(output_filename, "output_%ld.txt", id);
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    fprintf(output_file, "%f %s", result.probability, result.label);
    fclose(output_file);

    /* Free memory */
    for (int i = 0; i < image.height; i++) {
        free(image.pixels[i]);
    }
    free(image.pixels);

    pthread_exit(NULL);
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Initialize threads */
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, worker, (void *) t);
        if (rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    /* Wait for threads to complete */
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}