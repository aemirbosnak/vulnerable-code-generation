//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Define the maximum number of questions
#define MAX_QUESTIONS 10

//Define the maximum size of the answer
#define MAX_ANSWER_SIZE 20

//Define the elements in the periodic table
char element[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
                        "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
                        "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
                        "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm",
                        "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
                        "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
                        "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

//Define the symbols in the periodic table
char symbol[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
                        "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
                        "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
                        "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm",
                        "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
                        "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
                        "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

int main(){
  //Welcome message
  printf("Welcome to Periodic Table Quiz!\n");

  //Initialize the random number generator
  srand(time(NULL));

  //Initialize the score
  int score = 0;

  //Initialize the number of questions
  int num_questions = 0;

  //Initialize the array of questions
  char question[MAX_QUESTIONS][MAX_ANSWER_SIZE];

  //Generate questions randomly
  for(int i = 0; i < MAX_QUESTIONS; i++){
      char element_name[3];
      //Generate a random element name
      int random_index = rand() % 118;
      strcpy(element_name, element[random_index]);
      //Ask for the symbol of the element
      printf("What is the symbol for %s? ", element_name);
      scanf("%s", question[i]);
      //Check if the answer is correct and update the score
      if(strcmp(symbol[random_index], question[i]) == 0){
          printf("Correct!\n");
          score++;
      }else{
          printf("Wrong! The correct answer is %s.\n", symbol[random_index]);
      }
      //Increment the number of questions asked
      num_questions++;
  }

  //Display the statistics after the quiz
  printf("\nStatistics:\n");
  printf("Number of questions: %d\n", num_questions);
  printf("Score: %d / %d (%.2f%%)\n", score, MAX_QUESTIONS, ((float)score/MAX_QUESTIONS)*100);

  return 0;
}