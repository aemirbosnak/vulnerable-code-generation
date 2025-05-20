//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_FORTUNE_LENGTH 500
#define NUM_FORTUNES 5

void print_welcome();
void get_user_name(char *name);
void ask_questions(int *color, int *animal, int *number);
void generate_fortune(int color, int animal, int number, char *fortune);
void print_fortune(const char *name, const char *fortune);

int main() {
    char name[MAX_NAME_LENGTH];
    char fortune[MAX_FORTUNE_LENGTH];
    int color, animal, number;

    print_welcome();
    get_user_name(name);

    ask_questions(&color, &animal, &number);
    generate_fortune(color, animal, number, fortune);
    print_fortune(name, fortune);

    return 0;
}

void print_welcome() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I can unlock the secrets of your future with a few questions.\n");
    printf("Let's begin...\n");
}

void get_user_name(char *name) {
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    // Remove newline character from the input
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
}

void ask_questions(int *color, int *animal, int *number) {
    printf("Choose a color from the following options:\n");
    printf("1. Red\n2. Blue\n3. Green\n4. Yellow\n5. Purple\n");
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", color);

    printf("Choose your favorite animal from the following options:\n");
    printf("1. Lion\n2. Dove\n3. Dolphin\n4. Elephant\n5. Owl\n");
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", animal);

    printf("Choose a number between 1 and 10: ");
    scanf("%d", number);
}

void generate_fortune(int color, int animal, int number, char *fortune) {
    srand(time(NULL));
    
    const char *colors[] = {"passion", "faith", "nature", "happiness", "mystery"};
    const char *animals[] = {
        "you will roar with success.",
        "you will find peace in chaos.",
        "you will navigate through challenges with grace.",
        "you will carry wisdom and strength.",
        "you will gain insights from observing others."
    };

    const char *numbers[] = {
        "Adventure awaits you on your travels.",
        "Expect a call from an old friend.",
        "Your hard work will soon pay off.",
        "A surprise gift comes your way.",
        "Love is just around the corner.",
        "A new hobby will bring joy to your life.",
        "You will discover a hidden talent.",
        "A financial opportunity is approaching.",
        "A journey will bring valuable lessons.",
        "A chance encounter will change your perspective."
    };

    if (color < 1 || color > 5) color = 1; // Default to Red
    if (animal < 1 || animal > 5) animal = 1; // Default to Lion
    if (number < 1 || number > 10) number = 1; // Default to 1

    snprintf(fortune, MAX_FORTUNE_LENGTH, "As a %s lover, %s Because you chose the number %d, %s",
             colors[color - 1], animals[animal - 1], number, numbers[number - 1]);
}

void print_fortune(const char *name, const char *fortune) {
    printf("\n%s, here is your fortune:\n", name);
    printf("%s\n", fortune);
    printf("May your future be bright and full of surprises!\n");
}