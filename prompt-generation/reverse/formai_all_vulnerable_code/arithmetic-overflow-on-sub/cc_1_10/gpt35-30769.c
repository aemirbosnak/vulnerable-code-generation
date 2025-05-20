//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int age;
  float income;
  char* occupation;
} Person;

int main(void) {
  int numPeople;
  printf("Enter the number of people to sort: ");
  scanf("%d", &numPeople);

  // Allocate memory for the people array
  Person* people = malloc(numPeople * sizeof(Person));
  if (people == NULL) {
    printf("Error: Memory allocation failed\n");
    return 1;
  }

  // Prompt the user to enter data for each person
  for (int i = 0; i < numPeople; i++) {
    printf("Enter data for person %d\n", i + 1);

    printf("Age: ");
    scanf("%d", &people[i].age);

    printf("Income: $");
    scanf("%f", &people[i].income);

    // Allocate memory for the occupation string
    people[i].occupation = malloc(50 * sizeof(char));
    if (people[i].occupation == NULL) {
      printf("Error: Memory allocation failed\n");
      return 1;
    }

    printf("Occupation: ");
    scanf("%s", people[i].occupation);
  }

  // Sort the people array based on income in ascending order
  for (int i = 0; i < numPeople - 1; i++) {
    for (int j = i + 1; j < numPeople; j++) {
      if (people[i].income > people[j].income) {
        // Swap the two elements
        Person temp = people[i];
        people[i] = people[j];
        people[j] = temp;
      }
    }
  }

  // Print the sorted array
  printf("\nSorted by income (ascending):\n");
  for (int i = 0; i < numPeople; i++) {
    printf("Person %d:\n", i + 1);
    printf("Age: %d\n", people[i].age);
    printf("Income: $%.2f\n", people[i].income);
    printf("Occupation: %s\n", people[i].occupation);
    printf("\n");
  }

  // Deallocate memory for the people array
  for (int i = 0; i < numPeople; i++) {
    free(people[i].occupation);
  }
  free(people);

  return 0;
}