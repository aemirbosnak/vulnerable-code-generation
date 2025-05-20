//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *number;
} entry;

int main() {
  entry *phonebook = malloc(sizeof(entry) * 10);
  int num_entries = 0;

  while (1) {
    char input[100];
    printf("> ");
    gets(input);

    if (strcmp(input, "add") == 0) {
      char name[50];
      char number[50];
      printf("Name: ");
      gets(name);
      printf("Number: ");
      gets(number);

      phonebook[num_entries].name = malloc(strlen(name) + 1);
      strcpy(phonebook[num_entries].name, name);
      phonebook[num_entries].number = malloc(strlen(number) + 1);
      strcpy(phonebook[num_entries].number, number);

      num_entries++;
    } else if (strcmp(input, "find") == 0) {
      char name[50];
      printf("Name: ");
      gets(name);

      for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
          printf("%s\n", phonebook[i].number);
          break;
        }
      }
    } else if (strcmp(input, "list") == 0) {
      for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
      }
    } else if (strcmp(input, "exit") == 0) {
      break;
    }
  }

  for (int i = 0; i < num_entries; i++) {
    free(phonebook[i].name);
    free(phonebook[i].number);
  }
  free(phonebook);

  return 0;
}