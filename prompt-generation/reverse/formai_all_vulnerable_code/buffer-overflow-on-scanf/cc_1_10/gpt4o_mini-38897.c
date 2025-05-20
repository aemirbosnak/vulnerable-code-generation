//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void display_introduction() {
    printf("Welcome to the Fortune Teller!\n");
    printf("I will provide you with a fortune based on your answers!\n");
    printf("Please answer the questions truthfully.\n\n");
}

void get_user_details(char* name, int name_size, int* birth_year) {
    printf("What is your name? ");
    fgets(name, name_size, stdin);
    
    printf("What year were you born? ");
    scanf("%d", birth_year);
    getchar(); // Clear input buffer
}

void provide_fortune(int index) {
    const char* fortunes[NUM_FORTUNES] = {
        "You will find wealth beyond your wildest dreams.",
        "A great opportunity is coming your way.",
        "Someone you are close to will soon disappoint you.",
        "Today is a good day for a new project.",
        "Expect an exciting change in your life soon.",
        "Trust your intuition; it is guiding you.",
        "Love is just around the corner.",
        "An old friend will reach out to you unexpectedly.",
        "Beware of unexpected challenges.",
        "Joy and happiness will come to you in abundance."
    };
    
    printf("Your fortune: %s\n\n", fortunes[index]);
}

int calculate_fortune_index(int birth_year) {
    srand(time(NULL)); // Seed the random number generator
    return (birth_year + rand()) % NUM_FORTUNES;
}

void display_conclusion(char* name) {
    printf("Thank you for visiting, %s", name);
    printf("May your day be filled with fortune and prosperity!\n");
}

int main() {
    char name[50];
    int birth_year = 0;

    display_introduction();
    get_user_details(name, sizeof(name), &birth_year);
    
    int fortune_index = calculate_fortune_index(birth_year);
    provide_fortune(fortune_index);
    
    display_conclusion(name);

    return 0;
}