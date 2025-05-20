//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: genius
// Ingenious Online Examination System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Question Database
typedef struct Question {
    char question[256];
    char options[4][128];
    int correctOption;
} Question;

Question questions[] = {
    {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 0},
    {"Who wrote the novel 'To Kill a Mockingbird'?", {"J.K. Rowling", "Harper Lee", "Jane Austen", "Ernest Hemingway"}, 1},
    {"Which planet is known as the 'Red Planet'?", {"Mars", "Jupiter", "Saturn", "Mercury"}, 0},
    {"What is the largest ocean in the world?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 1},
    {"Who invented the light bulb?", {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Albert Einstein"}, 1},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"Which country is known for its kangaroos?", {"Australia", "China", "India", "Brazil"}, 0},
    {"What is the national anthem of the United States?", {"The Star-Spangled Banner", "God Save the Queen", "La Marseillaise", "Das Lied der Deutschen"}, 0},
    {"Who was the first president of the United States?", {"George Washington", "Abraham Lincoln", "Thomas Jefferson", "Theodore Roosevelt"}, 0},
    {"What is the currency of Japan?", {"Yen", "Euro", "Dollar", "Pound"}, 0}
};

// User Interface
void displayMenu() {
    printf("\n** Online Examination System **\n");
    printf("1. Start Examination\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void startExamination() {
    int score = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int qIndex = rand() % 10;  // Random question index

        printf("\n%s\n", questions[qIndex].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[qIndex].options[j]);
        }

        int userChoice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &userChoice);

        if (userChoice == questions[qIndex].correctOption + 1) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }

    printf("\n** Result **\n");
    printf("Score: %d/10\n", score);
}

void viewResults() {
    printf("\n** Examination Results **\n");
    printf("%-5s%-25s%-10s\n", "QNo", "Question", "Status");
    for (int i = 0; i < 10; i++) {
        printf("%-5d%-25s", i + 1, questions[i].question);
        if (questions[i].correctOption == 0) {
            printf("%-10s\n", "Correct");
        } else {
            printf("%-10s\n", "Incorrect");
        }
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startExamination();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("Thank you for using the Online Examination System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}