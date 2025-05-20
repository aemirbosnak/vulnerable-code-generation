//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to print fortune
void print_fortune(char* fortune) {
    printf("%s\n", fortune);
}

// Function to generate random fortune
char* generate_fortune() {
    char* fortunes[] = {
        "You will have a successful day today.",
        "You will meet someone new and interesting.",
        "You will receive good news soon.",
        "You will overcome a challenge in your life.",
        "You will find happiness in unexpected places.",
        "You will have a great opportunity presented to you.",
        "You will achieve your goals with hard work and determination.",
        "You will be blessed with good health and fortune.",
        "You will experience a positive change in your life.",
        "You will have a lucky day today."
    };

    int rand_num = rand() % 10;
    return fortunes[rand_num];
}

// Main function
int main() {
    srand(time(NULL));

    // Greet user
    printf("Welcome to the Automated Fortune Teller!\n");

    // Get user's name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    // Capitalize user's name
    for (int i = 0; i < strlen(name); i++) {
        name[i] = toupper(name[i]);
    }

    // Print personalized fortune
    printf("Hello %s, your fortune is:\n", name);
    char* fortune = generate_fortune();
    print_fortune(fortune);

    // Ask user if they want another fortune
    char choice;
    while (toupper(choice)!= 'N') {
        printf("\nDo you want another fortune? (Y/N) ");
        scanf(" %c", &choice);
        if (toupper(choice) == 'Y') {
            printf("\nYour new fortune is:\n");
            fortune = generate_fortune();
            print_fortune(fortune);
        }
    }

    return 0;
}