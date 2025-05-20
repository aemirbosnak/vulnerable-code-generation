//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_CUSTOMERS 5

const char* fortunes[MAX_FORTUNES] = {
    "You will find a great opportunity at work soon.",
    "A journey of a thousand miles begins with a single step.",
    "You will meet an interesting person in the next few days.",
    "Patience is your key to success.",
    "A surprise gift is waiting for you around the corner.",
    "New adventures will bring you happiness.",
    "You will overcome your fears this week.",
    "Someone is thinking of you right now.",
    "Your hard work will soon pay off.",
    "Love is coming your way."
};

typedef struct {
    char name[50];
    int age;
    char question[100];
} Customer;

void displayWelcomeMessage() {
    printf("*********************************\n");
    printf("   Welcome to the Fortune Teller  \n");
    printf("*********************************\n");
    printf("     What's on your mind today?  \n");
    printf("*********************************\n");
}

void getCustomerDetails(Customer *customer) {
    printf("Please enter your name: ");
    fgets(customer->name, sizeof(customer->name), stdin);
    customer->name[strcspn(customer->name, "\n")] = 0; // Remove newline

    printf("Please enter your age: ");
    scanf("%d", &customer->age);
    getchar(); // Consume newline

    printf("What is your question for the fortune teller? ");
    fgets(customer->question, sizeof(customer->question), stdin);
    customer->question[strcspn(customer->question, "\n")] = 0; // Remove newline
}

void displayFortune(int index) {
    printf("Your fortune: %s\n", fortunes[index]);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;
    char continueInput;

    do {
        if (customerCount >= MAX_CUSTOMERS) {
            printf("Maximum number of customers reached. Thank you for visiting!\n");
            break;
        }

        displayWelcomeMessage();
        getCustomerDetails(&customers[customerCount]);

        printf("\nThank you, %s. Here is your fortune!\n", customers[customerCount].name);
        int randomIndex = rand() % MAX_FORTUNES; // Get random fortune
        displayFortune(randomIndex);

        printf("Would you like to consult the fortune teller again? (y/n): ");
        scanf(" %c", &continueInput);
        getchar(); // Consume newline
        
        customerCount++;

    } while (continueInput == 'y' || continueInput == 'Y');

    printf("\nThank you for visiting the Fortune Teller!\n");
    printf("We hope to see you again soon!\n");

    return 0;
}