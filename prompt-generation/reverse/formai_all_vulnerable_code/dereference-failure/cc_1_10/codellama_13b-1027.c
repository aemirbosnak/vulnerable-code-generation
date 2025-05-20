//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: imaginative
// imaginative_database.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
  float height;
} Person;

void print_person(Person* person) {
  printf("Name: %s, Age: %d, Height: %f\n", person->name, person->age, person->height);
}

int main() {
  Person* people = (Person*)malloc(10 * sizeof(Person));
  for (int i = 0; i < 10; i++) {
    strcpy(people[i].name, "John Doe");
    people[i].age = i * 10;
    people[i].height = i * 10.5;
  }

  // Query 1: Print all people with age greater than 20
  for (int i = 0; i < 10; i++) {
    if (people[i].age > 20) {
      print_person(&people[i]);
    }
  }

  // Query 2: Print all people with height less than 150
  for (int i = 0; i < 10; i++) {
    if (people[i].height < 150) {
      print_person(&people[i]);
    }
  }

  // Query 3: Print all people with name "John Doe"
  for (int i = 0; i < 10; i++) {
    if (strcmp(people[i].name, "John Doe") == 0) {
      print_person(&people[i]);
    }
  }

  // Query 4: Print all people with age and height greater than 20 and less than 150
  for (int i = 0; i < 10; i++) {
    if (people[i].age > 20 && people[i].height < 150) {
      print_person(&people[i]);
    }
  }

  return 0;
}