//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
  char *name;
  int age;
  char *email;
} Person;

Person *read_csv(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  Person *people = NULL;
  int i = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (i == 0) {
      // Ignore the first line
      i++;
      continue;
    }

    // Allocate memory for the current person
    Person *current = malloc(sizeof(Person));

    // Extract the name
    char *name = strtok(line, ",");
    current->name = strdup(name);

    // Extract the age
    char *age = strtok(NULL, ",");
    current->age = atoi(age);

    // Extract the email
    char *email = strtok(NULL, ",");
    current->email = strdup(email);

    // Add the person to the array
    people = realloc(people, (i + 1) * sizeof(Person));
    people[i] = *current;

    i++;
  }

  // Free the line buffer
  free(line);

  // Return the array of people
  return people;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file.csv>\n", argv[0]);
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open file: %s\n", argv[1]);
    exit(1);
  }

  Person *people = read_csv(fp);

  // Print the array of people
  for (int i = 0; i < i; i++) {
    printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].email);
  }

  // Free the array of people
  free(people);

  fclose(fp);

  return 0;
}