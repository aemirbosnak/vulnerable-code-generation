//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 30 // Let's track for a month

void displayMenu() {
    printf("\n💪 Welcome to Your Cheerful Fitness Tracker! 💪\n");
    printf("1. Log your steps for today\n");
    printf("2. View your progress\n");
    printf("3. View motivational quotes\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void addSteps(int steps[], int day) {
    printf("Enter the number of steps you walked today: ");
    scanf("%d", &steps[day]);
    printf("🎉 You've logged %d steps today! Keep it up! 🎉\n", steps[day]);
}

void viewProgress(int steps[]) {
    printf("\n📊 Your Fitness Progress 📊\n");
    for (int i = 0; i < MAX_DAYS; ++i) {
        if (steps[i] == 0) {
            printf("Day %d: No steps logged yet! Let's get moving! 🚶‍♂️\n", i + 1);
        } else {
            printf("Day %d: %d steps walked! You're on fire! 🔥\n", i + 1, steps[i]);
        }
    }
}

void motivationalQuotes() {
    const char *quotes[] = {
        "🌟 \"Your body can stand almost anything. It’s your mind you have to convince!\" 🌟",
        "🌈 \"Success is the sum of small efforts, repeated day in and day out.\" 🌈",
        "🤩 \"The journey of a thousand miles begins with one step.\" 🤩",
        "✨ \"You are stronger than you think! Keep going!\" ✨",
        "🚀 \"Fitness is not about being better than someone else. It's about being better than you used to be!\" 🚀"
    };

    srand(time(NULL));
    int index = rand() % 5; // Pick a random motivational quote
    printf("\n💖 Here's a motivational quote for you: 💖\n%s\n", quotes[index]);
}

int main() {
    int steps[MAX_DAYS] = {0}; // Initialize an array for tracking steps
    int choice;
    int day = 0;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (day < MAX_DAYS) {
                    addSteps(steps, day);
                    day++;
                } else {
                    printf("🎯 You've logged steps for all %d days! Time to review your progress or reset! 🎯\n", MAX_DAYS);
                }
                break;
            case 2:
                viewProgress(steps);
                break;
            case 3:
                motivationalQuotes();
                break;
            case 4:
                printf("👋 Thank you for using the Fitness Tracker! Keep up the great work! 👋\n");
                exit(0); // Exit the program
            default:
                printf("😅 Invalid choice! Please select a valid option from the menu.\n");
                break;
        }
    }
    
    return 0;
}