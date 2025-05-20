//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char answers[10][50] = {
        "The future looks bright for you!",
        "You will have a great day today!",
        "Better days are ahead of you.",
        "You're going to meet someone special soon.",
        "Your hard work will pay off soon.",
        "A surprise is coming your way.",
        "Take a risk and see what happens.",
        "Be patient, good things take time!",
        "Listen to your intuition, it will guide you.",
        "Your creativity will be at an all-time high soon!"
    };
    
    printf("Welcome to the Automated Fortune Teller! What is your name?\n");
    char name[20];
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    
    printf("Please enter your birth year: ");
    int birth_year;
    scanf("%d", &birth_year);
    
    int current_year = 2021;
    int age = current_year - birth_year;
    
    printf("You are %d years old!\n", age);
    printf("Now, ask me any question and I'll give you a fortune! Or type 'quit' to exit.\n");
    
    char question[100];
    while (1) {
        printf("\n> ");
        scanf("%s", question);
        
        if (strcmp(question, "quit") == 0) {
            printf("Goodbye, %s!\n", name);
            break;
        }
        
        srand(time(0));
        int random_index = rand() % 10;
        printf("%s\n", answers[random_index]);
    }
    
    return 0;
}