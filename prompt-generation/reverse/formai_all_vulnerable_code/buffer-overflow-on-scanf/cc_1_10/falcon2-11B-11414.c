//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main() {
    // Create an array of elements from the periodic table
    char* elements[] = {
        "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron",
        "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
        "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus",
        "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
        "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese",
        "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium",
        "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton",
        "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
        "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium",
        "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium",
        "Iodine", "Xenon", "Caesium", "Barium", "Lanthanum", "Cerium",
        "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium",
        "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium",
        "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
        "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
        "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium",
        "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
        "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium",
        "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
        "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
        "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
        "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium",
        "Livermorium", "Tennessine", "Oganesson"
    };
    int num_elements = sizeof(elements) / sizeof(char*);
    srand(time(NULL));

    // Ask the user for their name
    printf("What is your name?\n");
    char name[100];
    scanf("%s", name);
    printf("Hi %s, welcome to the periodic table quiz!\n", name);
    printf("I'll ask you a question about the periodic table and you can answer 'yes' or 'no'. Good luck!\n\n");

    // Loop through all the elements in the periodic table
    for (int i = 0; i < num_elements; i++) {
        // Pick a random element from the periodic table
        int random_index = rand() % num_elements;
        char* element = elements[random_index];

        // Ask the user a question about the element
        printf("%s %s\n", "Is", element);
        char answer[100];
        scanf("%s", answer);

        // Check if the user's answer is correct
        if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0) {
            printf("%s is correct!\n", element);
        } else {
            printf("%s is incorrect.\n", element);
        }

        // Wait for the user to press a key before moving on to the next element
        printf("Press any key to continue...\n");
        getchar();
    }

    // Thank the user for taking the quiz
    printf("Thanks for taking the periodic table quiz %s!\n", name);

    return 0;
}