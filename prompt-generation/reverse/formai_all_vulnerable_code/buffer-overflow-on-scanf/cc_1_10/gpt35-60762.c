//FormAI DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2

struct pixel{
  int red;
  int green;
  int blue;
};

struct image{
  int width;
  int height;
  struct pixel** pixels;
};

void read_image(char* filename, struct image* img){

  FILE* fp = fopen(filename, "r");
  
  if(fp == NULL){
    printf("Could not open file %s", filename);
    exit(1);
  }

  fscanf(fp, "%d %d", &img->width, &img->height);
  
  img->pixels = (struct pixel**) malloc(img->height * sizeof(struct pixel*));
  for(int i = 0; i < img->height; i++){
    img->pixels[i] = (struct pixel*) malloc(img->width * sizeof(struct pixel));
  }

  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < img->width; j++){
      fscanf(fp, "%d %d %d", &img->pixels[i][j].red, &img->pixels[i][j].green, &img->pixels[i][j].blue);
    }
  }

  printf("Image read from file successfully!\n");
} 

void write_image(char* filename, struct image* img){

  FILE* fp = fopen(filename, "w");

  if(fp == NULL){
    printf("Could not open file %s", filename);
    exit(1);
  }

  fprintf(fp, "%d %d\n", img->width, img->height);

  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < img->width; j++){
      fprintf(fp, "%d %d %d\n", img->pixels[i][j].red, img->pixels[i][j].green, img->pixels[i][j].blue);
    }
  }

  printf("Image written to file successfully!\n");
}

void grayscale(struct image* img){

  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < img->width; j++){
      int avg = (img->pixels[i][j].red + img->pixels[i][j].green + img->pixels[i][j].blue) / 3;
      img->pixels[i][j].red = avg;
      img->pixels[i][j].green = avg;
      img->pixels[i][j].blue = avg;
    }
  }

  printf("Image has been converted to grayscale!\n");
}

void invert_colors(struct image* img){

  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < img->width; j++){
      img->pixels[i][j].red = 255 - img->pixels[i][j].red;
      img->pixels[i][j].green = 255 - img->pixels[i][j].green;
      img->pixels[i][j].blue = 255 - img->pixels[i][j].blue;
    }
  }

  printf("Colors of the image have been inverted!\n");
}

int main(){

  char filename[100];
  printf("Enter the name of the file to be edited: ");
  scanf("%s", filename);

  struct image my_image;
  read_image(filename, &my_image);

  int choice = -1;

  while(choice != 0){

    printf("\nChoose an option:\n");
    printf("1. Convert to grayscale\n");
    printf("2. Invert colors\n");
    printf("3. Save image\n");
    printf("0. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        grayscale(&my_image);
        break;
      case 2:
        invert_colors(&my_image);
        break;
      case 3:
        printf("Enter the name of the file to save the image: ");
        scanf("%s", filename);
        write_image(filename, &my_image);
        break;
      case 0:
        printf("Good bye!\n");
        break;
      default:
        printf("Invalid choice. Try again!\n");
        break;
    }
  }

  return 0;
}