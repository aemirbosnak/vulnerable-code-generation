//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void welcome_message();
int get_user_input();
void print_fortune(int fortune_number);
void goodbye_message();

// Main function
int main()
{
    // Print welcome message
    welcome_message();

    // User prompt
    printf("Enter any number from 1 to 10: ");

    // Get user input
    int user_input = get_user_input();

    // Generate random fortune number
    srand(time(NULL)); // seed random number generator
    int fortune_number = rand() % 10 + 1;

    // Print fortune based on user input
    if (user_input % 2 == 0) {
        print_fortune(user_input + fortune_number);
    } else {
        print_fortune(user_input - fortune_number);
    }

    // Print goodbye message
    goodbye_message();

    return 0;
}

// Function definitions
void welcome_message()
{
    printf("*** Welcome to the Automated Fortune Teller ***\n\n");
}

int get_user_input()
{
    int user_input;
    scanf("%d", &user_input);
    return user_input;
}

void print_fortune(int fortune_number)
{
    switch (fortune_number) {
        case 1:
            printf("You will soon receive a surprise visit from a loved one.\n");
            break;
        case 2:
            printf("Good luck will come to you by the light of a full moon.\n");
            break;
        case 3:
            printf("You will be blessed with good health and prosperity.\n");
            break;
        case 4:
            printf("Happiness is just around the corner for you.\n");
            break;
        case 5:
            printf("You will be presented with an opportunity to excel in your career.\n");
            break;
        case 6:
            printf("Your efforts and hard work will pay off in the near future.\n");
            break;
        case 7:
            printf("Your creative inspiration will guide you to great success.\n");
            break;
        case 8:
            printf("You will soon find love in an unexpected place.\n");
            break;
        case 9:
            printf("A confrontation with someone close to you is inevitable.\n");
            break;
        case 10:
            printf("You will experience a great adventure soon.\n");
            break;
        default:
            printf("Invalid fortune number.\n");
    }
}

void goodbye_message()
{
    printf("\n*** Thank you for using our Automated Fortune Teller ***\n");
}