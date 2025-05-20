//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: grateful
// Grateful Program in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 5

void grateful(int depth);

int main() {
    int choice;

    // Welcome message
    printf("Welcome to the Grateful Program!\n");

    // Ask user for their choice
    printf("Please enter your choice (1-4): ");
    scanf("%d", &choice);

    // Recursively call grateful function based on user's choice
    switch (choice) {
        case 1:
            grateful(1);
            break;
        case 2:
            grateful(2);
            break;
        case 3:
            grateful(3);
            break;
        case 4:
            grateful(4);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            return 0;
    }

    // Thank the user for their input
    printf("Thank you for playing the Grateful Program! You have been a wonderful player!\n");

    return 0;
}

void grateful(int depth) {
    // Greet the user with a message based on the depth
    switch (depth) {
        case 1:
            printf("Thank you for choosing the first option! You are a true friend.\n");
            break;
        case 2:
            printf("Wow, you have chosen the second option! You are a kind soul.\n");
            break;
        case 3:
            printf("You have chosen the third option! You are a generous spirit.\n");
            break;
        case 4:
            printf("Congratulations on choosing the fourth option! You are a true gem.\n");
            break;
        default:
            printf("Invalid depth! Please try again.\n");
            return;
    }

    // Recursively call grateful function with the next depth level
    if (depth < MAX_DEPTH) {
        grateful(depth + 1);
    }
}