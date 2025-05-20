//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_mass;
    char block;
} Element;

int main() {
    Element table[] = {
        {"H", "Hydrogen", 1, 1.008, 's'},
        {"He", "Helium", 2, 4.003, 'p'},
        {"Li", "Lithium", 3, 6.941, 's'},
        {"Be", "Beryllium", 4, 9.012, 's'},
        {"B", "Boron", 5, 10.81, 'p'},
        {"C", "Carbon", 6, 12.01, 'p'},
        {"N", "Nitrogen", 7, 14.01, 'p'},
        {"O", "Oxygen", 8, 16.00, 'p'},
        {"F", "Fluorine", 9, 19.00, 'p'},
        {"Ne", "Neon", 10, 20.18, 'p'},
        {"Na", "Sodium", 11, 22.99, 's'},
        {"Mg", "Magnesium", 12, 24.31, 's'},
        {"Al", "Aluminum", 13, 26.98, 'p'},
        {"Si", "Silicon", 14, 28.09, 'p'},
        {"P", "Phosphorus", 15, 30.97, 'p'},
        {"S", "Sulfur", 16, 32.07, 'p'},
        {"Cl", "Chlorine", 17, 35.45, 'p'},
        {"Ar", "Argon", 18, 39.95, 'p'},
        {"K", "Potassium", 19, 39.10, 's'},
        {"Ca", "Calcium", 20, 40.08, 's'},
        {"Sc", "Scandium", 21, 44.96, 'd'},
        {"Ti", "Titanium", 22, 47.87, 'd'},
        {"V", "Vanadium", 23, 50.94, 'd'},
        {"Cr", "Chromium", 24, 52.00, 'd'},
        {"Mn", "Manganese", 25, 54.94, 'd'},
        {"Fe", "Iron", 26, 55.85, 'd'},
        {"Co", "Cobalt", 27, 58.93, 'd'},
        {"Ni", "Nickel", 28, 58.69, 'd'},
        {"Cu", "Copper", 29, 63.55, 'd'},
        {"Zn", "Zinc", 30, 65.38, 'd'},
        {"Ga", "Gallium", 31, 69.72, 'p'},
        {"Ge", "Germanium", 32, 72.63, 'p'},
        {"As", "Arsenic", 33, 74.92, 'p'},
        {"Se", "Selenium", 34, 78.96, 'p'},
        {"Br", "Bromine", 35, 79.90, 'p'},
        {"Kr", "Krypton", 36, 83.80, 'p'},
        {"Rb", "Rubidium", 37, 85.47, 's'},
        {"Sr", "Strontium", 38, 87.62, 's'},
        {"Y", "Yttrium", 39, 88.91, 'd'},
        {"Zr", "Zirconium", 40, 91.22, 'd'},
        {"Nb", "Niobium", 41, 92.91, 'd'},
        {"Mo", "Molybdenum", 42, 95.94, 'd'},
        {"Tc", "Technetium", 43, 98.00, 'd'},
        {"Ru", "Ruthenium", 44, 101.07, 'd'},
        {"Rh", "Rhodium", 45, 102.91, 'd'},
        {"Pd", "Palladium", 46, 106.42, 'd'},
        {"Ag", "Silver", 47, 107.87, 'd'},
        {"Cd", "Cadmium", 48, 112.41, 'd'},
        {"In", "Indium", 49, 114.82, 'p'},
        {"Sn", "Tin", 50, 118.71, 'p'},
        {"Sb", "Antimony", 51, 121.76, 'p'},
        {"Te", "Tellurium", 52, 127.60, 'p'},
        {"I", "Iodine", 53, 126.90, 'p'},
        {"Xe", "Xenon", 54, 131.29, 'p'},
    };
    int num_elements = sizeof(table) / sizeof(Element);
    int score = 0;
    int n;
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    do {
        printf("Choose a difficulty level:\n");
        printf("1 - Easy (atomic number)\n");
        printf("2 - Medium (symbol)\n");
        printf("3 - Hard (name)\n");
        printf("0 - Quit\n");
        printf("Your choice: ");
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else if (n < 1 || n > 3) {
            printf("Invalid choice. Please try again.\n\n");
            continue;
        }
        int num_questions;
        if (n == 1) {
            num_questions = 5;
        } else if (n == 2) {
            num_questions = 10;
        } else {
            num_questions = 20;
        }
        int asked[num_questions];
        for (int i = 0; i < num_questions; i++) {
            int rand_num;
            do {
                rand_num = rand() % num_elements;
            } while (contains(asked, rand_num, i));
            asked[i] = rand_num;
            if (n == 1) {
                printf("Question %d: What is the atomic number of %s?\n", i + 1, table[rand_num].name);
                int answer;
                scanf("%d", &answer);
                if (answer == table[rand_num].atomic_number) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", table[rand_num].atomic_number);
                }
            } else if (n == 2) {
                printf("Question %d: What is the symbol for %s?\n", i + 1, table[rand_num].name);
                char answer[3];
                scanf("%s", answer);
                if (strcmp(answer, table[rand_num].symbol) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", table[rand_num].symbol);
                }
            } else {
                printf("Question %d: What is the name of %s?\n", i + 1, table[rand_num].symbol);
                char answer[20];
                scanf("%s", answer);
                if (strcmp(answer, table[rand_num].name) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", table[rand_num].name);
                }
            }
        }
        printf("Quiz complete! You got %d out of %d questions correct.\n\n", score, num_questions);
    } while (n != 0);
    printf("Thanks for playing the C Periodic Table Quiz!\n");
    return 0;
}

int contains(int arr[], int num, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}