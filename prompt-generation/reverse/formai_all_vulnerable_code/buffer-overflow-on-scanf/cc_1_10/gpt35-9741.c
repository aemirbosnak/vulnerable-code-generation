//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 18

void display_table(char periodic_table[][COLS]);
void check_answer(char answer[], char correct_answer[]);

int main(void) {
  char periodic_table[ROWS][COLS] = {
    {'H', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'Li', 'Be', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'B', 'C', 'N', 'O', 'F', 'Ne'},
    {'Na', 'Mg', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'Al', 'Si', 'P', 'S', 'Cl', 'Ar'},
    {'K', 'Ca', 'Sc', 'Ti', 'V', 'Cr', 'Mn', 'Fe', 'Co', 'Ni', 'Cu', 'Zn', 'Ga', 'Ge', 'As', 'Se', 'Br', 'Kr'},
    {'Rb', 'Sr', 'Y', 'Zr', 'Nb', 'Mo', 'Tc', 'Ru', 'Rh', 'Pd', 'Ag', 'Cd', 'In', 'Sn', 'Sb', 'Te', 'I', 'Xe'},
    {'Cs', 'Ba', '-', 'Hf', 'Ta', 'W', 'Re', 'Os', 'Ir', 'Pt', 'Au', 'Hg', 'Tl', 'Pb', 'Bi', 'Po', 'At', 'Rn'},
    {'Fr', 'Ra', '-', 'Rf', 'Db', 'Sg', 'Bh', 'Hs', 'Mt', 'Ds', 'Rg', 'Cn', 'Nh', 'Fl', 'Mc', 'Lv', 'Ts', 'Og'},
    {'-', '-', 'La', 'Ce', 'Pr', 'Nd', 'Pm', 'Sm', 'Eu', 'Gd', 'Tb', 'Dy', 'Ho', 'Er', 'Tm', 'Yb', 'Lu', '-'},
    {'-', '-', 'Ac', 'Th', 'Pa', 'U', 'Np', 'Pu', 'Am', 'Cm', 'Bk', 'Cf', 'Es', 'Fm', 'Md', 'No', 'Lr', '-'},
    {'-', '-', '-', '-', '-', '-', 'Lanthanides', '-', '-', '-', '-', '-', '-', 'Actinides', '-', '-', '-', '-'},
  };

  printf("Welcome to the Futuristic Periodic Table Quiz!\n\n");
  printf("You will be shown a question in the following format:\n\n");
  printf("What is the symbol for [element name]?\n\n");
  printf("You will then have to type in the correct symbol for that element.\n\n");
  printf("Are you ready to begin? (y/n): ");

  char ready;
  scanf(" %c", &ready);

  if (ready == 'y') {
    printf("\nGreat! Let's begin.\n\n");

    char *elements[] = {"Gold","Oxygen", "Zinc", "Iodine", "Bromine", "Sodium", "Sulfur", "Nitrogen", "Chlorine", "Calcium"};
    char *answers[] = {"Au", "O", "Zn", "I", "Br", "Na", "S", "N", "Cl", "Ca"};

    for (int i = 0; i < 10; i++) {
      display_table(periodic_table);

      char guess[3];
      printf("What is the symbol for %s?\n\n", elements[i]);
      scanf(" %s", guess);
      check_answer(guess, answers[i]);

      printf("\n");
    }

    printf("Quiz complete. Thanks for playing!\n");
  }
  else {
    printf("\nGoodbye.\n");
  }

  return 0;
}

void display_table(char periodic_table[][COLS]) {
  printf(" _____________________________________________\n");
  for (int i = 0; i < ROWS; i++) {
    printf("|");
    for (int j = 0; j < COLS; j++) {
      if (periodic_table[i][j] != '-') {
        printf("%-2c", periodic_table[i][j]);
      }
      else {
        printf("  ");
      }
      printf("  ");
    }
    printf("|\n");
  }
  printf("|_____________________________________________|\n\n");
}

void check_answer(char answer[], char correct_answer[]) {
  if (strcmp(answer, correct_answer) == 0) {
    printf("Correct!\n");
  }
  else {
    printf("Incorrect. The correct answer is %s.\n", correct_answer);
  }
}