//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    // Initializing variables
    char name[50];
    int score = 0;
    
    // Greeting the user and asking for their name
    printf("Hello, and welcome to the C Periodic Table Quiz!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    
    // Displaying quiz instructions
    printf("\nGreat, thanks %s! Here are the instructions for the quiz:\n", name);
    printf("There are 10 questions about the elements in the periodic table. For each question, you will be presented with the symbol of an element and four answer choices.\n");
    printf("Select the answer that you believe is correct. Each correct answer is worth 10 points. Good luck!\n\n");
    
    // Question 1
    printf("Question 1: What is the symbol for nitrogen?\n");
    printf("A) N\n");
    printf("B) Ni\n");
    printf("C) Na\n");
    printf("D) Ne\n");
    char answer1 = 'A';
    char guess1;
    scanf(" %c", &guess1);
    if (toupper(guess1) == answer1) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) N.\n");
    }
    
    // Question 2
    printf("\nQuestion 2: What is the symbol for gold?\n");
    printf("A) Au\n");
    printf("B) Ag\n");
    printf("C) Al\n");
    printf("D) Fe\n");
    char answer2 = 'A';
    char guess2;
    scanf(" %c", &guess2);
    if (toupper(guess2) == answer2) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Au.\n");
    }
    
    // Question 3
    printf("\nQuestion 3: What is the symbol for oxygen?\n");
    printf("A) O\n");
    printf("B) Xe\n");
    printf("C) Pb\n");
    printf("D) O2\n");
    char answer3 = 'A';
    char guess3;
    scanf(" %c", &guess3);
    if (toupper(guess3) == answer3) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) O.\n");
    }
    
    // Question 4
    printf("\nQuestion 4: What is the symbol for sodium?\n");
    printf("A) Na\n");
    printf("B) Si\n");
    printf("C) S\n");
    printf("D) Co\n");
    char answer4 = 'A';
    char guess4;
    scanf(" %c", &guess4);
    if (toupper(guess4) == answer4) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Na.\n");
    }
    
    // Question 5
    printf("\nQuestion 5: What is the symbol for helium?\n");
    printf("A) He\n");
    printf("B) Hf\n");
    printf("C) Hg\n");
    printf("D) H\n");
    char answer5 = 'A';
    char guess5;
    scanf(" %c", &guess5);
    if (toupper(guess5) == answer5) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) He.\n");
    }
    
    // Question 6
    printf("\nQuestion 6: What is the symbol for iron?\n");
    printf("A) Fe\n");
    printf("B) F\n");
    printf("C) Fr\n");
    printf("D) Au\n");
    char answer6 = 'A';
    char guess6;
    scanf(" %c", &guess6);
    if (toupper(guess6) == answer6) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Fe.\n");
    }
    
    // Question 7
    printf("\nQuestion 7: What is the symbol for zinc?\n");
    printf("A) Zn\n");
    printf("B) Zr\n");
    printf("C) Z\n");
    printf("D) Xe\n");
    char answer7 = 'A';
    char guess7;
    scanf(" %c", &guess7);
    if (toupper(guess7) == answer7) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Zn.\n");
    }
    
    // Question 8
    printf("\nQuestion 8: What is the symbol for neon?\n");
    printf("A) Ne\n");
    printf("B) Na\n");
    printf("C) Ni\n");
    printf("D) Nb\n");
    char answer8 = 'A';
    char guess8;
    scanf(" %c", &guess8);
    if (toupper(guess8) == answer8) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Ne.\n");
    }
    
    // Question 9
    printf("\nQuestion 9: What is the symbol for copper?\n");
    printf("A) Cu\n");
    printf("B) C\n");
    printf("C) Ca\n");
    printf("D) Cr\n");
    char answer9 = 'A';
    char guess9;
    scanf(" %c", &guess9);
    if (toupper(guess9) == answer9) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) Cu.\n");
    }
    
    // Question 10
    printf("\nQuestion 10: What is the symbol for carbon?\n");
    printf("A) C\n");
    printf("B) Co\n");
    printf("C) Cd\n");
    printf("D) Cs\n");
    char answer10 = 'A';
    char guess10;
    scanf(" %c", &guess10);
    if (toupper(guess10) == answer10) {
        score += 10;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is A) C.\n");
    }
    
    // Displaying final score and romantic message
    printf("\nCongrats %s, you have finished the quiz! Your final score is %d out of 100.\n", name, score);
    if (score >= 80) {
        printf("Wow %s, you are a true chemistry genius! I am impressed by your knowledge of the periodic table. Maybe we could bond over some chemical equations if you're interested? ;)\n", name);
    } else {
        printf("Not bad %s, but I see there is still room for improvement. Maybe we could study chemistry together sometime? ;) \n", name);
    }
    
    return 0;
}