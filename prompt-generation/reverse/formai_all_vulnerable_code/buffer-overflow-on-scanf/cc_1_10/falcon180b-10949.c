//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CODE_LENGTH 4096
#define MAX_TABLE_LENGTH 4096
#define MAX_INPUT_LENGTH 4096
#define MAX_OUTPUT_LENGTH 4096

typedef struct {
  char input[MAX_INPUT_LENGTH];
  char output[MAX_OUTPUT_LENGTH];
} CodeTable;

void InitializeTable(CodeTable *table) {
  memset(table, 0, sizeof(CodeTable));
  table->input[0] = '\0';
  table->output[0] = '\0';
}

int AddToTable(CodeTable *table, char *input, char *output) {
  int i = 0;
  while (i < MAX_TABLE_LENGTH && table->input[i]!= '\0') {
    if (strcmp(table->input[i], input) == 0) {
      strcpy(table->output[i], output);
      return 1;
    }
    i++;
  }
  if (i >= MAX_TABLE_LENGTH) {
    return 0;
  }
  strcpy(table->input[i], input);
  strcpy(table->output[i], output);
  i++;
  return 1;
}

int FindInTable(CodeTable *table, char *input) {
  int i = 0;
  while (i < MAX_TABLE_LENGTH && table->input[i]!= '\0') {
    if (strcmp(table->input[i], input) == 0) {
      return i;
    }
    i++;
  }
  return -1;
}

int Compress(char *input, char *output) {
  int input_length = strlen(input);
  int output_length = 0;
  int i = 0;
  CodeTable table;
  InitializeTable(&table);

  while (i < input_length) {
    char *match = strstr(table.input, input + i);
    if (match!= NULL) {
      output_length += sprintf(output + output_length, "%c%d", '*', match - table.input);
      i += strlen(match);
    } else {
      output_length += sprintf(output + output_length, "%c", input[i]);
      AddToTable(&table, input + i, output + output_length - 1);
      i++;
    }
  }
  return output_length;
}

int Decompress(char *input, char *output) {
  int input_length = strlen(input);
  int output_length = 0;
  int i = 0;
  char c;

  while (i < input_length) {
    if (input[i] == '*') {
      c = input[++i];
      while (c-- > 0) {
        strcat(output, input + i);
      }
      i++;
    } else {
      strcat(output, input + i);
      i++;
    }
  }
  return output_length;
}

int main() {
  char input[MAX_INPUT_LENGTH];
  char compressed[MAX_INPUT_LENGTH * 2];
  char decompressed[MAX_INPUT_LENGTH * 2];
  char *ptr;
  int input_length, compressed_length, decompressed_length;

  printf("Enter input string: ");
  scanf("%s", input);
  input_length = strlen(input);

  compressed_length = Compress(input, compressed);
  printf("Compressed string: %s\n", compressed);

  decompressed_length = Decompress(compressed, decompressed);
  printf("Decompressed string: %s\n", decompressed);

  return 0;
}