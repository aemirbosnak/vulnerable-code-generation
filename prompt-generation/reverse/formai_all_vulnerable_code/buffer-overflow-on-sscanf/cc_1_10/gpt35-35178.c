//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for element
typedef struct element {
    int atomic_number;
    char symbol[3];
    char name[20];
    float atomic_weight;
} Element;

// Define constants
#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10
#define MAX_SELECTIONS 4

// Declare global variables
Element elements[NUM_ELEMENTS];
int num_correct = 0;
int num_incorrect = 0;

// Define function prototypes
void load_elements();
void shuffle_elements();
void generate_question(int question_number);
void print_selections(Element correct_element, Element selections[MAX_SELECTIONS]);
void print_results(float time_taken);

int main() {
    // Load elements and shuffle them
    load_elements();
    shuffle_elements();
    
    // Generate and ask questions
    printf("\n--- Welcome to the Periodic Table Quiz! ---\n");
    printf("\nYou will be asked %d multiple-choice questions about the periodic table.\n", NUM_QUESTIONS);
    printf("You will have 10 seconds to answer each question.\n\n");
    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        generate_question(i);
    }
    
    // Print results
    float time_taken = (float)(clock()) / CLOCKS_PER_SEC;
    printf("\n--- RESULTS ---\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, NUM_QUESTIONS);
    printf("You answered %d out of %d questions incorrectly.\n", num_incorrect, NUM_QUESTIONS);
    printf("You took %.2f seconds to complete the quiz.\n", time_taken);
    
    return 0;
}

// Load elements from file into elements array
void load_elements() {
    FILE *file;
    file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    
    char line[50];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // Read data into temporary variable
        int atomic_number_temp;
        char symbol_temp[3];
        char name_temp[20];
        float atomic_weight_temp;
        fgets(line, sizeof(line), file);
        sscanf(line, "%d %s %s %f", &atomic_number_temp, symbol_temp, name_temp, &atomic_weight_temp);
        
        // Copy data into Element struct
        Element element_temp;
        element_temp.atomic_number = atomic_number_temp;
        strcpy(element_temp.symbol, symbol_temp);
        strcpy(element_temp.name, name_temp);
        element_temp.atomic_weight = atomic_weight_temp;
        
        // Add Element struct to elements array
        elements[i] = element_temp;
    }
    
    fclose(file);
}

// Shuffle elements array
void shuffle_elements() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int random_index = rand() % NUM_ELEMENTS;
        Element temp = elements[i];
        elements[i] = elements[random_index];
        elements[random_index] = temp;
    }
}

// Generate one multiple-choice question
void generate_question(int question_number) {
    // Choose the correct answer
    Element correct_element = elements[question_number - 1];
    
    // Generate three incorrect answers
    Element selections[MAX_SELECTIONS];
    for (int i = 0; i < MAX_SELECTIONS; i++) {
        int random_index = rand() % NUM_ELEMENTS;
        Element selection_temp = elements[random_index];
        while (strcmp(selection_temp.symbol, correct_element.symbol) == 0) {
            random_index = rand() % NUM_ELEMENTS;
            selection_temp = elements[random_index];
        }
        selections[i] = selection_temp;
    }
    
    // Add correct answer to selections array and shuffle
    selections[MAX_SELECTIONS - 1] = correct_element;
    srand(time(NULL));
    for (int i = 0; i < MAX_SELECTIONS; i++) {
        int random_index = rand() % MAX_SELECTIONS;
        Element temp = selections[i];
        selections[i] = selections[random_index];
        selections[random_index] = temp;
    }
    
    // Print question and selections
    printf("Question %d: What is the atomic symbol for %s?\n", question_number, correct_element.name);
    print_selections(correct_element, selections);
    
    // Get answer from user
    char answer[3];
    clock_t start_time = clock();
    scanf("%2s", answer);
    
    // Check answer and update scores
    if (strcmp(answer, correct_element.symbol) == 0) {
        printf("Correct!\n");
        num_correct++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_element.symbol);
        num_incorrect++;
    }
    
    // Print elapsed time and sleep for 2 seconds
    float time_taken = (float)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Press Enter to continue...");
    fflush(stdout);
    getchar();
    sleep(2);
}

// Print selections with correct answer at the end
void print_selections(Element correct_element, Element selections[MAX_SELECTIONS]) {
    for (int i = 0; i < MAX_SELECTIONS; i++) {
        printf("%d) %s", i + 1, selections[i].symbol);
        if (strcmp(selections[i].symbol, correct_element.symbol) == 0) {
            printf(" (correct)");
        }
        printf("\n");
    }
}

// Print final results after completing all questions
void print_results(float time_taken) {
    printf("\n--- RESULTS ---\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, NUM_QUESTIONS);
    printf("You answered %d out of %d questions incorrectly.\n", num_incorrect, NUM_QUESTIONS);
    printf("You took %.2f seconds to complete the quiz.\n", time_taken);
}