//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
  int id;
  char name[30];
  char address[50];
  char phone[15];
};

struct Database {
  struct Record records[MAX_RECORDS];
  int count;
};

void display_menu() {
  printf("CYBERDB - A Cyberpunk Database Simulation System\n");
  printf("1. Add Record\n2. Edit Record\n3. Delete Record\n");
  printf("4. Search Record\n5. Display All Records\n6. Exit\n");
}

int get_menu_choice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

void clear_input_buffer() {
  while (getchar() != '\n');
}

void add_record(struct Database* db) {
  if (db->count == MAX_RECORDS) {
    printf("ERROR: Database is full.\n");
    return;
  }
  struct Record record;
  printf("Enter ID: ");
  scanf("%d", &record.id);
  clear_input_buffer();
  printf("Enter Name: ");
  fgets(record.name, sizeof(record.name), stdin);
  record.name[strcspn(record.name, "\n")] = '\0';
  printf("Enter Address: ");
  fgets(record.address, sizeof(record.address), stdin);
  record.address[strcspn(record.address, "\n")] = '\0';
  printf("Enter Phone: ");
  fgets(record.phone, sizeof(record.phone), stdin);
  record.phone[strcspn(record.phone, "\n")] = '\0';
  db->records[db->count] = record;
  db->count++;
  printf("Record Added Successfully.\n");
}

void edit_record(struct Database* db) {
  if (db->count == 0) {
    printf("ERROR: Database is empty.\n");
    return;
  }
  int id;
  printf("Enter ID of the Record to Edit: ");
  scanf("%d", &id);
  clear_input_buffer();
  int i;
  for (i = 0; i < db->count; i++) {
    if (db->records[i].id == id) {
      struct Record record;
      printf("Enter New Name: ");
      fgets(record.name, sizeof(record.name), stdin);
      record.name[strcspn(record.name, "\n")] = '\0';
      printf("Enter New Address: ");
      fgets(record.address, sizeof(record.address), stdin);
      record.address[strcspn(record.address, "\n")] = '\0';
      printf("Enter New Phone: ");
      fgets(record.phone, sizeof(record.phone), stdin);
      record.phone[strcspn(record.phone, "\n")] = '\0';
      db->records[i] = record;
      printf("Record Edited Successfully.\n");
      return;
    }
  }
  printf("ERROR: Record with ID %d not found.\n", id);
}

void delete_record(struct Database* db) {
  if (db->count == 0) {
    printf("ERROR: Database is empty.\n");
    return;
  }
  int id;
  printf("Enter ID of the Record to Delete: ");
  scanf("%d", &id);
  clear_input_buffer();
  int i;
  for (i = 0; i < db->count; i++) {
    if (db->records[i].id == id) {
      int j;
      for (j = i; j < db->count - 1; j++) {
        db->records[j] = db->records[j+1];
      }
      db->count--;
      printf("Record Deleted Successfully.\n");
      return;
    }
  }
  printf("ERROR: Record with ID %d not found.\n", id);
}

void search_record(struct Database* db) {
  if (db->count == 0) {
    printf("ERROR: Database is empty.\n");
    return;
  }
  char name[30];
  printf("Enter Name to Search: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0';
  int i;
  for (i = 0; i < db->count; i++) {
    if (strcmp(db->records[i].name, name) == 0) {
      printf("Record Found:\n");
      printf("ID: %d\nName: %s\nAddress: %s\nPhone: %s\n", db->records[i].id, db->records[i].name, db->records[i].address, db->records[i].phone);
      return;
    }
  }
  printf("ERROR: Record with Name %s not found.\n", name);
}

void display_all_records(struct Database* db) {
  if (db->count == 0) {
    printf("ERROR: Database is empty.\n");
    return;
  }
  int i;
  for (i = 0; i < db->count; i++) {
    printf("Record %d:\n", i+1);
    printf("ID: %d\nName: %s\nAddress: %s\nPhone: %s\n", db->records[i].id, db->records[i].name, db->records[i].address, db->records[i].phone);
  }
}

int main() {
  struct Database db = { .count = 0 };
  int choice;
  do {
    display_menu();
    choice = get_menu_choice();
    switch (choice) {
      case 1:
        add_record(&db);
        break;
      case 2:
        edit_record(&db);
        break;
      case 3:
        delete_record(&db);
        break;
      case 4:
        search_record(&db);
        break;
      case 5:
        display_all_records(&db);
        break;
      case 6:
        printf("Thank you for using CYBERDB.\n");
        break;
      default:
        printf("Invalid Choice. Please Try Again.\n");
        break;
    }
  } while (choice != 6);
  return 0;
}