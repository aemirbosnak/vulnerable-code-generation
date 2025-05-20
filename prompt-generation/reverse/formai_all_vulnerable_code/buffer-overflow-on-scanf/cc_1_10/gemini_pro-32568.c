//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  int quantity;
  float price;
};

struct node {
  struct medicine data;
  struct node *next;
};

struct node *head = NULL;

void add_medicine() {
  struct medicine m;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  printf("Enter medicine name: ");
  scanf("%s", m.name);
  printf("Enter quantity: ");
  scanf("%d", &m.quantity);
  printf("Enter price: ");
  scanf("%f", &m.price);
  new_node->data = m;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
  } else {
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void display_medicines() {
  struct node *temp = head;
  printf("Medicine Name\tQuantity\tPrice\n");
  while (temp != NULL) {
    printf("%s\t%d\t%f\n", temp->data.name, temp->data.quantity, temp->data.price);
    temp = temp->next;
  }
}

void search_medicine() {
  char name[50];
  printf("Enter medicine name to search: ");
  scanf("%s", name);
  struct node *temp = head;
  while (temp != NULL) {
    if (strcmp(temp->data.name, name) == 0) {
      printf("Medicine found:\n");
      printf("Name: %s\n", temp->data.name);
      printf("Quantity: %d\n", temp->data.quantity);
      printf("Price: %f\n", temp->data.price);
      break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Medicine not found!\n");
  }
}

void update_medicine() {
  char name[50];
  printf("Enter medicine name to update: ");
  scanf("%s", name);
  struct node *temp = head;
  while (temp != NULL) {
    if (strcmp(temp->data.name, name) == 0) {
      printf("Enter new quantity: ");
      scanf("%d", &temp->data.quantity);
      printf("Enter new price: ");
      scanf("%f", &temp->data.price);
      printf("Medicine updated successfully!\n");
      break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Medicine not found!\n");
  }
}

void delete_medicine() {
  char name[50];
  printf("Enter medicine name to delete: ");
  scanf("%s", name);
  struct node *temp = head, *prev = NULL;
  while (temp != NULL) {
    if (strcmp(temp->data.name, name) == 0) {
      if (prev == NULL) {
        head = head->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      printf("Medicine deleted successfully!\n");
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Medicine not found!\n");
  }
}

int main() {
  int choice;
  while (1) {
    printf("\n\nMedical Store Management System\n");
    printf("1. Add New Medicine\n");
    printf("2. Display All Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_medicine();
        break;
      case 2:
        display_medicines();
        break;
      case 3:
        search_medicine();
        break;
      case 4:
        update_medicine();
        break;
      case 5:
        delete_medicine();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}