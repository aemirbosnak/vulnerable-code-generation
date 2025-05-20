//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_INPUT_LENGTH 100

const char *fortunes[MAX_FORTUNES] = {
    "An unexpected mystery shall unfold before you.",
    "You will uncover hidden truths in your path.",
    "Danger lurks close, but your intuition will guide you.",
    "A wise friend will offer you a crucial piece of advice.",
    "Look beyond the obvious; the answer lies in the shadows.",
    "A curious stranger will be a pivotal character in your story.",
    "Your sharp mind will decipher the unlikeliest of clues.",
    "Patience is a virtue; wait for the opportune moment.",
    "Trust in your instincts; they will lead you correctly.",
    "A sudden revelation will illuminate your choices."
};

void print_intro() {
    printf("=============================================\n");
    printf("   Welcome to the Automated Fortune Teller   \n");
    printf("            In the Style of Sherlock Holmes  \n");
    printf("=============================================\n");
    printf("Pose your question about the future and seek wisdom.\n\n");
}

void get_user_question(char *input) {
    printf("Enter your question: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the trailing newline character
}

void tell_fortune() {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;
    printf("As Sherlock Holmes would say: \"%s\"\n\n", fortunes[index]);
}

int main() {
    char question[MAX_INPUT_LENGTH];
    char continue_asking;

    print_intro();

    do {
        get_user_question(question);
        
        if (strlen(question) == 0) {
            printf("A question unasked is a mystery unsolved.\n");
        } else {
            printf("You pondered: \"%s\"\n", question);
            tell_fortune();
        }

        printf("Would you like to ask another question? (y/n): ");
        scanf(" %c", &continue_asking);
        getchar(); // To consume the newline character left in the input buffer
    } while (continue_asking == 'y' || continue_asking == 'Y');

    printf("Thank you for consulting the fortune teller. Until next time, be ever observant!\n");
    
    return 0;
}