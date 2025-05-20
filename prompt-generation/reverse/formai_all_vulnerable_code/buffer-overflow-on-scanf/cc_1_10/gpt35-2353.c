//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

int main() {
    int score = 0, i, j, correct_choice, user_choice;
    char blank_space[] = "_____";
    char *element_names[MAX_QUESTIONS] = {"Iron", "Hydrogen", "Gold", "Nitrogen", "Chlorine", "Sodium", "Calcium", "Oxygen", "Carbon", "Neon"};
    char *element_symbols[MAX_QUESTIONS] = {"Fe", "H", "Au", "N", "Cl", "Na", "Ca", "O", "C", "Ne"};
    char *element_categories[MAX_QUESTIONS] = {"Transition metal", "Non-metal", "Transition metal", "Non-metal", "Halogen", "Alkali metal", "Alkaline earth metal", "Non-metal", "Non-metal", "Noble gas"};
    int atomic_numbers[MAX_QUESTIONS] = {26, 1, 79, 7, 17, 11, 20, 8, 6, 10};
    char *choices[MAX_CHOICES] = {"a) ", "b) ", "c) ", "d) ", "e) "};
    
    // Seed the random number generator with current time
    srand(time(NULL));
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("WELCOME TO THE FUTURISTIC PERIODIC TABLE QUIZ!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    for(i = 0; i < MAX_QUESTIONS; i++) {
        // Generate a random number between 0 and 9
        j = rand() % MAX_QUESTIONS;
        
        // Print the question with blank space for the missing word
        printf("\nQuestion %d:\nWhat is the chemical symbol for %s?\n", (i+1), element_names[j]);
        printf("a) %s\nb) %s\nc) %s\nd) %s\ne) %s\n", element_symbols[(j+1)%MAX_QUESTIONS], element_symbols[(j+2)%MAX_QUESTIONS], element_symbols[(j+3)%MAX_QUESTIONS], element_symbols[(j+4)%MAX_QUESTIONS], element_symbols[j]);
        printf("Choose your answer (a, b, c, d or e): ");
        scanf("%d", &user_choice);
        user_choice--;
        
        // Check if the user's choice is correct and update score
        correct_choice = 4;
        if(user_choice == correct_choice) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", element_symbols[j]);
        }
    }
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("You have reached the end of the quiz!\n");
    printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    return 0;
}