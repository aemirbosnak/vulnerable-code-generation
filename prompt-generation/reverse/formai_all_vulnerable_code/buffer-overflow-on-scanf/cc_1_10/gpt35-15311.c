//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void print_image(char image[HEIGHT][WIDTH][3]) {
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      for (k = 0; k < 3; k++) {
        printf("%c", image[i][j][k]);
      }
    }
    printf("\n");
  }
}

void create_image(char image[HEIGHT][WIDTH][3], int color[]) {
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      for (k = 0; k < 3; k++) {
        image[i][j][k] = color[k];
      }
    }
  }
}

void random_image(char image[HEIGHT][WIDTH][3]) {
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      for (k = 0; k < 3; k++) {
        image[i][j][k] = rand() % 256;
      }
    }
  }
}

void save_image(char image[HEIGHT][WIDTH][3]) {
  FILE *fp;
  fp = fopen("image.txt", "w");
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      for (k = 0; k < 3; k++) {
        fprintf(fp, "%d ", image[i][j][k]);
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

void load_image(char image[HEIGHT][WIDTH][3]) {
  FILE *fp;
  fp = fopen("image.txt", "r");
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      for (k = 0; k < 3; k++) {
        fscanf(fp, "%d ", &image[i][j][k]);
      }
    }
  }
}

void animate_image(char image[HEIGHT][WIDTH][3]) {
  int i, j, k;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < HEIGHT; j++) {
      for (k = 0; k < WIDTH; k++) {
        image[j][k][0] += i*10;
        image[j][k][1] += i*5;
        image[j][k][2] += i*2;
      }
    }
    print_image(image);
    printf("\n\n");
  }
}

int main() {
  char image[HEIGHT][WIDTH][3];
  int color[3];
  int option;
  srand(time(NULL));
  printf("Welcome to the C Pixel Art Generator!\n\n");

  do {
    printf("Choose an option:\n");
    printf("1. Create a custom image\n");
    printf("2. Generate a random image\n");
    printf("3. Save current image to file\n");
    printf("4. Load an image from file\n");
    printf("5. Animate current image\n");
    printf("6. Quit\n\n");

    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter RGB color values (0-255):\n");
        printf("Red: ");
        scanf("%d", &color[0]);
        printf("Green: ");
        scanf("%d", &color[1]);
        printf("Blue: ");
        scanf("%d", &color[2]);
        create_image(image, color);
        print_image(image);
        break;
      case 2:
        random_image(image);
        print_image(image);
        break;
      case 3:
        save_image(image);
        printf("Image saved to file.\n");
        break;
      case 4:
        load_image(image);
        print_image(image);
        break;
      case 5:
        animate_image(image);
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option. Try again.\n");
    }
    printf("\n\n");
  } while (option != 6);

  return 0;
}