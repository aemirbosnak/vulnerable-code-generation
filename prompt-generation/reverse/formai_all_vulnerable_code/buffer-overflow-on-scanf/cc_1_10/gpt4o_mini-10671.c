//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function to display a welcome message
void displayWelcomeMessage() {
    printf("**********************************\n");
    printf("*        Welcome to the          *\n");
    printf("*      Automated Fortune Teller   *\n");
    printf("**********************************\n");
    printf("Ask a question and receive your fortune!\n");
}

// Function to get random fortune
const char* getFortune(int index) {
    const char* fortunes[MAX_FORTUNES] = {
        "You will have a great day today!",
        "Something wonderful is about to happen.",
        "Be careful of new acquaintances.",
        "A positive change is coming your way.",
        "You will soon receive good news.",
        "Do not worry about the future.",
        "Expect a delay in your plans.",
        "Someone close to you is keeping a secret.",
        "Your talents will be recognized soon.",
        "Travel is in your future."
    };
    
    return fortunes[index];
}

// Function to get user's question
void getUserQuestion() {
    char question[256];
    printf("What is your question? ");
    fgets(question, sizeof(question), stdin);
    printf("\nYou asked: %s\n", question);
}

// Function to generate a random fortune
void tellFortune() {
    srand(time(NULL)); // Seed the random number generator
    int randomIndex = rand() % MAX_FORTUNES; // Get a random index
    const char* fortune = getFortune(randomIndex); // Get the fortune based on the random index
    printf("Your fortune: %s\n\n", fortune);
}

int main() {
    char continueFortuneTelling;

    displayWelcomeMessage();

    do {
        getUserQuestion(); // Handle user question input
        tellFortune(); // Display fortune
        printf("Do you want to ask another question? (y/n): ");
        scanf(" %c", &continueFortuneTelling);
        getchar(); // Consume leftover newline character from the buffer
    } while (continueFortuneTelling == 'y' || continueFortuneTelling == 'Y');

    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}