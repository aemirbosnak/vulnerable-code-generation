//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayFortune(int choice);
void askForCategory();

int main() {
    srand(time(0));  // Seed for random number generation
    askForCategory();
    return 0;
}

void askForCategory() {
    int category;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Choose a category for your fortune:\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. Future\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    
    scanf("%d", &category);
    
    if (category < 1 || category > 5) {
        printf("Invalid choice! Please select a number between 1-5.\n");
        askForCategory();  // Recursion if invalid choice
    } else if (category == 5) {
        printf("Thank you for visiting the fortune teller. Goodbye!\n");
    } else {
        displayFortune(category);  // Get the fortune if choice is valid
    }
}

void displayFortune(int choice) {
    const char *fortunes[][5] = {
        {"You will meet someone special soon.", "Love is around the corner!", "An old flame will rekindle.", "Expect surprises in your love life.", "True love is coming your way."}, // Love
        {"A new job opportunity is on the horizon.", "Your hard work will be rewarded.", "Expect a promotion soon.", "Follow your passion, success is near.", "Teamwork will lead to great success."}, // Career
        {"Take care of your health, it's your greatest wealth.", "You're about to start a new fitness journey.", "Step outside and embrace nature!", "Balance is key to your well-being.", "Listen to your body and rest up."}, // Health
        {"Your future holds great potential.", "Travel is in your future.", "A surprise adventure awaits you!", "Embrace change, it will lead to growth.", "The path you choose will define your destiny."}  // Future
    };
    
    int index = rand() % 5;  // Random index for fortune
    printf("Your fortune: %s\n\n", fortunes[choice - 1][index]);
    
    // Ask if the user wants another fortune or to exit
    char response;
    printf("Would you like another fortune? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        askForCategory();  // Recursive call to ask for category again
    } else {
        printf("Thank you for visiting the fortune teller. Goodbye!\n");
    }
}