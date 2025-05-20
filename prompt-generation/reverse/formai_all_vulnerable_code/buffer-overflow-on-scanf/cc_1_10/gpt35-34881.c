//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element{
    char name[20];
    char symbol[3];
    int atomicNumber;
};

void printElement(struct Element element){
    printf("Element:\nName: %s\nSymbol: %s\nAtomic Number: %d\n", 
    element.name, element.symbol, element.atomicNumber);
}

void printPeriodicTable(struct Element periodicTable[], int size){
    for(int i=0; i<size; i++){
        printf("\n\n=== Element %d ===\n", i+1);
        printElement(periodicTable[i]);
    }
}

int main(){
    int size = 3;
    struct Element periodicTable[size];

    // Adding elements to periodic table
    strcpy(periodicTable[0].name, "Hydrogen");
    strcpy(periodicTable[0].symbol, "H");
    periodicTable[0].atomicNumber = 1;

    strcpy(periodicTable[1].name, "Helium");
    strcpy(periodicTable[1].symbol, "He");
    periodicTable[1].atomicNumber = 2;

    strcpy(periodicTable[2].name, "Lithium");
    strcpy(periodicTable[2].symbol, "Li");
    periodicTable[2].atomicNumber = 3;

    printf("\n\n========================= WELCOME TO THE PERIODIC TABLE QUIZ =========================\n\n");

    printf("Instructions:\n1. The quiz consists of %d elements\n2. Type the name of the element to answer\n3. Type 'exit' to end the quiz\n\n", size);

    printPeriodicTable(periodicTable, size);

    char answer[20];
    int score = 0;
    int totalQuestions = 0;
    int maxQuestions = size;

    while(totalQuestions < maxQuestions){
        printf("\n\nQuestion %d:\nWhat is the symbol for ", totalQuestions+1);
        int questionIndex = rand()%size;
        printf("%s?\n", periodicTable[questionIndex].name);

        printf("Answer: ");
        scanf("%s", answer);

        // Convert answer to lowercase
        for(int i=0; answer[i]; i++){
            answer[i] = tolower(answer[i]);
        }

        // Check if answer is correct
        if(strcmp(answer, periodicTable[questionIndex].symbol) == 0){
            printf("Correct!\n");
            score++;
        }else if(strcmp(answer, "exit") == 0){
            break;
        }else{
            printf("Incorrect. The correct symbol for %s is %s.\n", periodicTable[questionIndex].name, periodicTable[questionIndex].symbol);
        }

        totalQuestions++;
    }

    printf("\n\nThanks for playing! You got %d out of %d questions correct.\n", score, maxQuestions);

    return 0;
}