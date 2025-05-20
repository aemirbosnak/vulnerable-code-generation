//FormAI DATASET v1.0 Category: File system simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISK_SIZE 100 // Maximum size of the disk in blocks
#define MAX_FILENAME_LENGTH 20 // Maximum length of the file name

typedef struct {
  char name[MAX_FILENAME_LENGTH];
  int start_block;
  int num_blocks;
} file_entry;

file_entry* file_system[MAX_DISK_SIZE]; // Array to store file entries
char disk[MAX_DISK_SIZE]; // Array to represent disk blocks, each block is a char

// Function to initialize the disk with empty blocks (represented by '-')
void initialize_disk() {
  memset(disk, '-', sizeof(disk));
}

// Function to create a new file entry
file_entry* create_file_entry(char* name, int start_block, int num_blocks) {
  file_entry* new_entry = malloc(sizeof(file_entry));
  strncpy(new_entry->name, name, MAX_FILENAME_LENGTH);
  new_entry->start_block = start_block;
  new_entry->num_blocks = num_blocks;
  return new_entry;
}

// Function to delete a file entry from the file system
void delete_file_entry(char* name) {
  int i;

  for (i = 0; i < MAX_DISK_SIZE; i++) {
    if (file_system[i] != NULL && strcmp(file_system[i]->name, name) == 0) {
      // Free the memory allocated to the file entry
      free(file_system[i]);
      // Update the file system array to show that the block(s) are now free
      int j;
      for (j = 0; j < file_system[i]->num_blocks; j++) {
        disk[file_system[i]->start_block + j] = '-';
      }
      file_system[i] = NULL;
      printf("File %s deleted.\n", name);
      return;
    }
  }

  printf("File %s not found.\n", name);
}

// Function to add a file to the file system
void add_file(char* name, int size) {
  int i, j, num_free_blocks = 0;

  // Check if the file already exists
  for (i = 0; i < MAX_DISK_SIZE; i++) {
    if (file_system[i] != NULL && strcmp(file_system[i]->name, name) == 0) {
      printf("File %s already exists.\n", name);
      return;
    }
  }

  // Check if there are enough free blocks to accommodate the file
  for (i = 0; i < MAX_DISK_SIZE; i++) {
    if (disk[i] == '-') {
      num_free_blocks++;
      if (num_free_blocks == size) {
        // Allocate the blocks to the file
        int start_block = i - size + 1;
        file_entry* new_entry = create_file_entry(name, start_block, size);
        for (j = 0; j < size; j++) {
          disk[start_block + j] = '#'; // Mark the block as used by the file
        }
        // Add the file entry to the file system array
        for (j = 0; j < MAX_DISK_SIZE; j++) {
          if (file_system[j] == NULL) {
            file_system[j] = new_entry;
            printf("File %s added.\n", name);
            return;
          }
        }
        printf("Error: File system is full.\n");
        return;
      }
    } else {
      num_free_blocks = 0;
    }
  }

  printf("Error: Not enough free space on the disk.\n");
}

// Function to print the file system contents
void print_file_system() {
  int i;

  printf("Disk contents:\n");
  for (i = 0; i < MAX_DISK_SIZE; i++) {
    printf("%c ", disk[i]);
  }
  printf("\n");

  printf("File system:\n");
  for (i = 0; i < MAX_DISK_SIZE; i++) {
    if (file_system[i] != NULL) {
      printf("%s (start block: %d, num blocks: %d)\n", file_system[i]->name, file_system[i]->start_block, file_system[i]->num_blocks);
    }
  }
}

int main() {
  int choice;
  char name[MAX_FILENAME_LENGTH];
  int size;

  initialize_disk();

  while (1) {
    printf("\n1. Add file\n");
    printf("2. Delete file\n");
    printf("3. Print file system\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter file name: ");
        scanf("%s", name);
        printf("Enter file size (in blocks): ");
        scanf("%d", &size);
        add_file(name, size);
        break;
      case 2:
        printf("Enter file name: ");
        scanf("%s", name);
        delete_file_entry(name);
        break;
      case 3:
        print_file_system();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}