//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <string.h>

void getFortune(int count);
void askQuestion(const char *question, int *yesCount);

int main() {
    printf("Welcome to the Automated Fortune Teller!\n");
    getFortune(0);
    return 0;
}

void getFortune(int count) {
    if (count >= 5) {
        printf("Your fortune is: You will have a wonderful day filled with unexpected surprises!\n");
        return;
    }

    int yesCount = 0;
    char response[4];

    switch (count) {
        case 0:
            askQuestion("Do you believe in magic? (yes/no): ", &yesCount);
            break;
        case 1:
            askQuestion("Have you ever seen a shooting star? (yes/no): ", &yesCount);
            break;
        case 2:
            askQuestion("Do you think you can change your destiny? (yes/no): ", &yesCount);
            break;
        case 3:
            askQuestion("Is love in your future? (yes/no): ", &yesCount);
            break;
        case 4:
            askQuestion("Will you achieve your dreams? (yes/no): ", &yesCount);
            break;
    }

    if (yesCount > 0) {
        printf("Based on your responses so far...\n");
        getFortune(count + 1);
    } else {
        printf("Your fortune is: You will face challenges, but remember, every cloud has a silver lining!\n");
    }
}

void askQuestion(const char *question, int *yesCount) {
    char response[4];

    printf("%s", question);
    scanf("%3s", response);
    
    // Normalize input
    for (int i = 0; response[i]; i++) {
        response[i] = tolower(response[i]);
    }

    if (strcmp(response, "yes") == 0) {
        (*yesCount)++;
        printf("Great! Your positivity is noted.\n");
    } else if (strcmp(response, "no") == 0) {
        printf("That's okay! Everyone has their beliefs.\n");
    } else {
        printf("Please respond with 'yes' or 'no'.\n");
        askQuestion(question, yesCount); // Recursive call to validate input
    }
}