//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

void surprise(int depth);

int main() {
    int choice;
    char str[MAX_STR_LEN];

    printf("Welcome to the Surprise Program!\n");

    do {
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You have chosen option 1! Here's your surprise:\n");
                surprise(1);
                break;
            case 2:
                printf("You have chosen option 2! Here's your surprise:\n");
                surprise(2);
                break;
            case 3:
                printf("You have chosen option 3! Here's your surprise:\n");
                surprise(3);
                break;
            case 4:
                printf("You have chosen option 4! Here's your surprise:\n");
                surprise(4);
                break;
            case 5:
                printf("You have chosen option 5! Here's your surprise:\n");
                surprise(5);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void surprise(int depth) {
    if (depth == 1) {
        printf("Wow, you've chosen option 1! Here's your surprise: \n");
        printf("You've won a prize! Congratulations! \n");
    } else if (depth == 2) {
        printf("Whoa, you've chosen option 2! Here's your surprise: \n");
        printf("You've been transported to a strange planet! \n");
        printf("You see a strange creature approaching you...\n");
    } else if (depth == 3) {
        printf("Oh my, you've chosen option 3! Here's your surprise: \n");
        printf("You've been given a magical power! \n");
        printf("You can now fly! \n");
    } else if (depth == 4) {
        printf("Gasp, you've chosen option 4! Here's your surprise: \n");
        printf("You've discovered a hidden treasure! \n");
        printf("You've won a million dollars! \n");
    } else if (depth == 5) {
        printf("Blimey, you've chosen option 5! Here's your surprise: \n");
        printf("You've been transported to a parallel universe! \n");
        printf("You see a strange version of yourself approaching you...\n");
    } else {
        printf("Invalid depth! Please try again.\n");
    }
}