//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUESTIONS 5

void display_intro();
int generate_question(int level);
void display_options();
int get_user_answer();
int check_answer(int correct_answer, int user_answer);
void hack_attempt();

int main() {
    srand(time(NULL)); // Seed the random number generator
    display_intro();
    hack_attempt();
    return 0;
}

void display_intro() {
    printf("Initializing CyberHacker... Loading...\n");
    sleep(2);
    printf("You have entered the Neon Grid.\n");
    printf("Your mission: Infiltrate the system by solving math equations.\n");
    printf("Each correct answer unlocks a new layer of security.\n");
    printf("Prepare yourself, Data Thief. The clock is ticking...\n\n");
}

int generate_question(int level) {
    int num1, num2, answer;
    char operator;
    
    num1 = rand() % (level * 10) + 1; // Numbers based on level
    num2 = rand() % (level * 10) + 1; 
    
    switch (rand() % 4) { // Random operator
        case 0:
            operator = '+';
            answer = num1 + num2;
            break;
        case 1:
            operator = '-';
            answer = num1 - num2;
            break;
        case 2:
            operator = '*';
            answer = num1 * num2;
            break;
        case 3:
            operator = '/';
            if (num2 == 0) num2 = 1; // Prevent division by zero
            answer = num1 / num2;
            break;
    }

    printf("Solve this: %d %c %d = ?\n", num1, operator, num2);
    return answer; // Return the correct answer
}

void display_options() {
    printf("1. Start Hacking\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int get_user_answer() {
    int user_answer;
    scanf("%d", &user_answer);
    return user_answer;
}

int check_answer(int correct_answer, int user_answer) {
    if (correct_answer == user_answer) {
        printf("Access Granted! You cracked the code.\n\n");
        return 1;
    } else {
        printf("Access Denied! You failed to decode the data...\n\n");
        return 0;
    }
}

void hack_attempt() {
    int level = 1;
    int score = 0;
    int user_answer;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Cracking Layer %d...\n", level);
        int correct_answer = generate_question(level);
        user_answer = get_user_answer();
        
        // Check the user's answer
        if (check_answer(correct_answer, user_answer)) {
            score++;
            level++;
        } else {
            printf("Try again! You need %d correct answers to proceed.\n\n", MAX_QUESTIONS - score);
            break; // Exit if failed
        }

        sleep(1); // Simulate time delay for dramatic effect
    }
    
    if (score == MAX_QUESTIONS) {
        printf("Congratulations! You've successfully hacked the Neon Grid!\n");
    } else {
        printf("Mission Failed. The Neon Grid remains secure...\n");
    }
}