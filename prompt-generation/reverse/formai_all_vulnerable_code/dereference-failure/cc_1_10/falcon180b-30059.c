//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
  char input_file[100], output_file[100];
  char key[100];
  char ch;
  FILE *fp, *out;
  int i, j, k, n, len;
  char buffer[100];
  time_t t;
  srand((unsigned) time(&t));

  printf("Enter the name of the input file: ");
  scanf("%s", input_file);

  printf("Enter the name of the output file: ");
  scanf("%s", output_file);

  printf("Enter the encryption key: ");
  scanf("%s", key);

  fp = fopen(input_file, "r");
  if (fp == NULL) {
    printf("Error: Input file not found.\n");
    exit(0);
  }

  out = fopen(output_file, "w");
  if (out == NULL) {
    printf("Error: Output file not created.\n");
    exit(0);
  }

  while ((ch = fgetc(fp))!= EOF) {
    if (isalpha(ch)) {
      n = rand() % 26 + 65;
      ch = toupper(ch);
      ch = (char) (ch + n);
    }
    else if (isdigit(ch)) {
      n = rand() % 10 + 48;
      ch = (char) n;
    }
    else {
      ch = ch;
    }
    fputc(ch, out);
  }

  fclose(fp);
  fclose(out);

  printf("File encrypted successfully.\n");

  return 0;
}