//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void display_introduction() {
    printf("Ah, greetings, dear friend. I am Sherlock Holmes, here to unveil the mysteries of your future.\n");
    printf("Please allow me a moment to gather my thoughts, for the universe does hold secrets aplenty.\n");
    printf("Now, let us embark on this intriguing journey.\n\n");
}

void display_fortune(char *fortune) {
    printf("As the fog of time clears, I see...\n");
    printf("%s\n", fortune);
    printf("Take heed, for all is not as it appears!\n\n");
}

char* get_fortune(int choice) {
    switch (choice) {
        case 1:
            return "A great opportunity will present itself very soon.";
        case 2:
            return "Beware of deception; not all allies are trustworthy.";
        case 3:
            return "Love is lurking just around the corner.";
        case 4:
            return "A journey awaits that may redefine your path.";
        case 5:
            return "You will discover an unexpected talent.";
        default:
            return "Mystery prevails; I cannot see your fortune.";
    }
}

void display_choices() {
    printf("Choose your path wisely, for fate is in your hands:\n");
    printf("1. The path of opportunity\n");
    printf("2. The road of caution\n");
    printf("3. The trail of love\n");
    printf("4. The journey of discovery\n");
    printf("5. The uncovering of new skills\n");
}

int get_user_choice() {
    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) {
        printf("Invalid choice. Please select a number between 1 and 5.\n");
        return get_user_choice();
    }
    return choice;
}

void play_fortune_teller() {
    int user_choice;

    display_choices();
    user_choice = get_user_choice();
    
    char* fortune = get_fortune(user_choice);
    display_fortune(fortune);
}

int main() {
    srand(time(NULL)); // Seed for randomness
    display_introduction();
    play_fortune_teller();
    
    printf("Thank you for consulting me, dear friend. Remember, the future is but a tapestry awaiting your thread.\n");
    return 0;
}