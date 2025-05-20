//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a line of input
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in the input file
#define MAX_LINES 1000

// Read a line of input from the given file pointer
char *readline(FILE *fp) {
  char *line = malloc(MAX_LINE_LENGTH);
  if (line == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for line.\n");
    exit(1);
  }
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    free(line);
    return NULL;
  }
  return line;
}

// Free the memory allocated for the given line
void free_line(char *line) {
  if (line != NULL) {
    free(line);
  }
}

// Parse a line of input and store the results in the given structure
typedef struct {
  int id;
  char *name;
  int age;
} person_t;

person_t parse_line(char *line) {
  person_t person;
  char *fields[3];
  int num_fields = 0;

  // Split the line into fields
  char *field = strtok(line, ",");
  while (field != NULL && num_fields < 3) {
    fields[num_fields++] = field;
    field = strtok(NULL, ",");
  }

  // Check that we have the correct number of fields
  if (num_fields != 3) {
    fprintf(stderr, "Error: Invalid line format: %s\n", line);
    exit(1);
  }

  // Convert the fields to the appropriate types
  person.id = atoi(fields[0]);
  person.name = strdup(fields[1]);
  person.age = atoi(fields[2]);

  return person;
}

// Free the memory allocated for the given person
void free_person(person_t person) {
  if (person.name != NULL) {
    free(person.name);
  }
}

// Load the people from the given file into an array
person_t *load_people(char *filename, int *num_people) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Unable to open file %s\n", filename);
    exit(1);
  }

  // Read the number of people
  if (fscanf(fp, "%d", num_people) != 1) {
    fprintf(stderr, "Error: Invalid file format: %s\n", filename);
    exit(1);
  }

  // Allocate memory for the people
  person_t *people = malloc(*num_people * sizeof(person_t));
  if (people == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for people.\n");
    exit(1);
  }

  // Read the people
  for (int i = 0; i < *num_people; i++) {
    char *line = readline(fp);
    if (line == NULL) {
      fprintf(stderr, "Error: Unexpected end of file: %s\n", filename);
      exit(1);
    }
    people[i] = parse_line(line);
    free_line(line);
  }

  fclose(fp);

  return people;
}

// Free the memory allocated for the given array of people
void free_people(person_t *people, int num_people) {
  for (int i = 0; i < num_people; i++) {
    free_person(people[i]);
  }
  free(people);
}

// Sort the people by age using the quicksort algorithm
void quicksort(person_t *people, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = people[right].age;
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (people[j].age <= pivot) {
      i++;
      person_t temp = people[i];
      people[i] = people[j];
      people[j] = temp;
    }
  }

  person_t temp = people[i + 1];
  people[i + 1] = people[right];
  people[right] = temp;

  quicksort(people, left, i);
  quicksort(people, i + 2, right);
}

// Print the people to the console
void print_people(person_t *people, int num_people) {
  for (int i = 0; i < num_people; i++) {
    printf("%d, %s, %d\n", people[i].id, people[i].name, people[i].age);
  }
}

int main(void) {
  // Load the people from the file
  char *filename = "people.txt";
  int num_people;
  person_t *people = load_people(filename, &num_people);

  // Sort the people by age
  quicksort(people, 0, num_people - 1);

  // Print the people to the console
  print_people(people, num_people);

  // Free the memory allocated for the people
  free_people(people, num_people);

  return 0;
}