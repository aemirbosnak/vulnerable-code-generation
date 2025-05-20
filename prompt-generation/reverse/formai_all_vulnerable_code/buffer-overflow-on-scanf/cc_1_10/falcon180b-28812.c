//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input_file[100];
  printf("Enter input file name: ");
  scanf("%s", input_file);

  FILE *fp = fopen(input_file, "rb");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  char buffer[1024];
  int file_size = 0;
  while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
    file_size += strlen(buffer);
  }
  fclose(fp);

  char *file_data = malloc(file_size + 1);
  fp = fopen(input_file, "rb");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  fread(file_data, 1, file_size, fp);
  fclose(fp);
  file_data[file_size] = '\0';

  int virus_count = 0;
  char *viruses[] = {"virus1", "virus2", "virus3"};
  int virus_sizes[] = {10, 20, 30};

  for (int i = 0; i < sizeof(viruses)/sizeof(char *); i++) {
    char *virus = viruses[i];
    int virus_size = virus_sizes[i];
    int j;
    for (j = 0; j <= file_size - virus_size; j++) {
      if (strncmp(file_data + j, virus, virus_size) == 0) {
        virus_count++;
        break;
      }
    }
  }

  if (virus_count == 0) {
    printf("No viruses found.\n");
  } else {
    printf("%d viruses found.\n", virus_count);
  }

  free(file_data);
  return 0;
}