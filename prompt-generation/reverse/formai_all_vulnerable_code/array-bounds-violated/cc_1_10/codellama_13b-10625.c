//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
/*
 * JSON Parser Example Program
 *
 * This program demonstrates how to build a JSON parser using C.
 * It parses a JSON file and prints the data to the console.
 */

#include <stdio.h>
#include <string.h>

// Define the JSON structure
typedef struct {
  char *name;
  char *age;
} Person;

// Define the JSON object
typedef struct {
  Person person;
} JSON;

// Function to parse the JSON file
void parseJSON(char *filePath) {
  FILE *fp = fopen(filePath, "r");
  if (fp == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }

  // Read the file line by line
  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Check if the line starts with a curly brace
    if (line[0] == '{') {
      // Parse the JSON object
      JSON json;
      char *name = NULL;
      char *age = NULL;
      char *token = strtok(line, " ");
      while (token != NULL) {
        if (strcmp(token, "name") == 0) {
          name = strtok(NULL, " ");
        } else if (strcmp(token, "age") == 0) {
          age = strtok(NULL, " ");
        }
        token = strtok(NULL, " ");
      }
      json.person.name = name;
      json.person.age = age;

      // Print the JSON object
      printf("Name: %s\n", json.person.name);
      printf("Age: %s\n", json.person.age);
    }
  }
  fclose(fp);
}

int main() {
  // Parse the JSON file
  parseJSON("example.json");
  return 0;
}