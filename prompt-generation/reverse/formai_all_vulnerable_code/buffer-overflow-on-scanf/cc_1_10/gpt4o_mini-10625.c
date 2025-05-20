//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_THEMES 5
#define MAX_FACTS 5

const char *fortunes[MAX_THEMES][MAX_FORTUNES] = {
    {
        "You will find a hidden talent today.",
        "A new opportunity will knock at your door.",
        "Expect a surprise from a friend.",
        "Today is a perfect day for new beginnings.",
        "A major change is coming your way.",
        "Your creativity will shine today.",
        "A stranger will impact your life.",
        "Love is on the horizon.",
        "You will receive good news soon.",
        "A small adventure awaits you."
    },
    {
        "Balance is key in your life right now.",
        "A risk you take today will pay off.",
        "Embrace the unknown, it will lead you to greatness.",
        "Listening to your intuition will lead you further.",
        "An old friend will reach out to you.",
        "You are the master of your destiny.",
        "Success is in your near future.",
        "Look for signs in your dreams.",
        "A moment of joy is just around the corner.",
        "You will solve a puzzle today."
    },
    {
        "A financial blessing is on its way.",
        "Take a break; relaxation brings clarity.",
        "Adventure is in your stars, take a chance.",
        "Seek comfort in things you love.",
        "An opportunity for collaboration will arise.",
        "You will gain a new perspective today.",
        "Some changes will be challenging, but rewarding.",
        "Your confidence will attract new chances.",
        "Revive old passions today.",
        "Be mindful of the words you choose."
    },
    {
        "Happiness is a choice; make yours.",
        "A misunderstanding will clear up today.",
        "Kindness will lead to unexpected rewards.",
        "A chance encounter will change your outlook.",
        "Cherish moments with loved ones.",
        "Something you've waited for will arrive.",
        "Your hard work will bring forth results.",
        "Trust in the journey, not just the destination.",
        "Your uniqueness is your greatest strength.",
        "Dream big and take steps towards those dreams."
    },
    {
        "Prepare for a wave of creativity.",
        "Someone close to you admires you.",
        "Your efforts will bring recognition.",
        "Today holds the potential for joy.",
        "Count your blessings before the end of the day.",
        "A relaxing moment will bring clarity.",
        "Trust your instincts more than usual.",
        "Explore new ideas; they will be fruitful.",
        "Stay open to new possibilities.",
        "A light-hearted moment is in store."
    }
};

const char *funFacts[MAX_FACTS] = {
    "Did you know? Honey never spoils.",
    "Did you know? Bananas are berries, but strawberries are not.",
    "Did you know? A group of flamingos is called a 'flamboyance.'",
    "Did you know? The longest time between two twins being born is 87 days.",
    "Did you know? Octopuses have three hearts."
};

void print_welcome_message() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Let me unveil the mysteries that await you...\n");
}

int get_user_choice() {
    int choice;
    printf("\nPlease select a theme for your fortune:\n");
    printf("1. Inspiration\n");
    printf("2. Life Changes\n");
    printf("3. Wealth and Abundance\n");
    printf("4. Happiness and Joy\n");
    printf("5. Creativity and Growth\n");
    printf("Your choice (1-5): ");
    scanf("%d", &choice);
    return choice - 1; // Adjust for array indexing
}

void display_fortune(int theme) {
    srand(time(NULL));
    int fortuneIndex = rand() % MAX_FORTUNES;
    printf("Your fortune: %s\n\n", fortunes[theme][fortuneIndex]);
}

void display_fun_fact() {
    srand(time(0));
    int factIndex = rand() % MAX_FACTS;
    printf("Fun Fact: %s\n", funFacts[factIndex]);
}

int main() {
    print_welcome_message();
    
    int userChoice;
    
    do {
        userChoice = get_user_choice();
        
        if (userChoice >= 0 && userChoice < MAX_THEMES) {
            display_fortune(userChoice);
            display_fun_fact();
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        char continueChoice[3];
        printf("Would you like to get another fortune? (yes/no): ");
        scanf("%s", continueChoice);

        if (strcmp(continueChoice, "no") == 0) {
            printf("Thank you for visiting the Automated Fortune Teller!\n");
            break;
        }

    } while (1);

    return 0;
}