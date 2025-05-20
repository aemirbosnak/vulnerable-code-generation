//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 118      // Number of elements in the Periodic Table

// Structure for holding element details
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float weight;
} element;


// Function to read the Periodic Table data from a file and store it in an array of structs
void read_data(element* e) {
    char filename[] = "periodic_table.txt";
    FILE *file = fopen(filename, "r");
    char line[50];
    int i = 0;

    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %d %f", e[i].symbol, e[i].name, &e[i].atomic_number, &e[i].weight);
        i++;
    }
    fclose(file);
    printf("Periodic Table data has been read successfully.\n");
}

// Function to display the Periodic Table data
void display_data(element* e) {
    printf("Symbol\tName\t\t\t\tAtomic Number\tWeight\n");
    printf("-------------------------------------------------------------\n");
    for(int i=0; i<SIZE; i++) {
        printf("%-3s\t%-20s\t%d\t\t%.2f\n", e[i].symbol, e[i].name, e[i].atomic_number, e[i].weight);
    }
}

// Function to quiz the user on the Periodic Table
void quiz(element* e) {
    int score = 0;
    int random_index;
    char guess[20];
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown a symbol or name of an element and you have to guess its name or symbol.\n");
    printf("You will be given 10 questions and your score will be displayed at the end.\n");
    printf("Are you ready? Let's get started!\n");
    for(int i=0; i<10; i++) {
        // Generate a random index
        random_index = rand() % SIZE;
        // Prompt user with either symbol or name of an element
        printf("Question %d: What is the %s of element %s?\n", i+1, (rand() % 2 == 0) ? "name" : "symbol", e[random_index].name);
        scanf("%s", guess);
        // Check if the guess is correct
        if(strcmp(guess, e[random_index].symbol) == 0 || strcmp(guess, e[random_index].name) == 0) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect! The correct answer was %s (%s).\n", e[random_index].name, e[random_index].symbol);
        }
    }
    printf("Quiz complete! Your score is %d/10.\n", score);
} 

int main() {
    // Allocate memory for the array of structs
    element *table = (element*) malloc(SIZE * sizeof(element));
    // Read the Periodic Table data from the file
    read_data(table);
    // Display the Periodic Table data
    display_data(table);
    // Start the quiz
    quiz(table);
    // Free the allocated memory
    free(table);
    return 0;
}