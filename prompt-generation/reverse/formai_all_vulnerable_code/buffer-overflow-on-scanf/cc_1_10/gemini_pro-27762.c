//GEMINI-pro DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct {
  char *name;
  int age;
  char *occupation;
} person_t;

person_t *create_person(char *name, int age, char *occupation) {
  person_t *person = malloc(sizeof(person_t));
  person->name = strdup(name);
  person->age = age;
  person->occupation = strdup(occupation);
  return person;
}

void destroy_person(person_t *person) {
  free(person->name);
  free(person->occupation);
  free(person);
}

int main(void) {
  person_t *people[MAX_LENGTH];
  int num_people = 0;

  while (1) {
    char name[MAX_LENGTH];
    int age;
    char occupation[MAX_LENGTH];

    printf("Enter a name, age, and occupation (or q to quit): ");
    scanf("%s %d %s", name, &age, occupation);

    if (strcmp(name, "q") == 0) {
      break;
    }

    people[num_people++] = create_person(name, age, occupation);
  }

  printf("\nHere is a list of the people you entered:\n");
  for (int i = 0; i < num_people; i++) {
    printf("%s, %d, %s\n", people[i]->name, people[i]->age, people[i]->occupation);
  }

  for (int i = 0; i < num_people; i++) {
    destroy_person(people[i]);
  }

  return 0;
}