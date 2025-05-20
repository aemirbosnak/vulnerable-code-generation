//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 128
#define MAX_BUFFER_SIZE 4096

/* This function recovers data from a file and puts it into a buffer */
int recover_data(char *file_name, char *buffer) {
  FILE *fp;
  int bytes_read = 0;

  fp = fopen(file_name, "rb");
  if (fp == NULL) {
    return 0;
  }

  fseek(fp, 0L, SEEK_END);
  int file_size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  bytes_read = fread(buffer, sizeof(char), file_size, fp);
  fclose(fp);

  if (bytes_read != file_size) {
    return 0;
  } else {
    return bytes_read;
  }
}

/* This function writes the recovered data to a new file */
int save_data(char *file_name, char *buffer, int buffer_size) {
  FILE *fp;

  fp = fopen(file_name, "wb");
  if (fp == NULL) {
    return 0;
  }

  fwrite(buffer, sizeof(char), buffer_size, fp);
  fclose(fp);

  return 1;
}

/* Main function */
int main() {
  char file_name[MAX_FILE_NAME_LEN];
  char buffer[MAX_BUFFER_SIZE];
  int data_size = 0;

  printf("Enter file name: ");
  scanf("%s", file_name);

  /* Attempt to recover data */
  data_size = recover_data(file_name, buffer);
  if (data_size == 0) {
    printf("Error: file '%s' could not be recovered\n", file_name);
    return -1;
  }

  printf("Recovered data:\n%s", buffer);

  /* Ask user if they want to save the recovered data to a new file */
  char save_choice;
  printf("\nDo you want to save the recovered data to a new file? (y/n): ");
  scanf(" %c", &save_choice);

  if (save_choice == 'y' || save_choice == 'Y') {
    char new_file_name[MAX_FILE_NAME_LEN];
    printf("Enter new file name: ");
    scanf("%s", new_file_name);

    /* Attempt to save the recovered data to a new file */
    int save_result = save_data(new_file_name, buffer, data_size);
    if (save_result == 0) {
      printf("Error: data could not be saved to new file '%s'\n", new_file_name);
      return -1;
    }

    printf("Data successfully saved to new file '%s'\n", new_file_name);
  }

  return 0;
}