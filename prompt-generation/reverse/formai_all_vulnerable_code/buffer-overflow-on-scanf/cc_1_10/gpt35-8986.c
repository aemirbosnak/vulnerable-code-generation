//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 100

typedef struct {
  int id;
  char name[50];
  char email[100];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void addEntry(int id, char *name, char *email) {
  pthread_mutex_lock(&mutex);
  Entry entry = {id, "", ""};
  strcpy(entry.name, name);
  strcpy(entry.email, email);
  entries[num_entries] = entry;
  num_entries++;
  pthread_mutex_unlock(&mutex);
}

void removeEntry(int id) {
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < num_entries; i++) {
    if (entries[i].id == id) {
      for (int j = i; j < num_entries - 1; j++) {
        entries[j] = entries[j+1];
      }
      num_entries--;
      break;
    }
  }
  pthread_mutex_unlock(&mutex);
}

void displayEntries() {
  for (int i = 0; i < num_entries; i++) {
    printf("Entry %d:\nID: %d\nName: %s\nEmail: %s\n\n", i+1, entries[i].id, entries[i].name, entries[i].email);
  }
}

void* addThread(void* arg) {
  int id;
  char name[50], email[100];
  printf("Enter ID: ");
  scanf("%d", &id);
  printf("Enter Name: ");
  scanf("%s", name);
  printf("Enter Email: ");
  scanf("%s", email);
  addEntry(id, name, email);
}

void* removeThread(void* arg) {
  int id;
  printf("Enter ID to remove: ");
  scanf("%d", &id);
  removeEntry(id);
}

int main() {
  pthread_t tid;
  int choice = 0;

  while(1) {
    printf("Menu:\n1. Add Entry\n2. Remove Entry\n3. Display Entries\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        pthread_create(&tid, NULL, addThread, NULL);
        pthread_join(tid, NULL);
        break;

      case 2:
        pthread_create(&tid, NULL, removeThread, NULL);
        pthread_join(tid, NULL);
        break;

      case 3:
        displayEntries();
        break;

      case 4:
        exit(0);

      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}