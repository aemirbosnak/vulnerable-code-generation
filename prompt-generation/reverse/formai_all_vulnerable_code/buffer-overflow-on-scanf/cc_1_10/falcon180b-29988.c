//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define M 1000
#define PI 3.14159265358979323846
#define MAX_STRING_SIZE 50

typedef struct {
  char name[MAX_STRING_SIZE];
  int age;
} Person;

void read_person(Person* person) {
  printf("Enter name: ");
  scanf("%s", person->name);
  printf("Enter age: ");
  scanf("%d", &person->age);
}

int compare_age(const void* a, const void* b) {
  const Person* p1 = a;
  const Person* p2 = b;
  return p1->age - p2->age;
}

void print_person(const Person* person) {
  printf("%s (%d)\n", person->name, person->age);
}

int main() {
  Person* people = malloc(N * sizeof(Person));
  if (people == NULL) {
    printf("Error: could not allocate memory\n");
    return 1;
  }

  for (int i = 0; i < N; i++) {
    read_person(&people[i]);
  }

  qsort(people, N, sizeof(Person), compare_age);

  printf("Sorted by age:\n");
  for (int i = 0; i < N; i++) {
    print_person(&people[i]);
  }

  free(people);
  return 0;
}