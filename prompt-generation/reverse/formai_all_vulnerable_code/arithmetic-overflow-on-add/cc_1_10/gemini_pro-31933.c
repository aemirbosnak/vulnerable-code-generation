//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
// A tragic tale of star-crossed files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Thine Romeo, the source file
typedef struct {
  char *name;
  char *content;
} Romeo;

// Thine Juliet, the backup file
typedef struct {
  char *name;
  char *content;
} Juliet;

// Friar Laurence, the backup system
void FriarLaurence(Romeo *romeo, Juliet *juliet) {
  // Copy Romeo's content to Juliet
  juliet->content = malloc(strlen(romeo->content) + 1);
  strcpy(juliet->content, romeo->content);

  // Unveil their secrets
  printf("Romeo:\n%s\n", romeo->content);
  printf("Juliet:\n%s\n", juliet->content);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create Romeo
  Romeo romeo;
  romeo.name = argv[1];
  romeo.content = NULL;

  // Open Romeo's file
  FILE *romeo_file = fopen(romeo.name, "r");
  if (romeo_file == NULL) {
    fprintf(stderr, "Error: Unable to open %s\n", romeo.name);
    return EXIT_FAILURE;
  }

  // Read Romeo's content
  int romeo_size;
  fseek(romeo_file, 0, SEEK_END);
  romeo_size = ftell(romeo_file);
  rewind(romeo_file);
  romeo.content = malloc(romeo_size + 1);
  fread(romeo.content, 1, romeo_size, romeo_file);
  romeo.content[romeo_size] = '\0';

  // Close Romeo's file
  fclose(romeo_file);

  // Create Juliet
  char juliet_name[strlen(romeo.name) + 5];
  strcpy(juliet_name, romeo.name);
  strcat(juliet_name, ".bak");
  Juliet juliet;
  juliet.name = juliet_name;
  juliet.content = NULL;

  // Friar Laurence's sacred work
  FriarLaurence(&romeo, &juliet);

  // Farewell, star-crossed files
  free(romeo.content);
  free(juliet.content);
  return EXIT_SUCCESS;
}