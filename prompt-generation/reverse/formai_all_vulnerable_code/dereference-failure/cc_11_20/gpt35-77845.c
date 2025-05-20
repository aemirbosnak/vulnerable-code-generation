//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int height = 0;
  int width = 0;
  int i,j,k,l;

  printf("Welcome to the ASCII Art Maker!!\n");
  printf("Please enter the height and width of the art:\n");

  scanf("%d %d", &height, &width);

  char* art = (char*) malloc(sizeof(char) * height * width);

  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      char c = '.';
      if(i == 0 || j == 0 || i == height-1 || j == width-1) {
        c = '#';
      }
      art[(i * width) + j] = c;
    }
  }

  printf("Here is your art:\n");
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      printf("%c", art[(i * width) + j]);
    }
    printf("\n");
  }

  printf("Would you like to make the art more interesting?\n");
  printf("Enter a number between 1 and %d:\n", height-2);

  scanf("%d", &k);

  for(l = 1; l <= k; l++) {
    for(i = l; i < height-l; i++) {
      for(j = l; j < width-l; j++) {
        if(i == l || j == l || i == height-l-1 || j == width-l-1) {
          art[(i * width) + j] = '#';
        }
      }
    }
  }

  printf("Here is your updated art:\n");
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      printf("%c", art[(i * width) + j]);
    }
    printf("\n");
  }

  free(art);

  return 0;
}