//FormAI DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Our unique data structure, a linked list of cats
typedef struct cat_node {
  char name[15];
  int age;
  struct cat_node *next;
} cat_node;

// Function to create a new cat node and add it to the linked list
void add_cat(cat_node **head, char *name, int age) {
  cat_node *new_cat = (cat_node*) malloc(sizeof(cat_node));
  for (int i = 0; i < 15; i++) {
    new_cat->name[i] = name[i];
  }
  new_cat->age = age;
  new_cat->next = *head;
  *head = new_cat;
}

// Function to print the linked list of cats
void print_cats(cat_node *head) {
  printf("  .     ,\n");
  printf("   \\  /(    |\n");
  printf("    -'~~`- ,)>\n");
  printf("   _/ _,\\ \n");
  printf("  /   \\ \\\n");
  printf("  \\ |  | ~\n");
  while (head != NULL) {
    printf("   (%d year old %s)\n", head->age, head->name);
    head = head->next;
  }
}

int main() {
  cat_node *head = NULL;
  printf("Welcome to our Cat Sanctuary!\n");
  printf("We keep track of all the cats who come through our doors.\n\n");
  printf("Let's start with our first cat...\n\n");
  printf("What is the name of the cat?\n");
  char name[15];
  scanf("%s", name);
  printf("How old is the cat?\n");
  int age;
  scanf("%d", &age);
  add_cat(&head, name, age);

  printf("\nGreat, let's add another cat!\n\n");
  printf("What is the name of the cat?\n");
  scanf("%s", name);
  printf("How old is the cat?\n");
  scanf("%d", &age);
  add_cat(&head, name, age);

  printf("\nWonderful! Now let's see all the cats we have:\n\n");
  print_cats(head);

  printf("\nThank you for visiting our Cat Sanctuary! We hope to see you again soon!\n");
  return 0;
}