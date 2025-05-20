//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: immersive
// C Immersive Image Steganography Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to extract a message from an image
void extract_message(char *image_file, char *message) {
  // Open the image file
  FILE *fp = fopen(image_file, "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  // Read the image file and extract the message
  char *message_buffer = malloc(1024);
  if (message_buffer == NULL) {
    printf("Error allocating memory\n");
    return;
  }
  int message_length = 0;
  while (1) {
    char c = fgetc(fp);
    if (c == EOF) {
      break;
    }
    if (isalnum(c)) {
      message_buffer[message_length++] = c;
    }
  }
  message_buffer[message_length] = '\0';
  strcpy(message, message_buffer);
  free(message_buffer);
  fclose(fp);
}

// Function to embed a message in an image
void embed_message(char *image_file, char *message) {
  // Open the image file
  FILE *fp = fopen(image_file, "rb+");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  // Read the image file and extract the message
  char *message_buffer = malloc(1024);
  if (message_buffer == NULL) {
    printf("Error allocating memory\n");
    return;
  }
  int message_length = strlen(message);
  int i = 0;
  while (i < message_length) {
    char c = message[i];
    if (isalnum(c)) {
      fseek(fp, i, SEEK_SET);
      fputc(c, fp);
    }
    i++;
  }
  free(message_buffer);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 3) {
    printf("Usage: %s <image_file> <message>\n", argv[0]);
    return 1;
  }

  // Extract the message from the image
  char *message = malloc(1024);
  if (message == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }
  extract_message(argv[1], message);

  // Embed the message in the image
  embed_message(argv[1], message);

  // Print the extracted message
  printf("Extracted message: %s\n", message);

  return 0;
}