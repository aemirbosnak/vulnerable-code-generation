//FormAI DATASET v1.0 Category: Image Classification system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define NUM_CLASSES 5
#define NUM_IMAGES 10

typedef struct {
   float pixel[28][28];
   int label;
} Image;

int main() {
   printf("Welcome to the Image Classification System!\n");

   char file_name[MAX_FILE_NAME_LEN];
   printf("Enter file name: ");
   scanf("%s", file_name);

   FILE *file = fopen(file_name, "r");
   if (!file) {
      printf("File not found!\n");
      return -1;
   }

   Image images[NUM_IMAGES];
   int count = 0;

   // Read images from file
   while (count < NUM_IMAGES && !feof(file)) {
      Image img;
      fread(&img, sizeof(Image), 1, file);
      images[count] = img;
      count++;
   }

   fclose(file);

   // Initialize weights and bias
   float weights[784][NUM_CLASSES];
   float bias[NUM_CLASSES];
   for (int i = 0; i < 784; i++) {
      for (int j = 0; j < NUM_CLASSES; j++) {
         weights[i][j] = (float)rand() / RAND_MAX;
      }
   }
   for (int i = 0; i < NUM_CLASSES; i++) {
      bias[i] = (float)rand() / RAND_MAX;
   }

   // Train the model
   printf("Training the model...\n");
   for (int epoch = 0; epoch < 10; epoch++) {
      for (int i = 0; i < NUM_IMAGES; i++) {
         Image img = images[i];
         float inputs[784];
         for (int j = 0; j < 28; j++) {
            for (int k = 0; k < 28; k++) {
               inputs[j*28+k] = img.pixel[j][k];
            }
         }

         // Forward pass
         float outputs[NUM_CLASSES];
         for (int j = 0; j < NUM_CLASSES; j++) {
            outputs[j] = bias[j];
            for (int k = 0; k < 784; k++) {
               outputs[j] += weights[k][j] * inputs[k];
            }
         }

         // Softmax activation
         float sum = 0.0;
         for (int j = 0; j < NUM_CLASSES; j++) {
            outputs[j] = exp(outputs[j]);
            sum += outputs[j];
         }
         for (int j = 0; j < NUM_CLASSES; j++) {
            outputs[j] /= sum;
         }

         // Backward pass
         for (int j = 0; j < NUM_CLASSES; j++) {
            float target = (j == img.label) ? 1.0 : 0.0;
            float error = target - outputs[j];
            for (int k = 0; k < 784; k++) {
               weights[k][j] += 0.1 * error * inputs[k];
            }
            bias[j] += 0.1 * error;
         }
      }
   }

   // Classify new images
   printf("Enter name of test image: ");
   scanf("%s", file_name);

   file = fopen(file_name, "r");
   if (!file) {
      printf("File not found!\n");
      return -1;
   }

   Image img;
   fread(&img, sizeof(Image), 1, file);

   float inputs[784];
   for (int j = 0; j < 28; j++) {
      for (int k = 0; k < 28; k++) {
         inputs[j*28+k] = img.pixel[j][k];
      }
   }

   float outputs[NUM_CLASSES];
   for (int j = 0; j < NUM_CLASSES; j++) {
      outputs[j] = bias[j];
      for (int k = 0; k < 784; k++) {
         outputs[j] += weights[k][j] * inputs[k];
      }
   }

   int max_index = 0;
   float max_value = -1.0;
   for (int j = 0; j < NUM_CLASSES; j++) {
      if (outputs[j] > max_value) {
         max_index = j;
         max_value = outputs[j];
      }
   }

   printf("Classification result: %d\n", max_index);

   fclose(file);
   return 0;
}