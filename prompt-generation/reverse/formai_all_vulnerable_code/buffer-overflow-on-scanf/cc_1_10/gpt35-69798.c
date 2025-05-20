//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // maximum number of records the database can hold
#define MAX_NAME_LENGTH 50 // maximum length of a name string
#define MAX_PHONE_LENGTH 20 // maximum length of a phone number string

// define a structure for each record in the database
typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Record;

// global variables
Record database[MAX_RECORDS];
int num_records = 0;

// function prototypes
void add_record(int id, char* name, char* phone);
void remove_record(int id);
void find_record(char* name);
void print_database();
void save_database();
void load_database();

// main program
int main() {
  // load the initial database from file
  load_database();

  // menu loop
  while (1) {
    char command[50], name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    int id;

    // print menu options
    printf("Enter a command:\n");
    printf("add <id> <name> <phone>\n");
    printf("remove <id>\n");
    printf("find <name>\n");
    printf("list\n");
    printf("save\n");
    printf("quit\n");

    // get user input
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      // add a new record to the database
      scanf("%d %s %s", &id, name, phone);
      add_record(id, name, phone);
    } else if (strcmp(command, "remove") == 0) {
      // remove a record from the database
      scanf("%d", &id);
      remove_record(id);
    } else if (strcmp(command, "find") == 0) {
      // find a record by name
      scanf("%s", name);
      find_record(name);
    } else if (strcmp(command, "list") == 0) {
      // print the whole database
      print_database();
    } else if (strcmp(command, "save") == 0) {
      // save the database to file
      save_database();
    } else if (strcmp(command, "quit") == 0) {
      // exit the program
      break;
    } else {
      // invalid command
      printf("Invalid command: %s\n", command);
    }
  }

  return 0;
}

// function to add a record to the database
void add_record(int id, char* name, char* phone) {
  // check if the database is full
  if (num_records >= MAX_RECORDS) {
    printf("Error: database full\n");
    return;
  }

  // check if the record with this id already exists
  for (int i = 0; i < num_records; i++) {
    if (database[i].id == id) {
      printf("Error: record with id %d already exists\n", id);
      return;
    }
  }

  // add the new record to the database
  database[num_records].id = id;
  strcpy(database[num_records].name, name);
  strcpy(database[num_records].phone, phone);
  num_records++;

  printf("Record added successfully\n");
}

// function to remove a record from the database
void remove_record(int id) {
  // find the record with this id
  int index = -1;
  for (int i = 0; i < num_records; i++) {
    if (database[i].id == id) {
      index = i;
      break;
    }
  }

  // if the record was found, remove it
  if (index >= 0) {
    for (int i = index; i < num_records - 1; i++) {
      database[i] = database[i+1];
    }
    num_records--;
    printf("Record removed successfully\n");
  } else {
    printf("Error: record with id %d not found\n", id);
  }
}

// function to find a record by name
void find_record(char* name) {
  // find all records that contain the given name
  int found = 0;
  for (int i = 0; i < num_records; i++) {
    if (strstr(database[i].name, name) != NULL) {
      printf("Record #%d: %d, %s, %s\n", i+1, database[i].id, database[i].name, database[i].phone);
      found = 1;
    }
  }

  if (!found) {
    printf("No records found for name '%s'\n", name);
  }
}

// function to print the whole database
void print_database() {
  printf("Current database:\n");
  for (int i = 0; i < num_records; i++) {
    printf("Record #%d: %d, %s, %s\n", i+1, database[i].id, database[i].name, database[i].phone);
  }
}

// function to save the database to file
void save_database() {
  FILE* fp = fopen("database.txt", "w");
  if (fp == NULL) {
    printf("Error: could not save database\n");
    return;
  }

  for (int i = 0; i < num_records; i++) {
    fprintf(fp, "%d,%s,%s\n", database[i].id, database[i].name, database[i].phone);
  }

  fclose(fp);
  printf("Database saved successfully\n");
}

// function to load the database from file
void load_database() {
  FILE* fp = fopen("database.txt", "r");
  if (fp == NULL) {
    printf("Could not load initial database: file not found\n");
    return;
  }

  char line[100];
  while (fgets(line, 100, fp) != NULL) {
    char* token = strtok(line, ",");
    int id = atoi(token);
    token = strtok(NULL, ",");
    char name[MAX_NAME_LENGTH];
    strcpy(name, token);
    token = strtok(NULL, ",");
    char phone[MAX_PHONE_LENGTH];
    strcpy(phone, token);
    add_record(id, name, phone);
  }

  fclose(fp);
  printf("Initial database loaded successfully\n");
}