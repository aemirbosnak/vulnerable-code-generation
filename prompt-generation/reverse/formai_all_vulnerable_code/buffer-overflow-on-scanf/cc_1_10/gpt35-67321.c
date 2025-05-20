//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define the quiz questions and answers
    char questions[118][50] = {
        "What element is represented by the symbol H?", 
        "What element is represented by the symbol He?",
        "What element is represented by the symbol Li?", 
        "What element is represented by the symbol Be?", 
        "What element is represented by the symbol B?", 
        "What element is represented by the symbol C?", 
        "What element is represented by the symbol N?", 
        "What element is represented by the symbol O?", 
        "What element is represented by the symbol F?", 
        "What element is represented by the symbol Ne?",
        "What element is represented by the symbol Na?", 
        "What element is represented by the symbol Mg?", 
        "What element is represented by the symbol Al?", 
        "What element is represented by the symbol Si?", 
        "What element is represented by the symbol P?", 
        "What element is represented by the symbol S?", 
        "What element is represented by the symbol Cl?", 
        "What element is represented by the symbol Ar?", 
        "What element is represented by the symbol K?", 
        "What element is represented by the symbol Ca?",
        "What element is represented by the symbol Sc?", 
        "What element is represented by the symbol Ti?", 
        "What element is represented by the symbol V?", 
        "What element is represented by the symbol Cr?", 
        "What element is represented by the symbol Mn?", 
        "What element is represented by the symbol Fe?", 
        "What element is represented by the symbol Co?", 
        "What element is represented by the symbol Ni?", 
        "What element is represented by the symbol Cu?",
        "What element is represented by the symbol Zn?", 
        "What element is represented by the symbol Ga?", 
        "What element is represented by the symbol Ge?", 
        "What element is represented by the symbol As?", 
        "What element is represented by the symbol Se?", 
        "What element is represented by the symbol Br?", 
        "What element is represented by the symbol Kr?", 
        "What element is represented by the symbol Rb?", 
        "What element is represented by the symbol Sr?",
        "What element is represented by the symbol Y?", 
        "What element is represented by the symbol Zr?", 
        "What element is represented by the symbol Nb?", 
        "What element is represented by the symbol Mo?", 
        "What element is represented by the symbol Tc?", 
        "What element is represented by the symbol Ru?", 
        "What element is represented by the symbol Rh?", 
        "What element is represented by the symbol Pd?", 
        "What element is represented by the symbol Ag?",
        "What element is represented by the symbol Cd?", 
        "What element is represented by the symbol In?", 
        "What element is represented by the symbol Sn?", 
        "What element is represented by the symbol Sb?", 
        "What element is represented by the symbol Te?", 
        "What element is represented by the symbol I?", 
        "What element is represented by the symbol Xe?", 
        "What element is represented by the symbol Cs?", 
        "What element is represented by the symbol Ba?",
        "What element is represented by the symbol La?", 
        "What element is represented by the symbol Ce?", 
        "What element is represented by the symbol Pr?", 
        "What element is represented by the symbol Nd?", 
        "What element is represented by the symbol Pm?", 
        "What element is represented by the symbol Sm?", 
        "What element is represented by the symbol Eu?", 
        "What element is represented by the symbol Gd?", 
        "What element is represented by the symbol Tb?",
        "What element is represented by the symbol Dy?", 
        "What element is represented by the symbol Ho?", 
        "What element is represented by the symbol Er?", 
        "What element is represented by the symbol Tm?", 
        "What element is represented by the symbol Yb?", 
        "What element is represented by the symbol Lu?", 
        "What element is represented by the symbol Hf?", 
        "What element is represented by the symbol Ta?", 
        "What element is represented by the symbol W?", 
        "What element is represented by the symbol Re?",
        "What element is represented by the symbol Os?", 
        "What element is represented by the symbol Ir?", 
        "What element is represented by the symbol Pt?", 
        "What element is represented by the symbol Au?", 
        "What element is represented by the symbol Hg?", 
        "What element is represented by the symbol Tl?", 
        "What element is represented by the symbol Pb?", 
        "What element is represented by the symbol Bi?", 
        "What element is represented by the symbol Th?",
        "What element is represented by the symbol Pa?", 
        "What element is represented by the symbol U?", 
        "What element is represented by the symbol Np?", 
        "What element is represented by the symbol Pu?", 
        "What element is represented by the symbol Am?", 
        "What element is represented by the symbol Cm?", 
        "What element is represented by the symbol Bk?", 
        "What element is represented by the symbol Cf?", 
        "What element is represented by the symbol Es?",
        "What element is represented by the symbol Fm?", 
        "What element is represented by the symbol Md?", 
        "What element is represented by the symbol No?", 
        "What element is represented by the symbol Lr?", 
        "What element is represented by the symbol Rf?", 
        "What element is represented by the symbol Db?", 
        "What element is represented by the symbol Sg?", 
        "What element is represented by the symbol Bh?", 
        "What element is represented by the symbol Hs?",
        "What element is represented by the symbol Mt?"
    };

    char answers[118][30] = {
        "hydrogen",
        "helium",
        "lithium",
        "beryllium",
        "boron",
        "carbon",
        "nitrogen",
        "oxygen",
        "fluorine",
        "neon",
        "sodium",
        "magnesium",
        "aluminum",
        "silicon",
        "phosphorus",
        "sulfur",
        "chlorine",
        "argon",
        "potassium",
        "calcium",
        "scandium",
        "titanium",
        "vanadium",
        "chromium",
        "manganese",
        "iron",
        "cobalt",
        "nickel",
        "copper",
        "zinc",
        "gallium",
        "germanium",
        "arsenic",
        "selenium",
        "bromine",
        "krypton",
        "rubidium",
        "strontium",
        "yttrium",
        "zirconium",
        "niobium",
        "molybdenum",
        "technetium",
        "ruthenium",
        "rhodium",
        "palladium",
        "silver",
        "cadmium",
        "indium",
        "tin",
        "antimony",
        "tellurium",
        "iodine",
        "xenon",
        "cesium",
        "barium",
        "lanthanum",
        "cerium",
        "praseodymium",
        "neodymium",
        "promethium",
        "samarium",
        "europium",
        "gadolinium",
        "terbium",
        "dysprosium",
        "holmium",
        "erbium",
        "thulium",
        "ytterbium",
        "lutetium",
        "hafnium",
        "tantalum",
        "tungsten",
        "rhenium",
        "osmium",
        "iridium",
        "platinum",
        "gold",
        "mercury",
        "thallium",
        "lead",
        "bismuth",
        "thorium",
        "protactinium",
        "uranium",
        "neptunium",
        "plutonium",
        "americium",
        "curium",
        "berkelium",
        "californium",
        "einsteinium",
        "fermium",
        "mendelevium",
        "nobelium",
        "lawrencium",
        "rutherfordium",
        "dubnium",
        "seaborgium",
        "bohrium",
        "hassium",
        "meitnerium"
    };

    // Define variables to keep track of score and current question number
    int score = 0;
    int questionNum = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Print welcome message and instructions
    printf("\nWelcome to the Periodic Table Quiz!\n\n");
    printf("You will be asked 10 questions about elements on the periodic table.\n");
    printf("For each question, enter the name of the element as your answer.\n");
    printf("Capitalization and spelling count, so be careful!\n");
    printf("You will get one point for each correct answer.\n");
    printf("Good luck!\n\n");

    // Loop through 10 randomly-selected questions
    for (int i = 0; i < 10; i++)
    {
        // Select a random question and print it
        int randIndex = rand() % 118;
        printf("Question #%d: %s\n", questionNum+1, questions[randIndex]);

        // Read user's answer and convert to lowercase
        char userAnswer[30];
        scanf("%s", userAnswer);
        for (int i = 0; userAnswer[i]; i++) {
            userAnswer[i] = tolower(userAnswer[i]);
        }

        // Check if user's answer is correct
        if (strcmp(userAnswer, answers[randIndex]) == 0) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Sorry, that is incorrect.\n\n");
        }

        // Increment question number
        questionNum++;
    }

    // Print final score
    printf("Quiz complete! You got %d out of 10 questions correct.\n\n", score);

    // Check if perfect score was achieved
    if (score == 10) {
        printf("Wow, you got a perfect score! Are you a chemistry genius?\n");
    } else {
        printf("Thanks for taking the quiz!\n");
    }

    return 0;
}