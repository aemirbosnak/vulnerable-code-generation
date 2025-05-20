//FormAI DATASET v1.0 Category: Image Editor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
  printf("Welcome to the Cheerful Image Editor!\n");
  printf("1. Load image\n");
  printf("2. Brightness\n");
  printf("3. Contrast\n");
  printf("4. Hue\n");
  printf("5. Saturation\n");
  printf("6. Save image\n");
  printf("7. Quit\n");
}

void brighten_image(int **image, int width, int height) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[x][y] += 50;
      if (image[x][y] > 255) {
        image[x][y] = 255;
      }
    }
  }
}

void contrast_image(int **image, int width, int height) {
  int mean = 0;
  
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      mean += image[x][y];
    }
  }
  
  mean /= (width * height);
  
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if (image[x][y] < mean) {
        image[x][y] -= 50;
        if (image[x][y] < 0) {
          image[x][y] = 0;
        }
      } else {
        image[x][y] += 50;
        if (image[x][y] > 255) {
          image[x][y] = 255;
        }
      }
    }
  }
}

void hue_image(int **image, int width, int height) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[x][y] = (image[x][y] + 128) % 256;
    }
  }
}

void saturate_image(int **image, int width, int height) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if (image[x][y] < 128) {
        image[x][y] /= 2;
      } else {
        image[x][y] = ((image[x][y] - 128) * 2) + 128;
        if (image[x][y] > 255) {
          image[x][y] = 255;
        }
      }
    }
  }
}

void save_image(int **image, int width, int height, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  
  fprintf(fp, "P2\n");
  fprintf(fp, "%d %d\n", width, height);
  fprintf(fp, "255\n");
  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      fprintf(fp, "%d ", image[x][y]);
    }
    fprintf(fp, "\n");
  }
  
  fclose(fp);
}

int main() {
  int **image = NULL;
  int width = 0;
  int height = 0;

  int running = 1;
  while (running) {
    print_menu();
    
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    switch (choice) {
      case 1: {
        char filename[100];
        printf("Enter the filename to load: ");
        scanf("%s", filename);
        printf("\n");
        
        FILE *fp = fopen(filename, "rb");
        
        if (!fp) {
          printf("Could not open file!\n");
          break;
        }
        
        char header[3];
        fscanf(fp, "%s", header);
        
        if (strcmp(header, "P2") != 0) {
          printf("Invalid file header!\n");
          fclose(fp);
          break;
        }
        
        fscanf(fp, "%d %d", &width, &height);
        
        int max_val;
        fscanf(fp, "%d", &max_val);
        
        if (max_val != 255) {
          printf("Invalid maximum value!\n");
          fclose(fp);
          break;
        }
        
        image = (int **)malloc(sizeof(int *) * width);
        
        for (int x = 0; x < width; x++) {
          image[x] = (int *)malloc(sizeof(int) * height);
        }
        
        for (int y = 0; y < height; y++) {
          for (int x = 0; x < width; x++) {
            fscanf(fp, "%d", &image[x][y]);
          }
        }
        
        fclose(fp);
        printf("Loaded image successfully!\n");
        break;
      }
      case 2: {
        if (!image) {
          printf("No image loaded!\n");
          break;
        }
        
        brighten_image(image, width, height);
        printf("Brightened image!\n");
        break;
      }
      case 3: {
        if (!image) {
          printf("No image loaded!\n");
          break;
        }
        
        contrast_image(image, width, height);
        printf("Contrasted image!\n");
        break;
      }
      case 4: {
        if (!image) {
          printf("No image loaded!\n");
          break;
        }
        
        hue_image(image, width, height);
        printf("Changed hue!\n");
        break;
      }
      case 5: {
        if (!image) {
          printf("No image loaded!\n");
          break;
        }
        
        saturate_image(image, width, height);
        printf("Saturated image!\n");
        break;
      }
      case 6: {
        if (!image) {
          printf("No image loaded!\n");
          break;
        }
        
        char filename[100];
        printf("Enter the filename to save: ");
        scanf("%s", filename);
        printf("\n");
        
        save_image(image, width, height, filename);
        printf("Saved image!\n");
        break;
      }
      case 7: {
        running = 0;
        printf("Goodbye!\n");
        break;
      }
      default: {
        printf("Invalid choice!\n");
        break;
      }
    }
    
    printf("\n");
  }
  
  if (image) {
    for (int x = 0; x < width; x++) {
      free(image[x]);
    }
    free(image);
  }
  
  return 0;
}