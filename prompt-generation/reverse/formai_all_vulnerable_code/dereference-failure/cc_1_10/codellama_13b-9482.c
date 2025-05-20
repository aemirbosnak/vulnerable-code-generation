//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
  char *name;
  char *email;
  int age;
} Person;

Person *read_csv(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }

  Person *people = malloc(sizeof(Person) * MAX_FIELDS);
  if (!people) {
    fprintf(stderr, "Error allocating memory for people array\n");
    exit(1);
  }

  char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
  if (!line) {
    fprintf(stderr, "Error allocating memory for line buffer\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    char *token = strtok(line, ",");
    if (!token) {
      fprintf(stderr, "Error parsing line: %s\n", line);
      exit(1);
    }
    people[i].name = token;

    token = strtok(NULL, ",");
    if (!token) {
      fprintf(stderr, "Error parsing line: %s\n", line);
      exit(1);
    }
    people[i].email = token;

    token = strtok(NULL, ",");
    if (!token) {
      fprintf(stderr, "Error parsing line: %s\n", line);
      exit(1);
    }
    people[i].age = atoi(token);

    i++;
  }

  fclose(fp);
  free(line);
  return people;
}

int main() {
  Person *people = read_csv("people.csv");
  for (int i = 0; i < MAX_FIELDS; i++) {
    printf("%s, %s, %d\n", people[i].name, people[i].email, people[i].age);
  }
  return 0;
}