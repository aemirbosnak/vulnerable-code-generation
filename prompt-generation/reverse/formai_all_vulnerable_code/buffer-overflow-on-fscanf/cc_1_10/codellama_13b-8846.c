//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

// Structure to store information about each element
typedef struct {
    char name[20];
    char symbol[10];
    int number;
    char group[10];
    char period[10];
    char block[10];
} Element;

// Function to generate a random number between min and max
int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle an array of elements
void shuffle(Element* elements, int num_elements) {
    for (int i = 0; i < num_elements - 1; i++) {
        int j = i + randint(0, num_elements - i - 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Function to generate a question and its answers
void generate_question(Element* elements, int num_elements, int* question_index, char* question, char* answers) {
    // Generate a random element index
    int element_index = randint(0, num_elements - 1);

    // Set the question and the correct answer
    strcpy(question, elements[element_index].name);
    strcpy(answers, elements[element_index].symbol);

    // Shuffle the answers
    shuffle(answers, MAX_ANSWERS);

    // Set the other three answers
    for (int i = 0; i < MAX_ANSWERS; i++) {
        if (i == 0) {
            strcpy(answers + i * 10, elements[element_index].symbol);
        } else {
            int j = randint(0, num_elements - 1);
            while (j == element_index) {
                j = randint(0, num_elements - 1);
            }
            strcpy(answers + i * 10, elements[j].symbol);
        }
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Declare and initialize the elements array
    Element elements[MAX_ELEMENTS];
    int num_elements = 0;

    // Load the elements from a file
    FILE* fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fscanf(fp, "%s %s %d %s %s %s\n", elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].number, elements[num_elements].group, elements[num_elements].period, elements[num_elements].block) == 6) {
        num_elements++;
    }
    fclose(fp);

    // Shuffle the elements
    shuffle(elements, num_elements);

    // Initialize the question index
    int question_index = 0;

    // Generate the questions and answers
    char question[20];
    char answers[40];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(elements, num_elements, &question_index, question, answers);
        printf("%d. %s\n", i + 1, question);
        printf("A) %s\n", answers);
        printf("B) %s\n", answers + 10);
        printf("C) %s\n", answers + 20);
        printf("D) %s\n", answers + 30);
    }

    return 0;
}