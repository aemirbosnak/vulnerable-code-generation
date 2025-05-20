//FormAI DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH_SIZE 256
#define MAX_FILTER_NAME_SIZE 16
#define MAX_FILTERS 10

// Define filter types
enum FilterType {
  GRAYSCALE,
  INVERT,
  BLUR,
  SHARPEN,
  EDGE_DETECT
};

// Define filter struct
typedef struct {
  enum FilterType type; // filter type
  char name[MAX_FILTER_NAME_SIZE]; // filter name
  int strength; // filter strength (0-100)
  int enabled; // filter enabled flag
} Filter;

// Define image struct
typedef struct {
  char file_path[MAX_FILE_PATH_SIZE]; // image file path
  int width; // image width
  int height; // image height
  int channels; // image channels
  unsigned char *data; // image data
} Image;

// Function prototypes
void print_filters(Filter *filters, int count);
void load_image(char *file_path, Image *image);
void apply_filter(Filter *filter, Image *image);
void save_image(Image *image);

int main() {
  // Initialize filters
  Filter filters[MAX_FILTERS];
  filters[0] = (Filter) { .type = GRAYSCALE, .name = "Grayscale", .strength = 50, .enabled = 1 };
  filters[1] = (Filter) { .type = INVERT, .name = "Invert", .strength = 50, .enabled = 1 };
  filters[2] = (Filter) { .type = BLUR, .name = "Blur", .strength = 50, .enabled = 1 };
  filters[3] = (Filter) { .type = SHARPEN, .name = "Sharpen", .strength = 50, .enabled = 1 };
  filters[4] = (Filter) { .type = EDGE_DETECT, .name = "Edge Detect", .strength = 50, .enabled = 1 };
  int filter_count = 5;
  
  // Load image
  char file_path[MAX_FILE_PATH_SIZE];
  printf("Enter image file path: ");
  fgets(file_path, MAX_FILE_PATH_SIZE, stdin);
  file_path[strcspn(file_path, "\n")] = '\0'; // remove newline character
  Image image = (Image) { .file_path = file_path };
  load_image(file_path, &image);
  
  // Apply filters
  int selection;
  do {
    // Print filters
    printf("\n");
    print_filters(filters, filter_count);
    
    // Get filter selection
    printf("\nEnter filter number to enable/disable (0-%d) or -1 to apply filters: ", filter_count - 1);
    scanf("%d", &selection);
    if (selection >= 0 && selection < filter_count) {
      filters[selection].enabled = !filters[selection].enabled; // toggle filter enablement
    } else if (selection != -1) {
      printf("Invalid selection.\n");
    }
  } while (selection != -1);
  
  // Apply enabled filters to image
  for (int i = 0; i < filter_count; i++) {
    if (filters[i].enabled) {
      apply_filter(&filters[i], &image);
    }
  }
  
  // Save image
  save_image(&image);

  // Free image data
  free(image.data);
  
  return 0;
}

// Print filters
void print_filters(Filter *filters, int count) {
  printf("Filters:\n");
  for (int i = 0; i < count; i++) {
    printf("%d. [%s] %s (strength: %d, %s)\n", i, filters[i].enabled ? "x" : " ", filters[i].name, filters[i].strength, filters[i].enabled ? "enabled" : "disabled");
  }
}

// Load image from file
void load_image(char *file_path, Image *image) {
  FILE *file = fopen(file_path, "rb");
  if (!file) {
    printf("Error: could not open file %s.\n", file_path);
    exit(1);
  }
  
  // Read image header
  char header[54];
  fread(header, sizeof(char), 54, file);
  
  // Extract image dimensions and channels
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];
  int channels = *(int*)&header[28];
  
  // Read image data
  unsigned char *data = (unsigned char*) malloc(width * height * channels);
  fread(data, sizeof(char), width * height * channels, file);
  
  // Set image attributes
  image->width = width;
  image->height = height;
  image->channels = channels;
  image->data = data;
  
  // Close file
  fclose(file);
}

// Apply filter to image
void apply_filter(Filter *filter, Image *image) {
  switch(filter->type) {
    case GRAYSCALE: {
      // Convert to grayscale
      for (int i = 0; i < image->width * image->height * image->channels; i += image->channels) {
        unsigned char r = image->data[i];
        unsigned char g = image->data[i + 1];
        unsigned char b = image->data[i + 2];
        unsigned char average = (r + g + b) / 3;
        image->data[i] = image->data[i + 1] = image->data[i + 2] = average;
      }
    } break;
    case INVERT: {
      // Invert colors
      for (int i = 0; i < image->width * image->height * image->channels; i++) {
        image->data[i] = 255 - image->data[i];
      }
    } break;
    case BLUR: {
      // Apply blur
      int size = 5;
      unsigned char *temp = (unsigned char*) malloc(image->width * image->height * image->channels);
      int radius = filter->strength / 10 * 2 + 1;
      float kernel[radius][radius];
      float sum = 0;
      for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
          float x = i - radius / 2;
          float y = j - radius / 2;
          kernel[i][j] = (1.0f / (2 * 3.14159 * (radius / 2) * (radius / 2))) * pow(2.71828, -(x * x + y * y) / (2 * (radius / 2) * (radius / 2)));
          sum += kernel[i][j];
        }
      }
      for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
          kernel[i][j] /= sum;
        }
      }
      for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
          for (int c = 0; c < image->channels; c++) {
            float value = 0;
            for (int kx = 0; kx < radius; kx++) {
              for (int ky = 0; ky < radius; ky++) {
                int sx = x + kx - radius / 2;
                int sy = y + ky - radius / 2;
                if (sx >= 0 && sx < image->width && sy >= 0 && sy < image->height) {
                  value += image->data[(sy * image->width + sx) * image->channels + c] * kernel[kx][ky];
                }
              }
            }
            temp[(y * image->width + x) * image->channels + c] = value;
          }
        }
      }
      memcpy(image->data, temp, image->width * image->height * image->channels);
      free(temp);
    } break;
    case SHARPEN: {
      // Apply sharpen
      int kernel[9] = {0, -1, 0, -1, 5, -1, 0, -1, 0};
      int divisor = 1;
      int bias = 0;
      for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
          for (int c = 0; c < image->channels; c++) {
            int value = 0;
            for (int kx = 0; kx < 3; kx++) {
              for (int ky = 0; ky < 3; ky++) {
                int sx = x + kx - 1;
                int sy = y + ky - 1;
                if (sx >= 0 && sx < image->width && sy >= 0 && sy < image->height) {
                  value += image->data[(sy * image->width + sx) * image->channels + c] * kernel[ky * 3 + kx];
                }
              }
            }
            value = (value / divisor) + bias;
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            image->data[(y * image->width + x) * image->channels + c] = value;
          }
        }
      }
    } break;
    case EDGE_DETECT: {
      // Apply edge detect
      int kernel[9] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
      int divisor = 1;
      int bias = 0;
      unsigned char *temp = (unsigned char*) malloc(image->width * image->height * image->channels);
      for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
          for (int c = 0; c < image->channels; c++) {
            int value = 0;
            for (int kx = 0; kx < 3; kx++) {
              for (int ky = 0; ky < 3; ky++) {
                int sx = x + kx - 1;
                int sy = y + ky - 1;
                if (sx >= 0 && sx < image->width && sy >= 0 && sy < image->height) {
                  value += image->data[(sy * image->width + sx) * image->channels + c] * kernel[ky * 3 + kx];
                }
              }
            }
            value = (value / divisor) + bias;
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            temp[(y * image->width + x) * image->channels + c] = value;
          }
        }
      }
      memcpy(image->data, temp, image->width * image->height * image->channels);
      free(temp);
    } break;
  }
}

// Save image to file
void save_image(Image *image) {
  FILE *file = fopen(image->file_path, "wb");
  if (!file) {
    printf("Error: could not create file %s.\n", image->file_path);
    exit(1);
  }
  
  // Write image header
  unsigned char header[54] = {
    0x42, 0x4d, 0x36, 0x9c, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x64, 0x00,
    0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6c, 0x9c, 0x0b, 0x00, 0x13, 0x0b,
    0x00, 0x00, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  *(int*)&header[18] = image->width;
  *(int*)&header[22] = image->height;
  *(int*)&header[28] = image->channels;
  fwrite(header, sizeof(unsigned char), 54, file);
  
  // Write image data
  fwrite(image->data, sizeof(unsigned char), image->width * image->height * image->channels, file);
  
  // Close file
  fclose(file);
}