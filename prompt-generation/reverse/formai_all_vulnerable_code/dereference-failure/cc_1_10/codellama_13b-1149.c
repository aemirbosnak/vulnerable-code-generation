//Code Llama-13B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure to represent a file
typedef struct {
  char *name;
  char *content;
} File;

// Function to create a new file
File *create_file(char *name, char *content) {
  File *file = malloc(sizeof(File));
  file->name = strdup(name);
  file->content = strdup(content);
  return file;
}

// Function to read the content of a file
char *read_file(File *file) {
  return file->content;
}

// Function to write the content of a file
void write_file(File *file, char *content) {
  file->content = strdup(content);
}

// Function to delete a file
void delete_file(File *file) {
  free(file->name);
  free(file->content);
  free(file);
}

// Function to print the content of a file
void print_file(File *file) {
  printf("%s\n", file->content);
}

int main() {
  // Create a new file
  File *file = create_file("example.txt", "This is an example file.");

  // Read the content of the file
  char *content = read_file(file);
  printf("%s\n", content);

  // Write new content to the file
  write_file(file, "This is a modified file.");

  // Read the new content of the file
  content = read_file(file);
  printf("%s\n", content);

  // Delete the file
  delete_file(file);

  return 0;
}