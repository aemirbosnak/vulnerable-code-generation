//FormAI DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 256
#define MAX_LABEL_LEN 32
#define MAX_IMAGES 1000

typedef struct Image {
  char filename[MAX_FILENAME_LEN];
  char label[MAX_LABEL_LEN];
  float *pixels;
} Image;

typedef struct ImageClassificationModel {
  int num_images;
  int num_pixels;
  char *labels[MAX_IMAGES];
  float *pixels[MAX_IMAGES];
} ImageClassificationModel;

void free_image(Image *image) {
  free(image->pixels);
  free(image);
}

void free_model(ImageClassificationModel *model) {
  for (int i = 0; i < model->num_images; i++) {
    free(model->labels[i]);
    free(model->pixels[i]);
  }
  free(model);
}

// Load image from disk and return pointer to Image object
Image *load_image(char *filename, char *label, int num_pixels) {
  Image *image = malloc(sizeof(Image));
  if (!image) {
    perror("Failed to allocate memory for image.");
    exit(EXIT_FAILURE);
  }
  strncpy(image->filename, filename, MAX_FILENAME_LEN);
  strncpy(image->label, label, MAX_LABEL_LEN);

  FILE *f = fopen(filename, "rb");
  if (!f) {
    printf("Failed to open file %s.\n", filename);
    free(image);
    return NULL;
  }
  fseek(f, 0, SEEK_END);
  long file_size = ftell(f);
  fseek(f, 0, SEEK_SET);

  // Check if file size is correct before reading data
  if (file_size != num_pixels * sizeof(float)) {
    printf("Expected %d pixels (%d bytes), but got file size of %ld bytes for %s.\n", num_pixels, num_pixels*sizeof(float), file_size, filename);
    free(image);
    fclose(f);
    return NULL;
  }

  image->pixels = malloc(num_pixels * sizeof(float));
  if (!image->pixels) {
    perror("Failed to allocate memory for pixels.");
    free(image);
    fclose(f);
    exit(EXIT_FAILURE);
  }
  size_t bytes_read = fread(image->pixels, sizeof(float), num_pixels, f);
  if (bytes_read < num_pixels) {
    printf("Failed to read %d pixels from file %s (only read %zu bytes).\n", num_pixels, filename, bytes_read * sizeof(float));
    free(image->pixels);
    free(image);
    fclose(f);
    return NULL;
  }

  fclose(f);
  return image;
}

// Load model from disk and return pointer to ImageClassificationModel object
ImageClassificationModel *load_model(char *model_filename) {
  ImageClassificationModel *model = malloc(sizeof(ImageClassificationModel));
  if (!model) {
    perror("Failed to allocate memory for model.");
    exit(EXIT_FAILURE);
  }

  FILE *f = fopen(model_filename, "r");
  if (!f) {
    printf("Failed to open file %s.\n", model_filename);
    free(model);
    return NULL;
  }

  // Read number of images and pixels per image
  fscanf(f, "%d %d", &model->num_images, &model->num_pixels);

  // Read labels for each image
  for (int i = 0; i < model->num_images; i++) {
    char *label = malloc(MAX_LABEL_LEN);
    if (!label) {
      perror("Failed to allocate memory for label.");
      free_model(model);
      exit(EXIT_FAILURE);
    }
    fscanf(f, "%s", label);
    model->labels[i] = label;
  }

  // Read pixel data for each image
  for (int i = 0; i < model->num_images; i++) {
    float *pixels = malloc(model->num_pixels * sizeof(float));
    if (!pixels) {
      perror("Failed to allocate memory for pixels.");
      free_model(model);
      exit(EXIT_FAILURE);
    }
    if (fread(pixels, sizeof(float), model->num_pixels, f) < model->num_pixels) {
      printf("Failed to read pixel data for image %d.\n", i);
      free(pixels);
      free_model(model);
      fclose(f);
      return NULL;
    }
    model->pixels[i] = pixels;
  }

  fclose(f);
  return model;
}

// Predict label for given image using given model
char *predict_label(Image *image, ImageClassificationModel *model) {
  float min_distance = -1;
  char *predicted_label = NULL;

  for (int i = 0; i < model->num_images; i++) {
    float distance = 0;
    for (int j = 0; j < model->num_pixels; j++) {
      float diff = image->pixels[j] - model->pixels[i][j];
      distance += diff * diff;
    }
    if (min_distance == -1 || distance < min_distance) {
      min_distance = distance;
      predicted_label = model->labels[i];
    }
  }

  return predicted_label;
}

int main() {
  char *model_filename = "model.dat";
  ImageClassificationModel *model = load_model(model_filename);
  if (!model) {
    printf("Failed to load model from %s.\n", model_filename);
    return EXIT_FAILURE;
  }

  char *image_filename = "test_image.dat";
  Image *image = load_image(image_filename, "unknown", model->num_pixels);
  if (!image) {
    printf("Failed to load image from %s.\n", image_filename);
    free_model(model);
    return EXIT_FAILURE;
  }

  char *predicted_label = predict_label(image, model);
  printf("Predicted label for %s: %s\n", image->filename, predicted_label);

  free_image(image);
  free_model(model);

  return EXIT_SUCCESS;
}