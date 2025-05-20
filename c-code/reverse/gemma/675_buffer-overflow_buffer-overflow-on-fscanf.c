#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename1, *filename2;
  FILE *fp1, *fp2;

  printf("Enter the name of the file to read:");
  scanf("%s", filename1);

  printf("Enter the name of the file to write:");
  scanf("%s", filename2);

  fp1 = fopen(filename1, "r");
  if (fp1 == NULL) {
    printf("Error opening file: %s", filename1);
    return 1;
  }

  fp2 = fopen(filename2, "w");
  if (fp2 == NULL) {
    printf("Error opening file: %s", filename2);
    fclose(fp1);
    return 1;
  }

  char word[100];
  while (fscanf(fp1, "%s", word) != EOF) {
    word[0] = toupper(word[0]);
    strcat(word, "ay");
    fprintf(fp2, "%s\n", word);
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}
