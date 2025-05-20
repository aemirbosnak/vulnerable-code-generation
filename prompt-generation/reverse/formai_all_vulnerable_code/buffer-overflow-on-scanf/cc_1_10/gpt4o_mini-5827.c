//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome_message() {
    printf("****************************************\n");
    printf("*          Welcome to                 *\n");
    printf("*         The Mathematical Fortune Teller       *\n");
    printf("****************************************\n");
    printf("Enter your name to start: ");
}

int get_random_number(int max) {
    return rand() % max;
}

const char* get_fortune(int num) {
    switch (num) {
        case 0:
            return "You will discover a new passion!";
        case 1:
            return "Expect great news soon, perhaps a new opportunity.";
        case 2:
            return "Beware of unexpected challenges ahead.";
        case 3:
            return "A friend will bring you luck shortly.";
        case 4:
            return "Your hard work will soon pay off!";
        case 5:
            return "Love is in the air; keep your heart open.";
        case 6:
            return "A travel opportunity awaits you.";
        case 7:
            return "Trust your instincts; they are powerful.";
        case 8:
            return "You will gain wisdom from recent events.";
        case 9:
            return "An old acquaintance will reenter your life.";
        default:
            return "The universe withholds its secrets.";
    }
}

void ask_for_number() {
    printf("Now, think of a number between 1 and 10.\n");
    printf("This number will impact your fortune...\n");
}

int main() {
    char name[50];
    int user_number, random_fortune;

    // Initialization for random number generation
    srand(time(0));

    // Display welcome message
    display_welcome_message();
    scanf("%s", name);

    // Ask user for a number
    ask_for_number();
    printf("Enter your number: ");
    scanf("%d", &user_number);

    // Sanitize user input
    if (user_number < 1 || user_number > 10) {
        printf("Please enter a valid number between 1 and 10.\n");
        return 1; // Exit if invalid number
    }

    // Compute a fortune based on user's number
    random_fortune = (get_random_number(10) + user_number) % 10;

    // Retrieve the corresponding fortune
    const char* fortune = get_fortune(random_fortune);

    // Display the fortune
    printf("\n%s, here is your fortune:\n", name);
    printf("**********************************************************\n");
    printf("* %s *\n", fortune);
    printf("**********************************************************\n");

    // Closing thoughts
    printf("Remember, fortunes are just reflections of your potential.\n");
    printf("Good luck with your endeavors, %s!\n", name);
    
    return 0;
}