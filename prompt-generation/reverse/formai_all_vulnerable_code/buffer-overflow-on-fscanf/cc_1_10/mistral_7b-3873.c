//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Struct for elements with their symbol, name, and atomic number
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// Function to generate random numbers between min and max (inclusive)
int rand_range(int min, int max) {
    int range = max - min + 1;
    int num = rand() % range;
    return num + min;
}

// Function to initialize the array of elements with dummy data
void init_elements(Element elements[], int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        strcpy(elements[i].symbol, "DUM");
        strcpy(elements[i].name, "Dummy Element");
        elements[i].atomic_number = i + 1;
    }
}

// Function to fill the array of elements with real data from a file
void load_elements_from_file(Element elements[], int num_elements, char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_elements; i++) {
        fscanf(file, "%s %s %d\n", elements[i].symbol, elements[i].name, &elements[i].atomic_number);
    }

    fclose(file);
}

// Function to print the periodic table with given elements
void print_periodic_table(Element elements[], int num_elements) {
    printf("+-----------------------------------------------------+\n");
    printf("| %-2s | %-18s | %-5s | %-5s |\n", "No.", "Symbol", "Name", "Atomic Number");
    printf("+-----------------------------------------------------+\n");

    for (int group = 1; group <= 18; group++) {
        printf("+-----------------------------------------------------+\n");
        printf("| Group %d                                           |\n", group);
        printf("+-----------------------------------------------------+\n");

        int start = (group - 1) * 18 + 1;
        int end = start + 17;

        for (int i = start; i <= end; i++) {
            printf("| %-2d | %-2s | %-18s | %-5d |\n", i, elements[i - 1].symbol, elements[i - 1].name, elements[i - 1].atomic_number);
        }
        printf("+-----------------------------------------------------+\n");
    }
}

// Function to generate a random quiz question about an element
void generate_quiz_question(Element elements[], int num_elements) {
    int random_element = rand_range(0, num_elements - 1);
    int random_number = rand() % 10 + 1;

    printf("Question %d:\n", random_number);
    printf("What is the atomic number of the element with the symbol '%s'?\n", elements[random_element].symbol);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    const int num_elements = 118;
    Element elements[num_elements];

    // Uncomment the following line to use dummy data instead of real data from a file
    // init_elements(elements, num_elements);

    char filename[] = "elements.txt";
    load_elements_from_file(elements, num_elements, filename);

    print_periodic_table(elements, num_elements);

    int num_questions = 5;
    for (int i = 0; i < num_questions; i++) {
        generate_quiz_question(elements, num_elements);
        int answer;
        scanf("%d", &answer);

        if (answer != elements[rand() % num_elements].atomic_number) {
            printf("Sorry, that's incorrect.\n");
        } else {
            printf("Great job! That's correct.\n");
        }
    }

    return 0;
}