#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int choice, file_num;
  char filename[255];
  FILE *fp;
  char text[1024];
  int words = 0;

  printf("1. Create File\n");
  printf("2. Read File\n");
  printf("3. Write to File\n");
  printf("4. Count Words in File\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "w");
      fclose(fp);
      break;
    case 2:
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "r");
      fscanf(fp, "%s", text);
      fclose(fp);
      printf("Text: %s", text);
      break;
    case 3:
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "a");
      printf("Enter text: ");
      scanf("%s", text);
      fprintf(fp, "%s", text);
      fclose(fp);
      break;
    case 4:
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "r");
      words = count_words(fp);
      fclose(fp);
      printf("Number of words: %d", words);
      break;
  }

  return 0;
}

int count_words(FILE *fp) {
  char word[255];
  int words = 0;

  while (fscanf(fp, "%s", word) != EOF) {
    words++;
  }

  return words;
}
