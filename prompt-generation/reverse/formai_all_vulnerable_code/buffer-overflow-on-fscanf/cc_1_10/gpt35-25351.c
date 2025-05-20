//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
    char electronConfig[30];
} Element;

// Function prototypes
void loadElements(Element[]);
void startQuiz(Element[]);
void displayMenu();
int getChoice();
void quiz(Element[]);

int main(){
    // Declare an array of 118 elements
    Element elements[118];

    // Load elements from file
    loadElements(elements);

    // Display menu and start quiz
    displayMenu();
    startQuiz(elements);

    return 0;
}

void loadElements(Element elements[]){
    // Open file for reading
    FILE *fp = fopen("elements.txt", "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    // Read elements from file and fill the array
    int i = 0;
    while(fscanf(fp, "%d,%f,%[^,],%[^,],%[^\n]", &elements[i].atomicNumber, &elements[i].atomicMass, elements[i].symbol, elements[i].name, elements[i].electronConfig) != EOF){
        i++;
    }

    // Close file
    fclose(fp);
}

void startQuiz(Element elements[]){
    int choice = getChoice();

    while(choice != 3){
        if(choice == 1){
            quiz(elements);
        }
        else if(choice == 2){
            printf("Sorry, this feature is still under development.\n");
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }

        choice = getChoice();
    }
}

void displayMenu(){
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("-----------------------------------\n");
    printf("1. Start Quiz\n");
    printf("2. View Scores\n");
    printf("3. Quit\n");
}

int getChoice(){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void quiz(Element elements[]){
    int numQuestions, score = 0;

    printf("\nHow many questions would you like to answer? ");
    scanf("%d", &numQuestions);

    // Generate random questions
    for(int i=0; i<numQuestions; i++){
        int index = rand() % 118;

        printf("\nQ%d. What is the symbol for %s?\n", i+1, elements[index].name);

        char answer[3];
        printf("Answer: ");
        scanf("%s", answer);

        // Check if answer is correct
        if(strcmp(answer, elements[index].symbol) == 0){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect! The correct answer is %s.\n", elements[index].symbol);
        }
    }

    // Display score
    printf("\nYour score is %d out of %d.\n", score, numQuestions);
}