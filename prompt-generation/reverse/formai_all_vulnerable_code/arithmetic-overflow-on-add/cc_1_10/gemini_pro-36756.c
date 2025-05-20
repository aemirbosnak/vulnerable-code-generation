//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the scroll structure
typedef struct {
  char *text;
  int length;
} Scroll;

// Function to read a scroll from a file
Scroll read_scroll(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the scroll
  Scroll scroll;
  scroll.text = malloc(size + 1);
  if (scroll.text == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  // Read the file into the scroll
  fread(scroll.text, 1, size, file);
  scroll.text[size] = '\0';

  // Close the file
  fclose(file);

  // Return the scroll
  return scroll;
}

// Function to display a scroll
void display_scroll(Scroll scroll) {
  // Print the scroll text
  printf("%s\n", scroll.text);
}

// Function to free the memory allocated to a scroll
void free_scroll(Scroll scroll) {
  // Free the scroll text
  free(scroll.text);
}

// Main function
int main(int argc, char **argv) {
  // Check if a filename was provided
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Read the scroll from the file
  Scroll scroll = read_scroll(argv[1]);

  // Display the scroll
  display_scroll(scroll);

  // Free the memory allocated to the scroll
  free_scroll(scroll);

  return 0;
}