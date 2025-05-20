//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayIntro() {
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*            Welcome to the Fortune Teller     *\n");
    printf("*      Where the Mystical and Real Collide!    *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("In this journey, your destiny will unfold.\n");
    printf("Type your name to receive a glimpse of your future...\n");
}

void getFortune(int choice) {
    switch (choice) {
        case 1:
            printf("Your fortune: Great adventures await you!\n");
            break;
        case 2:
            printf("Your fortune: Secret knowledge will come your way.\n");
            break;
        case 3:
            printf("Your fortune: A surprise is just around the corner.\n");
            break;
        case 4:
            printf("Your fortune: Love is in the air, but be patient!\n");
            break;
        case 5:
            printf("Your fortune: You will inspire others with your creativity.\n");
            break;
        default:
            printf("Your fortune: The stars are not aligned. Try again later!\n");
            break;
    }
}

void showChoices() {
    printf("Choose a number from the list below to unveil your fortune:\n");
    printf("1. Adventure\n");
    printf("2. Knowledge\n");
    printf("3. Surprise\n");
    printf("4. Love\n");
    printf("5. Creativity\n");
}

char* getName() {
    static char name[30];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    // Remove newline character added by fgets
    name[strcspn(name, "\n")] = 0;
    return name;
}

int getRandomFortune() {
    return rand() % 5 + 1; // Returns a random number between 1 and 5
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    displayIntro();
    
    char* userName = getName();
    printf("Hello, %s! Let's uncover your fortune...\n", userName);

    showChoices();

    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    // Get a random fortune if user gives an invalid choice
    if (choice < 1 || choice > 5) {
        choice = getRandomFortune();
        printf("Invalid choice. A random fortune has been selected for you!\n");
    }

    getFortune(choice);

    printf("Thank you for visiting the Fortune Teller! May your days be filled with magic!\n");
    
    return 0;
}