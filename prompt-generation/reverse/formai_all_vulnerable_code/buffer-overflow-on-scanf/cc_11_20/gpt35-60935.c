//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  printf("Welcome to the QR Code Generator!\n");
  printf("Please enter the text you want to encode in the QR code: ");
  
  char input[101];
  scanf("%s", input);
  
  printf("Do you want to add additional fun to your QR code? (y/n): ");
  
  char response;
  scanf(" %c", &response);
  
  int fun_level = 0;
  
  if (response == 'y') {
    printf("Please enter the fun level (1-5): ");
    scanf("%d", &fun_level);
    
    if (fun_level < 1 || fun_level > 5) {
      printf("Invalid fun level entered. Fun level set to 1.\n");
      fun_level = 1;
    }
  }
  
  printf("Generating QR code...\n");
  
  // Randomly generate QR code
  srand(time(NULL));
  int qr_code[25][25];
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      qr_code[i][j] = rand() % 2;
    }
  }
  
  // Add fun to QR code
  if (fun_level > 0) {
    for (int i = 0; i < fun_level; i++) {
      int x = rand() % 25;
      int y = rand() % 25;
      qr_code[x][y] = !qr_code[x][y];
    }
  }
  
  // Print QR code to console
  printf("\nQR code:\n");
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if (qr_code[i][j] == 0) {
        printf("██");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  
  printf("\nThanks for using the QR Code Generator! Have a fun day!\n");
  
  return 0; 
}