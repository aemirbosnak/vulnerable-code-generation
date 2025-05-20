//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include <stdio.h>

/* Function Prototype Declarations */
int get_choice(void);
int check_answer(int atomic_number, char symbol[], char name[]);

int main(void)
{
    /* Array Declarations for Atomic Number, Symbol, and Name for Each Element */
    int atomic_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    char symbols[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"};
    char names[][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon"};

    int choice = 0; /* Variable Declaration for User's Menu Choice */
    int answered_correctly = 0; /* Variable Declaration for Number of Correct Answers */
    int index = 0; /* Variable Declaration for Array Index */
    int atomic_number = 0; /* Variable Declaration for Element's Atomic Number */
    char symbol[3]; /* Variable Declaration for Element's Symbol */
    char name[20]; /* Variable Declaration for Element's Name */

    /* Loop Through the Menu Until the User Quits */
    do {
        /* Print the Menu */
        printf("Periodic Table Quiz\n");
        printf("-------------------\n");
        printf("1. Quiz Me on Element Symbols\n");
        printf("2. Quiz Me on Element Names\n");
        printf("3. Quit\n");
        printf("Enter Choice (1 - 3): ");

        /* Get the User's Menu Choice */
        choice = get_choice();

        /* Clear the Screen */
        system("cls");

        /* Process the User's Menu Choice */
        switch (choice) {
            case 1:
                /* Quiz the User on Element Symbols */
                printf("Quiz Me on Element Symbols\n");
                printf("--------------------------\n");

                /* Loop Through the Elements and Quiz the User */
                for (index = 0; index < 50; index++) {
                    /* Get the Element's Atomic Number, Symbol, and Name */
                    atomic_number = atomic_numbers[index];
                    strcpy(symbol, symbols[index]);
                    strcpy(name, names[index]);

                    /* Ask the User for the Symbol */
                    printf("What is the symbol for %s? ", name);

                    /* Check the User's Answer */
                    answered_correctly += check_answer(atomic_number, symbol, name);
                }

                /* Print the User's Score */
                printf("You answered %d out of 50 questions correctly.\n", answered_correctly);

                /* Reset the Number of Correct Answers */
                answered_correctly = 0;

                /* Wait for the User to Press Enter */
                printf("Press Enter to Continue... ");
                while (getchar() != '\n');

                /* Clear the Screen */
                system("cls");

                break;
            case 2:
                /* Quiz the User on Element Names */
                printf("Quiz Me on Element Names\n");
                printf("------------------------\n");

                /* Loop Through the Elements and Quiz the User */
                for (index = 0; index < 50; index++) {
                    /* Get the Element's Atomic Number, Symbol, and Name */
                    atomic_number = atomic_numbers[index];
                    strcpy(symbol, symbols[index]);
                    strcpy(name, names[index]);

                    /* Ask the User for the Name */
                    printf("What is the name for %s? ", symbol);

                    /* Check the User's Answer */
                    answered_correctly += check_answer(atomic_number, symbol, name);
                }

                /* Print the User's Score */
                printf("You answered %d out of 50 questions correctly.\n", answered_correctly);

                /* Reset the Number of Correct Answers */
                answered_correctly = 0;

                /* Wait for the User to Press Enter */
                printf("Press Enter to Continue... ");
                while (getchar() != '\n');

                /* Clear the Screen */
                system("cls");

                break;
            case 3:
                /* Quit the Program */
                printf("Goodbye!\n");

                break;
            default:
                /* Invalid Menu Choice */
                printf("Invalid Choice! Please Try Again.\n");

                break;
        }
    } while (choice != 3);

    /* Exit the Program */
    return 0;
}

/* Function to Get the User's Menu Choice */
int get_choice(void)
{
    /* Variable Declaration */
    int choice = 0; /* User's Menu Choice */

    /* Loop Until a Valid Choice is Made */
    do {
        /* Read the User's Choice */
        scanf("%d", &choice);

        /* Clear the Input Stream */
        while (getchar() != '\n');

        /* Check the Validity of the User's Choice */
        if (choice < 1 || choice > 3) {
            printf("Invalid Choice! Please Try Again.\n");
            printf("Enter Choice (1 - 3): ");
        }
    } while (choice < 1 || choice > 3);

    /* Return the User's Valid Menu Choice */
    return choice;
}

/* Function to Check the User's Answer */
int check_answer(int atomic_number, char symbol[], char name[])
{
    /* Variable Declaration */
    int correct = 0; /* User's Correct Answer Flag */
    char answer[20]; /* User's Answer */

    /* Read the User's Answer */
    scanf("%s", answer);

    /* Clear the Input Stream */
    while (getchar() != '\n');

    /* Check the Validity of the User's Answer */
    if (strcmp(answer, symbol) == 0) {
        /* User Entered Correct Symbol */
        printf("Correct!\n");
        correct = 1;
    } else if (strcmp(answer, name) == 0) {
        /* User Entered Correct Name */
        printf("Correct!\n");
        correct = 1;
    } else {
        /* User Entered Incorrect Answer */
        printf("Incorrect. The Correct Answer is %s\n", symbol);
    }

    /* Return the User's Correct Answer Flag */
    return correct;
}