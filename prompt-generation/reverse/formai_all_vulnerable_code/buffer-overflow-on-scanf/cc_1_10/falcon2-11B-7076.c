//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a post-apocalyptic world
void simulate_apocalypse() {
    printf("The world has ended. You are alone in a post-apocalyptic wasteland.\n");
    printf("The only sound you hear is the wind howling through the deserted streets.\n");
    printf("You can see the ruins of once great cities in the distance, now nothing but piles of rubble.\n");
    printf("You must find a way to survive in this harsh new world.\n");
    printf("But be careful, there are dangers lurking around every corner.\n");
}

// Function to simulate an online examination
void online_exam() {
    printf("Welcome to the post-apocalyptic online examination system.\n");
    printf("Please log in with your username and password.\n");
    printf("Username: ");
    char username[20];
    scanf("%s", username);
    printf("Password: ");
    char password[20];
    scanf("%s", password);
    printf("Logging in...\n");
    printf("Welcome, %s!\n", username);
    printf("Please select a subject to begin the exam:\n");
    printf("1. Mathematics\n");
    printf("2. Science\n");
    printf("3. English\n");
    printf("4. Back\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("You have chosen Mathematics.\n");
            printf("Question 1: 2 + 2 =?\n");
            printf("Answer: 4\n");
            printf("Question 2: 3 * 4 =?\n");
            printf("Answer: 12\n");
            break;
        case 2:
            printf("You have chosen Science.\n");
            printf("Question 1: The sun is the source of light and heat for which planet?\n");
            printf("Answer: Earth\n");
            printf("Question 2: Which gas makes up most of Earth's atmosphere?\n");
            printf("Answer: Nitrogen\n");
            break;
        case 3:
            printf("You have chosen English.\n");
            printf("Question 1: What is the past tense of \"run\"?\n");
            printf("Answer: Ran\n");
            printf("Question 2: How many letters are in the word \"post-apocalyptic\"?\n");
            printf("Answer: 16\n");
            break;
        case 4:
            printf("You have chosen Back.\n");
            printf("Please select another subject to begin the exam:\n");
            printf("1. Mathematics\n");
            printf("2. Science\n");
            printf("3. English\n");
            printf("4. Back\n");
            scanf("%d", &choice);
            break;
        default:
            printf("Invalid choice. Please select a valid subject.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int choice;
    printf("Do you want to simulate the apocalypse first? (y/n): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            simulate_apocalypse();
            break;
        case 2:
            break;
        default:
            printf("Invalid choice. Please select y or n.\n");
            break;
    }
    while (1) {
        printf("Welcome to the post-apocalyptic online examination system.\n");
        printf("Please log in with your username and password.\n");
        printf("Username: ");
        char username[20];
        scanf("%s", username);
        printf("Password: ");
        char password[20];
        scanf("%s", password);
        printf("Logging in...\n");
        printf("Welcome, %s!\n", username);
        printf("Please select a subject to begin the exam:\n");
        printf("1. Mathematics\n");
        printf("2. Science\n");
        printf("3. English\n");
        printf("4. Back\n");
        printf("Subject: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                online_exam();
                break;
            case 2:
                online_exam();
                break;
            case 3:
                online_exam();
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid subject.\n");
                break;
        }
        printf("Do you want to simulate the apocalypse again? (y/n): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                simulate_apocalypse();
                break;
            case 2:
                break;
            default:
                printf("Invalid choice. Please select y or n.\n");
                break;
        }
    }
}