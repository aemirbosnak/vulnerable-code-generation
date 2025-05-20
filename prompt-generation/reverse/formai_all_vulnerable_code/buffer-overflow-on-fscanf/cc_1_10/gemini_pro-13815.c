//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SURVIVORS 100
#define MAX_RESOURCES 10

// Survivor data type
typedef struct survivor {
  char name[20];
  int age;
  int strength;
  int intelligence;
  int charisma;
} survivor;

// Resource data type
typedef struct resource {
  char name[20];
  int quantity;
} resource;

// Global variables
survivor survivors[MAX_SURVIVORS];
resource resources[MAX_RESOURCES];
int num_survivors = 0;
int num_resources = 0;

// Function to load survivor data from a file
void load_survivors(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening survivor data file");
    exit(EXIT_FAILURE);
  }

  // Read the number of survivors from the file
  fscanf(fp, "%d", &num_survivors);

  // Read the survivor data from the file
  for (int i = 0; i < num_survivors; i++) {
    fscanf(fp, "%s %d %d %d %d", survivors[i].name, &survivors[i].age, &survivors[i].strength, &survivors[i].intelligence, &survivors[i].charisma);
  }

  fclose(fp);
}

// Function to load resource data from a file
void load_resources(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening resource data file");
    exit(EXIT_FAILURE);
  }

  // Read the number of resources from the file
  fscanf(fp, "%d", &num_resources);

  // Read the resource data from the file
  for (int i = 0; i < num_resources; i++) {
    fscanf(fp, "%s %d", resources[i].name, &resources[i].quantity);
  }

  fclose(fp);
}

// Function to find the most valuable resource
resource *find_most_valuable_resource() {
  // Initialize the most valuable resource to the first resource in the array
  resource *most_valuable_resource = &resources[0];

  // Iterate over the remaining resources in the array
  for (int i = 1; i < num_resources; i++) {
    // If the current resource is more valuable than the most valuable resource, update the most valuable resource
    if (resources[i].quantity > most_valuable_resource->quantity) {
      most_valuable_resource = &resources[i];
    }
  }

  // Return the most valuable resource
  return most_valuable_resource;
}

// Function to find the strongest survivor
survivor *find_strongest_survivor() {
  // Initialize the strongest survivor to the first survivor in the array
  survivor *strongest_survivor = &survivors[0];

  // Iterate over the remaining survivors in the array
  for (int i = 1; i < num_survivors; i++) {
    // If the current survivor is stronger than the strongest survivor, update the strongest survivor
    if (survivors[i].strength > strongest_survivor->strength) {
      strongest_survivor = &survivors[i];
    }
  }

  // Return the strongest survivor
  return strongest_survivor;
}

// Function to find the most intelligent survivor
survivor *find_most_intelligent_survivor() {
  // Initialize the most intelligent survivor to the first survivor in the array
  survivor *most_intelligent_survivor = &survivors[0];

  // Iterate over the remaining survivors in the array
  for (int i = 1; i < num_survivors; i++) {
    // If the current survivor is more intelligent than the most intelligent survivor, update the most intelligent survivor
    if (survivors[i].intelligence > most_intelligent_survivor->intelligence) {
      most_intelligent_survivor = &survivors[i];
    }
  }

  // Return the most intelligent survivor
  return most_intelligent_survivor;
}

// Function to find the most charismatic survivor
survivor *find_most_charismatic_survivor() {
  // Initialize the most charismatic survivor to the first survivor in the array
  survivor *most_charismatic_survivor = &survivors[0];

  // Iterate over the remaining survivors in the array
  for (int i = 1; i < num_survivors; i++) {
    // If the current survivor is more charismatic than the most charismatic survivor, update the most charismatic survivor
    if (survivors[i].charisma > most_charismatic_survivor->charisma) {
      most_charismatic_survivor = &survivors[i];
    }
  }

  // Return the most charismatic survivor
  return most_charismatic_survivor;
}

// Function to main
int main() {
  // Load the survivor data from a file
  load_survivors("survivors.txt");

  // Load the resource data from a file
  load_resources("resources.txt");

  // Find the most valuable resource
  resource *most_valuable_resource = find_most_valuable_resource();

  // Find the strongest survivor
  survivor *strongest_survivor = find_strongest_survivor();

  // Find the most intelligent survivor
  survivor *most_intelligent_survivor = find_most_intelligent_survivor();

  // Find the most charismatic survivor
  survivor *most_charismatic_survivor = find_most_charismatic_survivor();

  // Print the results
  printf("The most valuable resource is %s with a quantity of %d.\n", most_valuable_resource->name, most_valuable_resource->quantity);
  printf("The strongest survivor is %s with a strength of %d.\n", strongest_survivor->name, strongest_survivor->strength);
  printf("The most intelligent survivor is %s with an intelligence of %d.\n", most_intelligent_survivor->name, most_intelligent_survivor->intelligence);
  printf("The most charismatic survivor is %s with a charisma of %d.\n", most_charismatic_survivor->name, most_charismatic_survivor->charisma);

  return 0;
}