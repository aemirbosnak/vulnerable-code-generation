//FormAI DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/* A struct representing a survivor in the post-apocalyptic world */
typedef struct survivor {
  char *name;
  int age;
  struct survivor *next;
} Survivor;

/* Global declaration of starting pointer for the linked list */
Survivor *start = NULL;

/* Function to allocate memory for a new survivor struct */
Survivor* getSurvivor() {
  Survivor *newSurvivor = (Survivor*)malloc(sizeof(Survivor));
  
  /* If memory allocation failed, exit the program with an error message */
  if (newSurvivor == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  
  /* Prompt the user for the survivor's name and age */
  printf("Enter name: ");
  char *name = (char*)malloc(MAX_SIZE * sizeof(char));
  scanf("%s", name);
  newSurvivor->name = name;
  
  printf("Enter age: ");
  int age;
  scanf("%d", &age);
  newSurvivor->age = age;
  
  /* Return the newly created survivor struct */
  return newSurvivor;
}

/* Function to add a survivor to the linked list */
void addSurvivor() {
  /* If the linked list is empty, create a new survivor and make it the start */
  if (start == NULL) {
    start = getSurvivor();
    start->next = NULL;
    printf("%s has been added to the survivor list.\n", start->name);
    return;
  }
  
  /* Traverse the linked list to the end */
  Survivor *traverse = start;
  while (traverse->next != NULL) {
    traverse = traverse->next;
  }
  
  /* Create a new survivor and add it to the end of the linked list */
  traverse->next = getSurvivor();
  traverse->next->next = NULL;
  printf("%s has been added to the survivor list.\n", traverse->next->name);
}

/* Function to delete a survivor from the linked list */
void deleteSurvivor() {
  /* If the linked list is empty, exit the function with an error message */
  if (start == NULL) {
    printf("The survivor list is empty.\n");
    return;
  }
  
  /* Prompt the user for the name of the survivor to delete */
  printf("Enter name of survivor to delete: ");
  char name[MAX_SIZE];
  scanf("%s", name);
  
  /* If the survivor to delete is at the start of the linked list */
  if (strcmp(start->name, name) == 0) {
    Survivor *temp = start;
    start = start->next;
    printf("%s has been deleted from the survivor list.\n", temp->name);
    free(temp);
    return;
  }
  
  /* Traverse the linked list to find the survivor to delete */
  Survivor *traverse = start;
  while (traverse->next != NULL && strcmp(traverse->next->name, name) != 0) {
    traverse = traverse->next;
  }
  
  /* If the survivor to delete is not found in the linked list */
  if (traverse->next == NULL) {
    printf("Survivor not found in the list.\n");
    return;
  }
  
  /* Delete the survivor from the linked list and free the memory */
  Survivor *temp = traverse->next;
  traverse->next = traverse->next->next;
  printf("%s has been deleted from the survivor list.\n", temp->name);
  free(temp);
}

/* Function to print the entire linked list of survivors */
void printSurvivors() {
  /* If the linked list is empty, exit the function with an error message */
  if (start == NULL) {
    printf("The survivor list is empty.\n");
    return;
  }
  
  /* Traverse the linked list and print each survivor's name and age */
  Survivor *traverse = start;
  printf("Survivor List:\n");
  while (traverse != NULL) {
    printf("Name: %s, Age: %d\n", traverse->name, traverse->age);
    traverse = traverse->next;
  }
}

/* Main function to run the memory management program */
int main() {
  int option;

  do {
    printf("\nMenu:\n");
    printf("1. Add survivor\n");
    printf("2. Delete survivor\n");
    printf("3. Print survivors\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
      case 1: addSurvivor();
              break;
      case 2: deleteSurvivor();
              break;
      case 3: printSurvivors();
              break;
      case 4: break;
      default: printf("Invalid option. Please try again.\n");
    }
  } while (option != 4);
  
  /* Terminate the program and free all memory */
  Survivor *traverse = start;
  while (traverse != NULL) {
    Survivor *temp = traverse;
    traverse = traverse->next;
    free(temp->name);
    free(temp);
  }
  
  return 0;
}