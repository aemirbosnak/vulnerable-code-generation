#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename1[256], filename2[256];
  FILE *fp1, *fp2;
  char word[256];

  printf("Enter the name of the file to read:");
  scanf("%s", filename1);

  printf("Enter the name of the file to write:");
  scanf("%s", filename2);

  fp1 = fopen(filename1, "r");
  fp2 = fopen(filename2, "w");

  if (fp1 == NULL) {
    printf("Error opening file: %s", filename1);
    return 1;
  }

  if (fp2 == NULL) {
    printf("Error opening file: %s", filename2);
    fclose(fp1);
    return 1;
  }

  while (fscanf(fp1, "%s", word) != EOF) {
    char pig_latin[256];
    pig_latin[0] = 'a' + (strlen(word) - 1) / 2;
    for (int i = 0; i < strlen(word); i++) {
      pig_latin[i + 1] = word[i] + 3;
    }
    fprintf(fp2, "%s\n", pig_latin);
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}
