//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
  int id;
  char name[30];
  float gpa;
};

int num_records = 0;

void insert_record(struct student* db[], int* num_rec);
void delete_record(struct student* db[], int* num_rec);
void update_record(struct student* db[], int* num_rec);
void print_record(struct student* db[], int* num_rec);

int main() {
  struct student* db[MAX_RECORDS];
  int choice;

  while (1) {
    printf("\nDatabase Application\n");
    printf("1. Insert Record\n");
    printf("2. Delete Record\n");
    printf("3. Update Record\n");
    printf("4. Print Records\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insert_record(db, &num_records);
        break;
      case 2:
        delete_record(db, &num_records);
        break;
      case 3:
        update_record(db, &num_records);
        break;
      case 4:
        print_record(db, &num_records);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}

void insert_record(struct student* db[], int* num_rec) {
  if (*num_rec >= MAX_RECORDS) {
    printf("Database is full\n");
    return;
  }

  db[*num_rec] = (struct student*) malloc(sizeof(struct student));

  printf("\nEnter student id: ");
  scanf("%d", &db[*num_rec]->id);

  printf("Enter student name: ");
  scanf("%s", db[*num_rec]->name);

  printf("Enter student GPA: ");
  scanf("%f", &db[*num_rec]->gpa);

  (*num_rec)++;
}

void delete_record(struct student* db[], int* num_rec) {
  int id, i, j;

  if (*num_rec == 0) {
    printf("Database is empty\n");
    return;
  }

  printf("\nEnter student id to delete: ");
  scanf("%d", &id);

  for (i = 0; i < *num_rec; i++) {
    if (db[i]->id == id) {
      free(db[i]);

      for (j = i; j < *num_rec; j++) {
        db[j] = db[j+1];
      }

      (*num_rec)--;
      return;
    }
  }

  printf("Record not found\n");
}

void update_record(struct student* db[], int* num_rec) {
  int id, i;

  if (*num_rec == 0) {
    printf("Database is empty\n");
    return;
  }

  printf("\nEnter student id to update: ");
  scanf("%d", &id);

  for (i = 0; i < *num_rec; i++) {
    if (db[i]->id == id) {
      printf("Enter student name (prev: %s): ", db[i]->name);
      scanf("%s", db[i]->name);

      printf("Enter student GPA (prev: %.2f): ", db[i]->gpa);
      scanf("%f", &db[i]->gpa);

      return;
    }
  }

  printf("Record not found\n");
}

void print_record(struct student* db[], int* num_rec) {
  int i;

  if (*num_rec == 0) {
    printf("Database is empty\n");
    return;
  }

  printf("\nID\tName\tGPA\n");

  for (i = 0; i < *num_rec; i++) {
    printf("%d\t%s\t%.2f\n", db[i]->id, db[i]->name, db[i]->gpa);
  }
}