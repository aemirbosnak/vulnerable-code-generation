//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: intelligent
// A unique C Sorting example program in an intelligent style

#include <stdio.h>
#include <stdlib.h>

// Define a struct for a person
typedef struct {
  char name[30];
  int age;
} Person;

// Define a function to sort an array of people by age
void sortPeopleByAge(Person *people, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (people[j].age > people[j + 1].age) {
        Person temp = people[j];
        people[j] = people[j + 1];
        people[j + 1] = temp;
      }
    }
  }
}

// Define a function to print an array of people
void printPeople(Person *people, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s (%d)\n", people[i].name, people[i].age);
  }
}

// Define a function to create an array of people
Person *createPeople(int n) {
  Person *people = malloc(n * sizeof(Person));
  for (int i = 0; i < n; i++) {
    people[i].age = rand() % 100 + 1;
    sprintf(people[i].name, "Person %d", i + 1);
  }
  return people;
}

int main() {
  // Create an array of people
  Person *people = createPeople(10);

  // Print the original array
  printPeople(people, 10);

  // Sort the array by age
  sortPeopleByAge(people, 10);

  // Print the sorted array
  printPeople(people, 10);

  // Free the memory
  free(people);

  return 0;
}