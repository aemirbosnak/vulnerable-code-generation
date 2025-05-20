//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
  printf("Hello! I am a program that prints unique C patterns.\n");
  printf("What kind of pattern would you like to see?\n");
  printf("1. Pyramid\n");
  printf("2. Diamond\n");
  printf("3. Hourglass\n");

  int choice;
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter the height of the pyramid: ");
    int height;
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= height - i; j++) {
        printf(" ");
      }
      for (int j = 1; j <= 2 * i - 1; j++) {
        printf("*");
      }
      printf("\n");
    }
  }

  else if (choice == 2) {
    printf("Enter the width of the diamond: ");
    int width;
    scanf("%d", &width);

    for(int i = 1; i <= width; i++){
      for(int j = 1; j <= width - i; j++){
         printf(" ");
      }
      for(int j = 1; j <= 2 * i - 1; j++){
         printf("*");
      }
      printf("\n");
   }

   for(int i = width - 1; i >= 1; i--){
      for(int j = 1; j <= width - i; j++){
         printf(" ");
      }
      for(int j = 1; j <= 2 * i - 1; j++){
         printf("*");
      }
      printf("\n");
    }
  }

  else if (choice == 3) {
    printf("Enter the height of the hourglass: ");
    int height;
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= i - 1; j++) {
        printf(" ");
      }
      for (int j = 1; j <= 2 * (height - i) + 1; j++) {
        printf("*");
      }
      printf("\n");
    }

    for (int i = height - 1; i >= 1; i--) {
      for (int j = 1; j <= i - 1; j++) {
        printf(" ");
      }
      for (int j = 1; j <= 2 * (height - i) + 1; j++) {
        printf("*");
      }
      printf("\n");
    }
  }

  else {
    printf("Invalid choice. Please choose between 1, 2, or 3.\n");
  }

  return 0;
}