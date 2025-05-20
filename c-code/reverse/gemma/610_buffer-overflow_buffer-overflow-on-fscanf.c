#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[256];
  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Buffer overflow vulnerability in fscanf
  char name[256];
  fscanf(fp, "%s", name);

  fclose(fp);

  // Rest of the program to read, add, update, and delete student records
}
