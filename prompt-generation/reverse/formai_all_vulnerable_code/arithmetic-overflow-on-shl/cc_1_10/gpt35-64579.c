//FormAI DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define NUM_CLASSES 10
#define IMAGE_SIZE 28*28 // 784 pixels

typedef struct {
  unsigned char pixels[IMAGE_SIZE];
  int label;
} image_t;

typedef struct {
  int num_images;
  image_t* images;
} dataset_t;

typedef struct {
  double weights[IMAGE_SIZE];
} classifier_t;

void load_dataset(const char* filename, dataset_t* dataset) {
  FILE* file = fopen(filename, "rb");
  if(!file) {
    printf("Failed to open %s\n", filename);
    exit(1);
  }
  unsigned char buffer[4];
  fread(buffer, 1, 4, file);
  int magic_number = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
  printf("Magic number: %d\n", magic_number);
  fread(buffer, 1, 4, file);
  dataset->num_images = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
  printf("Number of images: %d\n", dataset->num_images);
  fread(buffer, 1, 4, file);
  int num_rows = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
  fread(buffer, 1, 4, file);
  int num_cols = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
  printf("Image size: %d x %d\n", num_rows, num_cols);
  dataset->images = (image_t*)malloc(dataset->num_images*sizeof(image_t));
  for(int i=0; i<dataset->num_images; i++) {
    image_t image;
    fread(image.pixels, 1, IMAGE_SIZE, file);
    fread(buffer, 1, 1, file);
    image.label = buffer[0];
    dataset->images[i] = image;
  }
  fclose(file);
}

void save_classifier(const char* filename, classifier_t* classifier) {
  FILE* file = fopen(filename, "wb");
  fwrite(classifier->weights, sizeof(double), IMAGE_SIZE, file);
  fclose(file);
}

void load_classifier(const char* filename, classifier_t* classifier) {
  FILE* file = fopen(filename, "rb");
  fread(classifier->weights, sizeof(double), IMAGE_SIZE, file);
  fclose(file);
}

int classify_image(image_t* image, classifier_t* classifier) {
  double score[NUM_CLASSES] = {0};
  for(int i=0; i<NUM_CLASSES; i++) {
    for(int j=0; j<IMAGE_SIZE; j++) {
      score[i] += image->pixels[j]*classifier->weights[j];
    }
  }
  int max_index = 0;
  double max_score = score[0];
  for(int i=1; i<NUM_CLASSES; i++) {
    if(score[i]>max_score) {
      max_index = i;
      max_score = score[i];
    }
  }
  return max_index;
}

void train_classifier(dataset_t* dataset, classifier_t* classifier, int num_iterations, double learning_rate) {
  srand(0);
  for(int i=0; i<IMAGE_SIZE; i++) {
    classifier->weights[i] = (double)(rand()%10000)/10000.0;
  }
  for(int iter=0; iter<num_iterations; iter++) {
    printf("Iteration %d\n", iter);
    double loss = 0;
    for(int i=0; i<dataset->num_images; i++) {
      image_t* image = &dataset->images[i];
      double score[NUM_CLASSES] = {0};
      for(int j=0; j<NUM_CLASSES; j++) {
        for(int k=0; k<IMAGE_SIZE; k++) {
          score[j] += image->pixels[k]*classifier->weights[k];
        }
      }
      double correct_score = score[image->label];
      double margin = 1.0;
      for(int j=0; j<NUM_CLASSES; j++) {
        if(j==image->label) continue;
        double diff = score[j]-correct_score+margin;
        if(diff>0) {
          loss += diff;
          for(int k=0; k<IMAGE_SIZE; k++) {
            classifier->weights[k] -= learning_rate*image->pixels[k];
          }
          for(int k=0; k<IMAGE_SIZE; k++) {
            classifier->weights[k] += learning_rate*dataset->images[rand()%dataset->num_images].pixels[k];
          }
        }
      }
    }
    printf("Loss: %f\n", loss);
  }
}

int main(int argc, char** argv) {
  if(argc<4) {
    printf("Usage: %s train_file test_file model_file\n", argv[0]);
    return 0;
  }
  dataset_t train_dataset;
  load_dataset(argv[1], &train_dataset);
  dataset_t test_dataset;
  load_dataset(argv[2], &test_dataset);
  classifier_t classifier;
  train_classifier(&train_dataset, &classifier, 1000, 0.0001);
  save_classifier(argv[3], &classifier);
  int num_correct = 0;
  for(int i=0; i<test_dataset.num_images; i++) {
    int prediction = classify_image(&test_dataset.images[i], &classifier);
    if(prediction==test_dataset.images[i].label) num_correct++;
  }
  double accuracy = (double)num_correct/test_dataset.num_images;
  printf("Accuracy: %f\n", accuracy);
  return 0;
}