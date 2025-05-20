//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    printf("Welcome to the Periodic Table of Love Quiz!\n");
    
    // Define the periodic table of love
    char* elements[7][6] = {
        {"R", "H", "O", "D", "I", "U"},
        {"L", "O", "V", "E", "S", ""},
        {"K", "I", "S", "S", "", ""},
        {"F", "L", "A", "M", "E", ""},
        {"H", "E", "A", "R", "T", ""},
        {"F", "L", "O", "W", "E", "R"},
        {"M", "A", "R", "R", "I", "A"},
    };
    
    // Define the questions and answers
    char* questions[7] = {
        "What element of love represents a lasting commitment?",
        "Which element of love is associated with passion?",
        "What element of love is represented by a kiss?",
        "Which element of love represents the start of a relationship?",
        "What element of love represents the center of affection?",
        "What symbol of love is represented by giving flowers?",
        "What element of love represents a lifelong partnership?",
    };
    char* answers[7] = {"iridium", "flame", "kiss", "loves", "heart", "flower", "marriage"};
    
    // Initialize score and answer buffer
    int score = 0;
    char answer[50];
    
    // Loop through the questions
    for (int i = 0; i < 7; i++) {
        printf("%d. %s\n", i+1, questions[i]);
        scanf("%s", answer);
        clear_buffer();
        
        // Convert answer to lowercase for case-insensitive comparison
        for (int j = 0; answer[j]; j++) {
            answer[j] = tolower(answer[j]);
        }
        
        if (strcmp(answer, answers[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s\n", answers[i]);
        }
    }
    
    // Print final score and message
    printf("Congratulations, you scored %d out of 7!\n", score);
    if (score == 0) {
        printf("You may not know the periodic table of love yet, but remember that love is an ongoing learning process.\n");
    } else if (score < 4) {
        printf("Not bad, but there's still room for improvement. Keep learning about the elements of love!\n");
    } else if (score < 7) {
        printf("Great job, you know a lot about the elements of love!\n");
    } else {
        printf("Wow, you're a love expert!\n");
    }
    
    return 0;
}