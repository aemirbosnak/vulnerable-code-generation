//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 100

typedef struct {
  int age;
  char gender;
  float height;
  float weight;
  float bmi;
} Person;

void printPerson(Person p) {
  printf("Age: %d\n", p.age);
  printf("Gender: %c\n", p.gender);
  printf("Height: %f\n", p.height);
  printf("Weight: %f\n", p.weight);
  printf("BMI: %f\n", p.bmi);
}

void calculateBmi(Person* p) {
  p->bmi = p->weight / (p->height * p->height);
}

void sortByAge(Person* data, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j].age > data[j + 1].age) {
        Person temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

void sortByGender(Person* data, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j].gender > data[j + 1].gender) {
        Person temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

void sortByBmi(Person* data, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j].bmi > data[j + 1].bmi) {
        Person temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

int main() {
  Person data[MAX_DATA];
  int size = 0;

  printf("Enter the number of people: ");
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    printf("Enter person %d's age: ", i + 1);
    scanf("%d", &data[i].age);

    printf("Enter person %d's gender (M/F): ", i + 1);
    scanf(" %c", &data[i].gender);

    printf("Enter person %d's height (in meters): ", i + 1);
    scanf("%f", &data[i].height);

    printf("Enter person %d's weight (in kg): ", i + 1);
    scanf("%f", &data[i].weight);

    calculateBmi(&data[i]);
  }

  sortByAge(data, size);
  printf("Sorted by age:\n");
  for (int i = 0; i < size; i++) {
    printPerson(data[i]);
  }

  sortByGender(data, size);
  printf("Sorted by gender:\n");
  for (int i = 0; i < size; i++) {
    printPerson(data[i]);
  }

  sortByBmi(data, size);
  printf("Sorted by BMI:\n");
  for (int i = 0; i < size; i++) {
    printPerson(data[i]);
  }

  return 0;
}