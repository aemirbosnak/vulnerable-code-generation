//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
/*
 * Building a CSV Reader
 * ----------------------
 *
 * This program reads a CSV file and stores the data in a structured format.
 * The data is stored in a linked list, with each node representing a single
 * row in the CSV file.
 *
 * The program uses the standard C library function fopen() to open the file
 * and fgets() to read each line of the file. The line is then parsed using
 * strtok() to extract the individual fields.
 *
 * The program also uses the standard C library function malloc() to dynamically
 * allocate memory for the structured data.
 *
 * This program is written in a enthusiastic style, with a lot of comments and
 * a colorful output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single row of data
struct row {
  char *name;
  int age;
  char *gender;
  struct row *next;
};

// Function to parse a single line of the CSV file
struct row *parse_row(char *line) {
  // Allocate memory for the row struct
  struct row *row = malloc(sizeof(struct row));

  // Get the name field
  char *name = strtok(line, ",");
  row->name = strdup(name);

  // Get the age field
  char *age = strtok(NULL, ",");
  row->age = atoi(age);

  // Get the gender field
  char *gender = strtok(NULL, ",");
  row->gender = strdup(gender);

  // Set the next pointer to NULL
  row->next = NULL;

  return row;
}

// Function to read the CSV file and store the data in a linked list
struct row *read_csv(char *filename) {
  // Open the file for reading
  FILE *fp = fopen(filename, "r");

  // Create a linked list to store the data
  struct row *head = NULL;
  struct row *tail = NULL;

  // Read each line of the file
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the line and add it to the linked list
    struct row *row = parse_row(line);
    if (head == NULL) {
      head = row;
      tail = row;
    } else {
      tail->next = row;
      tail = row;
    }
  }

  // Close the file
  fclose(fp);

  // Return the head of the linked list
  return head;
}

// Function to print the data in the linked list
void print_data(struct row *head) {
  // Print the header
  printf("Name,Age,Gender\n");

  // Print each row of the linked list
  struct row *row = head;
  while (row != NULL) {
    printf("%s,%d,%s\n", row->name, row->age, row->gender);
    row = row->next;
  }
}

// Main function
int main() {
  // Read the CSV file
  struct row *head = read_csv("data.csv");

  // Print the data
  print_data(head);

  return 0;
}