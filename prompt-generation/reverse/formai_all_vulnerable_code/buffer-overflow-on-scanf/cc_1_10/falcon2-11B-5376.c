//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Image {
  int height;
  int width;
  char **data;
} Image;

Image* createImage(int height, int width) {
  Image *new_image = (Image*)malloc(sizeof(Image));
  new_image->height = height;
  new_image->width = width;
  new_image->data = (char**)malloc(sizeof(char*)*height);
  for(int i=0;i<height;i++){
    new_image->data[i] = (char*)malloc(sizeof(char)*width);
  }
  return new_image;
}

void freeImage(Image* image) {
  for(int i=0;i<image->height;i++){
    free(image->data[i]);
  }
  free(image->data);
  free(image);
}

void saveImage(Image* image, char* filename) {
  FILE *file = fopen(filename,"w");
  for(int i=0;i<image->height;i++){
    for(int j=0;j<image->width;j++){
      fprintf(file,"%c",image->data[i][j]);
    }
    fprintf(file,"\n");
  }
  fclose(file);
}

void editImage(Image* image, char* command) {
  if(strcmp(command,"save")==0){
    saveImage(image, "out.txt");
  }
}

int main() {
  int height, width;
  printf("Enter height and width: ");
  scanf("%d%d", &height, &width);
  Image* image = createImage(height, width);
  char command[100];
  while(1){
    printf("Enter command: ");
    fgets(command, 100, stdin);
    editImage(image, command);
    printf("Do you want to continue (y/n): ");
    fgets(command, 100, stdin);
  }
  freeImage(image);
  return 0;
}