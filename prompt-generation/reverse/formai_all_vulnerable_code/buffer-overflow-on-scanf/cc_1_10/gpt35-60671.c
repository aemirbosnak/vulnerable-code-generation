//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// A structure to store information about the test taker
struct student {
    char name[50];
    char rollNo[10];
    int score;
};

// A function to get input from the user
void getInput(struct student *s) {
    printf("Enter your name: ");
    fgets(s->name, 50, stdin);
    s->name[strcspn(s->name, "\n")] = 0; // To remove '\n' character from the name
    
    printf("Enter your roll number: ");
    fgets(s->rollNo, 10, stdin);
    s->rollNo[strcspn(s->rollNo, "\n")] = 0; // To remove '\n' character from the roll number
}

// A function to display instructions to the user
void displayInstructions() {
    printf("\nInstructions:\n");
    printf("1. This test contains 10 questions.\n");
    printf("2. Each correct answer will give you 1 point.\n");
    printf("3. There is no negative marking.\n");
    printf("4. Answer the questions by entering A/B/C/D as your choice.\n");
    printf("5. All the best!\n");
}

// A function to display a single question and take input from the user
int askQuestion(char *question, char *options, char answer) {
    printf("\n%s\n", question);
    printf("%s\n", options);
    
    char choice;
    printf("Your choice: ");
    scanf(" %c", &choice); // Taking input of a single character
    
    if(choice == answer) {
        printf("Correct answer!\n");
        return 1;
    } else {
        printf("Incorrect answer!\n");
        return 0;
    }
}

// A function to start the test
void startTest(struct student *s) {
    int score = 0;
    
    // Questions array
    char *questions[] = {
        "What is the capital of India?",
        "Which is the largest desert in the world?",
        "Who is known as the father of the nation?",
        "What is the highest mountain peak in the world?",
        "Which is the largest mammal in the world?",
        "Who is the CEO of Microsoft?",
        "What is the chemical formula of water?",
        "Which is the most populated country in the world?",
        "What is the name of the largest planet in our solar system?",
        "What is the national animal of India?"
    };
    
    // Options array
    char *options[] = {
        "[A] Mumbai  [B] New Delhi  [C] Chennai  [D] Kolkata",
        "[A] Sahara  [B] Gobi  [C] Thar  [D] Kalahari",
        "[A] Mahatma Gandhi  [B] Jawaharlal Nehru  [C] Subhash Chandra Bose  [D] Sardar Vallabhbhai Patel",
        "[A] Mount Everest  [B] K2  [C] Kangchenjunga  [D] Makalu",
        "[A] Elephant  [B] Whale  [C] Giraffe  [D] Rhinoceros",
        "[A] Sundar Pichai  [B] Jeff Bezos  [C] Bill Gates  [D] Tim Cook",
        "[A] H2O  [B] CO2  [C] NaCl  [D] NH3",
        "[A] India  [B] China  [C] USA  [D] Russia",
        "[A] Jupiter  [B] Saturn  [C] Uranus  [D] Neptune",
        "[A] Tiger  [B] Lion  [C] Elephant  [D] Panda"
    };
    
    // Answers array
    char answers[] = {
        'B', 'A', 'A', 'A', 'B', 'A', 'A', 'B', 'A', 'A'
    };
    
    printf("\nTest started!\n");
    
    // Asking the 10 questions one by one
    for(int i=0; i<10; i++) {
        score += askQuestion(questions[i], options[i], answers[i]);
    }
    
    s->score = score;
    
    printf("\nTest completed!\n");
    printf("Your score: %d out of 10\n", score);
}

// A function to display the result of the test taker
void displayResult(struct student *s) {
    printf("\nName: %s\n", s->name);
    printf("Roll Number: %s\n", s->rollNo);
    printf("Score: %d out of 10\n", s->score);
    
    if(s->score >= 7) {
        printf("Congratulations!\n");
    } else {
        printf("Better luck next time!\n");
    }
}

int main() {
    printf("Welcome to the Online Examination System!\n\n");
    
    struct student s;
    
    getInput(&s);
    
    displayInstructions();
    
    startTest(&s);
    
    displayResult(&s);
    
    return 0;
}