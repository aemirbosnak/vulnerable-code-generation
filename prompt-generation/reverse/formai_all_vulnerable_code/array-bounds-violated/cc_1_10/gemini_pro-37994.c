//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIGS 100

char *sigs[MAX_SIGS];
int sigs_count = 0;

int load_sigs(char *filename) {
  FILE *fp;
  char line[1024];
  int i;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    sigs[sigs_count++] = strdup(line);
  }

  fclose(fp);
  return 0;
}

int scan_file(char *filename) {
  FILE *fp;
  char buf[1024];
  int i;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }

  while (fread(buf, sizeof(char), sizeof(buf), fp) > 0) {
    for (i = 0; i < sigs_count; i++) {
      if (strstr(buf, sigs[i]) != NULL) {
        fclose(fp);
        return 1;
      }
    }
  }

  fclose(fp);
  return 0;
}

int main(int argc, char *argv[]) {
  int i;

  if (argc < 3) {
    printf("Usage: %s <signature file> <file to scan>\n", argv[0]);
    return 1;
  }

  if (load_sigs(argv[1]) != 0) {
    printf("Error loading signatures.\n");
    return 1;
  }

  if (scan_file(argv[2]) != 0) {
    printf("File is infected.\n");
    return 1;
  } else {
    printf("File is clean.\n");
    return 0;
  }
}