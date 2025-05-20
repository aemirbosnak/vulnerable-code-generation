//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_intro() {
    printf("====================================\n");
    printf("         Automated Fortune Teller   \n");
    printf("====================================\n");
    printf("Welcome, seeker of knowledge! \n");
    printf("I shall reveal your fate, but first, \n");
    printf("let me know which aspect of life you want to explore:\n\n");
}

void display_options() {
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Wealth\n");
    printf("4. Health\n");
    printf("5. Exit\n");
}

const char* get_love_fortune() {
    const char* fortunes[] = {
        "Love is on the horizon! Embrace it.",
        "A new friendship may bloom into romance.",
        "Beware of past lovers returning for a chat.",
        "A special gift will come your way.",
        "The stars favor you – love will find a way."
    };
    return fortunes[rand() % 5];
}

const char* get_career_fortune() {
    const char* fortunes[] = {
        "A promotion may be just around the corner.",
        "Consider a new venture; it may be rewarding.",
        "Networking today will yield benefits tomorrow.",
        "Stay focused, and success will follow.",
        "Your hard work will be acknowledged soon."
    };
    return fortunes[rand() % 5];
}

const char* get_wealth_fortune() {
    const char* fortunes[] = {
        "Financial gains are on the way. Invest wisely.",
        "A surprise expense may challenge your budget.",
        "Money will flow, but don't forget to save.",
        "A new opportunity could lead to increased wealth.",
        "Be cautious with lending; it may not return."
    };
    return fortunes[rand() % 5];
}

const char* get_health_fortune() {
    const char* fortunes[] = {
        "Your health will improve with small changes.",
        "Listen to your body; rest is needed.",
        "Balance is key; don't overwork yourself.",
        "A health-conscious friend may inspire you.",
        "Stay hydrated, as it will improve your wellbeing."
    };
    return fortunes[rand() % 5];
}

void shape_shifting_fortunes(int choice) {
    switch (choice) {
        case 1:
            printf("Your love fortune: %s\n", get_love_fortune());
            break;
        case 2:
            printf("Your career fortune: %s\n", get_career_fortune());
            break;
        case 3:
            printf("Your wealth fortune: %s\n", get_wealth_fortune());
            break;
        case 4:
            printf("Your health fortune: %s\n", get_health_fortune());
            break;
        case 5:
            printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }
}

int main() {
    srand(time(0));  // Seed the random number generator

    int choice = 0;
    while (1) {
        display_intro();
        display_options();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        shape_shifting_fortunes(choice);
        printf("\n");
    }

    return 0;  // Exit the program
}