//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_DATA_SIZE 10000
#define STG_FILE_NAME "steganography.txt"

void hide_data(char* image_file_name, char* data_file_name);
void retrieve_data(char* image_file_name);

int main()
{
  char image_file_name[MAX_FILE_NAME];
  char data_file_name[MAX_FILE_NAME];
  int choice;

  printf("Welcome to Romantic Steganography!\n");
  printf("Please select an option:\n");
  printf("1. Hide data in an image\n");
  printf("2. Retrieve data from an image\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Please enter the image file name (with extension): ");
      scanf("%s", image_file_name);
      printf("Please enter the data file name (with extension): ");
      scanf("%s", data_file_name);
      hide_data(image_file_name, data_file_name);
      printf("Data successfully hidden in %s\n", image_file_name);
      break;
    case 2:
      printf("Please enter the image file name (with extension): ");
      scanf("%s", image_file_name);
      retrieve_data(image_file_name);
      break;
    default:
      printf("Invalid choice\n");
      return 1;
  }

  return 0;
}

void hide_data(char* image_file_name, char* data_file_name) {
  FILE* image_file = fopen(image_file_name, "rb");
  if (!image_file) {
    printf("Error opening image file\n");
    exit(1);
  }

  FILE* data_file = fopen(data_file_name, "r");
  if (!data_file) {
    printf("Error opening data file\n");
    exit(1);
  }

  FILE* stg_file = fopen(STG_FILE_NAME, "wb");

  char data[MAX_DATA_SIZE];
  while (fgets(data, MAX_DATA_SIZE, data_file)) {
    size_t data_len = strlen(data);
    for (size_t i = 0; i < data_len; i++) {
      char data_char = data[i];
      for (int j = 7; j >= 0; j--) {
        char image_char;
        fread(&image_char, sizeof(char), 1, image_file);
        if (feof(image_file)) {
          printf("Error: Image file not large enough to hide data\n");
          exit(1);
        }
        char bit = ((data_char >> j) & 1);
        image_char = (image_char & 0xFE) | bit;
        fwrite(&image_char, sizeof(char), 1, stg_file);
      }
    }
  }

  char image_char = 0x00;
  while (!feof(image_file)) {
    fread(&image_char, sizeof(char), 1, image_file);
    fwrite(&image_char, sizeof(char), 1, stg_file);
  }

  fclose(image_file);
  fclose(data_file);
  fclose(stg_file);

  remove(image_file_name);
  rename(STG_FILE_NAME, image_file_name);
}

void retrieve_data(char* image_file_name) {
  FILE* image_file = fopen(image_file_name, "rb");
  if (!image_file) {
    printf("Error opening image file\n");
    exit(1);
  }

  char data[MAX_DATA_SIZE] = {0};
  int data_index = 0;
  char buffer = 0x00;
  int bit_count = 0;

  while (!feof(image_file)) {
    char image_char;
    fread(&image_char, sizeof(char), 1, image_file);
    char bit = (image_char & 0x01);
    buffer |= (bit << (7 - bit_count));
    bit_count++;
    if (bit_count == 8) {
      data[data_index++] = buffer;
      buffer = 0x00;
      bit_count = 0;
    }
  }

  printf("Retrieved data:\n%s\n", data);

  fclose(image_file);
}