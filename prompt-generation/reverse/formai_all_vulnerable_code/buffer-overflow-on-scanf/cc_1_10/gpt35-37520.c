//FormAI DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
  char name[50];
  char phone[15];
};

void saveContacts(struct Contact contacts[], int count);
int loadContacts(struct Contact contacts[]);
void addContact(struct Contact contacts[], int count);
void deleteContact(struct Contact contacts[], int count);
void printContacts(struct Contact contacts[], int count);
void searchContact(struct Contact contacts[], int count);

int main() {
  struct Contact contacts[100];
  int count = loadContacts(contacts);
  int choice;

  while (1) {
    printf("\nPhone Book\n");
    printf("1. View contacts\n");
    printf("2. Add contact\n");
    printf("3. Delete contact\n");
    printf("4. Search contact\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printContacts(contacts, count);
        break;
      case 2:
        addContact(contacts, count);
        count++;
        break;
      case 3:
        deleteContact(contacts, count);
        count--;
        break;
      case 4:
        searchContact(contacts, count);
        break;
      case 5:
        saveContacts(contacts, count);
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void saveContacts(struct Contact contacts[], int count) {
  FILE *fp;
  fp = fopen("contacts.dat", "wb");
  fwrite(contacts, sizeof(struct Contact), count, fp);
  fclose(fp);
}

int loadContacts(struct Contact contacts[]) {
  FILE *fp;
  int count = 0;

  fp = fopen("contacts.dat", "rb");

  if (fp != NULL) {
    while (fread(&contacts[count], sizeof(struct Contact), 1, fp) == 1) {
      count++;
    }

    fclose(fp);
  }

  return count;
}

void addContact(struct Contact contacts[], int count) {
  getchar(); // consume newline left by scanf

  printf("Enter name: ");
  fgets(contacts[count].name, 50, stdin);
  contacts[count].name[strcspn(contacts[count].name,"\n")] = '\0';

  printf("Enter phone number: ");
  fgets(contacts[count].phone, 15, stdin);
  contacts[count].phone[strcspn(contacts[count].phone,"\n")] = '\0';

  printf("Contact added\n");
}

void deleteContact(struct Contact contacts[], int count) {
  int found = 0;
  char name[50];

  getchar(); // consume newline left by scanf

  printf("Enter name of contact to delete: ");
  fgets(name, 50, stdin);
  name[strcspn(name,"\n")] = '\0';

  for (int i = 0; i < count; i++) {
    if (strcmp(name, contacts[i].name) == 0) {
      found = 1;
      printf("Contact found and deleted\n");

      for (int j = i; j < count - 1; j++) {
        contacts[j] = contacts[j+1];
      }

      break;
    }
  }

  if (!found) {
    printf("Contact not found\n");
  }
}

void printContacts(struct Contact contacts[], int count) {
  printf("Contacts:\n");

  for (int i = 0; i < count; i++) {
    printf("%s: %s\n", contacts[i].name, contacts[i].phone);
  }
}

void searchContact(struct Contact contacts[], int count) {
  int found = 0;
  char name[50];

  getchar(); // consume newline left by scanf

  printf("Enter name of contact to search for: ");
  fgets(name, 50, stdin);
  name[strcspn(name,"\n")] = '\0';

  for (int i = 0; i < count; i++) {
    if (strcmp(name, contacts[i].name) == 0) {
      found = 1;
      printf("%s: %s\n", contacts[i].name, contacts[i].phone);
      break;
    }
  }

  if (!found) {
    printf("Contact not found\n");
  }
}