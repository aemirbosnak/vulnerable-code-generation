//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: futuristic
/*
 * Online Examination System
 *
 * This program allows students to take an online examination and view their
 * results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_QUESTIONS 10

typedef struct {
    char question[100];
    char options[4][100];
    int correct_option;
} question_t;

void print_question(question_t *question) {
    printf("Question: %s\n", question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->options[i]);
    }
}

int get_answer(void) {
    char answer;
    printf("Enter your answer: ");
    scanf("%c", &answer);
    return answer - 'A';
}

void print_result(int answer, question_t *question) {
    if (answer == question->correct_option) {
        printf("Correct! Well done!\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n", question->options[question->correct_option]);
    }
}

int main(void) {
    question_t questions[NUM_QUESTIONS] = {
        {
            "What is the capital of France?",
            {
                "Paris",
                "London",
                "Berlin",
                "Rome"
            },
            0
        },
        {
            "What is the largest planet in our solar system?",
            {
                "Earth",
                "Saturn",
                "Jupiter",
                "Uranus"
            },
            1
        },
        {
            "What is the smallest country in the world?",
            {
                "Vatican City",
                "Monaco",
                "Liechtenstein",
                "Nauru"
            },
            3
        },
        {
            "What is the highest mountain in the solar system?",
            {
                "Mount Everest",
                "Mount Kilimanjaro",
                "Mount Olympus",
                "Mount Denali"
            },
            0
        },
        {
            "What is the largest living species of lizard?",
            {
                "Saltwater Crocodile",
                "Nile Crocodile",
                "Alligator",
                "Crocodile"
            },
            0
        },
        {
            "What is the largest mammal on Earth?",
            {
                "Blue Whale",
                "Fin Whale",
                "Humpback Whale",
                "Gray Whale"
            },
            0
        },
        {
            "What is the largest bird in the world?",
            {
                "Ostrich",
                "Emperor Penguin",
                "Emu",
                "Great Argus"
            },
            0
        },
        {
            "What is the largest fish in the world?",
            {
                "Whale Shark",
                "Megamouth Shark",
                "Basking Shark",
                "Goblin Shark"
            },
            0
        },
        {
            "What is the largest insect in the world?",
            {
                "Giant Silk Moth",
                "Goliath Birdeater",
                "Goliath Beetle",
                "Rhinoceros Beetle"
            },
            0
        },
        {
            "What is the largest reptile in the world?",
            {
                "Spectacled Caiman",
                "Amazonian Caiman",
                "Congo Caiman",
                "Saltwater Crocodile"
            },
            3
        }
    };

    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        print_question(&questions[i]);
        int answer = get_answer();
        print_result(answer, &questions[i]);
        if (answer == questions[i].correct_option) {
            score++;
        }
    }

    printf("Your final score is: %d/%d\n", score, NUM_QUESTIONS);

    return 0;
}