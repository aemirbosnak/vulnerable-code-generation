//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>

int main() {
  char artStyle;
  int width, height;
  
  printf("What ASCII art style do you prefer? ");
  scanf("%c", &artStyle);
  
  printf("What should be the width of the ASCII art? ");
  scanf("%d", &width);
  
  printf("What should be the height of the ASCII art? ");
  scanf("%d", &height);
  
  switch(artStyle) {
    case '1':
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          if(i%2 == 0) {
            if(j%2 == 0) {
              printf("/");
            } else {
              printf("\\");
            }
          } else {
            if(j%2 == 0) {
              printf("\\");
            } else {
              printf("/");
            }
          }
        }
        printf("\n");
      }
      break;
      
    case '2':
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          if(i < height/2) {
            if(j < width/2) {
              printf("+");
            } else {
              printf("*");
            }
          } else {
            if(j < width/2) {
              printf("*");
            } else {
              printf("+");
            }
          }
        }
        printf("\n");
      }
      break;
      
    case '3':
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          if(i == 0 || i == height-1 || j == 0 || j == width-1) {
            printf("*");
          } else {
            printf(" ");
          }
        }
        printf("\n");
      }
      break;
      
    default:
      printf("Invalid ASCII art style selected.");
      break;
  }
  
  return 0;
}