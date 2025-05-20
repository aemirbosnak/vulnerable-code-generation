//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function to get a random fortune
const char* get_fortune() {
    const char* fortunes[MAX_FORTUNES] = {
        "You will find great success in the near future.",
        "A close friend will bring you good news.",
        "An unexpected opportunity will present itself.",
        "You will soon embark on a journey that will change your life.",
        "Love is just around the corner.",
        "Patience is the key to your happiness.",
        "A financial opportunity is on the horizon.",
        "You will encounter a challenge, but you will overcome it.",
        "Good things come to those who wait.",
        "Your dreams are worth pursuing, go for them!"
    };

    return fortunes[rand() % MAX_FORTUNES];
}

void print_menu() {
    printf("\nWelcome to the Fortune Teller!\n");
    printf("1. Ask a question\n");
    printf("2. Exit\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int choice = 0;

    while (choice != 2) {
        print_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            // Buffer to hold user's question
            char question[256];
            printf("Ask your question: ");
            getchar(); // clear newline left by previous input
            fgets(question, sizeof(question), stdin);

            printf("Thinking...\n");
            // Simulate processing time
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                sleep(1); // Wait for 1 second
            }
            printf("\n");

            const char* fortune = get_fortune();
            printf("Fortune: %s\n", fortune);
        } else if (choice == 2) {
            printf("Thank you for visiting the Fortune Teller. Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}