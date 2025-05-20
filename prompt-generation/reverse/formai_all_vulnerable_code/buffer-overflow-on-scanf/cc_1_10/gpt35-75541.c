//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 100
#define MAX_MESSAGE_SIZE 10000
#define MAX_FILE_SIZE 500000

void hide_message(char *image_file_name, char *message_file_name, char *output_file_name) {
  FILE *image_file, *message_file, *output_file;
  char image_data[MAX_FILE_SIZE], message_data[MAX_MESSAGE_SIZE], temp_data[MAX_FILE_SIZE];
  char extension[4];
  size_t image_size, message_size, total_size, i, j;
  int message_byte_index, message_bit_index, current_bit, image_byte_index;

  // Load image file into memory
  image_file = fopen(image_file_name, "rb");
  if (!image_file) {
    printf("Error: Unable to open image file.\n");
    exit(1);
  }
  fseek(image_file, 0, SEEK_END);
  image_size = ftell(image_file);
  rewind(image_file);
  fread(image_data, 1, image_size, image_file);
  fclose(image_file);

  // Get file extension
  strcpy(extension, &image_file_name[strlen(image_file_name)-3]);

  // Load message file into memory
  message_file = fopen(message_file_name, "rb");
  if (!message_file) {
    printf("Error: Unable to open message file.\n");
    exit(1);
  }
  message_size = fread(message_data, 1, MAX_MESSAGE_SIZE, message_file);
  fclose(message_file);

  // Check if message is too large to fit in the image
  total_size = strlen(extension) + message_size + 6;  // size of extension + size of message + size of other headers
  if (total_size > image_size) {
    printf("Error: Message is too large to fit in the image file.\n");
    exit(1);
  }

  // Copy image data to output file
  output_file = fopen(output_file_name, "wb");
  if (!output_file) {
    printf("Error: Unable to create output file.\n");
    exit(1);
  }
  fwrite(image_data, 1, total_size, output_file);

  // Write message header
  fwrite("MSCN", 1, 4, output_file);
  fwrite(&message_size, sizeof(size_t), 1, output_file);

  // Write message data
  fwrite(message_data, 1, message_size, output_file);

  // Write file extension header
  fwrite("EXTN", 1, 4, output_file);
  fwrite(extension, 1, 3, output_file);

  // Write image data
  fwrite(&image_data[total_size], 1, image_size - total_size, output_file);

  fclose(output_file);

  printf("Message hidden successfully!\n");
}

void extract_message(char *image_file_name, char *output_file_name) {
  FILE *image_file, *output_file;
  char image_data[MAX_FILE_SIZE], message_data[MAX_MESSAGE_SIZE], temp_data[MAX_FILE_SIZE];
  char extension[4];
  size_t image_size, message_size;
  int message_byte_index, message_bit_index, current_bit, i, j;

  // Load image file into memory
  image_file = fopen(image_file_name, "rb");
  if (!image_file) {
    printf("Error: Unable to open image file.\n");
    exit(1);
  }
  fseek(image_file, 0, SEEK_END);
  image_size = ftell(image_file);
  rewind(image_file);
  fread(image_data, 1, image_size, image_file);
  fclose(image_file);

  // Extract message header
  if (strncmp(&image_data[image_size-10], "MSCN", 4) != 0) {  // message header not found
    printf("Error: No message found in the image file.\n");
    exit(1);
  }
  memcpy(&message_size, &image_data[image_size-6], sizeof(size_t));

  // Check if message is too large to fit in the buffer
  if (message_size > MAX_MESSAGE_SIZE) {
    printf("Error: Message size is too large.\n");
    exit(1);
  }

  // Extract message data
  memcpy(message_data, &image_data[image_size-message_size-10], message_size);

  // Extract file extension header
  if (strncmp(&image_data[image_size-message_size-14], "EXTN", 4) != 0) {  // extension header not found
    printf("Error: No file extension found in the image file.\n");
    exit(1);
  }
  memcpy(extension, &image_data[image_size-message_size-11], 3);
  extension[3] = '\0';

  // Copy image data to output file
  output_file = fopen(output_file_name, "wb");
  if (!output_file) {
    printf("Error: Unable to create output file.\n");
    exit(1);
  }
  fwrite(message_data, 1, message_size, output_file);
  fclose(output_file);

  printf("Message extracted successfully!\nFile extension: %s\n", extension);
}

int main(int argc, char **argv) {
  char image_file_name[FILE_NAME_SIZE], message_file_name[FILE_NAME_SIZE], output_file_name[FILE_NAME_SIZE];
  char action;

  // Get input parameters
  if (argc != 4) {
    printf("Usage: image_stegano <hide/extract> <image file> <input/output file>\n");
    exit(1);
  }
  action = argv[1][0];
  strcpy(image_file_name, argv[2]);
  strcpy(output_file_name, argv[3]);

  switch (action) {
    case 'h':
      printf("Enter message file name: ");
      scanf("%s", message_file_name);
      hide_message(image_file_name, message_file_name, output_file_name);
      break;
    case 'e':
      extract_message(image_file_name, output_file_name);
      break;
    default:
      printf("Invalid action.\n");
      exit(1);
  }

  return 0;
}