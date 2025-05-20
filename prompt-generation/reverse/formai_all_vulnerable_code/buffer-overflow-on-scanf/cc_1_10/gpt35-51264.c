//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_fortune() {
    int num = rand() % 10;
    char* fortune;

    switch(num) {
        case 0:
            fortune = "You will find love in the most unexpected place.";
            break;

        case 1:
            fortune = "The stars are aligned in your favor. You will soon enjoy great success.";
            break;

        case 2:
            fortune = "Be careful when making decisions. Your fate depends on them.";
            break;

        case 3:
            fortune = "You will soon embark on a great adventure. Embrace it with open arms.";
            break;

        case 4:
            fortune = "Your future is bright, but only if you work hard to achieve your goals.";
            break;

        case 5:
            fortune = "The past holds the key to your future. Remember to learn from it.";
            break;

        case 6:
            fortune = "Your dreams will soon become a reality. Keep pushing towards them.";
            break;

        case 7:
            fortune = "You have the power to shape your own destiny. Make the most of it.";
            break;

        case 8:
            fortune = "Take a moment to reflect on your past achievements. You'll find inspiration for the future.";
            break;

        default:
            fortune = "Beware of the unexpected. It may lead to great fortune or great misfortune.";
            break;
    }

    printf("%s\n", fortune);
}

int main() {
    srand(time(NULL));

    char question[100];
    printf("Welcome to the Automated Fortune Teller. Ask me a question for a glimpse into your future.\n");

    while(strcmp(question, "quit") != 0) {
        printf("Enter your question (type 'quit' to exit): ");
        scanf("%s", question);
        if(strcmp(question, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        print_fortune();
    }

    return 0;
}