//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10 // maximum number of questions in a single quiz
#define MAX_OPTIONS 4    // maximum number of options for a question

// configuration of questions and answers
char* questions[MAX_QUESTIONS] = {
   "What is the symbol for carbon?",
   "What is the atomic number of oxygen?",
   "What is the most common element in the Earth's crust?",
   "What is the symbol for gold?",
   "What is the atomic number of neon?",
   "What is the symbol for helium?",
   "What is the atomic number of iron?",
   "What is the symbol for nitrogen?",
   "What is the atomic number of potassium?",
   "What is the symbol for sodium?"
};
char* options[MAX_QUESTIONS][MAX_OPTIONS] = {
   {"Ca", "Cr", "C", "Co"},
   {"8", "16", "20", "6"},
   {"Hydrogen", "Oxygen", "Carbon", "Silicon"},
   {"Au", "Ag", "U", "Pb"},
   {"10", "11", "7", "8"},
   {"He", "Ne", "Na", "H"},
   {"25", "26", "27", "28"},
   {"N", "Na", "Mg", "Ca"},
   {"19", "18", "21", "39"},
   {"So", "Na", "Si", "S"}
};
int answers[MAX_QUESTIONS] = {2, 4, 3, 1, 3, 1, 4, 1, 4, 2}; // correct answer index for each question

// main function
int main() {
   int numQuestions = 0; // number of questions to ask in the quiz
   srand(time(NULL));   // initialize random number generator with current time

   printf("Welcome to the Periodic Table Quiz!\n\n");
   printf("Select the number of questions you would like to answer (1-%d): ", MAX_QUESTIONS);
   scanf("%d", &numQuestions);
   while (numQuestions < 1 || numQuestions > MAX_QUESTIONS) {
      printf("Invalid number of questions. Please enter a number between 1 and %d: ", MAX_QUESTIONS);
      scanf("%d", &numQuestions);
   }

   int questionIndices[MAX_QUESTIONS]; // array of indices of questions to ask
   for (int i = 0; i < MAX_QUESTIONS; i++) {
      questionIndices[i] = -1; // initialize to invalid index
   }
   for (int i = 0; i < numQuestions; i++) {
      int randomIndex = rand() % MAX_QUESTIONS;
      while (isDuplicate(randomIndex, questionIndices, i)) {
         randomIndex = rand() % MAX_QUESTIONS;
      }
      questionIndices[i] = randomIndex;
   }

   int score = 0; // number of correct answers
   printf("\nLet's begin! You will be asked %d questions.\n\n", numQuestions);
   for (int i = 0; i < numQuestions; i++) {
      printf("%d. %s\n", i+1, questions[questionIndices[i]]);
      for (int j = 0; j < MAX_OPTIONS; j++) {
         printf("%d) %s\n", j+1, options[questionIndices[i]][j]);
      }
      int answer;
      printf("Your answer: ");
      scanf("%d", &answer);
      while (answer < 1 || answer > MAX_OPTIONS) {
         printf("Invalid answer. Please enter a number between 1 and %d: ", MAX_OPTIONS);
         scanf("%d", &answer);
      }
      if (answer == answers[questionIndices[i]]) {
         printf("Correct!\n");
         score++;
      } else {
         printf("Incorrect. The correct answer is %d) %s\n", answers[questionIndices[i]], options[questionIndices[i]][answers[questionIndices[i]]-1]);
      }
      printf("\n");
   }

   printf("Quiz complete! You got %d out of %d questions correct.\n", score, numQuestions);

   return 0;
}

// helper function to check if the given index already exists in the array of indices
int isDuplicate(int index, int arr[], int size) {
   for (int i = 0; i < size; i++) {
      if (index == arr[i]) {
         return 1; // duplicate found
      }
   }
   return 0; // no duplicates found
}