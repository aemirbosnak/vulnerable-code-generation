//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3
#define NUM_QUESTIONS 10
 
struct Element {
    char name[20];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
};
 
typedef struct Element Element;
 
Element* loadElements();
char* generate_question(Element*);
void run_quiz(Element*, int);
 
int main(int argc, char** argv) {
    srand(time(NULL));
    Element* elements = loadElements();
    run_quiz(elements, NUM_QUESTIONS);
    free(elements);
    return 0;
}
 
Element* loadElements() {
    Element* elements = (Element*) malloc(MAX_ELEMENTS * sizeof(Element));
    if (elements == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
 
    FILE* inputFile = fopen("periodic_table.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
 
    int i = 0;
    char name[20];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
    while (!feof(inputFile)) {
        fscanf(inputFile, "%s %s %d", name, symbol, &atomicNumber);
        strcpy(elements[i].name, name);
        strcpy(elements[i].symbol, symbol);
        elements[i].atomicNumber = atomicNumber;
        i++;
    }
 
    fclose(inputFile);
    return elements;
}
 
char* generate_question(Element* elements) {
    char* question = (char*) malloc(50 * sizeof(char));
    if (question == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
 
    int symbolOrName = rand() % 2;
    int elementIndex = rand() % MAX_ELEMENTS;
    Element element = elements[elementIndex];
 
    if (symbolOrName) {
        sprintf(question, "What is the symbol for element %s?", element.name);
    } else {
        sprintf(question, "What is the name for the element with symbol %s?", element.symbol);
    }
 
    return question;
}
 
void run_quiz(Element* elements, int numQuestions) {
    int score = 0;
 
    for (int i = 0; i < numQuestions; i++) {
        char* question = generate_question(elements);
        printf("Question %d: %s\n", i+1, question);
        free(question);
 
        char answer[20];
        fgets(answer, 20, stdin);
        answer[strcspn(answer, "\r\n")] = 0; // remove newline
 
        Element element = elements[rand() % MAX_ELEMENTS];
        if ((strlen(answer) == MAX_SYMBOL_LENGTH && !strcmp(answer, element.symbol))
                || (!strcmp(answer, element.name))) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was %s.\n", element.name);
        }
    }
 
    printf("Quiz complete! You got %d/%d questions correct.\n", score, numQuestions);
}