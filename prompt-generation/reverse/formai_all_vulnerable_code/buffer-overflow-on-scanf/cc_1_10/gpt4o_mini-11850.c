//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_intro() {
    printf("Welcome, dear seeker of knowledge.\n");
    printf("I am your automated fortune teller.\n");
    printf("Together we shall unveil the mysteries that lie ahead.\n");
    printf("Please answer my questions with honesty.\n");
    printf("Your future awaits!\n");
}

int ask_question(const char *question) {
    int response;
    printf("%s (1: Yes, 2: No, 3: Maybe): ", question);
    scanf("%d", &response);
    while (response < 1 || response > 3) {
        printf("Invalid answer. Please respond with 1, 2, or 3: ");
        scanf("%d", &response);
    }
    return response;
}

void generate_fortune(int responses[]) {
    const char *fortunes[] = {
        "You will face a significant challenge, but victory is within your reach.",
        "A surprising encounter will change your perspective on life.",
        "Wealth will come unexpectedly; be prepared to receive it.",
        "A long-awaited journey is on the horizon.",
        "Love and friendship will blossom in familiar places.",
        "Patience is the key to solve your current dilemmas.",
        "An old friend will reach out; cherish this connection.",
        "Your creativity will open doors you never knew existed."
    };
    
    srand(time(NULL));
    int index = (responses[0] + responses[1] + responses[2]) % (sizeof(fortunes) / sizeof(fortunes[0]));
    printf("\nYour fortune is revealed:\n%s\n", fortunes[index]);
}

void conclude_session() {
    printf("As you ponder your fortune, remember, the future is not set in stone.\n");
    printf("Your choices shape your destiny. Embrace the journey ahead.\n");
    printf("Thank you for visiting the automated fortune teller.\n");
}

int main() {
    display_intro();

    int responses[3];
    responses[0] = ask_question("Do you believe in the power of the universe?");
    responses[1] = ask_question("Have you experienced a breakthrough in the past week?");
    responses[2] = ask_question("Are you open to new experiences, even if they are challenging?");

    generate_fortune(responses);
    conclude_session();

    return 0;
}