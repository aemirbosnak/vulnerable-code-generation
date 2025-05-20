//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_ELEMENTS 110
#define MAX_NUM_QUESTIONS 50

char* element_name_list[MAX_NUM_ELEMENTS] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

int num_elements = 110;

int num_questions = 50;

char question_text[MAX_NUM_QUESTIONS][MAX_NUM_ELEMENTS + 1];

char answer_text[MAX_NUM_QUESTIONS][MAX_NUM_ELEMENTS + 1];

int answer_index[MAX_NUM_QUESTIONS];

int question_index = 0;

int main()
{
    printf("Welcome to the C Periodic Table Quiz!\n");

    printf("This quiz will test your knowledge of the elements in the periodic table.\n");

    printf("You will be given %d questions about the elements.\n", num_questions);

    printf("Each question will ask you to identify the element with a certain property.\n");

    printf("For example, \"What is the element with the symbol Na?\"\n");

    printf("You will have to choose the correct element from the list below.\n");

    printf("Enter your answer (in lowercase letters) or type \"quit\" to exit the quiz:\n");

    char input[MAX_NUM_ELEMENTS + 1];

    scanf("%s", input);

    while (input[0]!= 'q' && input[0]!= 'Q' && input[0]!= '\0')
    {
        int element_index;

        bool found_element = false;

        for (element_index = 0; element_index < num_elements; element_index++)
        {
            if (strcmp(input, element_name_list[element_index]) == 0)
            {
                found_element = true;
                break;
            }
        }

        if (found_element)
        {
            printf("Correct!\n");

            printf("Your score is now %d/%d.\n", question_index + 1, num_questions);
        }
        else
        {
            printf("Incorrect. The correct answer is \"%s\".\n", element_name_list[element_index]);

            printf("Your score is now %d/%d.\n", question_index + 1, num_questions);
        }

        printf("Question %d:\n", question_index + 1);

        printf("%s\n", question_text[question_index]);

        question_index++;

        printf("Enter your answer (in lowercase letters) or type \"quit\" to exit the quiz:\n");

        scanf("%s", input);
    }

    printf("Congratulations! You have completed the C Periodic Table Quiz!\n");

    printf("Your final score is %d/%d.\n", question_index, num_questions);

    return 0;
}