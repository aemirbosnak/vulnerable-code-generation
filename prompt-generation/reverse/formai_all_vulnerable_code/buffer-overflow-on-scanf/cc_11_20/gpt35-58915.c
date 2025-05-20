//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>

int main() {
  printf("\t\tC Periodic Table Quiz\n");

  char name[20];
  printf("\nEnter your name: ");
  scanf("%s", name);
  
  printf("\nHello %s, let's begin the quiz!\n", name);
  printf("\nInstructions: \n");
  printf("1. There are 10 questions in this quiz. \n");
  printf("2. Each question has 4 options out of which only one is correct. \n");
  printf("3. For each correct answer you will get 10 points and for each incorrect answer you will lose 5 points. \n");
  printf("4. Enter the option number (1-4) for your answer. \n");

  int score = 0;
  int answer;

  // Question 1
  printf("\n1. Which element has the symbol 'C' in the periodic table?\n");
  printf("1. Carbon \t2. Copper \n");
  printf("3. Calcium \t4. Chlorine \n");
  scanf("%d", &answer);
  if (answer == 1) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Carbon'.\n");
    score -= 5;
  }

  // Question 2
  printf("\n2. Which noble gas has atomic number 18?\n");
  printf("1. Helium \t2. Neon \n");
  printf("3. Argon \t4. Krypton \n");
  scanf("%d", &answer);
  if (answer == 3) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Argon'.\n");
    score -= 5;
  }

  // Question 3
  printf("\n3. Which element is used as a coolant in nuclear reactors?\n");
  printf("1. Hydrogen \t2. Helium \n");
  printf("3. Lithium  \t4. Sodium \n");
  scanf("%d", &answer);
  if (answer == 3) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Lithium'.\n");
    score -= 5;
  }

  // Question 4
  printf("\n4. Which element has the highest atomic number?\n");
  printf("1. Uranium \t2. Plutonium \n");
  printf("3. Americium  \t4. Oganesson \n");
  scanf("%d", &answer);
  if (answer == 4) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Oganesson'.\n");
    score -= 5;
  }

  // Question 5
  printf("\n5. Which element has the highest melting point?\n");
  printf("1. Iron \t2. Tungsten \n");
  printf("3. Platinum  \t4. Copper \n");
  scanf("%d", &answer);
  if (answer == 2) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Tungsten'.\n");
    score -= 5;
  }

  // Question 6
  printf("\n6. Which element is used as a semiconductor in electronics?\n");
  printf("1. Silicon \t2. Aluminium \n");
  printf("3. Copper  \t4. Silver \n");
  scanf("%d", &answer);
  if (answer == 1) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Silicon'.\n");
    score -= 5;
  }

  // Question 7
  printf("\n7. Which element is used as a bleaching agent?\n");
  printf("1. Chlorine \t2. Oxygen \n");
  printf("3. Sulphur  \t4. Carbon \n");
  scanf("%d", &answer);
  if (answer == 1) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Chlorine'.\n");
    score -= 5;
  }

  // Question 8
  printf("\n8. Which element is used in fluorescent lamps?\n");
  printf("1. Neon \t2. Argon \n");
  printf("3. Krypton  \t4. Mercury \n");
  scanf("%d", &answer);
  if (answer == 4) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Mercury'.\n");
    score -= 5;
  }

  // Question 9
  printf("\n9. Which element is the lightest metal?\n");
  printf("1. Sodium \t2. Potassium \n");
  printf("3. Magnesium  \t4. Calcium \n");
  scanf("%d", &answer);
  if (answer == 1) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Sodium'.\n");
    score -= 5;
  }

  // Question 10
  printf("\n10. Which element is used in the production of ammonia?\n");
  printf("1. Hydrogen \t2. Nitrogen \n");
  printf("3. Carbon  \t4. Oxygen \n");
  scanf("%d", &answer);
  if (answer == 2) {
    printf("\nCorrect answer!\n");
    score += 10;
  } else {
    printf("\nIncorrect answer, the correct answer is 'Nitrogen'.\n");
    score -= 5;
  }

  printf("\n\nYour score is: %d\n\n", score);

  if (score >= 50) {
    printf("Congratulations %s, you passed the quiz!", name);
  } else {
    printf("Sorry %s, you did not pass the quiz. Please try again!", name);
  }

  printf("\n\n Thank you for playing the C Periodic Table Quiz!\n");

  return 0;
}