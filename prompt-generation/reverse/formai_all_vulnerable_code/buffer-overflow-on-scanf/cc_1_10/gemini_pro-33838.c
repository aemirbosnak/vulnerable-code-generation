//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible fortunes
char *fortunes[] = {
    "You will find happiness in the simplest of things.",
    "Your future is bright, but there will be challenges along the way.",
    "You have a strong will and a determined spirit.",
    "You are surrounded by people who love and support you.",
    "You have the power to make your dreams come true.",
    "You are a kind and compassionate person.",
    "You are always looking for the best in others.",
    "You are a true friend.",
    "You are a hard worker.",
    "You are a creative and talented person."
};

// Get a random fortune
char *get_fortune() {
    srand(time(NULL));
    int index = rand() % 10;
    return fortunes[index];
}

// Get the user's input
void get_input(char *name, int *age, char *question) {
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", age);
    printf("What is your question? ");
    scanf(" %[^\n]%*c", question);
}

// Print the fortune
void print_fortune(char *name, int age, char *question, char *fortune) {
    printf("Hello, %s! You are %d years old and your question is: %s\n", name, age, question);
    printf("Your fortune is: %s\n", fortune);
}

// Main function
int main() {
    char name[256];
    int age;
    char question[256];
    char *fortune;

    get_input(name, &age, question);
    fortune = get_fortune();
    print_fortune(name, age, question, fortune);

    return 0;
}