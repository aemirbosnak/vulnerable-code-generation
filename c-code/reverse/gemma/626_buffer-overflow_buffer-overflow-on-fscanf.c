#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[256];
  char data[1024];
  int option, word_count = 0;

  while (1) {
    printf("\nPlease select an option:");
    printf("\n1. Create file");
    printf("\n2. Read file");
    printf("\n3. Write to file");
    printf("\n4. Count words in file");
    printf("\nEnter your choice:");

    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter file name:");
        scanf("%s", filename);
        FILE *fp = fopen(filename, "w");
        fclose(fp);
        break;
      case 2:
        printf("Enter file name:");
        scanf("%s", filename);
        fp = fopen(filename, "r");
        fscanf(fp, "%s", data);
        fclose(fp);
        printf("File content:\n%s", data);
        break;
      case 3:
        printf("Enter file name:");
        scanf("%s", filename);
        fp = fopen(filename, "a");
        printf("Enter text:");
        scanf("%s", data);
        fprintf(fp, "%s", data);
        fclose(fp);
        break;
      case 4:
        printf("Enter file name:");
        scanf("%s", filename);
        fp = fopen(filename, "r");
        fscanf(fp, "%s", data);
        fclose(fp);
        word_count = 0;
        for (int i = 0; data[i] != '\0'; i++) {
          if (data[i] == ' ') {
            word_count++;
          }
        }
        printf("Word count: %d", word_count);
        break;
      default:
        printf("Invalid option");
    }

    if (option == 5) {
      break;
    }
  }

  return 0;
}
