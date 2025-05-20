//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
   char symbol[3];
   char name[30];
   int atomic_number;
   float atomic_weight;
} Element;

void print_element(Element *e) {
   printf("Symbol: %s\n", e->symbol);
   printf("Name: %s\n", e->name);
   printf("Atomic Number: %d\n", e->atomic_number);
   printf("Atomic Weight: %.2f\n", e->atomic_weight);
   printf("\n");
}

int main() {
   int num_elements = 118;
   Element elements[num_elements];
   FILE *fp = fopen("periodic_table.txt", "r");
   char line[100];
   int i = 0;

   while (fgets(line, sizeof(line), fp)) {
      sscanf(line, "%s %s %d %f", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].atomic_weight);
      i++;
   }

   fclose(fp);
   printf("Let's test your knowledge of the Periodic Table!\n");
   printf("Enter the atomic number of the element with the given symbol.\n");
   printf("-----------------------------------------------\n");

   int score = 0;

   for (int i = 0; i < 10; i++) {
      int rand_num = rand() % num_elements;
      Element e = elements[rand_num];

      printf("What is the atomic number of %s?\n", e.symbol);

      int user_input;
      scanf("%d", &user_input);

      if (user_input == e.atomic_number) {
         printf("Correct!\n");
         score++;
      } else {
         printf("Incorrect. The correct answer was %d.\n", e.atomic_number);
      }

      printf("\n");
   }

   printf("You got %d out of 10 correct.\n", score);
   printf("Thanks for playing!\n");

   return 0;
}