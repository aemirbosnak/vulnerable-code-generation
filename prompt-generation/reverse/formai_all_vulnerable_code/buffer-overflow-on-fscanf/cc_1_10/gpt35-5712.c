//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20

typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

typedef struct {
  int width;
  int height;
  Pixel* pixels;
} Image;

// Function to create a new Image
Image* create_image(int width, int height) {
  Image* image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(sizeof(Pixel) * width * height);
  return image;
}

// Function to free the memory allocated for an Image
void free_image(Image* image) {
  free(image->pixels);
  free(image);
}

// Function to get the Pixel at the given coordinates in the Image
Pixel get_pixel(Image* image, int x, int y) {
  int index = y * image->width + x;
  return image->pixels[index];
}

// Function to set the Pixel at the given coordinates in the Image
void set_pixel(Image* image, int x, int y, Pixel pixel) {
  int index = y * image->width + x;
  image->pixels[index] = pixel;
}

// Function to load an Image from a PPM file
Image* load_image(const char* filename) {
  FILE* file = fopen(filename, "r");
  
  if (!file) {
    printf("Error: Could not open file '%s'.\n", filename);
    return NULL;
  }
  
  char magic_number[3];
  fscanf(file, "%s", magic_number);
  
  if (strcmp(magic_number, "P3") != 0) {
    printf("Error: File '%s' is not a PPM file.\n", filename);
    fclose(file);
    return NULL;
  }
  
  int width, height, max_value;
  fscanf(file, "%d %d %d", &width, &height, &max_value);
  
  Image* image = create_image(width, height);
  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int red, green, blue;
      fscanf(file, "%d %d %d", &red, &green, &blue);
      Pixel pixel = {red, green, blue};
      set_pixel(image, x, y, pixel);
    }
  }
  
  fclose(file);
  return image;
}

// Function to save an Image to a PPM file
void save_image(Image* image, const char* filename) {
  FILE* file = fopen(filename, "w");
  
  if (!file) {
    printf("Error: Could not open file '%s' for writing.\n", filename);
    return;
  }
  
  fprintf(file, "P3\n");
  fprintf(file, "%d %d\n", image->width, image->height);
  fprintf(file, "255\n");
  
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = get_pixel(image, x, y);
      fprintf(file, "%d %d %d ", pixel.red, pixel.green, pixel.blue);
    }
    fprintf(file, "\n");
  }
  
  fclose(file);
}

// Function to flip an Image horizontally
void flip_horizontal(Image* image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width / 2; x++) {
      Pixel left_pixel = get_pixel(image, x, y);
      Pixel right_pixel = get_pixel(image, image->width - x - 1, y);
      set_pixel(image, x, y, right_pixel);
      set_pixel(image, image->width - x - 1, y, left_pixel);
    }
  }
}

// Function to flip an Image vertically
void flip_vertical(Image* image) {
  for (int y = 0; y < image->height / 2; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel top_pixel = get_pixel(image, x, y);
      Pixel bottom_pixel = get_pixel(image, x, image->height - y - 1);
      set_pixel(image, x, y, bottom_pixel);
      set_pixel(image, x, image->height - y - 1, top_pixel);
    }
  }
}

// Function to rotate an Image 90 degrees clockwise
void rotate(Image* image) {
  Image* new_image = create_image(image->height, image->width);
  
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = get_pixel(image, x, y);
      set_pixel(new_image, y, image->width - x - 1, pixel);
    }
  }
  
  free_image(image);
  *image = *new_image;
}

// Function to brighten an Image by the given amount
void brighten(Image* image, int amount) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = get_pixel(image, x, y);
      pixel.red += amount;
      pixel.green += amount;
      pixel.blue += amount;
      set_pixel(image, x, y, pixel);
    }
  }
}

// Function to darken an Image by the given amount
void darken(Image* image, int amount) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = get_pixel(image, x, y);
      pixel.red -= amount;
      pixel.green -= amount;
      pixel.blue -= amount;
      set_pixel(image, x, y, pixel);
    }
  }
}

int main() {
  Image* image = load_image("image.ppm");

  if (!image) {
    return 1;
  }

  char command[MAX_COMMAND_LENGTH];

  while (1) {
    printf("Enter a command ('help' for list of commands): ");
    scanf("%s", command);

    if (strcmp(command, "exit") == 0) {
      break;
    }
    else if (strcmp(command, "save") == 0) {
      char filename[100];
      printf("Enter filename: ");
      scanf("%s", filename);
      save_image(image, filename);
    }
    else if (strcmp(command, "flip_h") == 0) {
      flip_horizontal(image);
    }
    else if (strcmp(command, "flip_v") == 0) {
      flip_vertical(image);
    }
    else if (strcmp(command, "rotate") == 0) {
      rotate(image);
    }
    else if (strcmp(command, "brighten") == 0) {
      int amount;
      printf("Enter amount: ");
      scanf("%d", &amount);
      brighten(image, amount);
    }
    else if (strcmp(command, "darken") == 0) {
      int amount;
      printf("Enter amount: ");
      scanf("%d", &amount);
      darken(image, amount);
    }
    else if (strcmp(command, "help") == 0) {
      printf("Available commands:\n");
      printf("exit - exit the program\n");
      printf("save - save the image to a PPM file\n");
      printf("flip_h - flip the image horizontally\n");
      printf("flip_v - flip the image vertically\n");
      printf("rotate - rotate the image 90 degrees clockwise\n");
      printf("brighten - brighten the image by the given amount\n");
      printf("darken - darken the image by the given amount\n");
    }
    else {
      printf("Unknown command. Type 'help' for list of commands.\n");
    }
  }

  free_image(image);
  return 0;
}