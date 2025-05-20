//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char elements[118][3] = {
    "H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
    "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
    "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
  };

  int scores[118] = {
    2,  4,  1,  2,  3,  4,  5,  6,  7,  8,
    1,  2,  3,  4,  5,  6,  7,  8,  1,  2,
    3,  4,  5,  6,  7,  8,  1,  2,  3,  4,
    5,  6,  7,  8,  1,  2,  3,  4,  5,  6,
    7,  8,  1,  2,  3,  4,  5,  6,  7,  8,
    1,  2,  3,  4,  5,  6,  7,  8,  1,  2,
    3,  4,  5,  6,  7,  8,  1,  2,  3,  4,
    5,  6,  7,  8,  1,  2,  3,  4,  5,  6,
    7,  8,  1,  2,  3,  4,  5,  6,  7,  8,
    1,  2,  3,  4,  5,  6,  7,  8
  };

  int atomic_numbers[118] = {
    1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 112, 113, 114, 115, 116, 117, 118
  };

  int user_score = 0;
  srand(time(0)); // seed the random number generator

  printf("Welcome to the Periodic Table Quiz!\n");
  printf("You will be shown the symbols of chemical elements, and you need to guess their respective atomic numbers.\n");
  printf("Enter 'quit' to finish the quiz.\n");

  while (1) {
    int random_index = rand() % 118;
    char guess[10];
    printf("\n%d. What is the atomic number of the element with symbol %s?\n", user_score+1, elements[random_index]);
    scanf("%s", guess);

    if (strcmp(guess, "quit") == 0) {
      break;
    }

    if (atoi(guess) == atomic_numbers[random_index]) {
      printf("Correct!\n");
      user_score++;
    }
    else {
      printf("Wrong! The correct answer is %d.\n", atomic_numbers[random_index]);
    }
  }

  printf("\nQuiz finished. Your score is %d out of %d.\n", user_score, 118);
  return 0;
}