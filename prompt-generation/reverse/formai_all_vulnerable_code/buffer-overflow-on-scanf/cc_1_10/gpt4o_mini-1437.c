//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 5
#define MAX_MOODS 5
#define MAX_CATEGORIES 3
#define MAX_USER_FORTUNES 5

const char* fortunes[MAX_FORTUNES] = {
    "You will find a new hobby that brings you joy.",
    "Expect a surprise from a loved one soon.",
    "A financial opportunity will present itself.",
    "Adventure awaits, but be prepared for challenges.",
    "Love is in the air; don't miss your chance."
};

const char* moods[MAX_MOODS] = {
    "happy",
    "curious",
    "anxious",
    "grateful",
    "dreamy"
};

const char* categories[MAX_CATEGORIES] = {
    "Love",
    "Career",
    "Health"
};

void greet_user() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Today, you shall learn your fate.\n\n");
}

void display_categories() {
    printf("Choose a category to delve into:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
}

int get_user_choice() {
    int choice;
    printf("Enter the number corresponding to your choice (1-3): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > MAX_CATEGORIES) {
        printf("Invalid choice. Please choose a number between 1 and 3: ");
        scanf("%d", &choice);
    }
    return choice - 1; // return zero indexed
}

void generate_fortune(int category_index) {
    srand(time(NULL));
    int fortune_index = rand() % MAX_FORTUNES;
    printf("\nCategory: %s\n", categories[category_index]);
    printf("Your fortune: %s\n", fortunes[fortune_index]);
}

void ask_mood() {
    printf("\nHow are you feeling today?\n");
    for (int i = 0; i < MAX_MOODS; i++) {
        printf("%d. %s\n", i + 1, moods[i]);
    }

    int mood_choice;
    printf("Select your mood (1-5): ");
    scanf("%d", &mood_choice);
    while (mood_choice < 1 || mood_choice > MAX_MOODS) {
        printf("Invalid choice. Please choose a number between 1 and 5: ");
        scanf("%d", &mood_choice);
    }
    printf("Your current mood is: %s\n", moods[mood_choice - 1]);
}

void custom_fortune() {
    char user_fortunes[MAX_USER_FORTUNES][256];
    printf("\nShare your own fortunes! You can enter up to %d.\n", MAX_USER_FORTUNES);
    
    for (int i = 0; i < MAX_USER_FORTUNES; i++) {
        printf("Enter fortune #%d (type 'done' to finish): ", i + 1);
        fgets(user_fortunes[i], 256, stdin);
        // Remove newline character
        user_fortunes[i][strcspn(user_fortunes[i], "\n")] = 0; 
        if (strcmp(user_fortunes[i], "done") == 0) {
            printf("You've entered: %d fortunes.\n", i);
            break;
        }
    }

    printf("Thank you! Here are your custom fortunes:\n");
    for (int j = 0; j < MAX_USER_FORTUNES; j++) {
        if (strlen(user_fortunes[j]) > 0) {
            printf("%s\n", user_fortunes[j]);
        }
    }
}

int main() {
    greet_user();
    display_categories();
    int category_choice = get_user_choice();
    generate_fortune(category_choice);
    ask_mood();
    custom_fortune();
    printf("\nThank you for using the Automated Fortune Teller! Have a great day!\n");
    return 0;
}