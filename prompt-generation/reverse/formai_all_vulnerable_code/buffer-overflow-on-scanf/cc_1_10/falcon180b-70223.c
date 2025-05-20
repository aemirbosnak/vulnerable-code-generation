//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of fortunes
#define NUM_FORTUNES 50

// Struct to hold a fortune
typedef struct {
    char text[100];
    int length;
} Fortune;

// Function to generate a random fortune
Fortune generate_fortune() {
    Fortune fortune;
    char *words[] = {"wealth", "love", "success", "happiness", "health", "wisdom", "peace", "friendship", "creativity", "adventure", "spirituality", "freedom", "harmony", "confidence", "courage", "compassion", "patience", "gratitude", "forgiveness", "humility", "kindness", "generosity", "honesty", "integrity", "optimism", "perseverance", "self-discipline", "self-awareness", "self-improvement", "self-confidence", "self-esteem", "self-respect", "self-love", "self-care", "self-compassion", "self-acceptance", "self-expression", "self-discovery", "self-fulfillment", "self-realization", "self-actualization"};
    int num_words = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    int random_index = rand() % num_words;
    strcpy(fortune.text, words[random_index]);
    fortune.length = strlen(fortune.text);
    return fortune;
}

// Function to print a fortune
void print_fortune(Fortune fortune) {
    printf("Your fortune: %s\n", fortune.text);
}

// Main function
int main() {
    int choice;
    Fortune fortune;

    do {
        printf("Welcome to the automated fortune teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fortune = generate_fortune();
                print_fortune(fortune);
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}