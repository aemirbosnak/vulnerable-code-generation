//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <string.h>

struct Element {
    char symbol[3];
    int atomic_number;
    char name[20];
    float atomic_mass;
};

void print_menu();
int get_choice(int min, int max);
void run_quiz();

int main() {
    run_quiz();
    return 0;
}

void print_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("----------------------\n");
    printf("1. Guess the element's symbol\n");
    printf("2. Guess the element's name\n");
    printf("3. Guess the element's atomic number\n");
    printf("4. Guess the element's atomic mass\n");
    printf("5. Exit\n");
}

int get_choice(int min, int max) {
    int choice;
    do {
        printf("Enter your choice (%d-%d): ", min, max);
        scanf("%d", &choice);
    } while (choice < min || choice > max);
    return choice;
}

void run_quiz() {
    struct Element elements[] = {
        {"H", 1, "Hydrogen", 1.008},
        {"He", 2, "Helium", 4.003},
        {"Li", 3, "Lithium", 6.941},
        {"Be", 4, "Beryllium", 9.012},
        {"B", 5, "Boron", 10.81},
        {"C", 6, "Carbon", 12.01},
        {"N", 7, "Nitrogen", 14.01},
        {"O", 8, "Oxygen", 16.00},
        {"F", 9, "Fluorine", 19.00},
        {"Ne", 10, "Neon", 20.18},
    };
    int num_elements = sizeof(elements) / sizeof(elements[0]);
    int choice;
    int score = 0;
    int num_questions = 0;
    int i;
    char answer[20];
    
    do {
        print_menu();
        choice = get_choice(1, 5);
        if (choice == 5) {
            break;
        }
        i = rand() % num_elements;
        switch(choice) {
            case 1:
                printf("What element has the symbol %s?\n", elements[i].symbol);
                scanf("%s", answer);
                if (strcmp(answer, elements[i].symbol) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", elements[i].symbol);
                }
                break;
            case 2:
                printf("What is the name of element %d?\n", elements[i].atomic_number);
                scanf("%s", answer);
                if (strcmp(answer, elements[i].name) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", elements[i].name);
                }
                break;
            case 3:
                printf("What is the atomic number of element %s?\n", elements[i].name);
                scanf("%d", &num_questions);
                if (num_questions == elements[i].atomic_number) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", elements[i].atomic_number);
                }
                break;
            case 4:
                printf("What is the atomic mass of element %s?\n", elements[i].name);
                scanf("%f", &elements[i].atomic_mass);
                if (elements[i].atomic_mass == elements[i].atomic_mass) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %f.\n", elements[i].atomic_mass);
                }
                break;
        }
        num_questions++;
    } while (choice != 5);
    printf("Thank you for playing! You got %d out of %d questions correct.\n", score, num_questions);
}