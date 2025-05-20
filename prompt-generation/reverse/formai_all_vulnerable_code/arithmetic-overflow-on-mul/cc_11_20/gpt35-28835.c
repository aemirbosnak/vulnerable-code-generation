//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){

  printf("Here's an image of my cat, Mr. Whiskers, before I process it:\n");

  FILE *ptr = fopen("cat.ppm","rb");
  char buff[16];
  int width, height, max;
  fscanf(ptr,"%s %d %d %d", buff, &width, &height, &max);

  // allocate memory for pixel array
  unsigned char raster[height][width * 3];

  // read in pixel data
  fread(raster, sizeof(unsigned char), height * width * 3, ptr);
  fclose(ptr);

  /* --------- FLIPPING THE IMAGE --------- */

  // swapping values of each pixel in row
  for(int row=0; row<height; row++){
    for(int col=0; col<width * 3 / 2; col+=3){
      int opposite_col = width * 3 - col - 3;
      unsigned char temp_r = raster[row][col];
      raster[row][col] = raster[row][opposite_col];
      raster[row][opposite_col] = temp_r;
      unsigned char temp_g = raster[row][col+1];
      raster[row][col+1] = raster[row][opposite_col+1];
      raster[row][opposite_col+1] = temp_g;
      unsigned char temp_b = raster[row][col+2];
      raster[row][col+2] = raster[row][opposite_col+2];
      raster[row][opposite_col+2] = temp_b;
    }
  }

  /* --------- INCREASING BRIGHTNESS AND CONTRAST --------- */

  for(int row=0; row<height; row++){
    for(int col=0; col<width * 3; col+=3){
      // increasing brightness
      raster[row][col] = (raster[row][col] + 50 > max) ? max : (raster[row][col] + 50);
      raster[row][col+1] = (raster[row][col+1] + 50 > max) ? max : (raster[row][col+1] + 50);
      raster[row][col+2] = (raster[row][col+2] + 50 > max) ? max : (raster[row][col+2] + 50);

      // increasing contrast
      double mono = 0.2126 * raster[row][col] + 0.7152 * raster[row][col+1] + 0.0722 * raster[row][col+2];
      unsigned char temp = (mono - 128) * 1.5 + 128;
      raster[row][col] = (temp > max) ? max : temp;
      raster[row][col+1] = (temp > max) ? max : temp;
      raster[row][col+2] = (temp > max) ? max : temp;
    }
  }

  printf("\nHere's the flipped, brightened, and contrasted image of Mr. Whiskers:\n");

  FILE *ptr2 = fopen("cat_processed.ppm","wb");
  fprintf(ptr2, "%s\n%d %d\n%d\n", buff, width, height, max);
  fwrite(raster, sizeof(unsigned char), height * width * 3, ptr2);
  fclose(ptr2);

  return 0;

}