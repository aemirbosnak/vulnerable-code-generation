//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100

struct data {
  char name[20];
  int age;
  float height;
};

void print_data(struct data *data) {
  printf("Name: %s\n", data->name);
  printf("Age: %d\n", data->age);
  printf("Height: %.2f\n", data->height);
}

void sort_data(struct data *data, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (data[i].age < data[j].age) {
        struct data temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}

int main() {
  struct data data[MAX_DATA];
  int size = 0;

  // Read data from user
  while (size < MAX_DATA) {
    printf("Enter name: ");
    scanf("%s", data[size].name);
    printf("Enter age: ");
    scanf("%d", &data[size].age);
    printf("Enter height: ");
    scanf("%f", &data[size].height);
    size++;
  }

  // Print original data
  printf("Original data:\n");
  for (int i = 0; i < size; i++) {
    print_data(&data[i]);
  }

  // Sort data by age
  sort_data(data, size);

  // Print sorted data
  printf("Sorted data:\n");
  for (int i = 0; i < size; i++) {
    print_data(&data[i]);
  }

  return 0;
}