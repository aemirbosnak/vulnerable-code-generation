//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int score;
};

struct Question {
    char text[256];
    char options[4][64];
    int correct;
};

int main() {
    // Welcome message
    printf("Welcome to the Cyberpunk Examination System 2042.\n");

    // Initialize the student
    struct Student student;
    printf("Enter your name:\n");
    scanf("%s", student.name);

    // Initialize the questions
    struct Question questions[] = {
        {
            "What is the first rule of cyberpunk?",
            {"Don't trust the corps", "Don't get caught", "Don't sell out", "Don't be a sheep"},
            0
        },
        {
            "What is the name of the main character in the cyberpunk classic 'Neuromancer'?",
            {"Case", "Molly", "Armitage", "Wintermute"},
            0
        },
        {
            "What is the name of the hacker group in the movie 'Hackers'?",
            {"The Elite", "The Legion", "The Crackerz", "The NeoNET"},
            0
        },
        {
            "What is the name of the virtual reality city in the manga 'Ghost in the Shell'?",
            {"The Matrix", "The Grid", "The Cyberspace", "The Web"},
            0
        },
        {
            "What is the name of the artificial intelligence in the TV series 'Westworld'?",
            {"Ford", "Arnold", "Theresa", "Bernard"},
            0
        }
    };

    // Take the test
    int score = 0;
    for (int i = 0; i < 5; i++) {
        printf("\n%d. %s\n", i+1, questions[i].text);
        for (int j = 0; j < 4; j++) {
            printf("    %d. %s\n", j+1, questions[i].options[j]);
        }
        printf("Your answer:\n");
        int answer;
        scanf("%d", &answer);
        if (answer == questions[i].correct) {
            score++;
        }
    }

    // Calculate the grade
    char grade;
    if (score >= 4) {
        grade = 'A';
    } else if (score >= 3) {
        grade = 'B';
    } else if (score >= 2) {
        grade = 'C';
    } else if (score >= 1) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    // Display the results
    printf("\nYour score is %d out of 5.\n", score);
    printf("Your grade is %c.\n", grade);

    // Exit the program
    return 0;
}