//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct {
  time_t timestamp;
  char *text;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *create_entry(const char *text) {
  // Allocate memory for the diary entry
  DiaryEntry *entry = malloc(sizeof(DiaryEntry));
  if (entry == NULL) {
    return NULL;
  }

  // Copy the text into the diary entry
  entry->text = strdup(text);
  if (entry->text == NULL) {
    free(entry);
    return NULL;
  }

  // Set the timestamp of the diary entry
  entry->timestamp = time(NULL);

  return entry;
}

// Free the memory allocated for a diary entry
void free_entry(DiaryEntry *entry) {
  // Free the text of the diary entry
  free(entry->text);

  // Free the diary entry itself
  free(entry);
}

// Add a new diary entry to a file
int add_entry(const char *filename, DiaryEntry *entry) {
  // Open the file for appending
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    return -1;
  }

  // Write the timestamp of the diary entry to the file
  fprintf(file, "%ld\n", entry->timestamp);

  // Write the text of the diary entry to the file
  fprintf(file, "%s\n", entry->text);

  // Close the file
  fclose(file);

  return 0;
}

// Read a diary entry from a file
DiaryEntry *read_entry(const char *filename, long timestamp) {
  // Open the file for reading
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the timestamp of the diary entry from the file
  long entry_timestamp;
  fscanf(file, "%ld\n", &entry_timestamp);

  // Check if the timestamp of the diary entry matches the specified timestamp
  if (entry_timestamp != timestamp) {
    fclose(file);
    return NULL;
  }

  // Read the text of the diary entry from the file
  char *text = NULL;
  size_t len = 0;
  getline(&text, &len, file);

  // Close the file
  fclose(file);

  // Create a new diary entry with the specified timestamp and text
  DiaryEntry *entry = create_entry(text);
  if (entry == NULL) {
    free(text);
    return NULL;
  }

  // Free the text of the diary entry
  free(text);

  return entry;
}

// Print a diary entry to the console
void print_entry(DiaryEntry *entry) {
  // Print the timestamp of the diary entry
  printf("%s", ctime(&entry->timestamp));
printf("\n\n\n");
  // Print the text of the diary entry
  printf("%s", entry->text);
}

// Get the current date and time as a string
char *get_current_date_time() {
  // Allocate memory for the current date and time
  char *date_time = malloc(26);
  if (date_time == NULL) {
    return NULL;
  }

  // Get the current date and time
  time_t now = time(NULL);
  strftime(date_time, 26, "%Y-%m-%d %H:%M:%S", localtime(&now));

  return date_time;
}

// Free the memory allocated for the current date and time
void free_date_time(char *date_time) {
  // Free the memory allocated for the current date and time
  free(date_time);
}

// Get a diary entry from the user
DiaryEntry *get_entry() {
  // Get the current date and time
  char *date_time = get_current_date_time();
  if (date_time == NULL) {
    return NULL;
  }

  // Prompt the user to enter the text of the diary entry
  printf("Enter your diary entry for %s: ", date_time);
  char *text = NULL;
  size_t len = 0;
  getline(&text, &len, stdin);

  // Free the memory allocated for the current date and time
  free_date_time(date_time);

  // Create a new diary entry with the specified text
  DiaryEntry *entry = create_entry(text);
  if (entry == NULL) {
    free(text);
    return NULL;
  }

  // Free the text of the diary entry
  free(text);

  return entry;
}

// Main function
int main() {
  // Get the name of the diary file from the user
  char *filename = malloc(1024);
  if (filename == NULL) {
    return -1;
  }
  printf("Enter the name of the diary file: ");
  scanf("%s", filename);

  // Open the diary file for appending
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    return -1;
  }

  // Close the diary file
  fclose(file);

  // Get a diary entry from the user
  DiaryEntry *entry = get_entry();
  if (entry == NULL) {
    return -1;
  }

  // Add the diary entry to the file
  int result = add_entry(filename, entry);
  if (result != 0) {
    return -1;
  }

  // Free the memory allocated for the diary entry
  free_entry(entry);

  // Free the memory allocated for the diary file name
  free(filename);

  return 0;
}