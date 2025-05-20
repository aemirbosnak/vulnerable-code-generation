//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a file
int recoverData(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Allocate memory to store the file data
  char *data = (char *)malloc(size);
  if (data == NULL) {
    printf("Error allocating memory\n");
    fclose(fp);
    return -1;
  }

  // Read the file data into memory
  if (fread(data, 1, size, fp) != size) {
    printf("Error reading file data\n");
    fclose(fp);
    free(data);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Search for the data signature
  char *signature = "XYZ";
  char *found = strstr(data, signature);
  if (found == NULL) {
    printf("Data signature not found\n");
    free(data);
    return -1;
  }

  // Calculate the offset of the data
  int offset = found - data;

  // Allocate memory to store the recovered data
  char *recoveredData = (char *)malloc(size - offset);
  if (recoveredData == NULL) {
    printf("Error allocating memory\n");
    free(data);
    return -1;
  }

  // Copy the recovered data into memory
  memcpy(recoveredData, found, size - offset);

  // Save the recovered data to a new file
  fp = fopen("recovered_data.txt", "wb");
  if (fp == NULL) {
    printf("Error opening file recovered_data.txt\n");
    free(data);
    free(recoveredData);
    return -1;
  }

  // Write the recovered data to the file
  if (fwrite(recoveredData, 1, size - offset, fp) != size - offset) {
    printf("Error writing recovered data to file\n");
    fclose(fp);
    free(data);
    free(recoveredData);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Free the allocated memory
  free(data);
  free(recoveredData);

  // Return success
  return 0;
}

// Main function
int main() {
  // Get the filename from the user
  char filename[256];
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Recover the data from the file
  if (recoverData(filename) == 0) {
    printf("Data recovered successfully\n");
  } else {
    printf("Error recovering data\n");
  }

  return 0;
}