//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
  // Define the periodic table as a 2D array
  char periodic_table[118][3] = {
    {"H "}, {"He"}, {"Li"}, {"Be"}, {"B "}, {"C "}, {"N "}, {"O "}, {"F "},
    {"Ne"}, {"Na"}, {"Mg"}, {"Al"}, {"Si"}, {"P "}, {"S "}, {"Cl"}, {"Ar"},
    {"K "}, {"Ca"}, {"Sc"}, {"Ti"}, {"V "}, {"Cr"}, {"Mn"}, {"Fe"}, {"Co"},
    {"Ni"}, {"Cu"}, {"Zn"}, {"Ga"}, {"Ge"}, {"As"}, {"Se"}, {"Br"}, {"Kr"},
    {"Rb"}, {"Sr"}, {"Y "}, {"Zr"}, {"Nb"}, {"Mo"}, {"Tc"}, {"Ru"}, {"Rh"},
    {"Pd"}, {"Ag"}, {"Cd"}, {"In"}, {"Sn"}, {"Sb"}, {"Te"}, {"I "}, {"Xe"},
    {"Cs"}, {"Ba"}, {"La"}, {"Ce"}, {"Pr"}, {"Nd"}, {"Pm"}, {"Sm"}, {"Eu"},
    {"Gd"}, {"Tb"}, {"Dy"}, {"Ho"}, {"Er"}, {"Tm"}, {"Yb"}, {"Lu"}, {"Hf"},
    {"Ta"}, {"W "}, {"Re"}, {"Os"}, {"Ir"}, {"Pt"}, {"Au"}, {"Hg"}, {"Tl"},
    {"Pb"}, {"Bi"}, {"Po"}, {"At"}, {"Rn"}, {"Fr"}, {"Ra"}, {"Ac"}, {"Th"},
    {"Pa"}, {"U "}, {"Np"}, {"Pu"}, {"Am"}, {"Cm"}, {"Bk"}, {"Cf"}, {"Es"},
    {"Fm"}, {"Md"}, {"No"}, {"Lr"}, {"Rf"}, {"Db"}, {"Sg"}, {"Bh"}, {"Hs"},
    {"Mt"}, {"Ds"}, {"Rg"}, {"Cn"}, {"Nh"}, {"Fl"}, {"Mc"}, {"Lv"}, {"Ts"},
    {"Og"}
  };

  // Define 5 quiz questions
  char questions[5][30] = {
    "What element has the symbol Fe?",
    "What element is a noble gas and has the symbol He?",
    "What element is the lightest metal?",
    "What element is used to make pencils and has the symbol C?",
    "What element is essential for human survival and has the symbol O?"
  };

  // Define an array to store the correct answers
  char answers[5][3] = {
    "Fe", "He", "Li", "C ", "O "
  };

  // Define a counter for the number of correct answers
  int correct_count = 0;

  // Loop through each question
  for (int i = 0; i < 5; i++) {
    // Print the question
    printf("%s\n", questions[i]);

    // Get the user's answer
    char user_answer[3];
    scanf("%s", user_answer);

    // Check if the answer is correct
    if (strcmp(user_answer, answers[i]) == 0) {
      printf("Correct!\n");
      correct_count++;
    } else {
      // If the answer is wrong, print the correct answer
      printf("Incorrect! The correct answer is %s.\n", answers[i]);
    }
  }

  // Calculate the percentage of correct answers
  float percentage_correct = (float)correct_count / 5 * 100;

  // Print the user's score
  printf("You got %d out of 5 questions correct!\n", correct_count);
  printf("Your score is %.2f%%.\n", percentage_correct);

  // Print the periodic table
  printf("\n");
  for (int i = 0; i < 118; i++) {
    printf("%s ", periodic_table[i]);
    if ((i+1) % 18 == 0) {
      printf("\n");
    }
  }

  return 0;
}