//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME 20
#define MAX_PASSWORD 20
#define MAX_ENTRIES 10

struct Entry {
  char username[MAX_USERNAME];
  char password[MAX_PASSWORD];
};

struct Database {
  struct Entry entries[MAX_ENTRIES];
  int count;
};

void clear_input_buffer() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

void add_entry(struct Database *db) {
  if (db->count == MAX_ENTRIES) {
    printf("Database full. Cannot add more entries.\n");
    return;
  }

  struct Entry *entry = &db->entries[db->count];
  printf("Enter username (max %d characters): ", MAX_USERNAME);
  fgets(entry->username, MAX_USERNAME, stdin);
  entry->username[strcspn(entry->username, "\n")] = '\0';  // remove newline character

  printf("Enter password (max %d characters): ", MAX_PASSWORD);
  fgets(entry->password, MAX_PASSWORD, stdin);
  entry->password[strcspn(entry->password, "\n")] = '\0';  // remove newline character

  db->count++;
  printf("Entry added.\n");
}

void list_entries(struct Database *db) {
  if (db->count == 0) {
    printf("Database is empty.\n");
    return;
  }

  printf("Entries:\n");
  for (int i = 0; i < db->count; i++) {
    struct Entry *entry = &db->entries[i];
    printf("  Username: %s, Password: %s\n", entry->username, entry->password);
  }
}

void search_entries(struct Database *db) {
  if (db->count == 0) {
    printf("Database is empty.\n");
    return;
  }

  char search_username[MAX_USERNAME];
  printf("Enter search username (max %d characters): ", MAX_USERNAME);
  fgets(search_username, MAX_USERNAME, stdin);
  search_username[strcspn(search_username, "\n")] = '\0';  // remove newline character

  int match_count = 0;
  printf("Search results:\n");
  for (int i = 0; i < db->count; i++) {
    struct Entry *entry = &db->entries[i];
    if (strcmp(entry->username, search_username) == 0) {
      printf("  Password: %s\n", entry->password);
      match_count++;
    }
  }

  if (match_count == 0) {
    printf("No matches found for username %s.\n", search_username);
  } else {
    printf("Found %d match(es) for username %s.\n", match_count, search_username);
  }
}

void print_menu() {
  printf("Menu:\n");
  printf("1. Add entry\n");
  printf("2. List entries\n");
  printf("3. Search entries\n");
  printf("4. Quit\n");
  printf("Enter choice (1-4): ");
}

int main() {
  struct Database db = { .count = 0 };

  while (1) {
    print_menu();

    int choice;
    scanf("%d", &choice);
    clear_input_buffer();

    switch (choice) {
      case 1:
        add_entry(&db);
        break;
      case 2:
        list_entries(&db);
        break;
      case 3:
        search_entries(&db);
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
}