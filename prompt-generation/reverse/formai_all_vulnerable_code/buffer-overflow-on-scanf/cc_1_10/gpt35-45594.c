//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <string.h>

struct metadata {
  char artist[50];
  char album[50];
  char year[5];
  char genre[20];
};

struct metadata extract_metadata(char *filename) {
  struct metadata data = {"", "", "", ""};
  char line[100];
  FILE *fp;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return data;
  }

  while (fgets(line, 100, fp)) {
    if (strstr(line, "artist")) {
      sscanf(line, "%*[^=]=%[^\n]", data.artist);
    }
    else if (strstr(line, "album")) {
      sscanf(line, "%*[^=]=%[^\n]", data.album);
    }
    else if (strstr(line, "year")) {
      sscanf(line, "%*[^=]=%[^\n]", data.year);
    }
    else if (strstr(line, "genre")) {
      sscanf(line, "%*[^=]=%[^\n]", data.genre);
    }
  }

  fclose(fp);
  return data;
}

int main() {
  char filename[50];
  struct metadata data;

  printf("Enter the name of the file:\n");
  scanf("%s", filename);

  data = extract_metadata(filename);

  if (strcmp(data.artist, "") == 0) {
    printf("Error: metadata not found\n");
    return 0;
  }

  printf("Artist: %s\n", data.artist);
  printf("Album: %s\n", data.album);
  printf("Year: %s\n", data.year);
  printf("Genre: %s\n", data.genre);

  return 0;
}