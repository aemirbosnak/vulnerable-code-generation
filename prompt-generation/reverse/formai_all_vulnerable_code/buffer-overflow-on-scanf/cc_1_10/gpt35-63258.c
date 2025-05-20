//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>

int main() {
  FILE *file_ptr;
  char file_name[20];
  int num;

  printf("Enter the name of the file to open: ");
  scanf("%s", file_name);

  // open the file
  file_ptr = fopen(file_name, "r");

  if (file_ptr == NULL) {
    printf("Error opening file %s!",file_name);
    return 1; // exit the program with error code
  }

  printf("Enter the number to read from the file: ");
  scanf("%d", &num);

  if (feof(file_ptr)) {
    printf("End of file reached!");
    return 1; // exit the program with error code
  }

  // read the number from the file
  int file_num;
  int num_read = fscanf(file_ptr, "%d", &file_num);

  if (num_read != 1) {
    printf("Error reading from file %s!",file_name);
    fclose(file_ptr);
    return 1; // exit the program with error code
  }

  // check if the number matches the input
  if (num != file_num) {
    printf("Number %d does not match the number in the file %d!",num, file_num);
    fclose(file_ptr);
    return 1; // exit the program with error code
  }

  // close the file
  fclose(file_ptr);

  printf("The numbers match! Program completed successfully.");

  return 0; // exit the program with success code
}