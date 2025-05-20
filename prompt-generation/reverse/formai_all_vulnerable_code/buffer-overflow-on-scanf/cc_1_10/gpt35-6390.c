//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char PERIODIC_TABLE[7][18] = {
    {"H He Li Be B C N O F Ne"},
    {"Na Mg Al Si P S Cl Ar"},
    {"K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr"},
    {"Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe"},
    {"Cs Ba La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn"},
    {"Fr Ra Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og"},
    {" "},
};

const char ELEMENT_NAMES[118][20] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
    "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
    "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
    "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
    "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
    "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
    "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
    "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
    "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
    "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
    "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
};

const char ELEMENT_SYMBOLS[118][4] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

void shuffle(int arr[], int size) {
    // Shuffle an integer array using Fisher-Yates shuffle algorithm
    for (int i=size-1; i>0; --i) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_intro() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("This quiz will test your knowledge of the elements in the periodic table.\n");
}

void print_options() {
    printf("\nChoose an option:\n");
    printf("1. Easy (7 multiple choice questions)\n");
    printf("2. Medium (12 multiple choice questions)\n");
    printf("3. Hard (20 multiple choice questions)\n");
    printf("4. Expert (all 118 elements)\n");
    printf("5. Quit\n");
}

void print_question(int index, int num_options, int options[], bool is_expert) {
    printf("\nQuestion %d: ", index+1);
    int element_number = options[index];
    if (is_expert) printf("%s is represented by the symbol %s. ", ELEMENT_NAMES[element_number-1], ELEMENT_SYMBOLS[element_number-1]);
    printf("What is the atomic number of %s?\n", ELEMENT_NAMES[element_number-1]);

    // Print answer options
    bool is_answer_options[num_options];
    for (int i=0; i<num_options; ++i) is_answer_options[i] = false;
    int correct_option = rand() % num_options; // Randomly select the correct answer option

    // Mark the option containing the correct answer
    int option_count = 0;
    for (int i=0; i<num_options; ++i) {
        if (i == correct_option) {
            if (is_expert) printf("%d) %d\n", option_count+1, element_number);
            else printf("%d) %s\n", option_count+1, ELEMENT_SYMBOLS[element_number-1]);
            is_answer_options[i] = true;
        }
        else {
            int incorrect_element_number;
            do {
                incorrect_element_number = rand() % 118 + 1;
            } while (incorrect_element_number == element_number || is_answer_options[incorrect_element_number-1]);
            is_answer_options[incorrect_element_number-1] = true;
            if (is_expert) printf("%d) %d\n", option_count+1, incorrect_element_number);
            else printf("%d) %s\n", option_count+1, ELEMENT_SYMBOLS[incorrect_element_number-1]);
        }
        ++option_count;
    }
}

int main(void) {
    srand((unsigned int) time(NULL)); // Set the random seed based on current time

    // Print the intro and options
    print_intro();
    int option;
    do {
        print_options();
        printf("Enter your choice: ");
        scanf("%d", &option);
    } while (option < 1 || option > 5);

    if (option == 5) return 0;

    // Determine the number of elements and number of questions for the quiz
    int num_elements, num_questions;
    switch (option) {
        case 1:
            num_elements = 10;
            num_questions = 7;
            break;
        case 2:
            num_elements = 20;
            num_questions = 12;
            break;
        case 3:
            num_elements = 50;
            num_questions = 20;
            break;
        case 4:
            num_elements = 118;
            num_questions = 118;
            break;
        default:
            break;
    }

    // Shuffle the elements and select the required number of elements for the quiz
    int element_indices[118];
    for (int i=0; i<118; ++i) element_indices[i] = i+1;
    shuffle(element_indices, 118);
    int selected_elements[num_elements];
    for (int i=0; i<num_elements; ++i) selected_elements[i] = element_indices[i];

    // Shuffle the question order
    int question_order[num_questions];
    for (int i=0; i<num_questions; ++i) question_order[i] = i;
    shuffle(question_order, num_questions);

    // Ask the questions in the shuffled order
    bool is_expert = option == 4;
    int correct_answers = 0;
    for (int i=0; i<num_questions; ++i) {
        print_question(question_order[i], num_elements, selected_elements, is_expert);
        int choice;
        printf("Enter your answer (1-%d): ", num_elements);
        scanf("%d", &choice);
        if (choice == question_order[i]+1) {
            printf("Correct!\n");
            ++correct_answers;
        } else printf("Incorrect. The correct answer is %d.\n", question_order[i]+1);
    }

    // Print the results
    printf("\nYou got %d/%d questions correct. Thanks for playing!\n", correct_answers, num_questions);

    return 0;
}