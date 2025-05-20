//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define SIZE 8
#define WATERFALL_THRESHOLD 60

void addWatermark(char text[MAX], char watermark[]) {
   int textLen = strlen(text);
   int watermarkLen = strlen(watermark);
   int i, j = 0, k;
   char binary [textLen * SIZE];
   int watermarkBinary [watermarkLen * SIZE];

   for (i = 0; i < textLen; i++) {
      int asciiVal = text[i];
      for (j = 0; j < SIZE; j++) {
         binary[i * SIZE + j] = (asciiVal % 2) + '0';
         asciiVal = asciiVal / 2;
      }
   }
   for (i = 0; i < watermarkLen; i++) {
      int asciiVal = watermark[i];
      for (j = 0; j < SIZE; j++) {
         watermarkBinary [i * SIZE + j] = (asciiVal % 2);
         asciiVal = asciiVal / 2;
      }
   }

   int watermarkIndex = 0;
   for (i = 0; i < textLen * SIZE; i++) {
      if (watermarkIndex >= watermarkLen * SIZE) {
         break;
      }
      if (binary [ i ] == '1') {
         binary[i] = (watermarkBinary[watermarkIndex] == 1) ? '1' : '0';
         watermarkIndex++;
      }
   }

   for (i = 0; i < textLen / SIZE; i++) {
      char byte [SIZE + 1] = {'\0'};
      for (j = 0; j < SIZE; j++) {
         byte[j] = binary[i * SIZE + j];
      }
      char character = strtol(byte, 0, 2);
      text[i] = character;
   }
}

int detectWatermark(char text[MAX], char watermark[]) {
   int textLen = strlen(text);
   int watermarkLen = strlen(watermark);
   int i, j = 0, k;
   char binary [textLen * SIZE];
   int watermarkBinary [watermarkLen * SIZE];
   int found = 0;
   int numChanges = 0;
   int changeCount = 0;

   for (i = 0; i < textLen; i++) {
      int asciiVal = text[i];
      for (j = 0; j < SIZE; j++) {
         binary[i * SIZE + j] = (asciiVal % 2) + '0';
         asciiVal = asciiVal / 2;
      }
   }
   for (i = 0; i < watermarkLen; i++) {
      int asciiVal = watermark[i];
      for (j = 0; j < SIZE; j++) {
         watermarkBinary [i * SIZE + j] = (asciiVal % 2);
         asciiVal = asciiVal / 2;
      }
   }

   int watermarkIndex = 0;
   for (i = 0; i < textLen * SIZE; i++) {
      if (watermarkIndex >= watermarkLen * SIZE) {
         break;
      }
      if (binary [ i ] == '1') {
         if (watermarkBinary[watermarkIndex] == 1) {
            found++;
         }
         watermarkIndex++;
      } else {
         if (found > 0) {
            if (found >= WATERFALL_THRESHOLD) {
               numChanges++;
               changeCount += found;
            }
            found = 0;
         }
      }
   }
   if (found > 0) {
      if (found >= WATERFALL_THRESHOLD) {
         numChanges++;
         changeCount += found;
      }
      found = 0;
   }
   
   if (numChanges == 0) {
      return 0;
   } else {
      return changeCount / numChanges;
   }
}

int main (){
    char text [MAX];
    char watermark [MAX];
    char choice;
    printf("Enter text: ");
    fgets(text, MAX, stdin);
    printf("Enter watermark: ");
    fgets(watermark, MAX, stdin);
    printf("Do you want to add the watermark? (y/n)");
    scanf("%c", &choice);
    while ((getchar()) != '\n');
    if (choice == 'y') {
        addWatermark(text, watermark);
        printf("Watermark added to text.\n");
    }
    int strength = detectWatermark(text, watermark);
    if (strength == 0) {
        printf("Watermark not found in text.\n");
    } else {
        printf("Watermark detected with strength %d.\n", strength);
    }
    return 0;
}