//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define MAX_WATERMARK_LENGTH 100

char* generateWatermark(char* message, char* watermark) {
  int i, j;
  int lenMessage = strlen(message);
  int lenWatermark = strlen(watermark);
  char* encodedMessage = (char*)malloc(sizeof(char) * (lenMessage + 2 * lenWatermark + 1));
  
  for(i=0, j=0; i<lenMessage; i++, j++) {
    if(j == lenWatermark) {
      encodedMessage[j++] = watermark[0];
      encodedMessage[j++] = watermark[1];
    }
    encodedMessage[j] = message[i];
  }
  
  encodedMessage[j++] = watermark[0];
  encodedMessage[j++] = watermark[1];
  encodedMessage[j] = '\0';
  
  return encodedMessage;
}

char* getMessageFromWatermark(char* encodedMessage, char* watermark) {
  int i, j;
  int lenEncodedMessage = strlen(encodedMessage);
  int lenWatermark = strlen(watermark);
  char* message = (char*)malloc(sizeof(char) * (lenEncodedMessage - 2 * lenWatermark + 1));
  
  for(i=0, j=0; i<(lenEncodedMessage - 2 * lenWatermark); i++, j++) {
    if(encodedMessage[i] == watermark[0] && encodedMessage[i+1] == watermark[1]) {
      i += lenWatermark-1;
    }
    else {
      message[j] = encodedMessage[i];
    }
  }
  
  message[j] = '\0';
  
  return message;
}

int main() {
  char message[MAX_MSG_LENGTH];
  char watermark[MAX_WATERMARK_LENGTH];
  char* encodedMessage;
  char* decodedMessage;
  
  printf("Enter message: ");
  scanf("%[^\n]", message);
  
  printf("Enter watermark (2 characters): ");
  scanf(" %c%c", &watermark[0], &watermark[1]);
  
  encodedMessage = generateWatermark(message, watermark);
  printf("Encoded Message: %s\n", encodedMessage);
  
  decodedMessage = getMessageFromWatermark(encodedMessage, watermark);
  printf("Decoded Message: %s\n", decodedMessage);
  
  free(encodedMessage);
  free(decodedMessage);
  
  return 0;
}