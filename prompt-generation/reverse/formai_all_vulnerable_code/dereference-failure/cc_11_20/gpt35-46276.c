//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *file = NULL;
  char buffer[512];
  int line = 0;
  
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(1);
  }
  
  file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s: %s\n", argv[1], strerror(errno));
    exit(errno);
  }
  
  while (fgets(buffer, 512, file)) {
    line++;
    
    if (strlen(buffer) == 511 && buffer[510] != '\n') {
      fprintf(stderr, "Line %d: Input line too long\n", line);
      exit(1);
    }
    
    if (isdigit(buffer[0])) {
      int num = atoi(buffer);
      
      if (num < 0 || num > 100) {
        fprintf(stderr, "Line %d: Number out of range\n", line);
        exit(1);
      }
    }
  }
  
  if (ferror(file)) {
    fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
    exit(errno);
  }
  
  if (fclose(file) != 0) {
    fprintf(stderr, "Error closing file: %s\n", strerror(errno));
    exit(errno);
  }
  
  printf("File %s read successfully\n", argv[1]);
  
  return 0;
}