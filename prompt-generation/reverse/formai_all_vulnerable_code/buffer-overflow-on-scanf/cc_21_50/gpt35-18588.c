//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_GUESSES 5

struct element {
  char symbol[3];
  char name[20];
  int number;
  char region[10];
  char group[10];
};

typedef struct element Element;

int main(){

  srand(time(NULL));

  // Define elements
  Element elements[118] = {
      {"H", "Hydrogen", 1, "Nonmetal", "1"},
      {"He", "Helium", 2, "Noble gas", "18"},
      {"Li", "Lithium", 3, "Alkali metal", "1"},
      {"Be", "Beryllium", 4, "Alkaline earth metal", "2"},
      {"B", "Boron", 5, "Metalloid", "13"},
      {"C", "Carbon", 6, "Nonmetal", "14"},
      {"N", "Nitrogen", 7, "Nonmetal", "15"},
      {"O", "Oxygen", 8, "Nonmetal", "16"},
      {"F", "Fluorine", 9, "Halogen", "17"},
      {"Ne", "Neon", 10, "Noble gas", "18"},
      {"Na", "Sodium", 11, "Alkali metal", "1"},
      {"Mg", "Magnesium", 12, "Alkaline earth metal", "2"},
      {"Al", "Aluminium", 13, "Metal", "13"},
      {"Si", "Silicon", 14, "Metalloid", "14"},
      {"P", "Phosphorus", 15, "Nonmetal", "15"},
      {"S", "Sulfur", 16, "Nonmetal", "16"},
      {"Cl", "Chlorine", 17, "Halogen", "17"},
      {"Ar", "Argon", 18, "Noble gas", "18"},
      {"K", "Potassium", 19, "Alkali metal", "1"},
      {"Ca", "Calcium", 20, "Alkaline earth metal", "2"},
      {"Sc", "Scandium", 21, "Transition metal", "3"},
      {"Ti", "Titanium", 22, "Transition metal", "4"},
      {"V", "Vanadium", 23, "Transition metal", "5"},
      {"Cr", "Chromium", 24, "Transition metal", "6"},
      {"Mn", "Manganese", 25, "Transition metal", "7"},
      {"Fe", "Iron", 26, "Transition metal", "8"},
      {"Co", "Cobalt", 27, "Transition metal", "9"},
      {"Ni", "Nickel", 28, "Transition metal", "10"},
      {"Cu", "Copper", 29, "Transition metal", "11"},
      {"Zn", "Zinc", 30, "Transition metal", "12"},
      {"Ga", "Gallium", 31, "Metal", "13"},
      {"Ge", "Germanium", 32, "Metalloid", "14"},
      {"As", "Arsenic", 33, "Metalloid", "15"},
      {"Se", "Selenium", 34, "Nonmetal", "16"},
      {"Br", "Bromine", 35, "Halogen", "17"},
      {"Kr", "Krypton", 36, "Noble gas", "18"},
      {"Rb", "Rubidium", 37, "Alkali metal", "1"},
      {"Sr", "Strontium", 38, "Alkaline earth metal", "2"},
      {"Y", "Yttrium", 39, "Transition metal", "3"},
      {"Zr", "Zirconium", 40, "Transition metal", "4"},
      {"Nb", "Niobium", 41, "Transition metal", "5"},
      {"Mo", "Molybdenum", 42, "Transition metal", "6"},
      {"Tc", "Technetium", 43, "Transition metal", "7"},
      {"Ru", "Ruthenium", 44, "Transition metal", "8"},
      {"Rh", "Rhodium", 45, "Transition metal", "9"},
      {"Pd", "Palladium", 46, "Transition metal", "10"},
      {"Ag", "Silver", 47, "Transition metal", "11"},
      {"Cd", "Cadmium", 48, "Transition metal", "12"},
      {"In", "Indium", 49, "Metal", "13"},
      {"Sn", "Tin", 50, "Metal", "14"},
      {"Sb", "Antimony", 51, "Metalloid", "15"},
      {"Te", "Tellurium", 52, "Metalloid", "16"},
      {"I", "Iodine", 53, "Halogen", "17"},
      {"Xe", "Xenon", 54, "Noble gas", "18"},
      {"Cs", "Cesium", 55, "Alkali metal", "1"},
      {"Ba", "Barium", 56, "Alkaline earth metal", "2"},
      {"La", "Lanthanum", 57, "Lanthanide", " "},
      {"Ce", "Cerium", 58, "Lanthanide", " "},
      {"Pr", "Praseodymium", 59, "Lanthanide", " "},
      {"Nd", "Neodymium", 60, "Lanthanide", " "},
      {"Pm", "Promethium", 61, "Lanthanide", " "},
      {"Sm", "Samarium", 62, "Lanthanide", " "},
      {"Eu", "Europium", 63, "Lanthanide", " "},
      {"Gd", "Gadolinium", 64, "Lanthanide", " "},
      {"Tb", "Terbium", 65, "Lanthanide", " "},
      {"Dy", "Dysprosium", 66, "Lanthanide", " "},
      {"Ho", "Holmium", 67, "Lanthanide", " "},
      {"Er", "Erbium", 68, "Lanthanide", " "},
      {"Tm", "Thulium", 69, "Lanthanide", " "},
      {"Yb", "Ytterbium", 70, "Lanthanide", " "},
      {"Lu", "Lutetium", 71, "Lanthanide", " "},
      {"Hf", "Hafnium", 72, "Transition metal", "4"},
      {"Ta", "Tantalum", 73, "Transition metal", "5"},
      {"W", "Tungsten", 74, "Transition metal", "6"},
      {"Re", "Rhenium", 75, "Transition metal", "7"},
      {"Os", "Osmium", 76, "Transition metal", "8"},
      {"Ir", "Iridium", 77, "Transition metal", "9"},
      {"Pt", "Platinum", 78, "Transition metal", "10"},
      {"Au", "Gold", 79, "Transition metal", "11"},
      {"Hg", "Mercury", 80, "Transition metal", "12"},
      {"Tl", "Thallium", 81, "Metal", "13"},
      {"Pb", "Lead", 82, "Metal", "14"},
      {"Bi", "Bismuth", 83, "Metal", "15"},
      {"Po", "Polonium", 84, "Metal", "16"},
      {"At", "Astatine", 85, "Halogen", "17"},
      {"Rn", "Radon", 86, "Noble gas", "18"},
      {"Fr", "Francium", 87, "Alkali metal", "1"},
      {"Ra", "Radium", 88, "Alkaline earth metal", "2"},
      {"Ac", "Actinium", 89, "Actinide", " "},
      {"Th", "Thorium", 90, "Actinide", " "},
      {"Pa", "Protactinium", 91, "Actinide", " "},
      {"U", "Uranium", 92, "Actinide", " "},
      {"Np", "Neptunium", 93, "Actinide", " "},
      {"Pu", "Plutonium", 94, "Actinide", " "},
      {"Am", "Americium", 95, "Actinide", " "},
      {"Cm", "Curium", 96, "Actinide", " "},
      {"Bk", "Berkelium", 97, "Actinide", " "},
      {"Cf", "Californium", 98, "Actinide", " "},
      {"Es", "Einsteinium", 99, "Actinide", " "},
      {"Fm", "Fermium", 100, "Actinide", " "},
      {"Md", "Mendelevium", 101, "Actinide", " "},
      {"No", "Nobelium", 102, "Actinide", " "},
      {"Lr", "Lawrencium", 103, "Actinide", " "},
      {"Rf", "Rutherfordium", 104, "Transition metal", "4"},
      {"Db", "Dubnium", 105, "Transition metal", "5"},
      {"Sg", "Seaborgium", 106, "Transition metal", "6"},
      {"Bh", "Bohrium", 107, "Transition metal", "7"},
      {"Hs", "Hassium", 108, "Transition metal", "8"},
      {"Mt", "Meitnerium", 109, "Transition metal", "9"},
      {"Ds", "Darmstadtium", 110, "Transition metal", "10"},
      {"Rg", "Roentgenium", 111, "Transition metal", "11"},
      {"Cn", "Copernicium", 112, "Transition metal", "12"},
      {"Nh", "Nihonium", 113, "Unknown", "13"},
      {"Fl", "Flerovium", 114, "Unknown", "14"},
      {"Mc", "Moscovium", 115, "Unknown", "15"},
      {"Lv", "Livermorium", 116, "Unknown", "16"},
      {"Ts", "Tennessine", 117, "Unknown", "17"},
      {"Og", "Oganesson", 118, "Unknown", "18"},
  };

  // Define questions
  char *questions[MAX_QUESTIONS] = {
      "What is the symbol for %s?",
      "What is the name of element with atomic number %d?",
      "Which region does %s belong to?",
      "What is the group number for %s?",
      "What is the atomic number of %s?",
  };

  // Define answers
  char *answers[MAX_QUESTIONS][MAX_GUESSES] = {
      {"%s", "+1", "-1", "*"},
      {"%s", "*2", "/2", "%3"},
      {"%s", "Noble gas", "Halogen", "Metalloid"},
      {"%s", "1", "14", "18"},
      {"%d", "+3", "-2", "*2"},
  };

  int score = 0;
  int question_count = 0;
  int answered_questions[MAX_QUESTIONS] = {-1};

  printf("Welcome to the Periodic Table quiz!\n\n");

  while (question_count < MAX_QUESTIONS) {

    // Pick a random element
    int el_index = rand() % 118;
    while (1) {
      int found = 0;
      for (int i = 0; i < question_count; i++) {
        if (answered_questions[i] == el_index) {
          found = 1;
          break;
        }
      }
      if (!found) {
        break;
      }
      el_index = rand() % 118;
    }
    answered_questions[question_count] = el_index;
    Element el = elements[el_index];

    // Pick a random question
    int question_index = rand() % 5;
    char *question = questions[question_index];
    char *ans1 = answers[question_index][0];
    char *ans2 = answers[question_index][1];
    char *ans3 = answers[question_index][2];
    char correct_answer[20];

    // Fill in correct answer
    if (question_index == 0) { // symbol
      snprintf(correct_answer, 20, "%s", el.symbol);
    } else if (question_index == 1) { // name
      snprintf(correct_answer, 20, "%s", el.name);
    } else if (question_index == 2) { // region
      snprintf(correct_answer, 20, "%s", el.region);
    } else if (question_index == 3) { // group
      snprintf(correct_answer, 20, "%s", el.group);
    } else if (question_index == 4) { // number
      snprintf(correct_answer, 20, "%d", el.number);
    }

    // Shuffle answers
    int right_ans_pos = rand() % 3;
    int ans1_pos = (right_ans_pos + 1) % 3;
    int ans2_pos = (ans1_pos + 1) % 3;
    char *right_ans = correct_answer;
    char *answer1 = answers[question_index][ans1_pos];
    char *answer2 = answers[question_index][ans2_pos];
    char *answers[] = {right_ans, answer1, answer2};
    char *shuffled_answers[] = {right_ans, answer1, answer2};
    for (int i = 0; i < 3; i++) {
      int rand_pos = rand() % 3;
      while (rand_pos == i) {
        rand_pos = rand() % 3;
      }
      shuffled_answers[i] = answers[rand_pos];
    }

    // Print the question
    printf("%d. ", question_count + 1);
    if (question_index == 0) { // symbol
      printf(question, el.name);
    } else if (question_index == 1) { // name
      printf(question, el.number);
    } else {
      printf(question, el.symbol);
    }
    printf("\n");

    // Print answers
    printf("a. %s\n", shuffled_answers[0]);
    printf("b. %s\n", shuffled_answers[1]);
    printf("c. %s\n", shuffled_answers[2]);

    // Get input
    char guess;
    printf("Enter your guess (a-c): ");
    scanf(" %c", &guess);

    // Check answer
    if (guess == 'a' && shuffled_answers[0] == right_ans) {
      printf("Correct!\n\n");
      score++;
    } else if (guess == 'b' && shuffled_answers[1] == right_ans) {
      printf("Correct!\n\n");
      score++;
    } else if (guess == 'c' && shuffled_answers[2] == right_ans) {
      printf("Correct!\n\n");
      score++;
    } else {
      printf("Wrong! The correct answer is %s.\n\n", correct_answer);
    }

    question_count++;
  }

  // Print score
  printf("Congratulations, you finished the quiz!\n");
  printf("Your score is: %d/%d\n", score, MAX_QUESTIONS);

  return 0;
}