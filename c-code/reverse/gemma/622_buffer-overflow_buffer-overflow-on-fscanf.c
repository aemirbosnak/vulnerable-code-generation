#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int choice;
  char filename[256];
  char text[1024];

  printf("Menu:\n");
  printf("1. Create File\n");
  printf("2. Read File\n");
  printf("3. Write File\n");
  printf("4. Word Count\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter file name: ");
      scanf("%s", filename);
      FILE *fp = fopen(filename, "w");
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
      fp = fopen(filename, "w");
      printf("Enter text: ");
      scanf("%s", text);
      fprintf(fp, "%s", text);
      fclose(fp);
      break;
    case 4:
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "r");
      fscanf(fp, "%s", text);
      fclose(fp);
      int word_count = 0;
      char *word = strtok(text, " ");
      while (word) {
        word_count++;
        word = strtok(NULL, " ");
      }
      printf("Word count: %d", word_count);
      break;
    default:
      printf("Invalid choice");
  }

  return 0;
}
