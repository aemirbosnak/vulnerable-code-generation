//FormAI DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>

#define BLOCK_SIZE 512
#define FILENAME_SIZE 100

int main(void) {

  FILE *read_ptr = NULL, *write_ptr = NULL;
  char filename[FILENAME_SIZE];
  unsigned char block[BLOCK_SIZE];
  size_t blocks_read = 0;

  printf("Enter file name to recover: ");
  scanf("%s", filename);

  // Open file for reading
  read_ptr = fopen(filename, "rb");
  if (read_ptr == NULL) {
    printf("Error opening file %s!\n", filename);
    return 1;
  }

  // Determine size of file
  fseek(read_ptr, 0, SEEK_END);
  size_t size = ftell(read_ptr);
  fseek(read_ptr, 0, SEEK_SET);

  // Create output file
  write_ptr = fopen("recovered_file", "wb");
  if (write_ptr == NULL) {
    printf("Error creating output file!\n");
    fclose(read_ptr);
    return 1;
  }

  printf("Attempting to recover file %s...\n", filename);

  // Read file block by block
  while (fread(block, BLOCK_SIZE, 1, read_ptr) == 1) {
    // Check if block starts with a JPEG signature
    if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0) {
      // If a new JPEG file has been found, close previous file
      if (blocks_read != 0) {
        fclose(write_ptr);
      }
      // Generate new file name
      char temp_filename[FILENAME_SIZE];
      sprintf(temp_filename, "file_%zd.jpg", blocks_read);
      // Open new file for writing
      write_ptr = fopen(temp_filename, "wb");
      if (write_ptr == NULL) {
        printf("Error creating output file!\n");
        fclose(read_ptr);
        return 1;
      }
      blocks_read++;
    }
    // Write current block to output file
    fwrite(block, BLOCK_SIZE, 1, write_ptr);
  }

  // Close files
  fclose(read_ptr);
  fclose(write_ptr);

  printf("%zd file(s) successfully recovered!\n", blocks_read);

  return 0;
}