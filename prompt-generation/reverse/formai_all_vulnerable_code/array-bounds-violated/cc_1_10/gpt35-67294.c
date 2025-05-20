//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Linux Torvalds style ASCII art converter */

int width, height;
char *output;

const char shades[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void resize() {
  output = (char*) realloc(output, width * height);
}

void convert(char* filename) {
  FILE *fp = fopen(filename, "rb");
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, fp);
  
  width = *(int*)&header[18];
  height = *(int*)&header[22];
  
  resize();

  unsigned char pixel[3];
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      fread(pixel, sizeof(unsigned char), 3, fp);
      int index = (((int)pixel[0] + (int)pixel[1] + (int)pixel[2]) / 3) / 25;
      output[(i * width) + j] = shades[10 - index];
    }
  }
  fclose(fp);
}

void print_output() {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      printf("%c", output[(i * width) + j]);
    }
    printf("\n");
  }
}

void clean_up() {
  free(output);
}

int main(int argc, char* argv[]) {
  if(argc < 2 || argc > 2) {
    printf("Error: Usage: ./converter filename.bmp\n");
    return 1;
  }

  char* filename = argv[1];

  output = (char*) malloc(1);

  convert(filename);
  print_output();
  clean_up();
  
  return 0;
}