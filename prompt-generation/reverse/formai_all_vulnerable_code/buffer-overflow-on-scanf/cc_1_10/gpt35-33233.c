//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element { // declaring the struct element datatype
    char symbol[3]; // atomic symbol
    char name[20]; // element name
    int atomic_number; // atomic number
    float atomic_weight; // atomic weight
};

int main() {
    int option; // variable to store user option
    struct element period[] = { // declaring and initializing array of element structs
        {"H" , "Hydrogen" , 1 , 1.008},
        {"He", "Helium"   , 2 , 4.003},
        {"Li", "Lithium"  , 3 , 6.941},
        {"Be", "Beryllium", 4 , 9.012},
        {"B" , "Boron"    , 5 , 10.81},
        {"C" , "Carbon"   , 6 , 12.01},
        {"N" , "Nitrogen", 7 , 14.01},
        {"O" , "Oxygen"    , 8 , 16.00},
        {"F" , "Fluorine" , 9 , 19.00},
        {"Ne", "Neon"     , 10, 20.18}
    };
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose an option from the menu:\n\n");
    printf("1. Display all elements in Period 1\n");
    printf("2. Enter an atomic number to find the corresponding element\n");
    printf("3. Exit\n");
    
    do {
        printf("\nEnter option (1-3): ");
        scanf("%d", &option);

        switch (option) { // switch case to handle user input options
            case 1: // Display all elements in Period 1
                printf("\n--- Period 1 Elements ---\n");
                for (int i = 0; i < 10; i++) {
                    printf("%-3s %-10s %d %.3f\n", period[i].symbol, period[i].name, period[i].atomic_number, period[i].atomic_weight);
                }
                break;

            case 2: // Enter an atomic number to find the corresponding element
                printf("\nEnter atomic number: ");
                int num;
                scanf("%d", &num);

                if (num >= 1 && num <= 10) { // check if atomic number is within Period 1
                    int index = num - 1; // index in array
                    printf("\n--- Element %d ---\n", num);
                    printf("Name: %s\n", period[index].name);
                    printf("Symbol: %s\n", period[index].symbol);
                    printf("Atomic weight: %.3f\n", period[index].atomic_weight);
                }
                else {
                    printf("\nInvalid atomic number!\n");
                }
                break;

            case 3: // Exit program
                printf("\nThank you for playing!\n");
                exit(0);

            default: // Handle invalid input
                printf("\nInvalid option, try again.\n");
        }

    } while (option != 3); // Keep running program until user chooses to exit

    return 0;
}