//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Array of elements and their symbols
    char* elements[] = {"Hydrogen","Helium","Lithium","Beryllium",
                        "Boron","Carbon","Nitrogen","Oxygen",
                        "Fluorine","Neon","Sodium","Magnesium",
                        "Aluminum","Silicon","Phosphorus","Sulfur",
                        "Chlorine","Argon","Potassium","Calcium"};

    char* symbols[] = {"H","He","Li","Be","B","C","N","O",
                       "F","Ne","Na","Mg","Al","Si","P","S",
                       "Cl","Ar","K","Ca"};

    // Array of questions and answers
    char* questions[] = {"What element has the symbol H?", "What is the symbol for Oxygen?",
                         "What element has the symbol Na?", "What is the symbol for Chlorine?",
                         "What element has the symbol S?", "What is the symbol for Phosphorus?",
                         "What element has the symbol Ar?", "What is the symbol for Potassium?",
                         "What element has the symbol Be?", "What is the symbol for Calcium?"};

    char* answers[] = {"Hydrogen", "O", "Sodium", "Cl",
                       "Sulfur", "P", "Argon", "K",
                       "Beryllium", "Ca"};

    int num_questions = 10;
    int num_correct = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    for(int i=0; i<num_questions; i++)
    {
        // Get a random element index
        int index = rand() % 20;

        // Ask the question
        printf("%s\n", questions[i]);

        // Wait for the user's answer
        char answer[20];
        scanf("%s", answer);

        // Check the answer
        if(strcmp(answer, symbols[index]) == 0 || strcmp(answer, elements[index]) == 0)
        {
            printf("Correct!\n");
            num_correct++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s (%s).\n", elements[index], symbols[index]);
        }
    }

    printf("You got %d out of %d questions correct!\n", num_correct, num_questions);

    return 0;
}