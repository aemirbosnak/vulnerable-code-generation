//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void print_welcome_message() {
    printf("*********************************\n");
    printf("*    Welcome to the Fortune     *\n");
    printf("*           Teller!             *\n");
    printf("*********************************\n");
    printf("☀️  Get ready for some enlightening insights! ☀️\n");
}

void print_fortune(int index) {
    const char *fortunes[NUM_FORTUNES] = {
        "You will find great joy in the little things.",
        "An unexpected expense will bring new opportunities.",
        "Today is your lucky day! Trust your instincts.",
        "You will make a new friend today you will cherish.",
        "A journey of a thousand miles begins with a single step.",
        "You will soon discover a hidden talent.",
        "Your smile is your best accessory — wear it often!",
        "You will receive good news from a friend.",
        "An adventure awaits you — pack your bags!",
        "Great success is on the horizon. Keep striving!"
    };

    printf("\n🎉 Your Fortune: %s 🎉\n\n", fortunes[index]);
}

int main() {
    int user_choice;

    // Seed the random number generator
    srand(time(0));

    print_welcome_message();

    // Main loop for fortune telling
    do {
        printf("Would you like to know your fortune? (1 for Yes, 0 for No): ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            int fortune_index = rand() % NUM_FORTUNES; // Generate a random index
            print_fortune(fortune_index);
        } else if (user_choice == 0) {
            printf("Thank you for visiting the Fortune Teller! Have a splendid day! 🌞\n");
        } else {
            printf("😄 That's not a valid option! Please enter 1 for Yes or 0 for No.\n");
        }

    } while (user_choice != 0);

    return 0;
}