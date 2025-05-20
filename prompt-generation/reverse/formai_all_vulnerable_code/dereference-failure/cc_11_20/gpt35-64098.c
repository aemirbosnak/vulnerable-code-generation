//FormAI DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 10
#define MAX_FILENAME_LEN 256
#define MAX_LABEL_LEN 16

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // Load image from file
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", filename);
        return 1;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char*) malloc(file_size);
    if (image_data == NULL) {
        fprintf(stderr, "Could not allocate memory for image data\n");
        fclose(fp);
        return 1;
    }

    // Read image data from file
    int bytes_read = fread(image_data, 1, file_size, fp);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error reading file '%s'\n", filename);
        free(image_data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // Load label data from file
    char label_filename[MAX_FILENAME_LEN];
    strncpy(label_filename, filename, MAX_FILENAME_LEN - 1);
    char *dot = strrchr(label_filename, '.');
    if (dot) {
        *dot = '\0';
    }
    strncat(label_filename, ".label", MAX_FILENAME_LEN - strlen(label_filename) - 1);
    printf("Label file: %s\n", label_filename);

    FILE *label_fp = fopen(label_filename, "r");
    if (label_fp == NULL) {
        fprintf(stderr, "Could not open label file '%s'\n", label_filename);
        free(image_data);
        return 1;
    }

    char label_str[MAX_LABEL_LEN];
    if (fgets(label_str, MAX_LABEL_LEN, label_fp) != NULL) {
        // Trim newline character from end of label string
        char *newline = strchr(label_str, '\n');
        if (newline) {
            *newline = '\0';
        }

        // Convert label string to integer
        int label = atoi(label_str);
        printf("Image label: %d\n", label);

        // Classify image
        float scores[NUM_CLASSES];
        memset(scores, 0, sizeof(scores));

        for (int i = 0; i < file_size; i++) {
            scores[i % NUM_CLASSES] += image_data[i];
        }

        int max_index = 0;
        float max_score = scores[0];
        for (int i = 1; i < NUM_CLASSES; i++) {
            if (scores[i] > max_score) {
                max_index = i;
                max_score = scores[i];
            }
        }

        printf("Predicted label: %d\n", max_index);
    }

    fclose(label_fp);
    free(image_data);

    return 0;
}