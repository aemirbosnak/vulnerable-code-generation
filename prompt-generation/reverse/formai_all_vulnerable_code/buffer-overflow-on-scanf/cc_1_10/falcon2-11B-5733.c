//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

// Define the elements and their symbols
#define NUM_ELEMENTS 100
const char* elements[NUM_ELEMENTS] = {
  "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
  "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
  "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu",
  "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
  "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
  "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba",
  "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
  "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
  "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
  "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh",
  "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Mc", "Lv", "Ts",
  "Og"
};

int main() {
  printf("Welcome to the Periodic Table Quiz!\n");
  printf("Please answer the following questions:\n\n");

  // Ask questions and get answers from the user
  printf("Question 1: What is the symbol for Hydrogen? (H)\n");
  int ans1;
  scanf("%d", &ans1);
  if (ans1 == 1) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The correct answer is H.\n");
  }

  printf("Question 2: What is the symbol for Helium? (He)\n");
  int ans2;
  scanf("%d", &ans2);
  if (ans2 == 2) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The correct answer is He.\n");
  }

  // Add more questions and answers here

  printf("Thank you for playing the Periodic Table Quiz!\n");

  return 0;
}