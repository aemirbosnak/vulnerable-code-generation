//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
  char author[20];
  char title[50];
  char date[20];
  char version[10];
} Metadata;

Metadata extractMetadata(char* filename) {
  FILE* fp = fopen(filename, "r");
  Metadata metadata;
  if (fp == NULL) {
    printf("Unable to open file '%s'\n", filename);
    exit(0);
  }
  char line[100];
  char* token;
  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "Author:")) {
      token = strtok(line, ":");
      strcpy(metadata.author, strtok(NULL, "\n"));
    } else if (strstr(line, "Title:")) {
      token = strtok(line, ":");
      strcpy(metadata.title, strtok(NULL, "\n"));
    } else if (strstr(line, "Date:")) {
      token = strtok(line, ":");
      strcpy(metadata.date, strtok(NULL, "\n"));
    } else if (strstr(line, "Version:")) {
      token = strtok(line, ":");
      strcpy(metadata.version, strtok(NULL, "\n"));
    }
  }
  fclose(fp);
  return metadata;
}

int main() {
  char filename[50];
  printf("Enter filename:");
  scanf("%s", filename);
  Metadata metadata = extractMetadata(filename);
  printf("\nMetadata for file '%s':\n", filename);
  printf("Author: %s\n", metadata.author);
  printf("Title: %s\n", metadata.title);
  printf("Date: %s\n", metadata.date);
  printf("Version: %s\n", metadata.version);
  return 0;
}