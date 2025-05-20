//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for record
typedef struct {
  int id;
  char name[50];
  char location[50];
  int damage_level;
  int stock;
} Record;

// Function prototypes
void addRecord(Record* records, int* numRecords);
void viewRecords(Record* records, int numRecords);
void searchRecord(Record* records, int numRecords);
void damageRecord(Record* records, int numRecords);
void restockRecord(Record* records, int numRecords);
void saveRecords(Record* records, int numRecords);
void loadRecords(Record* records, int* numRecords);

int main() {
  // Seed random number generator
  srand(time(NULL));

  int numRecords = 0;
  Record records[100];

  // Load records from file if available
  loadRecords(records, &numRecords);

  int choice;
  do {
    // Display menu and get choice
    printf("Welcome to Post-Apocalyptic Supply Database\n");
    printf("Menu:\n");
    printf("1. Add a record\n");
    printf("2. View all records\n");
    printf("3. Search for a record\n");
    printf("4. Damage a record\n");
    printf("5. Restock a record\n");
    printf("6. Save records to file\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Perform action based on choice
    switch (choice) {
      case 1:
        addRecord(records, &numRecords);
        break;
      case 2:
        viewRecords(records, numRecords);
        break;
      case 3:
        searchRecord(records, numRecords);
        break;
      case 4:
        damageRecord(records, numRecords);
        break;
      case 5:
        restockRecord(records, numRecords);
        break;
      case 6:
        saveRecords(records, numRecords);
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  } while (choice != 7);

  return 0;
}

// Function to add a record to the database
void addRecord(Record* records, int* numRecords) {
  // Generate random ID
  int id = rand() % 1000 + 1;

  // Get input from user for name and location
  char name[50], location[50];
  printf("Enter name of item: ");
  scanf("%s", name);
  printf("Enter location of item: ");
  scanf("%s", location);

  // Set damage level and stock to 0 for new record
  int damage_level = 0, stock = 0;

  // Create new record and add to array
  Record newRecord = {id, name, location, damage_level, stock};
  records[*numRecords] = newRecord;
  (*numRecords)++;

  printf("Record added successfully!\n");
}

// Function to view all records in the database
void viewRecords(Record* records, int numRecords) {
  // Check if no records exist
  if (numRecords == 0) {
    printf("No records found.\n");
    return;
  }

  // Print header of table
  printf("| %-4s| %-20s| %-20s| %-14s| %-7s|\n", "ID", "Item Name", "Location", "Damage Level", "Stock");
  printf("-----------------------------------------------------------------\n");

  // Loop through all records and print them
  for (int i = 0; i < numRecords; i++) {
    printf("| %-4d| %-20s| %-20s| %-14d| %-7d|\n", records[i].id, records[i].name, records[i].location, records[i].damage_level, records[i].stock);
  }
}

// Function to search for a record in the database by name
void searchRecord(Record* records, int numRecords) {
  // Get input from user
  char name[50];
  printf("Enter name of item to search: ");
  scanf("%s", name);

  // Loop through all records and find matching names
  int numMatches = 0;
  for (int i = 0; i < numRecords; i++) {
    if (strcmp(records[i].name, name) == 0) {
      // Print record if name matches
      printf("Record found:\n");
      printf("ID: %d\n", records[i].id);
      printf("Name: %s\n", records[i].name);
      printf("Location: %s\n", records[i].location);
      printf("Damage Level: %d\n", records[i].damage_level);
      printf("Stock: %d\n", records[i].stock);
      numMatches++;
    }
  }

  // Print message if no matches were found
  if (numMatches == 0) {
    printf("No matching records found for %s.\n", name);
  }
}

// Function to damage a record in the database by ID
void damageRecord(Record* records, int numRecords) {
  // Get input from user
  int id;
  printf("Enter ID of item to damage: ");
  scanf("%d", &id);

  // Search for ID in array and update damage level
  int found = 0;
  for (int i = 0; i < numRecords; i++) {
    if (records[i].id == id) {
      records[i].damage_level++;
      printf("Record with ID %d has been damaged.\n", id);
      found = 1;
      break;
    }
  }

  // Print message if ID is not found
  if (!found) {
    printf("Record with ID %d not found.\n", id);
  }
}

// Function to restock a record in the database by ID
void restockRecord(Record* records, int numRecords) {
  // Get input from user
  int id, stock;
  printf("Enter ID of item to restock: ");
  scanf("%d", &id);
  printf("Enter new stock level: ");
  scanf("%d", &stock);

  // Search for ID in array and update stock level
  int found = 0;
  for (int i = 0; i < numRecords; i++) {
    if (records[i].id == id) {
      records[i].stock = stock;
      printf("Record with ID %d has been restocked.\n", id);
      found = 1;
      break;
    }
  }

  // Print message if ID is not found
  if (!found) {
    printf("Record with ID %d not found.\n", id);
  }
}

// Function to save all records to a file
void saveRecords(Record* records, int numRecords) {
  // Open file for writing
  FILE* fp = fopen("records.txt", "w");
  if (fp == NULL) {
    printf("Failed to open file for writing.\n");
    return;
  }

  // Write number of records to file
  fprintf(fp, "%d\n", numRecords);

  // Write each record to file
  for (int i = 0; i < numRecords; i++) {
    fprintf(fp, "%d|%s|%s|%d|%d\n", records[i].id, records[i].name, records[i].location, records[i].damage_level, records[i].stock);
  }

  // Close file
  fclose(fp);

  printf("Records saved to file successfully!\n");
}

// Function to load all records from a file
void loadRecords(Record* records, int* numRecords) {
  // Open file for reading
  FILE* fp = fopen("records.txt", "r");
  if (fp == NULL) {
    printf("No records found.\n");
    return;
  }

  // Read number of records from file
  fscanf(fp, "%d\n", numRecords);

  // Read each record from file
  for (int i = 0; i < *numRecords; i++) {
    int id, damage_level, stock;
    char name[50], location[50];
    fscanf(fp, "%d|%[^|]|%[^|]|%d|%d\n", &id, name, location, &damage_level, &stock);

    // Create new record and add to array
    Record newRecord = {id, name, location, damage_level, stock};
    records[i] = newRecord;
  }

  // Close file
  fclose(fp);

  printf("Records loaded from file successfully!\n");
}