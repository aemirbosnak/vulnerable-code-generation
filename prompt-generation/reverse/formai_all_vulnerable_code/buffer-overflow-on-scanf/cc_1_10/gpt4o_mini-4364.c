//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_FORTUNES 10

// Function to get a random fortune based on the user's birth month
const char* get_fortune(int month) {
    const char *fortunes[MAX_FORTUNES] = {
        "You will find a lost treasure soon.",
        "A great opportunity is coming your way.",
        "Expect to encounter an old friend unexpectedly.",
        "The stars are aligned for a new adventure.",
        "Love is in the air, keep your heart open.",
        "You will soon discover a hidden talent.",
        "A journey will bring you wisdom and insight.",
        "Your creativity will shine this month.",
        "You will receive good news about a project.",
        "A surprise awaits you on your next adventure."
    };

    return fortunes[(month - 1) % MAX_FORTUNES];
}

int main() {
    char name[MAX_NAME_LENGTH];
    int birth_day;
    int birth_month;

    // Seed the random number generator
    srand(time(NULL));

    // Welcome the user
    printf("Welcome to the Curious C Fortune Teller!\n");
    printf("Please tell me your name: ");
    fgets(name, sizeof(name), stdin);
    // Remove newline character from input
    name[strcspn(name, "\n")] = '\0';

    // Ask for birth month and day
    printf("Welcome, %s! What is your birth month (1-12)? ", name);
    scanf("%d", &birth_month);
    printf("And what is your birth day (1-31)? ");
    scanf("%d", &birth_day);

    // Validate the input
    if (birth_month < 1 || birth_month > 12) {
        printf("Hmm, that doesn't seem like a valid month. Try again next year!\n");
        return 1;
    }

    if (birth_day < 1 || birth_day > 31) {
        printf("Your birth day seems off. Are you sure you counted correctly?\n");
        return 1;
    }

    // Get the fortune
    const char* fortune = get_fortune(birth_month);

    // Display the fortune
    printf("\nDear %s,\nYour fortune for the month is:\n%s\n", name, fortune);

    // Provide a curious end note
    printf("\nRemember, %s, fortunes can change like the tides, so embrace each wave of fortune that comes your way!\n", name);
    printf("Good luck in your adventures!\n");

    return 0;
}