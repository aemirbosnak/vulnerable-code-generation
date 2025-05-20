//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    char symbol[118] = {'H', 'He', 'Li', 'Be', 'B', 'C', 'N', 'O', 'F', 'Ne', 'Na', 'Mg', 'Al', 'Si', 'P', 'S', 'Cl', 'Ar', 'K', 'Ca', 'Sc', 'Ti', 'V', 'Cr', 'Mn', 'Fe', 'Co', 'Ni', 'Cu', 'Zn', 'Ga', 'Ge', 'As', 'Se', 'Br', 'Kr', 'Rb', 'Sr', 'Y', 'Zr', 'Nb', 'Mo', 'Tc', 'Ru', 'Rh', 'Pd', 'Ag', 'Cd', 'In', 'Sn', 'Sb', 'Te', 'I', 'Xe', 'Cs', 'Ba', 'La', 'Ce', 'Pr', 'Nd', 'Pm', 'Sm', 'Eu', 'Gd', 'Tb', 'Dy', 'Ho', 'Er', 'Tm', 'Yb', 'Lu', 'Hf', 'Ta', 'W', 'Re', 'Os', 'Ir', 'Pt', 'Au', 'Hg', 'Tl', 'Pb', 'Bi', 'Po', 'At', 'Rn', 'Fr', 'Ra', 'Ac', 'Th', 'Pa', 'U', 'Np', 'Pu', 'Am', 'Cm', 'Bk', 'Cf', 'Es', 'Fm', 'Md', 'No', 'Lr', 'Rf', 'Db', 'Sg', 'Bh', 'Hs', 'Mt', 'Ds', 'Rg', 'Cn', 'Nh', 'Fl', 'Mc', 'Lv', 'Ts', 'Og'};
    int atomic_num[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 118};
    int answer = 0, guess;
    char choice;
  
    // Setting the seed for random number generator
    srand(time(NULL));
  
    // Welcome Message
    printf("***Welcome to the Periodic Table Quiz Game!***\n\n");
  
    // Loop for playing the game multiple times
    while(1) {
        printf("Do you want to play the quiz? (Y/N): ");
        scanf(" %c", &choice);
      
        // If user doesn't want to play, exit the game
        if(choice == 'N' || choice == 'n') {
            printf("Thank you for playing the quiz! Goodbye!\n");
            exit(0);
        }
      
        // Randomly selecting an element from the periodic table
        int index = rand() % 118;
        printf("\nElement %d: \n", index+1);
        printf("What is the symbol of this element? ");
      
        // Taking input from the user
        scanf("%s", &guess);
        printf("\n");
      
        // Checking the answer
        if(guess == symbol[index]) {
            printf("Congratulations! Your answer is correct!\n");
            answer++;
        } else {
            printf("Sorry, your answer is incorrect.\n");
            printf("Correct answer is %c.\n", symbol[index]);
        }
      
        // Asking the user if they want to continue playing the game
        printf("Do you want to continue playing the game? (Y/N): ");
        scanf(" %c", &choice);
      
        // Exiting the game if user doesn't want to play
        if(choice == 'N' || choice == 'n') {
            printf("Thank you for playing the quiz! Goodbye!\n");
            exit(0);
        }
    }
    return 0;
}