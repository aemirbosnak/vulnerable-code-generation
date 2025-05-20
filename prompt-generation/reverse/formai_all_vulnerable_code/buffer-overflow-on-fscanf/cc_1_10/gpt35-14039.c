//FormAI DATASET v1.0 Category: Image Classification system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IMAGES 1000
#define MAX_CLASSES 10
#define MAX_DIMENSION 784

// Image structure
typedef struct
{
    int pixels[MAX_DIMENSION];  // flattened pixel data
    int class;                  // class label
} Image;

// Class structure
typedef struct
{
    Image images[MAX_IMAGES];   // images belonging to this class
    int count;                  // number of images in this class
} Class;

// Dataset structure
typedef struct
{
    Class classes[MAX_CLASSES]; // classes in dataset
    int count;                  // number of classes in dataset
} Dataset;

// Function prototypes
void load_dataset(Dataset* dataset, char* filename);
double cosine_similarity(int* a, int* b, int size);
int classify_image(Image* image, Dataset* dataset);

// Main function
int main(int argc, char* argv[])
{
    // Load dataset
    Dataset dataset;
    load_dataset(&dataset, "dataset.txt");

    // Test image
    Image test_image;
    test_image.pixels[0] = 1;
    test_image.pixels[1] = 2;
    test_image.pixels[2] = 3;

    // Classify image
    int class = classify_image(&test_image, &dataset);

    // Print result
    printf("The image is classified as class %d\n", class);

    return 0;
}

// Function to load dataset from file
void load_dataset(Dataset* dataset, char* filename)
{
    // Open file
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    // Initialize dataset
    dataset->count = 0;

    // Read classes from file
    while (!feof(file))
    {
        // Read class label
        int class_label;
        fscanf(file, "%d", &class_label);

        // Create new class
        Class class;
        class.count = 0;

        // Read images belonging to class
        while (!feof(file))
        {
            // Read image pixels
            Image image;
            for (int i = 0; i < MAX_DIMENSION; i++)
            {
                fscanf(file, "%d", &image.pixels[i]);
            }

            // Set image class label
            image.class = class_label;

            // Add image to class
            class.images[class.count++] = image;

            // Check if class is full
            if (class.count == MAX_IMAGES)
            {
                break;
            }
        }

        // Add class to dataset
        dataset->classes[dataset->count++] = class;

        // Check if dataset is full
        if (dataset->count == MAX_CLASSES)
        {
            break;
        }
    }

    // Close file
    fclose(file);
}

// Function to calculate cosine similarity between two vectors
double cosine_similarity(int* a, int* b, int size)
{
    double dot_product = 0.0;
    double a_norm = 0.0;
    double b_norm = 0.0;

    for (int i = 0; i < size; i++)
    {
        dot_product += a[i] * b[i];
        a_norm += a[i] * a[i];
        b_norm += b[i] * b[i];
    }

    a_norm = sqrt(a_norm);
    b_norm = sqrt(b_norm);

    double similarity = dot_product / (a_norm * b_norm);

    return similarity;
}

// Function to classify image using nearest neighbor algorithm
int classify_image(Image* image, Dataset* dataset)
{
    int best_class = -1;
    double best_similarity = -1.0;

    // Compare image against all images in dataset
    for (int i = 0; i < dataset->count; i++)
    {
        for (int j = 0; j < dataset->classes[i].count; j++)
        {
            double similarity = cosine_similarity(image->pixels, dataset->classes[i].images[j].pixels, MAX_DIMENSION);

            if (similarity > best_similarity)
            {
                best_similarity = similarity;
                best_class = dataset->classes[i].images[j].class;
            }
        }
    }

    return best_class;
}