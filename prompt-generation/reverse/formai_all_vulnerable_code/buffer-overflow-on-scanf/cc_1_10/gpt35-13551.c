//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 500

void embedWatermark(char* inputMsg, char* watermark) {
  int i, j, k = 0, msgLen, watermarkLen;
  char outputMsg[MAX_LENGTH];

  msgLen = strlen(inputMsg);
  watermarkLen = strlen(watermark);

  for (i = 0; i < msgLen; i++) {
    // Embed the watermark every 3rd character
    if (i % 3 == 0 && k < watermarkLen) {
      outputMsg[i] = watermark[k++];
    }
    else {
      outputMsg[i] = inputMsg[i - k];
    }
  }

  // Add trailing watermark if there's enough space
  if (msgLen % 3 != 0 && k < watermarkLen) {
    for (j = i - k; j < msgLen; j++) {
      outputMsg[j] = watermark[k++];
    }
  }

  printf("Embedded Watermark: %s", outputMsg);
}

void extractWatermark(char* inputMsg) {
  int i, j = 0, msgLen, watermarkLen;
  char watermark[MAX_LENGTH];

  msgLen = strlen(inputMsg);

  for (i = 0; i < msgLen; i++) {
    // Extract the watermark from every 3rd character
    if (i % 3 == 0) {
      watermark[j++] = inputMsg[i];
    }
  }

  watermarkLen = strlen(watermark);
  
  printf("Extracted Watermark: %s\n", watermark);

  if (watermarkLen == 0) {
    printf("No watermark found in the input message.\n");
  }
}

int main() {
  char inputMsg[MAX_LENGTH], watermark[MAX_LENGTH], ch;
  int menuChoice;

  printf("Welcome to the Digital Watermarking Program!\n");

  do {
    printf("Please choose an option:\n");
    printf("1. Embed Watermark\n");
    printf("2. Extract Watermark\n");
    printf("3. Quit\n");

    scanf("%d", &menuChoice);
    fflush(stdin);

    switch(menuChoice) {
      case 1:
        printf("Enter the input message: ");
        fgets(inputMsg, MAX_LENGTH, stdin);
        printf("Enter the watermark: ");
        fgets(watermark, MAX_LENGTH, stdin);
        embedWatermark(inputMsg, watermark);
        break;
      case 2:
        printf("Enter the input message: ");
        fgets(inputMsg, MAX_LENGTH, stdin);
        extractWatermark(inputMsg);
        break;
      case 3:
        printf("Thanks for using the Digital Watermarking Program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (menuChoice != 3);

  return 0;
}