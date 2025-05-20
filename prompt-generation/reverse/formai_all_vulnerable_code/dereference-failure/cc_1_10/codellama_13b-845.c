//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  int price;
} medicine;

void print_medicine(medicine* medicine) {
  printf("%s: %s (%d)\n", medicine->name, medicine->description, medicine->price);
}

void add_medicine(medicine* medicines[], int* num_medicines, char* name, char* description, int price) {
  medicine* new_medicine = malloc(sizeof(medicine));
  strcpy(new_medicine->name, name);
  strcpy(new_medicine->description, description);
  new_medicine->price = price;
  medicines[*num_medicines] = new_medicine;
  *num_medicines += 1;
}

void remove_medicine(medicine* medicines[], int* num_medicines, char* name) {
  for (int i = 0; i < *num_medicines; i++) {
    if (strcmp(medicines[i]->name, name) == 0) {
      free(medicines[i]);
      medicines[i] = medicines[*num_medicines - 1];
      *num_medicines -= 1;
      break;
    }
  }
}

void update_medicine_price(medicine* medicines[], int* num_medicines, char* name, int price) {
  for (int i = 0; i < *num_medicines; i++) {
    if (strcmp(medicines[i]->name, name) == 0) {
      medicines[i]->price = price;
      break;
    }
  }
}

void print_all_medicines(medicine* medicines[], int num_medicines) {
  for (int i = 0; i < num_medicines; i++) {
    print_medicine(medicines[i]);
  }
}

int main() {
  medicine* medicines[MAX_MEDICINES];
  int num_medicines = 0;

  add_medicine(medicines, &num_medicines, "Paracetamol", "Pain reliever and fever reducer", 15);
  add_medicine(medicines, &num_medicines, "Ibuprofen", "Pain reliever and fever reducer", 20);
  add_medicine(medicines, &num_medicines, "Aspirin", "Pain reliever and fever reducer", 10);
  add_medicine(medicines, &num_medicines, "Antibiotics", "Bacterial infection treatment", 30);
  add_medicine(medicines, &num_medicines, "Vitamin C", "Immune system support", 15);
  add_medicine(medicines, &num_medicines, "Multivitamin", "Immune system support", 20);

  print_all_medicines(medicines, num_medicines);

  remove_medicine(medicines, &num_medicines, "Multivitamin");
  update_medicine_price(medicines, &num_medicines, "Aspirin", 20);

  print_all_medicines(medicines, num_medicines);

  return 0;
}