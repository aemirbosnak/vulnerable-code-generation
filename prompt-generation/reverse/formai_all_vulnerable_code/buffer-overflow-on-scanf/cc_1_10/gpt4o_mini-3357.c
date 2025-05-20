//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_STRING_SIZE 256

void initializeFortunes(char fortunes[][MAX_STRING_SIZE]) {
    strcpy(fortunes[0], "You will discover a hidden talent soon.");
    strcpy(fortunes[1], "A long-lost friend will contact you.");
    strcpy(fortunes[2], "Success is on the horizon; be prepared.");
    strcpy(fortunes[3], "Adventure awaits you; embrace it.");
    strcpy(fortunes[4], "Your kindness will be returned to you.");
    strcpy(fortunes[5], "A surprise gift will add joy to your life.");
    strcpy(fortunes[6], "You will travel to a place that inspires you.");
    strcpy(fortunes[7], "An unexpected opportunity is coming your way.");
    strcpy(fortunes[8], "Trust your instincts; they will guide you.");
    strcpy(fortunes[9], "Love is blossoming where you least expect it.");
}

void tellFortune() {
    char fortunes[MAX_FORTUNES][MAX_STRING_SIZE];
    initializeFortunes(fortunes);
    
    srand(time(NULL));
    int randomIndex = rand() % MAX_FORTUNES; // Get a random index of the fortune
    
    printf("\n🌟 Fortune Teller 🌟\n");
    printf("Here is your fortune for today:\n\n");
    printf("\"%s\"\n", fortunes[randomIndex]);
    printf("💫 Embrace the wisdom of the universe! 💫\n");
}

void displayMenu() {
    printf("\n====== Automated Fortune Teller ======\n");
    printf("1. Tell my fortune\n");
    printf("2. Exit\n");
    printf("=====================================\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Automated Fortune Teller!\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                tellFortune();
                break;
            case 2:
                printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);
    
    return 0;
}