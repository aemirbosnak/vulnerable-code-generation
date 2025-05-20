#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp_in, *fp_out;
  char str[1024];
  fp_in = fopen("words.txt", "r");
  fp_out = fopen("translated.txt", "w");

  fscanf(fp_in, "%s", str);
  strcpy(str, str + strcspn(str, "abcdefghijklmnopqrstuvwxyz"));
  str[0] = str[0] - 32;
  strcat(str, "ay");

  fprintf(fp_out, "%s", str);

  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
