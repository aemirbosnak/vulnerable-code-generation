//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_AGE 120

typedef struct {
  char name[MAX_NAME_LEN];
  char address[MAX_ADDRESS_LEN];
  int age;
} Record;

void print_record(Record *record) {
  printf("Name: %s\n", record->name);
  printf("Address: %s\n", record->address);
  printf("Age: %d\n", record->age);
}

void add_record(Record *record) {
  printf("Enter name: ");
  scanf("%s", record->name);
  printf("Enter address: ");
  scanf("%s", record->address);
  printf("Enter age: ");
  scanf("%d", &record->age);
}

void delete_record(Record *record) {
  printf("Enter name: ");
  scanf("%s", record->name);
  printf("Enter address: ");
  scanf("%s", record->address);
  printf("Enter age: ");
  scanf("%d", &record->age);
}

void update_record(Record *record) {
  printf("Enter name: ");
  scanf("%s", record->name);
  printf("Enter address: ");
  scanf("%s", record->address);
  printf("Enter age: ");
  scanf("%d", &record->age);
}

int main() {
  Record records[NUM_RECORDS];
  int i;

  for (i = 0; i < NUM_RECORDS; i++) {
    add_record(&records[i]);
  }

  for (i = 0; i < NUM_RECORDS; i++) {
    printf("Record %d:\n", i + 1);
    print_record(&records[i]);
  }

  return 0;
}